# IARaven

Ce projet est une adaptation du code source des chapitres 7-10 du livre de Mat Buckland, afin d’améliorer le jeu « Raven ».
Il s’agit de simuler des agents –bots- qui s’entretuent. Chaque agent est dirigé par un ou plusieurs buts tels que, sedéplacer vers un item (trousse de soins, munitions), attaquer une cible, explorer l’environnement,.... Ces bots se déplacent en suivant une carte qui consiste en un ensemble de chambres, de couloirs, et plusieurs points de génération.

## Améliorations

### #1 Amelioration de la fuzzification pour le choix d’une arme de type 'RocketLauncher'
_ Camille Boucher _

Augmentation à 5 ensembles flous : 
- distance de la cible - close , medium, far - 
- etat des munitions - loads, okay, low -
- etat de vie - low, medium, high - 
- score - low, medium, hugh -
- desirability - undesirable, desirable, very desirable -


### #2 Introduction d'un comportement flou pour la visée du tir
_ Camille Boucher _

La déviation d’un tir –trajectoire d’une balle- est en fonction des variables floues suivantes : 
- la distance à la cible - close , medium, far - 
- la vélocité  - low, medium, high - 
- la période pendant laquelle la cible est demeurée visible - short, medium, long -

Cette fuzzification a été ajoutée à la classe 'Raven_WeaponSystem', et la deviation est ajoutee dans l'appel de la fonction 'TakeAimAndShoot'.




### #Bonus
#### Creation d'une nouvelle arme : grenade
_ Camille Boucher _

Creation d'une nouvelle arme grenade et son projectile associe : bombe grenade. La particularite de ce projectile est qu'il est à usage unique.
La creation de cette arme et de ce projectile ont necessite des changements dans beaucoup de fichiers : dans les fichiers main, du jeu, du systeme des armes, de la gestion des buts, les paramtres, etc.
La map initiale a été modifée pour generer une grenade au debut du jeu (cercle simple noir).

