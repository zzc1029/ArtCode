/*
 * ZD24C0x.c
 *
 *  Created on: 2022-5-5
 *      Author: ART
 */

 
#include "system_init.h"
#include "ZD240Cx.h"
#include "Iic.h"

#define delaymax   255
#define   MS  1


 void ZD_iic_init(void)
 {
   ZD_SDA_output();
   ZD_SCL_output();
 
   ZD_SDA(SET);
   ZD_SCL(SET);
 }
  
  void ZD_start(void)
  {
	ZD_SDA(SET);
	delay_(MS);
	ZD_SCL(SET);
	delay_(MS);
	ZD_SDA(RESET);
	delay_(MS);

	ZD_SCL(RESET);
	delay_(MS);
  }
 
 void ZD_stop(void)
 {
   ZD_SDA(RESET);
   delay_(MS);
   ZD_SCL(SET);
   delay_(MS);
   ZD_SDA(SET);
   delay_(MS);
 }
  
  void ZD_respons(void)
  {
	volatile unsigned int i = 0;
	ZD_SCL(SET);
	ZD_SDA_input();
	delay_(MS);
	while((ZD_READ_SDA > 0) && (i < delaymax))
	  i++;
 	ZD_SCL(RESET);
	delay_(MS);
	ZD_SDA_output();
  }
 
  void ZD_write_byte(unsigned char date)
  {
	unsigned char i ,temp;
	temp = date;
	for(i = 0;i < 8;i++)
	{
	   ZD_SCL(RESET);
	   delay_(MS);
	   if((temp&0x80) == 0x80)
		 ZD_SDA(SET);
	   else
		 ZD_SDA(RESET); 
	   temp = temp<<1;
	   delay_(MS);
	   ZD_SCL(SET);
	   delay_(MS);
	}
	ZD_SCL(RESET);
	delay_(MS);
	ZD_SDA(SET);
	delay_(MS);
  }
 
 
  unsigned char ZD_read_byte(void)
  {
	unsigned char i,k = 0;
	ZD_SCL(RESET);
	ZD_SDA_output();
	delay_(MS);
	ZD_SDA(SET);
	delay_(MS);
	ZD_SDA_input();
	delay_(MS);
	for(i = 0;i < 8; i++)
	{
	  ZD_SCL(SET);
	  delay_(MS);
	  k = (k<<1)|ZD_READ_SDA;
	  ZD_SCL(RESET);
	  delay_(MS);
	}
	ZD_SDA_output();
	return k;
  }
 
 
  void ZD_write_add(unsigned int address,unsigned char date)
  {
	ZD_start();
	ZD_write_byte(ZD240C8_ADDR|(((address/256)&0x07) << 1));
	ZD_respons();
	ZD_write_byte(address%256);
	ZD_respons();
	ZD_write_byte(date);
	ZD_respons(); 
	ZD_stop();
  }
 
 
  unsigned char ZD_read_add(unsigned int address)
  {
	unsigned char date;
	ZD_start();
	//ZD_write_byte(ZD240C8_ADDR);
	ZD_write_byte(ZD240C8_ADDR|(((address/256)&0x07) << 1));
	ZD_respons();
	ZD_write_byte(address%2556);
	ZD_respons(); 
	ZD_start();
	ZD_write_byte(ZD240C8_ADDR | (((address/256)&0x07) << 1) | 0x01);
	ZD_respons();	
	date = ZD_read_byte();
	ZD_stop();
	return date;
  }

 //写一整页
  void ZD_write_bytes(unsigned int address,unsigned char *date,unsigned char writenum)
  {
    unsigned short i;
	ZD_start();
	//ZD_write_byte(ZD240C8_ADDR);
	ZD_write_byte(ZD240C8_ADDR|(((address/256)&0x07) << 1));
	ZD_respons();
	ZD_write_byte(address%256);
	ZD_respons();
	for(i = 0;i < writenum;i++)
	{
	  ZD_write_byte(*(date + i));
	  ZD_respons(); 
	}
	ZD_stop();
  }

  unsigned char ZD_read_bytes(unsigned int address,unsigned char *date,unsigned int readnum)
  {
	unsigned short i;
	//ZD_start();
	//ZD_write_byte(ZD240C8_ADDR);
	//ZD_respons();
	//ZD_write_byte(address);
	//ZD_respons(); 
	//ZD_start();
	*date++ = ZD_read_add(address);
	ZD_write_byte(ZD240C8_ADDR | 0x01);
	ZD_respons();
	//*date++ = ZD_read_add(address);
	for(i = 1;i < readnum;i++)
	{
	  *date++ = ZD_read_add(address + i);
	  //ZD_respons(); 
	}
	ZD_stop();
	return 1;
  }
 

