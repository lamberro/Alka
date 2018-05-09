# Alka

current version: 0.0.6 (Crab Coast Update)

This is a small adventure game I've been making. I'll try to update most of the major changes to here.

I'm programming in C++ using Visual Studio for the first time, so there will be some struggle.

I have no idea what the plot of this adventure is. I haven't thought that far ahead yet. I'm just trying to implement some concepts that I've been studying in my classes, like inheritance and polymorphism.

My friends might help me on this, so I'll try to credit them where I can.

## To do (soon): ##
* implement an inventory
* Implement a loot drop system
* Implement time system
* Give locations randomly generated names, e.g. "Fredera Forest"
* add location number 3.

## To do (eventually): ##
* Implement story / lore, or at least some introduction
* Implement more flavor text at camp and in battles
* Implement some degree of character creation
* Have enemies spawn according to level
* Implement currency and a use for currency (like a town, maybe?)
* Implement armor / weapons
* Implement some final boss

## Recent fixes and new stuff: ##
### 0.0.6 (Crab Coast Update):
* Implemented coast, which can be traveled to via camp. Coast has 2 events: wander and a crab encounter.
* New encounter: CRAB! Crab has low health and low attack, but has high defense and a special move called "Crustacean Stance" that heals it.
* Gold is now obtainable from defeating enemies. Drops in somewhat random amounts. Can be viewed in "Display Player info." Currently doesn't do anything.
* Enemies now drop random-ish amounts of xp.
* Healing function is now more generalized for future use, so more future enemies can use it.
* Cleaned up code for incrementing gold and xp.
* Added berries, which are an item that heals when consumed. Well, they probably do that. The player can't access items yet, since there isn't an inventory or anything, but the code is in place.

### 0.0.5 (Spider Update):
* Implemented spiders, which can be encountered in the forest and are the strongest enemy in the game currently.
* Spiders use the new poisoning system.
* Oh yeah, there's a new poisoning system.

### 0.0.4 (XP Update):
* Implemented xp and max_xp. Xp increases upon defeating enemies. Different enemies call different functions upon death, but the default is 10xp. Max_xp increases exponentially with every level. Player levels up if is at camp and xp >= max_xp.

### 0.0.3 (Rabbit Update):
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
