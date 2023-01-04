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

 //дһ��ҳ
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

 I2C_SFRmap* I2C_Choose;	//ָ��I2C�ڴ�ṹ��ָ�룬ȡֵΪI2C0_SFR~I2C3_SFR��


 void I2C_GPIO_init(void)
 {
	 /*I2Cx*/
	 /*��������*/
	 GPIO_InitTypeDef I2C_GPIO_Init;
 
	 I2C_GPIO_Init.m_Mode = GPIO_MODE_RMP;							 //����GPIO��ӳ�书��
	 I2C_GPIO_Init.m_OpenDrain = GPIO_POD_OD;						 //GPIO��©���
	 I2C_GPIO_Init.m_Pin = GPIO_PIN_MASK_11|GPIO_PIN_MASK_12;		   //Px1 Px2
	 I2C_GPIO_Init.m_PullUp = GPIO_PULLUP;							 //����GPIO����
	 I2C_GPIO_Init.m_PullDown = GPIO_NOPULL;						 //��ʹ��GPIO����
	 GPIO_Pin_RMP_Config(GPIOB_SFR,GPIO_Pin_Num_11,GPIO_RMP_AF8_I2C3); //����PB1ΪI2C1 SCL
	 GPIO_Pin_RMP_Config(GPIOB_SFR,GPIO_Pin_Num_12,GPIO_RMP_AF8_I2C3); //����PB2ΪI2C1 SDA
	 GPIO_Configuration(GPIOB_SFR,&I2C_GPIO_Init);

	 PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_I2C3CLKEN,TRUE);
 }


 
 /**
   * ����	I2Cx ��ʼ��
   * ����	I2Cx��ȡֵ��ΧI2C0_SFR~I2C1_SFR   ѡ�õ�I2C
   *
   * ����	��
 */
 void I2C_init_Master(I2C_SFRmap* I2Cx)
 {
	 /*����I2CxӦ�ò���*/
	 I2C_Reset(I2Cx);									   //I2C��λ��ʹ��I2Cʱ��
	 I2C_InitTypeDef newStruct_I2C; 					   //
	 newStruct_I2C.m_Mode = I2C_MODE_I2C;				   //����ΪI2Cģʽ
	 newStruct_I2C.m_ClockSource = I2C_CLK_SCLK;		   //ʱ��Դѡ��SCLK 48M

#if	IIC_10BIT_Address
	 newStruct_I2C.m_BADR10 = I2C_BUFRADDRESS_10BIT;	   //����10λ�ӻ���ַ
#else
	 newStruct_I2C.m_BADR10 = I2C_BUFRADDRESS_7BIT; 	   //����7λ�ӻ���ַ
#endif
	 newStruct_I2C.m_MasterSlave = I2C_MODE_SMBUSHOST;	   // SMBus����ѡ������ģʽ
	 //ʱ��ԴΪ120M��һ�μ���ʱ��Ϊ1/120=0.0083 us �����ʵĸߵ͵�ƽʱ������趨ֵ ������X0.0083us���趨ֵҪ������ֵ С
#ifdef IIC_100K
	 newStruct_I2C.m_BaudRateL = 555;						//I2C�����ʵ͵�ƽʱ������	���ֵ ����С��3
	 newStruct_I2C.m_BaudRateH = 555;						//I2C�����ʸߵ�ƽʱ������	���ֵ ����С��3
#elif defined IIC_400K
	 newStruct_I2C.m_BaudRateL = 115;						//I2C�����ʵ͵�ƽʱ������	���ֵ ����С��3
	 newStruct_I2C.m_BaudRateH = 115;						//I2C�����ʸߵ�ƽʱ������	���ֵ ����С��3
#elif defined IIC_1M
	 newStruct_I2C.m_BaudRateL = 20;					   //I2C�����ʵ͵�ƽʱ������   ���ֵ ����С��3
	 newStruct_I2C.m_BaudRateH = 20;					   //I2C�����ʸߵ�ƽʱ������   ���ֵ ����С��3
#endif
	 newStruct_I2C.m_AckEn = TRUE;						   //ʹ��Ӧ��
	 newStruct_I2C.m_AckData = I2C_ACKDATA_ACK; 		   //ѡ��Ӧ���ź�ΪACK
	 I2C_Configuration(I2Cx, &newStruct_I2C);
 
 
 
	 I2C_Cmd(I2Cx,TRUE);					//ʹ��I2Cģ��
	 I2C_Clear_INTERRUPT_Flag(I2Cx);		//��I2C�жϱ�־λ
 
	 I2C_MATCH_ADDRESS_Config(I2Cx,TRUE);	//ʹ������I2C��ַƥ��
	 I2C_ISIE_INT_Enable(I2Cx, TRUE);		//ʹ��I2C�ж�
	 I2C_Cmd(I2Cx,TRUE);					//ʹ��I2Cģ��
 
 
 }
 
 
 
 
 /**
   * ����	I2C дһ���ֽ�����
   * ����	 Write_address��Ҫд��ָ���ļĴ�����ַ
   *		I2C_data: д�����ݼĴ�����ֵ��ȡֵΪ10λ���ݡ�
   * ����	��
 */
 void I2C_Byte_Write(uint16_t Write_i2c_Addr,uint32_t I2C_data)
 {
	 I2C_Choose=IIC_SOURCE; //ѡ��I2C0_SFR I2C1_SFR
 
	 static uint8_t I2C_SLAVE_ADDRESS10BH=0;
	 static uint8_t I2C_SLAVE_ADDRESS10BL=0;
 
 
	 //����
	 /*ʹ��ģ��*/
	 I2C_Cmd(I2C_Choose,TRUE);
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		 //��I2C�жϱ�־λISIFλ
 
 
	 /*��ʼλ*/
	 I2C_Generate_START(I2C_Choose,TRUE);		   //ʹ����ʼ�ź�
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));   //�ȴ���ʼ�ź��ȶ�
 