#if 0

 I2C_SFRmap* I2C_Choose;	//指向I2C内存结构的指针，取值为I2C0_SFR~I2C3_SFR。


 void I2C_GPIO_init(void)
 {
	 /*I2Cx*/
	 /*引脚配置*/
	 GPIO_InitTypeDef I2C_GPIO_Init;
 
	 I2C_GPIO_Init.m_Mode = GPIO_MODE_RMP;							 //配置GPIO重映射功能
	 I2C_GPIO_Init.m_OpenDrain = GPIO_POD_OD;						 //GPIO开漏输出
	 I2C_GPIO_Init.m_Pin = GPIO_PIN_MASK_11|GPIO_PIN_MASK_12;		   //Px1 Px2
	 I2C_GPIO_Init.m_PullUp = GPIO_PULLUP;							 //配置GPIO上拉
	 I2C_GPIO_Init.m_PullDown = GPIO_NOPULL;						 //不使能GPIO下拉
	 GPIO_Pin_RMP_Config(GPIOB_SFR,GPIO_Pin_Num_11,GPIO_RMP_AF8_I2C3); //配置PB1为I2C1 SCL
	 GPIO_Pin_RMP_Config(GPIOB_SFR,GPIO_Pin_Num_12,GPIO_RMP_AF8_I2C3); //配置PB2为I2C1 SDA
	 GPIO_Configuration(GPIOB_SFR,&I2C_GPIO_Init);

	 PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_I2C3CLKEN,TRUE);
 }


 
 /**
   * 描述	I2Cx 初始化
   * 输入	I2Cx：取值范围I2C0_SFR~I2C1_SFR   选用的I2C
   *
   * 返回	无
 */
 void I2C_init_Master(I2C_SFRmap* I2Cx)
 {
	 /*配置I2Cx应用参数*/
	 I2C_Reset(I2Cx);									   //I2C复位，使能I2C时钟
	 I2C_InitTypeDef newStruct_I2C; 					   //
	 newStruct_I2C.m_Mode = I2C_MODE_I2C;				   //配置为I2C模式
	 newStruct_I2C.m_ClockSource = I2C_CLK_SCLK;		   //时钟源选择SCLK 48M

#if	IIC_10BIT_Address
	 newStruct_I2C.m_BADR10 = I2C_BUFRADDRESS_10BIT;	   //配置10位从机地址
#else
	 newStruct_I2C.m_BADR10 = I2C_BUFRADDRESS_7BIT; 	   //配置7位从机地址
#endif
	 newStruct_I2C.m_MasterSlave = I2C_MODE_SMBUSHOST;	   // SMBus类型选择主机模式
	 //时钟源为120M，一次计数时间为1/120=0.0083 us 波特率的高低电平时间就是设定值 计算数X0.0083us，设定值要比理论值 小
#ifdef IIC_100K
	 newStruct_I2C.m_BaudRateL = 555;						//I2C波特率低电平时间周期	这个值 不能小于3
	 newStruct_I2C.m_BaudRateH = 555;						//I2C波特率高电平时间周期	这个值 不能小于3
#elif defined IIC_400K
	 newStruct_I2C.m_BaudRateL = 115;						//I2C波特率低电平时间周期	这个值 不能小于3
	 newStruct_I2C.m_BaudRateH = 115;						//I2C波特率高电平时间周期	这个值 不能小于3
#elif defined IIC_1M
	 newStruct_I2C.m_BaudRateL = 20;					   //I2C波特率低电平时间周期   这个值 不能小于3
	 newStruct_I2C.m_BaudRateH = 20;					   //I2C波特率高电平时间周期   这个值 不能小于3
#endif
	 newStruct_I2C.m_AckEn = TRUE;						   //使能应答
	 newStruct_I2C.m_AckData = I2C_ACKDATA_ACK; 		   //选择应答信号为ACK
	 I2C_Configuration(I2Cx, &newStruct_I2C);
 
 
 
	 I2C_Cmd(I2Cx,TRUE);					//使能I2C模块
	 I2C_Clear_INTERRUPT_Flag(I2Cx);		//清I2C中断标志位
 
	 I2C_MATCH_ADDRESS_Config(I2Cx,TRUE);	//使能配置I2C地址匹配
	 I2C_ISIE_INT_Enable(I2Cx, TRUE);		//使能I2C中断
	 I2C_Cmd(I2Cx,TRUE);					//使能I2C模块
 
 
 }
 
 
 
 
 /**
   * 描述	I2C 写一个字节数据
   * 输入	 Write_address：要写入指定的寄存器地址
   *		I2C_data: 写入数据寄存器的值，取值为10位数据。
   * 返回	无
 */
 void I2C_Byte_Write(uint16_t Write_i2c_Addr,uint32_t I2C_data)
 {
	 I2C_Choose=IIC_SOURCE; //选择I2C0_SFR I2C1_SFR
 
	 static uint8_t I2C_SLAVE_ADDRESS10BH=0;
	 static uint8_t I2C_SLAVE_ADDRESS10BL=0;
 
 
	 //发送
	 /*使能模块*/
	 I2C_Cmd(I2C_Choose,TRUE);
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		 //清I2C中断标志位ISIF位
 
 
	 /*起始位*/
	 I2C_Generate_START(I2C_Choose,TRUE);		   //使能起始信号
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));   //等待起始信号稳定
 
