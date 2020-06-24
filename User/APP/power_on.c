/**
  ******************************************************************************
  * @file    sysytem.c
  * @author  k
  * @version V1.0
  * @date    2018-04-29
  * @brief   �ֳֶ�·�¶Ȳ����ǿ�������
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:����  STM32 F429 ������
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "./led/bsp_led.h"
#include "./lcd/bsp_lcd.h"
#include "./key/bsp_key.h"
#include "./beep/bsp_beep.h"
#include "./tim/bsp_basic_tim.h"
#include "jk508.h"

void power_on(void)
{
	u8 i;
//	char buf[10];
	
	
  /*��ʼ����Ĭ��ʹ��ǰ����*/
	LCD_SetLayer(LCD_FOREGROUND_LAYER); 
	/*Ĭ�����ò�͸��	���ú�������Ϊ��͸���ȣ���Χ 0-0xff ��0Ϊȫ͸����0xffΪ��͸��*/
    LCD_SetTransparency(0xFF);
	LCD_Clear(LCD_COLOR_BLACK);
	/*����LCD_SetLayer(LCD_FOREGROUND_LAYER)������
	����Һ����������ǰ����ˢ�£��������µ��ù�LCD_SetLayer�������ñ�����*/
//	for(i=0;i<16;i++)
//	{
//		LCD_SetColors(LCD_COLOR_WHITE,LCD_COLOR_BLACK);
//		DISP_INS(5+i*20,5,"Initializing Channel");
//		sprintf(buf,"%03d",i+1);
//		DISP_INS(5+i*20,336,(uint8_t*)buf);
//		Delay(500);
//	}
	
	DrawLogo(140,250);

//	Delay(0xffffff);
//	Delay(0xffffff);
//	Delay(0xffffff);
//	Delay(0xffffff);
//	Delay(0xffffff);
//	Delay(0xffffff);
//	LCD_SetColors(LCD_COLOR_BLACK,LCD_COLOR_BLACK);
//	LCD_DrawFullRect(200,200,150,150);
//	LCD_Clear(LCD_COLOR_BLACK);
	LCD_SetColors(LCD_COLOR_GR7,LCD_COLOR_BLACK);
	DISP_SYS(0,0,"JKOS");
	LCD_SetColors(LCD_COLOR_WHITE,LCD_COLOR_BLACK);
	DISP_INS(20,0,"REV 1.0");
	if(CHNUM == 8)
	{
		DISP_INS(80,0,"JK500C Multi-channel Temp.Meter");
	}else if(CHNUM == 16){
		DISP_INS(80,0,"JK500C Multi-channel Temp.Meter");
	}
//	DISP_INS(30,0,"REV 1.0");
	
	
	
	page_flag = poweron;
	
	
}