#if IIC_10BIT_Address
 
	 I2C_SLAVE_ADDRESS10BL=Write_i2c_Addr& 0xff;	   //��8λ�Ĵ�����ַ
	 I2C_SLAVE_ADDRESS10BH=(Write_i2c_Addr>>8)& 0xff;  //��8λ�Ĵ�����ַ
	 /*���ʹӻ�10λ��λ��ַ*/
	 I2C_SendData(I2C_Choose,I2C_SLAVE_ADDRESS10BH); //���ʹӻ���ַ  I2C_SLAVE_ADDRESS10BH
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //��I2C�жϱ�־λISIFλ
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //�ȴ��������
 
	 /*���ʹӻ�10λ��λ��ַ*/
	 I2C_SendData(I2C_Choose,I2C_SLAVE_ADDRESS10BL); //���ʹӻ���ַ  I2C_SLAVE_ADDRESS10BL
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //��I2C�жϱ�־λISIFλ
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //�ȴ��������
	 while(I2C_Get_Ack_Fail_Flag(I2C_Choose));	  //�ж��Ƿ���ACKӦ����û����ֹͣ��������������
 
#else
	 /*����7λ�ӻ���ַ*/
	 I2C_SendData8(I2C_Choose,Write_i2c_Addr); //���ʹӻ���ַ  I2C_SLAVE_ADDRESS10BH_W
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //��I2C�жϱ�־λISIFλ
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //�ȴ��������
	 while(I2C_Get_Ack_Fail_Flag(I2C_Choose));	  //�ж��Ƿ���ACKӦ����û����ֹͣ��������������
