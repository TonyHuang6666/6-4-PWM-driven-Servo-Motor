#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Servo.h"
#include "Key.h"

uint8_t Key_Value;
float Angle;

int main(void)
{
	OLED_Init();
	Key_Init();
	Servo_Init();
	OLED_ShowString(1, 1, "Servo Angle:");
	while (1)
	{
		Key_Value = Key_GetNum();
		if (Key_Value == 2)
		{
			Angle += 30;
			if (Angle > 180)
			{
				Angle = 0;
			}
			Servo_SetAngle(Angle);
		}
		OLED_ShowNum(1, 13, Angle, 3);
	}
}
