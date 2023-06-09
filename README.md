# Rapport Projet DRAGSTER
#  Introduction
  L'objectif de ce projet consiste en la réalisation d'un Dragster, un type de véhicule de course extrêmement rapide, conçu spécifiquement pour des accélérations fulgurantes sur de courtes distances. Ces machines de course impressionnantes sont souvent propulsées par des moteurs surpuissants, capables de générer une grande puissance en un temps très court. 
 
 L'aspect clé de notre projet est l'autonomie du Dragster. Contrairement à un véhicule télécommandé traditionnel, qui dépend d'un opérateur pour le contrôle, notre dragster sera muni d'un bouton poussoir ainsi que de capteurs tels qu'un accéléromètre afin d'assurer une trajectoire droite déclenchée automatiquement sur quelques mètres.
  
# Objectifs du projet
* Réaliser un PCB fonctionnel permettant d'être relié aux composants du Dragster
* Faire fonctionner le véhicule pour qu'il puisse avancer de manière autonome
* Faire avancer le véhicule sur une trajectoire droite de 10m
* Faire avancer le véhicule sur une trajectoire droite de 10m le plus rapidement possible

# Ressources utilisées
## Matériel à disposition :
* Robitronic Moteur Brushless R01230 3000kV
* Gens Ace Batterie 11,1V GEA45003S60X9
* Servomoteur Dynamiel XL-320
* Microcontrôleur STM32L412KBTx
* Variateur Brushless R01221 50A
* Châssis du Dragster ainsi que les deux roues arrière et la roue avant plus petite que les deux autres


## Ressources numériques :
* Github
* KiCad pour la réalisation des schematics et PCB 
* STM32CubeIDE pour la réalisation de la partie Software

# Réalisation

## PCB et Schematics
À partir du schéma hardware ainsi que les composants énoncés dans la datasheet, il a été possible de réaliser un schematic à l'aide de Kicad. Ce schematic reprend les fonctions énoncées dans le schéma hardware. Nous avons eu besoin de consulter les datasheets pour réaliser les montages impliquant notamment les régulateurs à découpage MAX5033DUSA+ pour les tensions 7.4 V et  3.3 V.
Le schéma hardware est disponible sous le nom "Schéma Hardaware.drawio" dans le dossier suivant : https://github.com/RayenENSEA/DRAGSTER/tree/main/Hardware.

## Régulateur à découpage
Comme détaillé precedemment, notre projet comprennait la réalisation de 2 régulateurs pour obtenir les tensions 7.4 V et  3.3 V.
Nos professeurs nous ont conseillés d'opter pour un régulateur plutôt que pour un régulateur linéaire LDO.

En effet, bien que plus compliqués à réaliser, les régulateurs à découpage ont un rendement compris entre 80 % et 90 %, bien plus grand que les régulateurs linéaires. Ces derniers ont en plus la mauvaise caractéristique de dissiper beaucoup de chaleur.

Cependant, la compléxité des régulateurs à découpage est plus élevée car ils necessitent plusieurs composants pour leur réalisation : des inductances, des diodes et des condensateurs de filtrage ainsi que le circuit intégré.

## Partie software
Ce projet permet de contrôler à la fois un servomoteur Dynamixel XL-320 et un driver de moteur synchrone 50A en utilisant la carte STM32L412KBT3. 
Il utilise l'environnement de développement STM32CubeIDE. 
Voici la description détaillée :  https://github.com/RayenENSEA/DRAGSTER/blob/main/Software/README.md

## Notes en cours de projet
* Liste des composants : https://github.com/RayenENSEA/DRAGSTER/wiki/Liste-des-composants
* Notes globales : https://github.com/RayenENSEA/DRAGSTER/wiki/Notes
* Point avec les professeurs : https://github.com/RayenENSEA/DRAGSTER/wiki/Point-prof-11.04


# Difficultés rencontrées 
* Nous avons fait face à plusieurs difficultés pour la réalisation du PCB, notamment par rapport au routage au vu de la taille de la carte et des composants à utiliser
* Il y a eu des difficultés au moment de tester la carte puisque nous avons constater pendant la soudure des composants des défauts compromettant le fonctionnement de la carte
* En raison du retard de la carte PCB, nous rencontrons des difficultés pour tester tous les codes que nous avons développés avec les autres composants. Cela nous a empêché de réaliser l'étude d'asservissement et d'améliorer les performances des moteurs.
* Les séances de soudure étaient très enrichissantes, nous avons découvert la technique de soudage sur PCB. En soudant des petits composants, il y a eu quelques court-circuits au début.
* Le professeur nous a ensuite conseillé d'essayer une 2ème version du PCB (plaque sans le vernis) pour réduire les risques de dysfonctionnement de la carte.
* Les régulateurs de tension ne fonctionnaient malheureusement pas comme nous le souhaitions. Il y avait de courtes phases de régulation puis la tension affichée était celle de l'alimentation.
* Nous avons quand même tenu à terminer le soudage des composants sur la carte pour observer le résultat final et plusieurs composants comme les LEDs fonctionnaient comme prévu.

# Enjeux environnementaux
* 1 - Votre projet favorise-t-il des changements dans les modes de production et de consommation en vue de les rendre plus viables et plus responsables sur les plans social et environnemental ?
 
Notre projet peut avoir un certain impact en faveur de changements dans les modes de production et de consommation premièrement par l'utilisation d'un Dragster fonctionnant avec un moteur éléctrique autonome. L'utilisation de moteurs éléctrique permet la réduction d'émission de gaz à effet de serre et permet donc de démontrer l'efficacité des technologies de propulsion éléctrique. L'exploitation des ressources utilisées permet au projet de pouvoir être réutilisé dans d'autres circonstances et sensibilise donc à la mobilité éléctrique en mettant l'accent sur la technologie de pointe et les performances écologiques concernant la mobilité durable.


* 2 - Quelle réflexion avez-vous mené au cours de ce projet autour de la réutilisation possible d'éléments matériels après votre projet ?

Lors de ce projet, nous avons pris en compte plusieurs points concernant cette question. En effet, la conception du Dragster est modulaire, ce qui rend plus facile le démontage
et la récupération éventuelle de composants individuels qui peuvent être réutilisés dans d'autres projets ou réparer si besoin. L'usage de composant standardisé comme le microcontrôleur permet de maximiser le potentiel de réutilisation, les composants peuvent être utilisés dans de nombreux projets ce qui augmente la chance de les intégrer dans d'autres systèmes à l'avenir.
La documentation nécessaire concernant les schematics, les codes sources et les instructions de montages peuvent également permettre une réutilisation approprié des éléments matériels du projet.
Finalement, si des matériaux ne peuvent être recyclés ou réparer, il est possible de les recycler correctement, comme les métaux ou les circuits imprimés pouvant être transformés en nouvelles ressources dans l'optique de réduire les déchets éléctroniques.



# Résultats

# Conclusion