#if IIC_10BIT_Address
 
	 I2C_SLAVE_ADDRESS10BL=Write_i2c_Addr& 0xff;	   //低8位寄存器地址
	 I2C_SLAVE_ADDRESS10BH=(Write_i2c_Addr>>8)& 0xff;  //高8位寄存器地址
	 /*发送从机10位高位地址*/
	 I2C_SendData(I2C_Choose,I2C_SLAVE_ADDRESS10BH); //发送从机地址  I2C_SLAVE_ADDRESS10BH
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //清I2C中断标志位ISIF位
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //等待发送完成
 
	 /*发送从机10位低位地址*/
	 I2C_SendData(I2C_Choose,I2C_SLAVE_ADDRESS10BL); //发送从机地址  I2C_SLAVE_ADDRESS10BL
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //清I2C中断标志位ISIF位
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //等待发送完成
	 while(I2C_Get_Ack_Fail_Flag(I2C_Choose));	  //判断是否有ACK应答，如没有则停止，如果有则继续发
 
#else
	 /*发送7位从机地址*/
	 I2C_SendData8(I2C_Choose,Write_i2c_Addr); //发送从机地址  I2C_SLAVE_ADDRESS10BH_W
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //清I2C中断标志位ISIF位
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //等待发送完成
	 while(I2C_Get_Ack_Fail_Flag(I2C_Choose));	  //判断是否有ACK应答，如没有则停止，如果有则继续发
