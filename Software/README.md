# Contrôle du servomoteur Dynamixel XL-320 et du driver de moteur synchrone 50A avec la carte STM32L412KBT3

Ce projet permet de contrôler à la fois un servomoteur Dynamixel XL-320 et un driver de moteur synchrone 50A en utilisant la carte STM32L412KBT3. 
Il utilise l'environnement de développement STM32CubeIDE.

## Environnement de développement :
   l'IDE STM32CubeIDE.

## Configuration des broches GPIO :
### - Pour le servo-moteur :
  Connection de la broche de signal PMW du servo-moteur à la broche PA0 sur la carte STM32L412KBT3. 
  Pour les autres broches de servo la broche d'alimentation est connectée avec +7.5V et GND avec le GND de la carte.

### - Pour le driver de moteur brushless
  Connection de la broche de signal PMW du driver de moteur brushless à la broche PA2 sur la carte STM32L412KBT3. 
  Pour les autres broches, la broche d'alimentaion et connecter avec 12V et GND avec GND de la carte.


## Contrôle du servomoteur :
- Utilisation des fonctions fournies pour envoyer des commandes au servomoteur la position et la vitesse.

## Contrôle du driver de moteur synchrone :
- Utilisation des broches GPIO configurées précédemment pour envoyer les signaux de contrôle nécessaires au driver.
- Implémentation des fonctions de contrôle appropriées pour démarrer/arrêter le moteur, régler la vitesse, etc.

## Intégration et exécution :
- Combinez les codes de contrôle du servomoteur et du driver de moteur synchrone dans le programme principal.
- Televersement du code final sur la carte a l'aide du debuggeur STLINK.

## Test et débogage :
- Connection de la carte STM32L412KBT3 au servomoteur Dynamixel XL-320 et au driver de moteur synchrone.
- Exécution du programme sur la carte et vérification si le servomoteur et le moteur synchrone fonctionnent comme prévu.
- Utilisation des fonctionnalités de débogage de STM32CubeIDE en cas de problèmes pour identifier et résoudre les erreurs.
