# IARaven

This project is an adaptation of the source code of chapters 7-10 of Mat Buckland's book, in order to improve the game "Raven".
It simulates agents -bots- that kill each other. Each agent is directed by one or more goals such as moving to an item (medical kit, ammunition), attacking a target, exploring the environment, .... These bots move along a map that consists of a set of rooms, corridors, and several generation points.


## Improvements

### #1 Improved fuzzification for 'RocketLauncher' weapon selection
*Camille Boucher*

Increase to 5 fuzzy sets: 
- distance to target - close, medium, far - 
- ammo status - loads, okay, low -
- life status - low, medium, high - 
- score - low, medium, high -
- desirability - undesirable, desirable, very desirable -


### #2 Introduction of a fuzzy behaviour for the aiming of the shot
*Camille Boucher*

The deviation of a shot -the trajectory of a bullet- is a function of the following fuzzy variables 
- the distance to the target - close, medium, far - 
- the velocity - low, medium, high - 
- the period during which the target remained visible - short, medium, long -.

This fuzzification has been added to the 'Raven_WeaponSystem' class, and the deviation is added in the 'TakeAimAndShoot' function call.


### #3 Team
*Tristan Badana*

Ability to create a team when controlling a bot by pressing the R key and clicking on another bot (which recruits it into the team).
Other members can be recruited in the same way except if they are already in a team. Team members have a coloured circle (which is the colour of the team) under their foot to differentiate them. The leader has yellow hair.


*Tristan Badana*

Ability to order team members to prioritize their shots at a target selected by the leader (by pressing the T key and clicking on a bot), This designation results in a message being sent to team members. When a bot is left-clicked, the target it is aiming at is marked by a red target under its feet. If the bot sees the bot it is targeting, then it will shoot it even if it was in combat with another bot.

*Nathan Guerin*

Ability to set a weapon drop-off location when a team member is eliminated. To add/modify the position, you must be in possession of the team leader, then press the ***L*** key and click on the desired location.

### #3 Adding a new goal
*Evan Touzet*

Added a new goal, when the bot is part of a team, it can make the decision to join its leader in order to attack enemies in a group. 


### #4 Creation of learning bots and addition of a neural network
*Alexandre Bourdarie*

I started by adding the neural network functions in the folder code_source_neural_networks. 
Inside we can find the creation of datatables and perceptrons that will be used to define the behaviour of the bots.
I tried to add a perceptron in the system and the new bots created will reproduce the player's shooting pattern thanks to 6 criteria:

* Distance 
* Ammunition 
* Remaining life 
* Current weapon 
* Number of allies.

I changed the Raven Bot files to modify their firing conditions.
The learning bot can't shoot until the dataset has been generated.
The class I added is Botapprenant. 



### #Bonus
#### Creation of a new weapon: grenade
*Camille Boucher*

Creation of a new grenade weapon and its associated projectile: grenade bomb. The particularity of this projectile is that it is single-use.
The creation of this weapon and projectile required changes in many files: in the main files, in the game, in the weapon system, in the goal management, in the parameters, etc.
The initial map was modified to generate a grenade at the beginning of the game (single black circle).


#### Team behaviour strategy
*Nathan Guerin*

Added the OffsetPursuit movement behaviour. To trigger this behaviour, you need to be in possession of the leader of a team, and press the ***O*** key, in order to order the other team members to form up around the leader, to protect him.

----

## Team members

* [Tristan Badana (BADT14010201)](mailto:tbadana@etu.uqac.ca)
* [Alexandre Bourdarie (BOUA28070007)](mailto:abourdarie@etu.uqac.ca)
* [Camille Boucher (BOUC19590002)](mailto:cboucher17@etu.uqac.ca)
* [Nathan Guerin (GUEN17020208)](mailto:nguerin5@etu.uqac.ca)
* [Evan Touzet (TOUE21120104)](mailto:etouzet@etu.uqac.ca)
