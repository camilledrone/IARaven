# IARaven

Ce projet est une adaptation du code source des chapitres 7-10 du livre de Mat Buckland, afin d’améliorer le jeu « Raven ».
Il s’agit de simuler des agents –bots- qui s’entretuent. Chaque agent est dirigé par un ou plusieurs buts tels que, sedéplacer vers un item (trousse de soins, munitions), attaquer une cible, explorer l’environnement,.... Ces bots se déplacent en suivant une carte qui consiste en un ensemble de chambres, de couloirs, et plusieurs points de génération.

## Améliorations

### #1 Amelioration de la fuzzification pour le choix d’une arme de type 'RocketLauncher'
*Camille Boucher*

Augmentation à 5 ensembles flous : 
- distance de la cible - close , medium, far - 
- etat des munitions - loads, okay, low -
- etat de vie - low, medium, high - 
- score - low, medium, hugh -
- desirability - undesirable, desirable, very desirable -


### #2 Introduction d'un comportement flou pour la visée du tir
*Camille Boucher*

La déviation d’un tir –trajectoire d’une balle- est en fonction des variables floues suivantes : 
- la distance à la cible - close , medium, far - 
- la vélocité  - low, medium, high - 
- la période pendant laquelle la cible est demeurée visible - short, medium, long -

Cette fuzzification a été ajoutée à la classe 'Raven_WeaponSystem', et la deviation est ajoutee dans l'appel de la fonction 'TakeAimAndShoot'.


### #3 Equipe
*Tristan Badana*

Possibilité de créer une équipe lors du contrôle d'un bot en appuyant sur la touche R et en cliquant sur un autre bot (ce qui le recrute dans l'équipe).
On peut recruter d'autres membres de la même façon à part s'ils sont déjà dans une équipe. Les membres de l'équipe voient apparaître un cercle de couleur (qui est la couleur de l'équipe) sous leur pied afin de les différencier. Le leader a les cheveux jaunes.


*Tristan Badana*

Possibilité d'ordonner aux membres de l'équipe de prioriser leurs tir sur une cible sélectionnée par le leader (en appuyant sur la touche T et en cliquant sur un bot),  Cette désignation se traduit par un envoi de message aux membres de l’équipe. Lorsque l'on fait un clic gauche sur un bot, la cible qu'il vise en priorité est marquée par une cible rouge sous ses pieds. Si le bot voit le bot qu'il cible, alors il lui tirera dessus même s'il était en combat contre un autre bot.


*Nathan Guerin*

Possibilité de définir un lieu de dépôt des armes lorsqu'un membre d'une équipe est éliminé. Pour ajouter/modifier la position, il faut être en possession du leader de l'équipe, puis appuyer sur la touche ***L*** et cliquer à l'endroit désiré.

### #3 Ajout d'un nouveau but
*Evan Touzet*

Ajout d'un nouveau but, lorsque le bot fait partie d'une équipe, il peut prendre la décision de rejoindre son leader afin de pouvoir attaquer des ennemis à plusieurs. 


### #4 Création de bots apprenants et ajout d'un réseau de neuronnes
*Alexandre Bourdarie*

J'ai commencé par ajouter les fonctions nécéssaires au réseau de neuronnes dans le dossier code_source_reseaux_neuronnes. 
A l'interieur on peut trouver la création des datatables et des perceptrons qui vont être utilisés pour définir le comportement des bots.
J'ai essayé de rajouter un perceptron dans le système et les nouveaux bots crées vont reproduire le schéma de tir de joueur grâce à 6 critères :

* la distance 
* Les munitions 
* la vie restante 
* L'arme actuelle 
* le nombre d'allié.

J'ai changé les fichiers Raven Bot pour modifier leurs conditions de tir.
Le bot apprenant ne peut pas tirer tant que le dataset n'a pas été généré.
La classe que j'ai ajouté est Botapprenant. 

Merci



### #Bonus
#### Creation d'une nouvelle arme : grenade
*Camille Boucher*

Creation d'une nouvelle arme grenade et son projectile associe : bombe grenade. La particularite de ce projectile est qu'il est à usage unique.
La creation de cette arme et de ce projectile ont necessite des changements dans beaucoup de fichiers : dans les fichiers main, du jeu, du systeme des armes, de la gestion des buts, les paramtres, etc.
La map initiale a été modifée pour generer une grenade au debut du jeu (cercle simple noir).


#### Stratégie de comportement au sein d'une équipe
*Nathan Guerin*

Ajout du comportement de déplacement OffsetPursuit. Pour déclencher ce comportement, il faut être en possession du leader d'une équipe, et d'appuyer sur la touche ***O***, afin d'ordonner aux autres membres de l'équipe de se mettre en formation autour du leader, pour le protéger.

----

## Membres du groupe

* [Tristan Badana (BADT14010201)](mailto:tbadana@etu.uqac.ca)
* [Alexandre Bourdarie (BOUA28070007)](mailto:abourdarie@etu.uqac.ca)
* [Camille Boucher (BOUC19590002)](mailto:cboucher17@etu.uqac.ca)
* [Nathan Guerin (GUEN17020208)](mailto:nguerin5@etu.uqac.ca)
* [Evan Touzet (TOUE21120104)](mailto:etouzet@etu.uqac.ca)
