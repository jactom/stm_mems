
/*------------------------------- Includes -------------------------------------*/
#include "mems.h"

int16_t ThresholdHigh = 200;
int16_t ThresholdLow = -200;

/* Private function prototypes -----------------------------------------------*/
static void ACCELERO_ReadAcc(void);
void us_Delay(int16_t);

/* Private functions ---------------------------------------------------------*/

void ACCELERO_MEMS_Test(void)
{
  /* Init Accelerometer MEMS */
  if(BSP_ACCELERO_Init() != ACCELERO_OK)
  {
    /* Initialization Error */
    Error_Handler(); 
  }

    ACCELERO_ReadAcc();
}


/*------------------------------Read Accelerometer----------------------------------*/
static void ACCELERO_ReadAcc(void)
{
  /* Accelerometer variables */
  int16_t buffer[3] = {0};
  int16_t xval, yval = 0x00;
  int16_t on_time = 0;
	
  /* Read Acceleration */
  BSP_ACCELERO_GetXYZ(buffer);
  
  xval = buffer[0];
  yval = buffer[1];
  
		if((ABS(xval))>(ABS(yval)))
		{
			if(xval > ThresholdHigh)
			{ 
				BSP_LED_On(LED3);
				HAL__Delay(1);
				BSP_LED_Off(LED3);
				HAL_Delay(20);
			}
			else if(xval < ThresholdLow)
			{ 
			
				BSP_LED_On(LED3);      
				HAL__Delay(0);
				BSP_LED_Off(LED3);
				HAL_Delay(20);
			}
			else								
			{ 
				HAL_Delay(20);
			}
  }
  else
  {
    if(yval < ThresholdLow)
    {
      BSP_LED_On(LED4);
      HAL_Delay(1);
	  BSP_LED_Off(LED4);
      HAL_Delay(20);
    }
    else if(yval > ThresholdHigh)
    {
     
      BSP_LED_On(LED4);      
      HAL_Delay(0);
	  BSP_LED_Off(LED4);
      HAL_Delay(20); 
    } 
    else							
    { 
      HAL_Delay(20);
    }
  } 
  
  BSP_LED_Off(LED3);
  BSP_LED_Off(LED4);
  BSP_LED_Off(LED5);
  BSP_LED_Off(LED6);
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
