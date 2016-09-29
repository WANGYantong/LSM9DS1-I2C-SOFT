#include <stdio.h>
#include "global.h"
#include "delay.h"

void gpio(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;

	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_SetBits(GPIOC, GPIO_Pin_9);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;

	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_SetBits(GPIOA, GPIO_Pin_8);
}

S32 main(void)
{
	U8 result;
	S32 acc_buffer[3], gyro_buffer[3], mag_buffer[3];

	DEV_HardwareInit();
	gpio();
	delay_init(72);
	DEV_PeripheralInit();
	while(1){

	printf("\r\n ++++++++++++++++++++++++++++++++++++++++ \n");
	printf("\r\n Test version %s \n", SOFTWARE_VERSION);
	printf("\r\n ++++++++++++++++++++++++++++++++++++++++ \r\n");
	DEV_DelayMs(1000);
	}
//	result = LSM9DS1_Identify();

//	if (result == 1)
//		printf("\r\n LSM9DS1 can be identified!\r\n");
//	else
//		printf("\r\n LSM9DS1 can not be identified!\r\n");

//	while (1) {
//		LSM9DS1_Accelerometer(acc_buffer);
//		printf("\r\n AX = %d | AY = %d | AZ = %d \r\n", acc_buffer[0], acc_buffer[1], acc_buffer[2]);

//		LSM9DS1_Gyroscope(gyro_buffer);
//		printf("\r\n GX = %d | GY = %d | GZ = %d \r\n", gyro_buffer[0], gyro_buffer[1], gyro_buffer[2]);

//		LSM9DS1_Magnetometer(mag_buffer);
//		printf("\r\n MX = %d | MY = %d | MZ = %d \r\n", mag_buffer[0], mag_buffer[1], mag_buffer[2]);

//		DEV_DelayMs(1000);

//	}

	return 0;
}
