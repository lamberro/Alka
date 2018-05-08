# Alka

current version: 0.0.3 (Rabbit Patch)

This is a small adventure game I've been making. I'll try to update most of the major changes to here.

I'm programming in C++ using Visual Studio for the first time, so there will be some struggle.

I have no idea what the plot of this adventure is. I haven't thought that far ahead yet. I'm just trying to implement some concepts that I've been studying in my classes, like inheritance and polymorphism.

My friends might help me on this, so I'll try to credit them where I can.

## Recent fixes and new stuff: ##
### 0.0.3:
* Implemented Wild Rabbit encounter in forest. Rabbits almost always try to evade, and they have high speed.
* Player used to only die if health hit exactly 0. Now dies at negative health.
* Level up now available from camp. This increases all stats by 10, and max HP by 15.
* Inflated player and enemy stats to make my life easier
* Player now has 3% chance to get lost in forest and be forced to wander more. This might be more annoying than fun.
* Overall made everything even cleaner


### 0.0.2:
* Fixed fighting UI to be readable,
* Completely overhauled how the enemy takes a turn, allowing the possibility of different types of enemy attacks

### 0.0.1:
* Entering improper input in a fight won't cause you to die.

## To do (soon): ##
* Implement a new location,
* implement an inventory,
* Implement multiple kinds of attacks, such as poisoning,
* Implement a loot drop system,
* Implement XP, have enemies drop XP

## To do (eventually): ##
* Implement time system,
* Implement story / lore, or at least some introduction,
* Implement more flavor text at camp and in battles,
* Implement some degree of character creation,
* Have enemies spawn according to level,
* Implement currency and a use for currency,
* Implement armor / weapons,
* Implement some final boss