#endif
 
 
	 /*��������*/
	 I2C_SendData(I2C_Choose,I2C_data); 		  //��������
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //��I2C�жϱ�־λISIFλ
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //�ȴ��������
 
 
	 /*ֹͣλ*/
	 I2C_Generate_STOP(I2C_Choose,TRUE);		 //ʹ��ֹͣ�ź�
 
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		 //��I2C�жϱ�־λISIFλ
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose)); //�ȴ�ֹͣ���
 
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		 //��I2C�жϱ�־λISIFλ
	 I2C_Clear_Stop_Flag(I2C_Choose);			 //��I2Cֹͣ��־λPIFλ
	 I2C_Cmd(I2C_Choose,FALSE); 				 //�ر�I2Cģ��
 
 }
 
 
 
 /**
   * ����	I2C д����ֽ�����
   * ����	Write_i2c_Addr��Ҫд��ָ����I2C��ַ
   *		  p_buffer: д�����ݵ�ַָ��
   *		  number_of_byte��д�����ݸ���
   * ����	��
 */
 void I2C_Buffer_write(uint16_t Write_i2c_Addr,uint8_t *p_buffer,uint16_t number_of_byte)
 {
 
	 I2C_Choose=IIC_SOURCE;//ѡ��I2C0_SFR I2C1_SFR
 
 
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);	 //��I2C�жϱ�־λISIFλ
	 I2C_Cmd(I2C_Choose,TRUE);				 //ʹ��I2Cģ��
	 /*��ʼλ*/
	 I2C_Generate_START(I2C_Choose,TRUE);	 //ʹ����ʼ�ź�
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose)); //�ȴ���ʼ�ź��ȶ�
 
 
#if IIC_10BIT_Address
	 static uint8_t I2C_SLAVE_ADDRESS10BH=0;
	 static uint8_t I2C_SLAVE_ADDRESS10BL=0;
	 I2C_SLAVE_ADDRESS10BL=Write_i2c_Addr& 0xff;	   //��8λI2C��ַ
	 I2C_SLAVE_ADDRESS10BH=(Write_i2c_Addr>>8)& 0xff;  //��8λI2C��ַ
 
 
	 /*���ʹӻ�10λ��λ��ַ*/
	 I2C_SendData(I2C_Choose,I2C_SLAVE_ADDRESS10BH); //���ʹӻ���ַ  I2C_SLAVE_ADDRESS10BH_W
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //��I2C�жϱ�־λISIFλ
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //�ȴ��������
 
	 /*���ʹӻ�10λ��λ��ַ*/
	 I2C_SendData(I2C_Choose,I2C_SLAVE_ADDRESS10BL); //���ʹӻ���ַ  I2C_SLAVE_ADDRESS10BH_W
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //��I2C�жϱ�־λISIFλ
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //�ȴ��������
	 while(I2C_Get_Ack_Fail_Flag(I2C_Choose));	  //�ж��Ƿ���ACKӦ����û����ֹͣ��������������
 
 
#else
	 /*����7λ�ӻ���ַ*/
	 I2C_SendData8(I2C_Choose,Write_i2c_Addr); //���ʹӻ���ַ  I2C_SLAVE_ADDRESS10BH_W
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //��I2C�жϱ�־λISIFλ
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //�ȴ��������
	 while(I2C_Get_Ack_Fail_Flag(I2C_Choose));	  //�ж��Ƿ���ACKӦ����û����ֹͣ��������������
