 /* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t  State4 = 0,S3_check = 0, S4_check = 0,S1=1,S2=1,S3=1,S4=1,S5=0,dem=0,S1_check=0,S2_check=0,StateS1=0,StateS2=0,S5_check=0,S6_check=0;
uint16_t t=100,count=0,time=0,count1=0,count2=0,count3=0,time1=0,count4=0;
uint8_t State5=0,State6=0,k=0,State=0,State7=0;
char z[5];
void TIM1_Configuration(void) {
    // Enable TIM1 clock
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
    // Configure PSC (Prescaler)
    TIM1->PSC = 7;

    // Configure ARR (Auto-Reload Register)
    TIM1->ARR = 999;

    // Enable Update Interrupt
    TIM1->DIER |= TIM_DIER_UIE;

    // Enable TIM1 interrupt in NVIC
    NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);

    // Enable TIM1 counter
    TIM1->CR1 |= TIM_CR1_CEN;
}
volatile uint8_t i=0;
volatile	uint8_t x=10,y=10;
 	uint8_t dataread[10],dataread1[10];
	void sendchar(char data)
	{
	while((USART2 ->SR & (1<<6))==0 ){}
		USART2->DR = data;
	}
	void send_string(char *str)
	{
		while(*str)
		 sendchar(*str++);
	}
	
	
// Kh?i t?o UART2
uint8_t State3=0,State2=0,State1=0;
void TIM1_UP_TIM10_IRQHandler(void) 
	{
    // Your TIM1 interrupt handler code here

    TIM1->SR &= ~TIM_SR_UIF;
		S1 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5);
	S2 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);
	S3 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);
	S4 = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_7);
	S5 = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_13);
	S1_check = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15);
	S2_check = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8);
	S3_check = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_11);
	S4_check = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6);
	S5_check = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7);
	S6_check = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_14);
		if ((State3 == 0) && (S3_check == 0))
				State3 = 1;
	if ((State3 == 1) && (S3_check != 0))
				State3 = 2;
	if(k==2)
		{
			if ((State3 == 0) && (S3_check == 0))
				State3 = 1;
	if ((State3 == 1) && (S3_check != 0))
				State3 = 2;
	if ((State3 == 2) && (S3_check == 0))
				State3 = 3;
	if ((State3 == 3) && (S3_check != 0))
				State3 = 0;
	
	if ((State4 == 0) && (S4_check == 0))
				State4 = 1;
	if ((State4 == 1) && (S4_check != 0))
				State4 = 2;
	if ((State4 == 2) && (S4_check == 0))
				State4 = 3;
	if ((State4 == 3) && (S4_check != 0))
				State4 = 0;
	
	if ((State5 == 0) && (S5_check == 0))
				State5 = 1;
	if ((State5 == 1) && (S5_check != 0))
				State5 = 2;
	if ((State5 == 2) && (S5_check == 0))
				State5 = 3;
	if ((State5 == 3) && (S5_check != 0))
				State5 = 0;
	
	if ((State6 == 0) && (S6_check == 0))
				State6 = 1;
	if ((State6 == 1) && (S6_check != 0))
				State6 = 0;
	
		}
if(State==1)
		{
			count2++;
	if (count2>1000)
		{
		HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_7);
			count2=0;
		}
		}
		if (State==2)
			{
		count4++;
	if(count4>=500)
{
	HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_7);
	HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_2);
	count4=0;
}
		}
	
	
	if(k==1)
if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)==0)
	 {
		 TIM3->CR1 &= ~TIM_CR1_CEN;
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,0);
	  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,1);
	  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,0);
	  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,1);
		 State3=0;
		 State2=0;
		 State1=0;
		 dem=0;
		 State7=0;

		 
	 }
	 if(k==1)
if(State3==9)
	 {
		 TIM3->CR1 &= ~TIM_CR1_CEN;
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,0);
	  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,1);
	  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,0);
	  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,1);
		 State3=0;
		 State2=0;
		 State1=0;
		 State=0;
		 dem=0;
		 State7=0;

		 
	 }
					
		
}
	void TIM3_Configuration(void) {
    // Enable TIM3 clock
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

    // Configure PSC (Prescaler)
    TIM3->PSC = 15;

    // Configure ARR (Auto-Reload Register)
    TIM3->ARR = 999;

    // Enable Update Interrupt
    TIM3->DIER |= TIM_DIER_UIE;

    // Enable TIM3 interrupt in NVIC
    NVIC_EnableIRQ(TIM3_IRQn);

    // Enable TIM3 counter
    TIM3->CR1 |= TIM_CR1_CEN;
}

void TIM3_IRQHandler(void) {
    // Your TIM3 interrupt handler code here

    TIM3->SR &= ~TIM_SR_UIF;
	//////////bai10
	if(State3==2)
		{
			count++;
	if (count>=2000)
	{
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,0);
		
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,1);
		
		State3=3;
		count=0;
		TIM3->CR1 &= ~TIM_CR1_CEN;
		
	}
	}
		if(State3==3)
		{
			count++;
	if (count>=2000)
	{
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,0);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,1);
		
		State3=4;
		count=0;
		TIM3->CR1 &= ~TIM_CR1_CEN;
		
	}
	}
	if(State3==5)
		{
	count1++;
	if (count1==1000)	
HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,1);		
	if (count1==1500)
	{
		
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,1);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,0);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,1);
		
		
	}
	if(count1>=2000)
{
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,0);	
	dem++;
		sprintf(z, "%d", dem);
        send_string(z);
				send_string(".");
		State3=2;
		State1=0;
		count1=0;
		State2=0;
		TIM3->CR1 &= ~TIM_CR1_CEN;
}
	
		}
	//////////bai10
	//////////////bai3
//	if(State3==2)
//		{
//			count++;
//	if (count>=2000)
//	{
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,0);
//		
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,1);
//		
//		State3=3;
//		count=0;
//		TIM3->CR1 &= ~TIM_CR1_CEN;
//		
//	}
//	}
//		if(State3==3)
//		{
//			count++;
//	if (count>=2000)
//	{
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,0);
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,1);
//		
//		State3=4;
//		count=0;
//		TIM3->CR1 &= ~TIM_CR1_CEN;
//		
//	}
//	}
//	if(State3==5)
//		{
//	count1++;
//	if (count1==1000)	
//HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,1);		
//	if (count1==1500)
//	{
//		
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,1);
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,0);
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,1);
//		
//		
//	}
//	if(count1>=2000)
//{
//	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,0);	
//	dem++;
//		sprintf(z, "%d", dem);
//        send_string(z);
//				send_string(".");
//		State3=2;
//		State1=0;
//		count1=0;
//		State2=0;
//		TIM3->CR1 &= ~TIM_CR1_CEN;
//}
//	
//		}
//////////bai3

	//////////////bai1
//    count++;
//	if (count>=2000)
//	{
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,0);
//		
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,1);
//		
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,0);
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,1);
//		State3=3;
//		count=0;
//		TIM3->CR1 &= ~TIM_CR1_CEN;
//		
//	}
//	if(State3==4)
//		{
//	count1++;
//			
//	if (count1>=2000)
//	{
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,0);
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,1);
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,0);
//		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,1);
//		dem++;
//		sprintf(z, "%d", dem);
//        send_string(z);
//				send_string(".");
//		State3=0;
//		State1=0;
//		count1=0;
//		State2=0;
//		TIM3->CR1 &= ~TIM_CR1_CEN;
//		
//	}
//		}
		//////////bai1
}
void TIM2_Configuration(void) {
    // Enable TIM2 clock
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    // Configure PSC (Prescaler)
    TIM2->PSC = 15;

    // Configure ARR (Auto-Reload Register)
    TIM2->ARR = 999;

    // Enable Update Interrupt
    TIM2->DIER |= TIM_DIER_UIE;

    // Enable TIM2 interrupt in NVIC
    NVIC_EnableIRQ(TIM2_IRQn);

    // Enable TIM2 counter
    TIM2->CR1 |= TIM_CR1_CEN;
}
void TIM2_IRQHandler(void) {
    
    TIM2->SR &= ~TIM_SR_UIF;
	count3++;
	
	if(count3==time)
		{
			State7=1;
			State=2;
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
	    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,1);
			TIM3->CR1 &= ~TIM_CR1_CEN;
		}
		if(State7==1 && S4_check==0 && count3<time1)
		{
			
			count3=0;
			TIM2->CR1 &= ~TIM_CR1_CEN;
			
		}
		if(State7==1  && count3>time1)
		{
			
			State7=0;
			count3=0;
			State=1;
			TIM3->CR1 |= TIM_CR1_CEN;
			TIM2->CR1 &= ~TIM_CR1_CEN;
			
		}

		
	 

        
    
}
void timer1_start()
	{
		TIM1_Configuration();
	}
void timer2_start()
	{
		TIM2_Configuration();
	}
void timer3_start()
	{
		TIM3_Configuration();
	}
//	void USART2_IRQHandler (void)
//	{

//		

//		 		if(USART2->DR == '.' )
//     {
//		 i=0;
//			 x=strcmp("START",dataread);
//		 if(x==0)
//			 {
//			 State3=2;
//				 State=1;
//		   }
//		 y=strncmp("STOP",dataread,4);
//		 if(y==0)
//		   State3=9;
//		 if(y>0 && x>0)
//			 {
//				 memcpy(dataread1, dataread, 4 * sizeof(int));
//		 time= atoi(dataread1);
//			 time1=time+10000;
//		 
//		 timer2_start();
//			 }
//    send_string(dataread);
//		 
//		 }
//		else 
//		{	
//			
//		  dataread[i++] = USART2 -> DR ;
//			
//		 }
//			 
//		 
//	}
		
void EXTI9_5_IRQHandler(void) 
{
    // Check if EXTI6 interrupt occurred
    if(EXTI->PR & EXTI_PR_PR6)
    {
        // Your interrupt handling code here
			TIM3->CR1 &= ~TIM_CR1_CEN;
			count=0;
			State3=0;
    HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,1);
	  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,1);
	  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,1);
	  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,1);
			
        // Clear EXTI6 pending bit
        EXTI->PR |= EXTI_PR_PR6;
    }
}
//	void Auto_3()
//{
//	k=1;
//	if( State3==2) 
//	{ 
//		if (S5==1 && S3==0 && State2==0)
//		{
//			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,1);
//		  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,0);
//			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,1);
//			State2=1;
//		}
//		if (S4==0 && State1==0)
//		{
//		  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,0);
//			State1=1;
//  	  timer3_start();
//		}
//			
//	}
//		 			 if(State3==3)
//						 {
//							 timer3_start();
//						 }
//		if(State3==4)
//		{
//			if(S3==0)
//			{
//				
//	      HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,0);
//				State3=5;
//				timer3_start();
//				
//			}
//		
//		}
//	
//		
//		
//		
//	}
//	 

//	void Manual_3()
//{
//	k=2;
//	if( State3==2)
//		{
//			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,1);
//			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,0);
//	  }
//		if( State3==0)
//		{
//			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,0);
//			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,1);
//	  }
//	 if(State4==2)
//	 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,0);
//	 if(State4==0)
//	 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,1);
//	 if(State5==2)
//	 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,0);
//	 if(State5==3)
//	 HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,1);
//	 if(State6==1)
//		{
//			State3=0,State4=0,State5=0;
//			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,0);
//	  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,1);
//	  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,0);
//	  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,1);
//	
//		}
//		
//	 
//}
//void BAI3()
//{
//	
//	if ((StateS1 == 0) && (S1_check == 0))
//				StateS1 = 1;
//			if ((StateS1 == 1) && (S1_check != 0))
//				StateS1 = 0;			
//			
//			if ((StateS2 == 0) && (S2_check == 0))
//				StateS2 = 1;
//			if ((StateS2 == 1) && (S2_check != 0))
//				StateS2 = 0;			
//			
//			if( StateS1==1)
//			{
//			 HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,1);
//			 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
//				Manual_3();
//			}
//			
//			if( StateS2==1)
//			{
//				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
//			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,0);
//				Auto_3();
//			}
//}

void BAI10()
{
		k=1;
	if( State3==2 && State7==0 ) 
	{ 
		if (S5==0 && S3==0 && State2==0 && State7==0)
		{
			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,1);
		  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,0);
			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,1);
			State2=1;
		}
		if (S4==0 && State1==0 && State7==0)
		{
		  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,0);
			State1=1;
  	  timer3_start();
		}
  }
		 if(State3==3 && State7==0)
			{
			  timer3_start();
			}
		if(State3==4 && State7==0)
		{
			if(S3==0)
			{
				
	      HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,0);
				State3=5;
				timer3_start();
				
			}
		
		}
}
//void BAI1()
//{
//	
//	if( State3==2) 
//	{ 
//		if (S5==1 && S3==0 && State2==0)
//		{
//			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,1);
//		  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,0);
//			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,1);
//			State2=1;
//		}
//		if (S4==0 && State1==0)
//		{
//		  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,0);
//			State1=1;
//  	  timer3_start();
//		}
//			
//	}
//		 			 
//		if(State3==3)
//		{
//			if(S3==0)
//			{
//				HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,1);
//	      HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,0);
//				State3=4;
//				timer3_start();
//				
//			}
//		
//		}
//	 
//}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
	
	USART2 -> BRR = (104 << 4) | (3<<0) ;
USART2 -> CR1 |= (1<<2) | (1<<3) ;
USART2 -> CR1 |= (1<<13) ;
//USART2 -> CR1 |= (1<<7) ;
 USART2 -> CR1 |= (1<<5) ;
 NVIC -> ISER[1] |= (1<<6) ;
// Enable GPIOC clock
//RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

//// Configure PC6 as input
//RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
//GPIOC->MODER &= ~(GPIO_MODER_MODE6_0 | GPIO_MODER_MODE6_1);
//GPIOC->PUPDR &= ~(GPIO_PUPDR_PUPD6_0 | GPIO_PUPDR_PUPD6_1);
//// Enable EXTI6 interrupt
//EXTI->IMR |= EXTI_IMR_MR6;

//// Configure trigger for EXTI6 (rising edge, falling edge, etc.)
//EXTI->RTSR |= EXTI_RTSR_TR6; // Rising edge

//// Enable NVIC interrupt for EXTI6
//NVIC_EnableIRQ(EXTI9_5_IRQn);

// No pull-up, pull-down
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	uint8_t State1 = 0,State2 = 0, State3 = 0,State4 = 0;
	uint8_t S1_check = 0, S2_check = 0,S3_check = 0, S4_check = 0;
	
	  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,0);
	  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,1);
	  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,0);
	  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,1);
	TIM1_Configuration();
  while (1)
  {
	
	
		//BAI1();
		BAI10();
		//BAI3();
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_RESET);

  /*Configure GPIO pin : PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB2 */
  GPIO_InitStruct.Pin = GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PE7 PE8 PE9 PE10 */
  GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : PE14 */
  GPIO_InitStruct.Pin = GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : PD11 */
  GPIO_InitStruct.Pin = GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : PD12 */
  GPIO_InitStruct.Pin = GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PC6 PC7 PC8 */
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
