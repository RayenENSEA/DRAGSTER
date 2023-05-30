/*
   Pour le servo-moteur :

    Connectez la broche de signal du servo-moteur (généralement la broche de commande) à la broche PA0 sur
	votre carte STM32.Assurez-vous que le servo-moteur est alimenté correctement avec une tension appropriée
	(généralement de 5V).

   Pour le driver de moteur brushless :

    Connectez la broche de signal du driver de moteur brushless (généralement la broche de commande) à la broche PA2
	sur votre carte STM32.ssurez-vous que le driver de moteur brushless est alimenté correctement avec la tension
	appropriée selon ses spécifications.
	*/



#include "main.h"
#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_tim.h"

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim1;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void PWM_Init(void);
void Error_Handler(void);

/* Main function */
int main(void)
{
  HAL_Init();
  SystemClock_Config();
  PWM_Init();

  while (1)
  {
    // Faire tourner le servo-moteur à 30 degrés (exemple)
    // Utilisez la fonction HAL_TIM_PWM_Start() pour démarrer le canal PWM du servo-moteur
    // et HAL_TIM_PWM_Stop() pour arrêter le canal PWM lorsque le mouvement est terminé
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    HAL_Delay(1000);  // Délai pour maintenir la position du servo-moteur
    HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);


    sConfigOC.Pulse = 1700; // À ajuster en fonction de votre servo et de la direction souhaitée
    HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    HAL_Delay(2000);


    // Contrôler le driver de moteur brushless (exemple)
    // Utilisez la fonction HAL_TIM_PWM_Start() pour démarrer le canal PWM du driver de moteur
    // et HAL_TIM_PWM_Stop() pour arrêter le canal PWM lorsque le contrôle est terminé
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_Delay(2000);  // Délai pour maintenir le contrôle du driver de moteur brushless
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);



  }
}

/* System Clock Configuration */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
                                RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/* PWM Initialization */
void PWM_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  __HAL_RCC_TIM2_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  // Configuration des broches GPIO en mode alternatif pour le canal PWM du servo-moteur
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  // Configuration du timer TIM2 pour le servo-moteur
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 19999;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 1500;  // Rapport cyclique initial pour le servo-moteur
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }

  __HAL_RCC_TIM1_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  // Configuration des broches GPIO en mode alternatif pour le canal PWM du driver de moteur brushless
  GPIO_InitStruct.Pin = GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF1_TIM15; // Utilisation de GPIO_AF1_TIM15 pour PA2
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  // Configuration du timer TIM1 pour le driver de moteur brushless
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 0;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 9999;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 5000;  // Rapport cyclique initial pour le driver de moteur brushless
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/* Error Handler */
void Error_Handler(void)
{
  while (1)
  {
    // Gestion des erreurs
  }
}