#endif
 
 
	 /*ѭ��д���� */
	 while(number_of_byte--){
		 I2C_SendData8(I2C_Choose, *p_buffer);	  //��������
		 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		 //��I2C�жϱ�־λISIFλ
		 /* ָ����һ��Ҫд���ֽ�*/
		 p_buffer++;
		 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));//�ȴ���ȡBuff���ISIF����1
	 }
 
 
	 /*ֹͣλ*/
	 I2C_Generate_STOP(I2C_Choose,TRUE);		 //ʹ��ֹͣ�ź�
 
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		 //��I2C�жϱ�־λISIFλ
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose)); //�ȴ�ֹͣ���
 
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		 //��I2C�жϱ�־λISIFλ
	 I2C_Clear_Stop_Flag(I2C_Choose);			 //��I2Cֹͣ��־λPIFλ
	 I2C_Cmd(I2C_Choose,FALSE); 				 //�ر�I2Cģ��
 
 }
 
 /**
   * ����	I2C �� һ���ֽ�����
   * ���� ����	 Read_I2C_Addr��ָ��Ҫ����I2C��ַ
   *		  p_buffer: �������ݵ�ַָ��
   *		  number_of_byte����ȡ���ݸ���
   * ����	��
 */
 void I2C_byte_read(uint16_t Read_i2c_Addr,uint32_t I2C_data,uint16_t number_of_byte)
 {
 
 
	 I2C_Choose=IIC_SOURCE;  //ѡ��I2C0_SFR I2C1_SFR
	 static uint8_t I2C_SLAVE_ADDRESS10BH=0;
	 static uint8_t I2C_SLAVE_ADDRESS10BL=0;
 
	 I2C_Cmd(I2C_Choose,TRUE);				 //ʹ��I2Cģ��
	 /*��ʼλ*/
	 I2C_Generate_START(I2C_Choose,TRUE);	 //ʹ����ʼ�ź�
	 while(!I2C_Get_Start_Flag(I2C_Choose)); //�ȴ���ʼ�ź��ȶ�
 
 
#if IIC_10BIT_Address
	 I2C_SLAVE_ADDRESS10BL=Read_i2c_Addr& 0xff; 	  //��8λ�Ĵ�����ַ
	 I2C_SLAVE_ADDRESS10BH=(Read_i2c_Addr>>8)& 0xff;  //��8λ�Ĵ�����ַ
	 /*���ʹӻ�10λ��λ��ַ*/
	 I2C_SendData(I2C_Choose,I2C_SLAVE_ADDRESS10BH|0x01); //���ʹӻ���ַ  I2C_SLAVE_ADDRESS10BH_W
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //��I2C�жϱ�־λISIFλ
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //�ȴ��������
 
	 /*���ʹӻ�10λ��λ��ַ*/
	 I2C_SendData(I2C_Choose,I2C_SLAVE_ADDRESS10BL); //���ʹӻ���ַ  I2C_SLAVE_ADDRESS10BH_W
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //��I2C�жϱ�־λISIFλ
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //�ȴ��������
	 while(I2C_Get_Ack_Fail_Flag(I2C_Choose));	  //�ж��Ƿ���ACKӦ����û����ֹͣ��������������
 
#else
	 /*����7λ�ӻ���ַ*/
	 I2C_SendData(I2C_Choose,Read_i2c_Addr|0x01); //���ʹӻ���ַ  Read_i2c_Addr
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //��I2C�жϱ�־λISIFλ
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //�ȴ��������
	 while(I2C_Get_Ack_Fail_Flag(I2C_Choose));	  //�ж��Ƿ���ACKӦ����û����ֹͣ��������������
#endif
 
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);			 //Ȼ��������־λISIFλ
 
	 /* ��I2C��ȡһ������*/
	 I2C_data = I2C_ReceiveData(I2C_Choose);
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //�ȴ���ȡBuff���ISIF����1
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //Ȼ���������־λISIFλ
	 I2C_Ack_DATA_Config(I2C_Choose,I2C_ACKDATA_ACK);//�������ݺ�ظ�ACK
 
 
 
	 /*ֹͣλ*/
	 I2C_Generate_STOP(I2C_Choose,TRUE);		 //ʹ��ֹͣ�ź�
 
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		 //��I2C�жϱ�־λISIFλ
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose)); //�ȴ�ֹͣ���
 
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		 //��I2C�жϱ�־λISIFλ
	 I2C_Clear_Stop_Flag(I2C_Choose);			 //��I2Cֹͣ��־λPIFλ
	 I2C_Cmd(I2C_Choose,FALSE); 				 //�ر�I2Cģ��
 
 }
 /**
   * ����	I2C ������ֽ�����
   * ����	Read_I2C_Addr��ָ��Ҫ����I2C��ַ
   *		  p_buffer: �������ݵ�ַָ��
   *		  number_of_byte����ȡ���ݸ���
   * ����	��
   *
 */
 void I2C_Buffer_read(uint16_t Read_I2C_Addr,uint8_t *p_buffer,uint16_t number_of_byte)
 {
 
 
	 I2C_Choose=IIC_SOURCE; //ѡ��I2C0_SFR I2C1_SFR
	 static uint8_t I2C_SLAVE_ADDRESS10BH=0;
	 static uint8_t I2C_SLAVE_ADDRESS10BL=0;
 
	 I2C_Cmd(I2C_Choose,TRUE);//��I2C
	 /*��ʼλ*/
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);	//���־λISIFλ
	 I2C_Generate_START(I2C_Choose,TRUE);	//��ʼ�ź�
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));//�ȴ���ʼλ�ȶ�
 
#if IIC_10BIT_Address
	 I2C_SLAVE_ADDRESS10BL=Read_I2C_Addr& 0xff; 	  //��8λ�Ĵ�����ַ
	 I2C_SLAVE_ADDRESS10BH=(Read_I2C_Addr>>8)& 0xff;  //��8λ�Ĵ�����ַ
	 /*���ʹӻ�10λ��λ��ַ*/
	 I2C_SendData(I2C_Choose,I2C_SLAVE_ADDRESS10BH|0x01); //���ʹӻ���ַ  I2C_SLAVE_ADDRESS10BH_W
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //��I2C�жϱ�־λISIFλ
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //�ȴ��������
 
	 /*���ʹӻ�10λ��λ��ַ*/
	 I2C_SendData(I2C_Choose,I2C_SLAVE_ADDRESS10BL); //���ʹӻ���ַ  I2C_SLAVE_ADDRESS10BH_W
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //��I2C�жϱ�־λISIFλ
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //�ȴ��������
	 while(I2C_Get_Ack_Fail_Flag(I2C_Choose));	  //�ж��Ƿ���ACKӦ����û����ֹͣ��������������
 