void DrawLogo(u16 x,u16 y)
{
//	page_flag = 0xff;
//	LCD_Clear(LCD_COLOR_BLACK);	
	LCD_SetColors(LCD_COLOR_GR7,LCD_COLOR_BLACK);
	/*J*/
	LCD_DrawLine(x,y,41,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x-1,y-1,44,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x-1,y-2,46,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x,y-3,46,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+2,y-4,46,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+35,y-5,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+35,y-6,15,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+35,y-7,15,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+36,y-8,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+36,y-9,15,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+37,y-10,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+37,y-11,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+37,y-12,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+38,y-13,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+37,y-14,15,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+38,y-15,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+38,y-16,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+38,y-17,15,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+39,y-18,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+39,y-19,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+39,y-20,15,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+40,y-21,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+40,y-22,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+40,y-23,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+40,y-24,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+41,y-25,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+41,y-26,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+41,y-27,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+42,y-28,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+42,y-29,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+42,y-30,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+42,y-31,15,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+42,y-32,15,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+43,y-33,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+43,y-34,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+44,y-35,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+44,y-36,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+44,y-37,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+44,y-38,15,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+44,y-39,15,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+45,y-40,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+45,y-41,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+45,y-42,15,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+45,y-43,15,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+46,y-44,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+46,y-45,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+46,y-46,15,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+47,y-47,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+47,y-48,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+47,y-49,15,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+47,y-50,15,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+48,y-51,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+48,y-52,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+48,y-53,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+49,y-54,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+49,y-55,14,LCD_DIR_HORIZONTAL);
	
	/*i*/
	LCD_DrawFullRect(x+72,y-54,12,3);
	LCD_DrawLine(x+71,y-52,13,LCD_DIR_HORIZONTAL);
	LCD_DrawFullRect(x+71,y-51,12,4);
	LCD_DrawFullRect(x+70,y-47,12,3);
	
	LCD_DrawLine(x+68,y-44+4,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+69,y-43+4,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+68,y-42+4,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+68,y-41+4,12,LCD_DIR_HORIZONTAL);
	LCD_DrawFullRect(x+68-1,y-40+4,13,3);
	LCD_DrawLine(x+68-1,y-37+4,12,LCD_DIR_HORIZONTAL);
	LCD_DrawFullRect(x+67-1,y-36+4,13,3);
	LCD_DrawLine(x+67-1,y-33+4,12,LCD_DIR_HORIZONTAL);
	LCD_DrawFullRect(x+66-1,y-32+4,13,2);
	LCD_DrawLine(x+66-1,y-30+4,12,LCD_DIR_HORIZONTAL);
	LCD_DrawFullRect(x+65-1,y-29+4,13,3);
	LCD_DrawLine(x+64-1,y-26+4,14,LCD_DIR_HORIZONTAL);
	LCD_DrawFullRect(x+64-1,y-25+4,13,2);
	LCD_DrawFullRect(x+64-1,y-23+4,12,2);
	LCD_DrawLine(x+63-1,y-21+4,13,LCD_DIR_HORIZONTAL);
	LCD_DrawFullRect(x+63-1,y-20+4,12,2);
	LCD_DrawFullRect(x+62-1,y-18+4,13,3);
	LCD_DrawLine(x+62-1,y-15+4,12,LCD_DIR_HORIZONTAL);
	LCD_DrawFullRect(x+61-1,y-14+4,13,3);
	LCD_DrawFullRect(x+60-1,y-11+4,13,2);
	LCD_DrawFullRect(x+59-1,y-5,13,2);
	LCD_DrawLine(x+59-1,y-3,14,LCD_DIR_HORIZONTAL);
	LCD_DrawFullRect(x+59-1,y-2,13,2);
	LCD_DrawLine(x+59-1,y,12,LCD_DIR_HORIZONTAL);
	
	/*n*/
	LCD_DrawLine(x+88,y-40,23,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+85,y-39,27,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+84,y-38,30,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+83,y-37,32,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+83,y-36,3,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+104,y-36,12,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+83,y-35,1,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+104,y-35,12,LCD_DIR_HORIZONTAL);
	LCD_DrawFullRect(x+104,y-34,12,3);
	LCD_DrawFullRect(x+103,y-31,13,3);
	LCD_DrawLine(x+102,y-28,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+103,y-27,12,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+102,y-26,13,LCD_DIR_HORIZONTAL);
	LCD_DrawFullRect(x+101,y-25,13,2);
	LCD_DrawFullRect(x+101,y-23,12,2);
	LCD_DrawFullRect(x+100,y-21,13,3);
	LCD_DrawFullRect(x+99,y-18,13,3);
	LCD_DrawLine(x+99,y-15,12,LCD_DIR_HORIZONTAL);
	LCD_DrawFullRect(x+98,y-14,13,3);
	LCD_DrawLine(x+98,y-11,12,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+97,y-10,13,LCD_DIR_HORIZONTAL);
	LCD_DrawFullRect(x+97,y-9,12,4);
	LCD_DrawFullRect(x+96,y-5,12,3);
	LCD_DrawFullRect(x+95,y-2,13,3);
	
	/*k*/
	LCD_DrawLine(x+127,y-56,12,LCD_DIR_HORIZONTAL);
	LCD_DrawFullRect(x+126,y-55,13,3);
	LCD_DrawFullRect(x+126,y-52,12,2);
	LCD_DrawFullRect(x+125,y-50,12,2);
	LCD_DrawLine(x+124,y-48,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+124,y-47,12,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+124,y-46,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+124,y-45,12,LCD_DIR_HORIZONTAL);
	LCD_DrawFullRect(x+123,y-44,13,2);
	LCD_DrawFullRect(x+123,y-42,12,3);
	LCD_DrawLine(x+153,y-41,12,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+151,y-40,13,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+122,y-39,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+150,y-39,12,LCD_DIR_HORIZONTAL);
	
	LCD_DrawFullRect(x+122,y-38,12,2);
	LCD_DrawLine(x+148,y-38,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+147,y-37,12,LCD_DIR_HORIZONTAL);
	
	LCD_DrawFullRect(x+121,y-36,13,3);
	LCD_DrawLine(x+146,y-36,12,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+145,y-35,11,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+143,y-34,12,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+120,y-33,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+141,y-33,13,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+121,y-32,12,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+140,y-32,12,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+120,y-31,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+138,y-31,13,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+120,y-30,12,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+137,y-30,13,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+119,y-29,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+135,y-29,15,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+119,y-28,12,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+134,y-28,16,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+119,y-27,31,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+118,y-26,31,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+118,y-25,32,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+118,y-24,32,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+117,y-23,33,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+118,y-22,19,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+138,y-22,12,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+117,y-21,19,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+138,y-21,12,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+117,y-20,18,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+138,y-20,13,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+116,y-19,17,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+138,y-19,13,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+116,y-18,16,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+138,y-18,14,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+116,y-17,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+138,y-17,14,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+116,y-16,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+138,y-16,14,LCD_DIR_HORIZONTAL);
	
	LCD_DrawFullRect(x+115,y-15,13,3);
	LCD_DrawLine(x+115,y-12,12,LCD_DIR_HORIZONTAL);
	LCD_DrawFullRect(x+114,y-11,13,3);
	LCD_DrawLine(x+114,y-8,12,LCD_DIR_HORIZONTAL);
	LCD_DrawFullRect(x+113,y-7,13,3);
	LCD_DrawLine(x+112,y-4,14,LCD_DIR_HORIZONTAL);
	LCD_DrawFullRect(x+112,y-3,13,3);
	LCD_DrawLine(x+112,y,12,LCD_DIR_HORIZONTAL);
	
	LCD_DrawFullRect(x+139,y-15,13,3);	
	LCD_DrawFullRect(x+139,y-12,14,2);
	LCD_DrawFullRect(x+140,y-10,13,3);
	LCD_DrawFullRect(x+140,y-7,14,3);
	LCD_DrawFullRect(x+140,y-4,15,2);
	LCD_DrawLine(x+141,y-2,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+143,y-1,12,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+145,y,10,LCD_DIR_HORIZONTAL);
	
	/*o*/
	LCD_DrawLine(x+173,y-41,35,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+171,y-40,39,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+169,y-39,41,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+168,y-38,43,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+167,y-37,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+198,y-37,13,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+166,y-36,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+199,y-36,13,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+166,y-35,12,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+198,y-35,14,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+165,y-34,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+198,y-34,14,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+165,y-33,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+198,y-33,13,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+165,y-32,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+198,y-32,13,LCD_DIR_HORIZONTAL);
	
	LCD_DrawFullRect(x+164,y-31,14,2);
	LCD_DrawFullRect(x+197,y-31,14,2);
	LCD_DrawLine(x+164,y-29,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+197,y-29,13,LCD_DIR_HORIZONTAL);
	
	LCD_DrawFullRect(x+163,y-28,14,2);
	LCD_DrawFullRect(x+196,y-28,14,2);
	LCD_DrawLine(x+163,y-26,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+196,y-26,13,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+162,y-25,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+196,y-25,13,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+162,y-25,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+195,y-25,14,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+162,y-24,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+195,y-24,13,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+162,y-23,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+195,y-23,13,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+161,y-22,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+194,y-22,14,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+161,y-21,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+194,y-21,14,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+161,y-20,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+194,y-20,13,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+160,y-19,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+194,y-19,13,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+160,y-18,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+193,y-18,14,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+160,y-17,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+193,y-17,14,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+159,y-16,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+193,y-16,14,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+160,y-15,13,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+193,y-15,13,LCD_DIR_HORIZONTAL);	
	
	LCD_DrawFullRect(x+159,y-14,13,4);
	LCD_DrawLine(x+192,y-14,14,LCD_DIR_HORIZONTAL);	
	LCD_DrawFullRect(x+192,y-13,13,3);
	
	LCD_DrawFullRect(x+159,y-10,12,3);
	LCD_DrawFullRect(x+191,y-10,13,2);
	LCD_DrawLine(x+190,y-8,13,LCD_DIR_HORIZONTAL);	
	
	LCD_DrawLine(x+159,y-7,14,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+188,y-7,14,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+159,y-6,43,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+160,y-5,41,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+161,y-4,39,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+162,y-3,36,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+163,y-2,34,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+164,y-1,32,LCD_DIR_HORIZONTAL);
	
	/*��*/
	LCD_DrawLine(x+224,y-36,18,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+223,y-35,22,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+222,y-34,24,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+221,y-33,25,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+221,y-32,9,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+238,y-32,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+220,y-31,9,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+238,y-31,9,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+219,y-30,9,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+238,y-30,9,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+218,y-29,9,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+239,y-29,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+218,y-28,8,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+239,y-28,9,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+217,y-27,8,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+226,y-27,22,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+215,y-26,33,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+214,y-25,35,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+213,y-24,9,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+227,y-24,8,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+232,y-24,9,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+213,y-23,8,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+227,y-23,9,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+232,y-23,9,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+227,y-22,8,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+226,y-21,9,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+226,y-20,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+213,y-19,34,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+212,y-18,35,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+212,y-17,35,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+225,y-16,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+213,y-15,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+225,y-15,8,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+238,y-15,7,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+212,y-14,8,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+225,y-14,8,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+237,y-14,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+212,y-13,8,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+224,y-13,9,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+237,y-13,7,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+212,y-12,8,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+224,y-12,8,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+236,y-12,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+212,y-11,8,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+223,y-11,9,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+235,y-11,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+212,y-10,8,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+223,y-10,9,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+235,y-10,7,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+212,y-9,8,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+223,y-9,8,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+235,y-9,7,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+212,y-8,8,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+222,y-8,9,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+234,y-8,7,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+212,y-7,9,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+222,y-7,19,LCD_DIR_HORIZONTAL);

	LCD_DrawLine(x+214,y-6,16,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+231,y-6,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+217,y-5,4,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+222,y-5,8,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+232,y-5,4,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+222,y-4,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawFullRect(x+206,y-3,39,2);
	
	/*��*/
	LCD_DrawLine(x+269,y-38,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+285,y-38,6,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+267,y-37,9,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+285,y-37,6,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+265,y-36,11,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+284,y-36,7,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+256,y-35,18,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+275,y-35,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+284,y-35,7,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+256,y-34,17,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+275,y-34,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+283,y-34,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+256,y-33,15,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+274,y-33,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+283,y-33,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+261,y-32,6,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+274,y-32,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+283,y-32,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+261,y-31,6,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+274,y-31,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+282,y-31,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+261,y-30,6,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+274,y-30,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+282,y-30,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+260,y-29,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+274,y-29,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+282,y-29,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+253,y-28,20,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+275,y-28,6,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+282,y-28,7,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+253,y-27,19,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+274,y-27,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+282,y-27,7,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+259,y-26,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+274,y-26,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+282,y-26,7,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+258,y-25,8,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+274,y-25,14,LCD_DIR_HORIZONTAL);

	LCD_DrawLine(x+259,y-24,6,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+277,y-24,11,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+253,y-23,4,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+258,y-23,10,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+271,y-23,5,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+281,y-23,6,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+253,y-22,16,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+270,y-22,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+280,y-22,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+253,y-21,16,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+270,y-21,6,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+280,y-21,7,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+252,y-20,24,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+280,y-20,7,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+252,y-19,4,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+257,y-19,12,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+270,y-19,6,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+280,y-19,7,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+252,y-18,4,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+257,y-18,12,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+270,y-18,6,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+279,y-18,7,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+251,y-17,18,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+270,y-17,6,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+279,y-17,7,LCD_DIR_HORIZONTAL);
		
	LCD_DrawLine(x+251,y-16,12,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+264,y-16,4,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+269,y-16,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+279,y-16,7,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+251,y-15,17,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+269,y-15,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+278,y-15,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+251,y-14,11,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+263,y-14,5,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+269,y-14,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+278,y-14,7,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+250,y-13,17,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+270,y-13,6,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+278,y-13,7,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+250,y-12,17,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+271,y-12,6,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+278,y-12,7,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+250,y-11,11,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+262,y-11,5,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+273,y-11,12,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+249,y-10,18,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+277,y-10,7,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+249,y-9,5,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+255,y-9,12,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+273,y-9,14,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+248,y-8,39,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+248,y-7,12,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+260,y-7,22,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+248,y-6,12,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+260,y-6,5,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+275,y-6,7,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+248,y-5,18,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+274,y-5,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+248,y-4,4,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+253,y-4,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+260,y-4,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+274,y-4,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+247,y-3,4,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+253,y-3,6,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+260,y-3,5,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+274,y-3,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+247,y-2,4,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+253,y-2,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+262,y-2,2,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+273,y-2,9,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+247,y-1,1,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+252,y-1,7,LCD_DIR_HORIZONTAL);
	LCD_DrawLine(x+273,y-1,8,LCD_DIR_HORIZONTAL);
	
	LCD_DrawLine(x+273,y,2,LCD_DIR_HORIZONTAL);
}