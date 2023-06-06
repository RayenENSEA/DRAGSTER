
/* Ces directives d'inclusion permettent d'importer les fichiers d'en-tête nécessaires pour utiliser les bibliothèques
et les fonctionnalités spécifiques à la carte STM32 */
#include "main.h"
#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_tim.h"
#include "SystemClock_Config.c"
#include "PWM_Init.c"


/* Ces déclarations créent des variables de type TIM_HandleTypeDef qui seront utilisées pour configurer et contrôler les
timers TIM2 et TIM1, respectivement */
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim1;


/* La fonction main est le point d'entrée du programme. Elle appelle les fonctions HAL_Init pour initialiser la bibliothèque
HAL, SystemClock_Config pour configurer l'horloge du système, et PWM_Init pour initialiser les timers et les broches
GPIO utilisés pour le contrôle du servo-moteur et du driver de moteur brushless */
int main(void)
{
  HAL_Init();
  SystemClock_Config();
  PWM_Init();


/* Cette boucle while représente la partie principale du programme qui s'exécute en boucle infinie. Elle contient des
fonctions de contrôle du servo-moteur et du driver de moteur brushless. Les fonctions HAL_TIM_PWM_Start et
HAL_TIM_PWM_Stop sont utilisées pour démarrer et arrêter les canaux PWM respectifs pour contrôler les dispositifs  */
  while (1)
  {
	// Faire tourner le servo-moteur à 30 degrés
	// Utiliser la fonction HAL_TIM_PWM_Start() pour démarrer le canal PWM du servo-moteur
	// et HAL_TIM_PWM_Stop() pour arrêter le canal PWM lorsque le mouvement est terminé

    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    HAL_Delay(1000);  // Délai pour maintenir la position du servo-moteur '1s'
    HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);


    sConfigOC = 1700; // position intial du moteur
    HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    HAL_Delay(2000);


    // Contrôle du driver de moteur brushless
    // Utilison la fonction HAL_TIM_PWM_Start() pour démarrer le canal PWM du driver de moteur
    // et HAL_TIM_PWM_Stop() pour arrêter le canal PWM lorsque le contrôle est terminé
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_Delay(2000);  // Délai pour maintenir le contrôle du driver de moteur brushless
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
  }
}




/* La fonction Error_Handler est appelée en cas d'erreur. Dans cet exemple, elle met simplement le microcontrôleur en
boucle infinie, ce qui permet de détecter et de gérer les erreurs.Cela conclut l'explication du code fourni. Il s'agit
d'un exemple générique pour le contrôle d'un servo-moteur et d'un driver de moteur brushless à l'aide des timers PWM de
la carte STM32. Vous devrez ajuster les valeurs de pulsation (Pulse) en fonction de votre matériel spécifique */
void Error_Handler(void)
{
  while (1)
  {
    // Gestion des erreurs
  }
}