#endif
 
 
	 /*发送数据*/
	 I2C_SendData(I2C_Choose,I2C_data); 		  //发送数据
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //清I2C中断标志位ISIF位
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //等待发送完成
 
 
	 /*停止位*/
	 I2C_Generate_STOP(I2C_Choose,TRUE);		 //使能停止信号
 
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		 //清I2C中断标志位ISIF位
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose)); //等待停止完成
 
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		 //清I2C中断标志位ISIF位
	 I2C_Clear_Stop_Flag(I2C_Choose);			 //清I2C停止标志位PIF位
	 I2C_Cmd(I2C_Choose,FALSE); 				 //关闭I2C模组
 
 }
 
 
 
 /**
   * 描述	I2C 写多个字节数据
   * 输入	Write_i2c_Addr：要写入指定的I2C地址
   *		  p_buffer: 写入数据地址指针
   *		  number_of_byte：写入数据个数
   * 返回	无
 */
 void I2C_Buffer_write(uint16_t Write_i2c_Addr,uint8_t *p_buffer,uint16_t number_of_byte)
 {
 
	 I2C_Choose=IIC_SOURCE;//选择I2C0_SFR I2C1_SFR
 
 
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);	 //清I2C中断标志位ISIF位
	 I2C_Cmd(I2C_Choose,TRUE);				 //使能I2C模块
	 /*起始位*/
	 I2C_Generate_START(I2C_Choose,TRUE);	 //使能起始信号
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose)); //等待起始信号稳定
 
 
#if IIC_10BIT_Address
	 static uint8_t I2C_SLAVE_ADDRESS10BH=0;
	 static uint8_t I2C_SLAVE_ADDRESS10BL=0;
	 I2C_SLAVE_ADDRESS10BL=Write_i2c_Addr& 0xff;	   //低8位I2C地址
	 I2C_SLAVE_ADDRESS10BH=(Write_i2c_Addr>>8)& 0xff;  //高8位I2C地址
 
 
	 /*发送从机10位高位地址*/
	 I2C_SendData(I2C_Choose,I2C_SLAVE_ADDRESS10BH); //发送从机地址  I2C_SLAVE_ADDRESS10BH_W
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //清I2C中断标志位ISIF位
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //等待发送完成
 
	 /*发送从机10位低位地址*/
	 I2C_SendData(I2C_Choose,I2C_SLAVE_ADDRESS10BL); //发送从机地址  I2C_SLAVE_ADDRESS10BH_W
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //清I2C中断标志位ISIF位
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //等待发送完成
	 while(I2C_Get_Ack_Fail_Flag(I2C_Choose));	  //判断是否有ACK应答，如没有则停止，如果有则继续发
 
 
#else
	 /*发送7位从机地址*/
	 I2C_SendData8(I2C_Choose,Write_i2c_Addr); //发送从机地址  I2C_SLAVE_ADDRESS10BH_W
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //清I2C中断标志位ISIF位
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //等待发送完成
	 while(I2C_Get_Ack_Fail_Flag(I2C_Choose));	  //判断是否有ACK应答，如没有则停止，如果有则继续发
