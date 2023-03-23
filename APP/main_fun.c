/*
 * main_fun.c
 *
 *  Created on: Feb 23, 2023
 *      Author: AgAmIa
 */


#include <util/delay.h>
#include "STD_TYPES.h"
#include "LCD_int.h"
#include "Keypad_int.h"
#include "ultrasonic.h"
#include "ADC_int.h"
#include "Dio_int.h"
#include "main_fun.h"
#include "LED_int.h"
#include "dc_init.h"
#include "LM35_int.h"

static u8 get_and_check_password(void);

#define MAX_TRYS      3
#define MAX_PASS_SIZE 4

u16 distance = 0 ;
u8 pass_arr[MAX_PASS_SIZE] = {'1','1','1','1'};

u16 Temp_read = 0;

void Init_system(void)
{
	H_LCD_void_Init();
	H_KEYPAD_void_init();
	//M_ADC_void_Init();
	H_TEMPSENSOR_void_Init();
	H_DcMotor_void_init();
	asm("SEI");
}

void wlcome_screen(void)
{

	H_LCD_void_sendString((const s8*)" welcome   ");
	_delay_ms(2000);
	H_LCD_void_clear();
}

void update_US_read(void)  //ultra sonic to get read
{
	distance = ultrasonic_u16distance(PORTC_ID ,PIN5_ID);

}

u8 TAKE_action(void)
{
	u8 check = FAIL;
	if(distance < 15)
	{

		H_LCD_void_sendString((const s8 *)"PLEASE ENTER THE ");
		H_LCD_void_gotXY(1, 4);
		H_LCD_void_sendString((const s8 *)"PASSWORD");
		_delay_ms(1000);
		H_LCD_void_clear();
		u8 trys = MAX_TRYS;
		do
		{
			check = get_and_check_password();
			if(check == FAIL)
			{
				H_LCD_void_clear();
				H_LCD_void_sendString((const s8 *)"try again");
				_delay_ms(1000);
				H_LCD_void_clear();
				trys--;
				if(trys==0)
				{
					H_LCD_void_clear();
					H_LCD_void_sendString((const s8 *)"max attempt");

					u8 i=0 ;

					for(i=0 ; i < 10;i++ )
					{
						_delay_ms(1000);
						trys = MAX_TRYS;
					}
					/*H_LCD_void_clear();
					H_LCD_void_sendString((const s8 *)"try again");
					_delay_ms(1000);
					H_LCD_void_clear(); */
				}
			}
		}while((check == FAIL ));
		if(check == PASS)
		{
			return check ;
		}


	}
	else
	{

		H_LCD_void_sendString((const s8 *)"out of range");
		H_LCD_void_gotXY(1,0);
		H_LCD_void_sendData(((distance/1000)%10)+48);
		H_LCD_void_sendData(((distance/100)%10)+48);
		H_LCD_void_sendData(((distance/10)%10)+48);
		H_LCD_void_sendData((distance%10)+48);
		_delay_ms(500);
		H_LCD_void_clear();

		DC_MOTOR();

		_delay_ms(1000);
	}
	return check;
}

static u8 get_and_check_password(void)
{
	u8 check = FAIL;
	u8 i = 0;
	u8 read = NO_PRESSED_KEY;
	u8 temp_pass_arr[MAX_PASS_SIZE] = {0};
	H_LCD_void_gotXY(0,0);
	for( i=1 ;i < MAX_PASS_SIZE+1 ;i++ )
	{
		while(read == NO_PRESSED_KEY)
		{
			read = H_KEYPAD_void_getPressesKey();
		}
		temp_pass_arr[i-1] = read;
		H_LCD_void_sendData(read);
		_delay_ms(500);
		H_LCD_void_gotXY(0, i-1);
		H_LCD_void_sendData('*');
		read = NO_PRESSED_KEY ;

	}

	for(i=0 ; i < MAX_PASS_SIZE ; i++)
	{
		if(temp_pass_arr[i] == pass_arr[i])
		{
			check = PASS;
		}
		else
		{
			check = FAIL;
			break;
		}
	}
	_delay_ms(500);
	return check;
}

void ALL_LEDS_ON(void)
{
	H_Led_void_ledInit(GRN_LED);
	H_Led_void_ledInit(BLU_LED);
	H_Led_void_ledInit(RED_LED);

	H_Led_void_setON(GRN_LED);
	H_Led_void_setON(BLU_LED);
	H_Led_void_setON(RED_LED);

}

void ALL_LEDS_OFF(void)
{
	H_Led_void_setOFF(GRN_LED);
	H_Led_void_setOFF(BLU_LED);
	H_Led_void_setOFF(RED_LED);
}


 void DC_MOTOR(void)
 {
	//u8 check = FAIL;
	 		Temp_read = H_TEMPSENSOR_u8_readTemp();  //from here we start the temp
	 		if(Temp_read <= 250)
	 		{
	 			H_DcMotor_void_OF();// dc motor off
	 		}

	 		else
	 		{
	 			H_DcMotor_void_ON();// dc motor  on
	 		}
	 		H_LCD_void_clear();
	 		H_LCD_void_sendString((const s8 *)"temp is :");
	 		H_LCD_void_gotXY(1,0);
	 		H_LCD_void_sendData(((Temp_read/10000)%10)+48);
	 		H_LCD_void_sendData(((Temp_read/1000)%10)+48);
	 		H_LCD_void_sendData(((Temp_read/100)%10)+48);
	 		H_LCD_void_sendData((Temp_read%10)+48);
	 		_delay_ms(1000);
 }