#else
	 /*����7λ�ӻ���ַ*/
	 I2C_SendData(I2C_Choose,Read_I2C_Addr|0x01); //���ʹӻ���ַ  Read_i2c_Addr
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		  //��I2C�жϱ�־λISIFλ
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //�ȴ��������
	 while(I2C_Get_Ack_Fail_Flag(I2C_Choose));	  //�ж��Ƿ���ACKӦ����û����ֹͣ��������������
#endif
 
 
 
	 /*���Ͷ�ָ��*/
	 I2C_SendData8(I2C_Choose,Read_I2C_Addr);//���ʹӻ���ַ��������
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);			 //���־λISIFλ
 
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));	 //�ȴ��������ISIF����1
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);			 //Ȼ��������־λISIFλ
 
	 while(number_of_byte)
	 {
 
		 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose));  //�ȴ���ȡBuff���ISIF����1
		 if(I2C_Get_Receive_Buff_Flag(I2C_Choose))	   //�ж�Buff�Ƿ�Ϊ��
		 {
			 I2C_Ack_DATA_Config(I2C_Choose,I2C_ACKDATA_ACK);//�ظ�ACK
			 *p_buffer = I2C_ReceiveData(I2C_Choose);
			  I2C_Clear_INTERRUPT_Flag(I2C_Choose); 	   //Ȼ���������־λISIFλ
			  p_buffer++;	   /* ָ����һ������ȡ���ֽڽ��������λ�� */
		 }
 
			 /* �ݼ���ȡ�ֽڼ����� */
			number_of_byte--;
 
	 }
 
 
	 /*ֹͣλ*/
	 I2C_Generate_STOP(I2C_Choose,TRUE);		 //ʹ��ֹͣ�ź�
 
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		 //��I2C�жϱ�־λISIFλ
	 while(!I2C_Get_INTERRUPT_Flag(I2C_Choose)); //�ȴ�ֹͣ���
 
	 I2C_Clear_INTERRUPT_Flag(I2C_Choose);		 //��I2C�жϱ�־λISIFλ
	 I2C_Clear_Stop_Flag(I2C_Choose);			 //��I2Cֹͣ��־λPIFλ
	 I2C_Cmd(I2C_Choose,FALSE); 				 //�ر�I2Cģ��
 
 }
#endif



 
 /*
 EE(ZD24C08)�滮:1000000������
 
 ��ַ0: ODO  L
 ��ַ1: ODO  H
 ��ַ2: ODO  HH
 ��ַ3: ODO  HHH
 ��ַ4: trip  L
 ��ַ5: trip  H 
 ��ַ6: CHECKSUM

 //����̱���:
 ��ַ 8: ODO  L
 ��ַ 9: ODO  H
 ��ַ10: ODO  HH
 ��ַ11: ODO  HHH
 ��ַ12: trip  L
 ��ַ13: trip  H 
 ��ַ14: CHECKSUM


 //para:
 ��ַ 16: switch
 ��ַ 17: backlight
 ��ַ 18: pulse  l
 ��ַ 19: pulse  h
 ��ַ 20: subi   l
 ��ַ 21: subi   h
 ��ַ 22: coef 
 ��ַ 23: speed_alarm 
 ��ַ 24: air_alarm 
 ��ַ 25: oil_alarm 
 ��ַ 26: ranyou_alarm 
 ��ַ 27: air_coef 
 ��ַ 28: air2_coef 
 ��ַ 29: video 
 ��ַ 30: fuel_coef 
 ��ַ 31: rain_time
 ��ַ 32: resv[]  start
 .
 .
 .
 ��ַ 46: resv[]  end
 ��ַ 47: checksum

 //para(����):
 ��ַ 48: switch
 ��ַ 49: backlight
 ��ַ 50: pulse  l
 ��ַ 51: pulse  h
 ��ַ 52: subi   l
 ��ַ 53: subi   h
 ��ַ 54: coef 
 ��ַ 55: speed_alarm 
 ��ַ 56: air_alarm 
 ��ַ 57: oil_alarm 
 ��ַ 58: ranyou_alarm 
 ��ַ 59: air_coef 
 ��ַ 60: air2_coef 
 ��ַ 61: video 
 ��ַ 62: fuel_coef 
 ��ַ 63: rain_time
 ��ַ 64: resv[]  start
 .
 .
 .
 ��ַ 78: resv[]  end
 ��ַ 79: checksum
 
 */
 
 
 
 