#endif
 
 
	 /*循环写数据 */
	 while(number_of_byte--){
		 I2C_SendData8(I2C_Choose, *p_buffer);	  //发送数据
		 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		 //清I2C中断标志位ISIF位
		 /* 指向下一个要写的字节*/
		 p_buffer++;
		 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));//等待读取Buff完成ISIF会置1
	 }
 
 
	 /*停止位*/
	 I2C_Generate_STOP(I2C_Choose,TRUE);		 //使能停止信号
 
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		 //清I2C中断标志位ISIF位
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose)); //等待停止完成
 
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		 //清I2C中断标志位ISIF位
	 I2C_Clear_Stop_Flag(I2C_Choose);			 //清I2C停止标志位PIF位
	 I2C_Cmd(I2C_Choose,FALSE); 				 //关闭I2C模组
 
 }
 
 /**
   * 描述	I2C 读 一个字节数据
   * 输入 输入	 Read_I2C_Addr：指定要读的I2C地址
   *		  p_buffer: 读入数据地址指针
   *		  number_of_byte：读取数据个数
   * 返回	无
 */
 void I2C_byte_read(uint16_t Read_i2c_Addr,uint32_t I2C_data,uint16_t number_of_byte)
 {
 
 
	 I2C_Choose=IIC_SOURCE;  //选择I2C0_SFR I2C1_SFR
	 static uint8_t I2C_SLAVE_ADDRESS10BH=0;
	 static uint8_t I2C_SLAVE_ADDRESS10BL=0;
 
	 I2C_Cmd(I2C_Choose,TRUE);				 //使能I2C模块
	 /*起始位*/
	 I2C_Generate_START(I2C_Choose,TRUE);	 //使能起始信号
	 while(!I2C_Get_Start_Flag(I2C_Choose)); //等待起始信号稳定
 
 
#if IIC_10BIT_Address
	 I2C_SLAVE_ADDRESS10BL=Read_i2c_Addr& 0xff; 	  //低8位寄存器地址
	 I2C_SLAVE_ADDRESS10BH=(Read_i2c_Addr>>8)& 0xff;  //高8位寄存器地址
	 /*发送从机10位高位地址*/
	 I2C_SendData(I2C_Choose,I2C_SLAVE_ADDRESS10BH|0x01); //发送从机地址  I2C_SLAVE_ADDRESS10BH_W
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //清I2C中断标志位ISIF位
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //等待发送完成
 
	 /*发送从机10位低位地址*/
	 I2C_SendData(I2C_Choose,I2C_SLAVE_ADDRESS10BL); //发送从机地址  I2C_SLAVE_ADDRESS10BH_W
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //清I2C中断标志位ISIF位
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //等待发送完成
	 while(I2C_Get_Ack_Fail_Flag(I2C_Choose));	  //判断是否有ACK应答，如没有则停止，如果有则继续发
 
#else
	 /*发送7位从机地址*/
	 I2C_SendData(I2C_Choose,Read_i2c_Addr|0x01); //发送从机地址  Read_i2c_Addr
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //清I2C中断标志位ISIF位
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //等待发送完成
	 while(I2C_Get_Ack_Fail_Flag(I2C_Choose));	  //判断是否有ACK应答，如没有则停止，如果有则继续发
#endif
 
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);			 //然后完成清标志位ISIF位
 
	 /* 从I2C读取一个数据*/
	 I2C_data = I2C_ReceiveData(I2C_Choose);
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //等待读取Buff完成ISIF会置1
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //然后读完后清标志位ISIF位
	 I2C_Ack_DATA_Config(I2C_Choose,I2C_ACKDATA_ACK);//读到数据后回复ACK
 
 
 
	 /*停止位*/
	 I2C_Generate_STOP(I2C_Choose,TRUE);		 //使能停止信号
 
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		 //清I2C中断标志位ISIF位
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose)); //等待停止完成
 
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		 //清I2C中断标志位ISIF位
	 I2C_Clear_Stop_Flag(I2C_Choose);			 //清I2C停止标志位PIF位
	 I2C_Cmd(I2C_Choose,FALSE); 				 //关闭I2C模组
 
 }
 /**
   * 描述	I2C 读多个字节数据
   * 输入	Read_I2C_Addr：指定要读的I2C地址
   *		  p_buffer: 读入数据地址指针
   *		  number_of_byte：读取数据个数
   * 返回	无
   *
 */
 void I2C_Buffer_read(uint16_t Read_I2C_Addr,uint8_t *p_buffer,uint16_t number_of_byte)
 {
 
 
	 I2C_Choose=IIC_SOURCE; //选择I2C0_SFR I2C1_SFR
	 static uint8_t I2C_SLAVE_ADDRESS10BH=0;
	 static uint8_t I2C_SLAVE_ADDRESS10BL=0;
 
	 I2C_Cmd(I2C_Choose,TRUE);//打开I2C
	 /*起始位*/
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);	//清标志位ISIF位
	 I2C_Generate_START(I2C_Choose,TRUE);	//起始信号
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));//等待起始位稳定
 
#if IIC_10BIT_Address
	 I2C_SLAVE_ADDRESS10BL=Read_I2C_Addr& 0xff; 	  //低8位寄存器地址
	 I2C_SLAVE_ADDRESS10BH=(Read_I2C_Addr>>8)& 0xff;  //高8位寄存器地址
	 /*发送从机10位高位地址*/
	 I2C_SendData(I2C_Choose,I2C_SLAVE_ADDRESS10BH|0x01); //发送从机地址  I2C_SLAVE_ADDRESS10BH_W
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //清I2C中断标志位ISIF位
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //等待发送完成
 
	 /*发送从机10位低位地址*/
	 I2C_SendData(I2C_Choose,I2C_SLAVE_ADDRESS10BL); //发送从机地址  I2C_SLAVE_ADDRESS10BH_W
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //清I2C中断标志位ISIF位
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //等待发送完成
	 while(I2C_Get_Ack_Fail_Flag(I2C_Choose));	  //判断是否有ACK应答，如没有则停止，如果有则继续发
 
#else
	 /*发送7位从机地址*/
	 I2C_SendData(I2C_Choose,Read_I2C_Addr|0x01); //发送从机地址  Read_i2c_Addr
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //清I2C中断标志位ISIF位
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //等待发送完成
	 while(I2C_Get_Ack_Fail_Flag(I2C_Choose));	  //判断是否有ACK应答，如没有则停止，如果有则继续发
#endif
 
 
 
	 /*发送读指令*/
	 I2C_SendData8(I2C_Choose,Read_I2C_Addr);//发送从机地址及读操作
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);			 //清标志位ISIF位
 
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));	 //等待发送完成ISIF会置1
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);			 //然后完成清标志位ISIF位
 
	 while(number_of_byte)
	 {
 
		 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //等待读取Buff完成ISIF会置1
		 if(I2C_Get_Receive_Buff_Flag(I2C_Choose))	   //判断Buff是否为满
		 {
			 I2C_Ack_DATA_Config(I2C_Choose,I2C_ACKDATA_ACK);//回复ACK
			 *p_buffer = I2C_ReceiveData(I2C_Choose);
			  I2C_Clear_INTERRUPT_Flag(I2C_Choose); 	   //然后读完后清标志位ISIF位
			  p_buffer++;	   /* 指向下一个被读取的字节将被保存的位置 */
		 }
 
			 /* 递减读取字节计数器 */
			number_of_byte--;
 
	 }
 
 
	 /*停止位*/
	 I2C_Generate_STOP(I2C_Choose,TRUE);		 //使能停止信号
 
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		 //清I2C中断标志位ISIF位
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose)); //等待停止完成
 
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		 //清I2C中断标志位ISIF位
	 I2C_Clear_Stop_Flag(I2C_Choose);			 //清I2C停止标志位PIF位
	 I2C_Cmd(I2C_Choose,FALSE); 				 //关闭I2C模组
 
 }
#endif



 
 /*
 EE(ZD24C08)规划:1000000次寿命
 
 地址0: ODO  L
 地址1: ODO  H
 地址2: ODO  HH
 地址3: ODO  HHH
 地址4: trip  L
 地址5: trip  H 
 地址6: CHECKSUM

 //总里程备份:
 地址 8: ODO  L
 地址 9: ODO  H
 地址10: ODO  HH
 地址11: ODO  HHH
 地址12: trip  L
 地址13: trip  H 
 地址14: CHECKSUM


 //para:
 地址 16: switch
 地址 17: backlight
 地址 18: pulse  l
 地址 19: pulse  h
 地址 20: subi   l
 地址 21: subi   h
 地址 22: coef 
 地址 23: speed_alarm 
 地址 24: air_alarm 
 地址 25: oil_alarm 
 地址 26: ranyou_alarm 
 地址 27: air_coef 
 地址 28: air2_coef 
 地址 29: video 
 地址 30: fuel_coef 
 地址 31: rain_time
 地址 32: resv[]  start
 .
 .
 .
 地址 46: resv[]  end
 地址 47: checksum

 //para(备份):
 地址 48: switch
 地址 49: backlight
 地址 50: pulse  l
 地址 51: pulse  h
 地址 52: subi   l
 地址 53: subi   h
 地址 54: coef 
 地址 55: speed_alarm 
 地址 56: air_alarm 
 地址 57: oil_alarm 
 地址 58: ranyou_alarm 
 地址 59: air_coef 
 地址 60: air2_coef 
 地址 61: video 
 地址 62: fuel_coef 
 地址 63: rain_time
 地址 64: resv[]  start
 .
 .
 .
 地址 78: resv[]  end
 地址 79: checksum
 
 */
 
 
 
 



