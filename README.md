# Alka

current version: 1.1

This is a small adventure game I've been making. I'll try to update most of the major changes to here.

I'm programming in C++ using Visual Studio for the first time, so there will be some struggle.

I have no idea what the plot of this adventure is. I haven't thought that far ahead yet. I'm just trying to implement some concepts that I've been studying in my classes, like inheritance and polymorphism.

My friends might help me on this, so I'll try to credit them where I can.

## To do (soon): ##
* Implement time system
* add location number 3.
* add an enemy that uses an item in battle
* have some slight variation in certain creatures, like variation in strength, name, encounter text, etc.
* The ability to use healing items in battle
* Improve the character creation system: add more classes/races

## To do (eventually): ##
* Implement story / lore, or at least some introduction. I was hoping that the game may follow themes or messages, like "one must love oneself before one can love others" or "all good things must come to an end" or "the flaws in other people are what makes them beautiful." Game mechanics, dialogue and lore should all work to support the themes. Still have no idea what the themes will be, though. Maybe I'll figure it out as I go.
* Implement a loot drop system
* Implement more flavor text at camp and in battles
* Have enemies spawn according to level
* Optimize input gathering method
* Implement a use for currency (like a town, maybe?)
* Implement armor / weapons
* Implement a dungeon
* Implement some final boss
* Include some conlanging
* Have scheduled events in the game, like a specific encounter on the 5th day or something
* Possibly make a local multiplayer mode. It honestly wouldn't be that hard, with the way things are currently set up. I don't know how that would be fun or interesting, though. It would probably be turn-trading co-op, similar to Super Mario Bros 3.
* Have ultra rare collectible Items
* Make locations discoverable over time rather than available all at the start of the game.
* Upon initializing the game, make it so that locations have randomly generated spawn rates for enemies, so playthroughs of the game vary

## Recent fixes and new stuff: ##
### 1.1
* Resolved (hopefully all) memory leak issues with following classes:
  * Inventory
  * Player
  * Game
* Improved character creation: added class descriptions in character creator, added gender, tidied things up, now asks for confirmation
* Can now load from a save file upon booting the game, rather than having to go through character creation every time
* Viewing inventory is now less confusing
* saving to file updated slightly. Still can't handle inventory, though. That'll be a whole project. Old save files are no longer compatible.

### 1.0
* Alka song "Diddy \#133" by Ross Lambert was added. User is given option to play music upon launching game.
* Game is much cleaner; game clears screen using fancy system commands.

### 0.9
* Inventory system FINALLY works as intended, and hopefully crashes the game 100% less.
* Saving and loading games is now possible! Saved game data is saved to "savefile.txt". Not all information is saved.
* Berries can be consumed from the inventory. Consuming an item removes it from the inventory (I know, shocking).
* DEBUG mode now exists.

### 0.8
* New character creation launches when the game is launched. There are currently 3 "classes" that give slightly different stat bonuses.
* Sea urchin now exists. Does charging attack, which takes two turns to execute. It is not intimidating.
* Items in inventory can now be selected, but this usually crashes the game, and when it doesn't the item still doesn't behave as it should.
* Items have descriptions.
* DEBUG mode is under way.

### 0.7
* Inventory now implemented. It took forever, but I settled with using vectors. Berries found in the forest can be added to the inventory. Inventory can be viewed via the camp. Currently there is no way to use anything in the inventory.
* Currently there are some memory leaks being caused by the inventory. Should be fixed soon.
* Game file "Alka.exe" is now available in GitHub. Doesn't need any other files to run.

### 0.6 (Crab Coast Update):
* Implemented coast, which can be traveled to via camp. Coast has 2 events: wander and a crab encounter.
* New encounter: CRAB! Crab has low health and low attack, but has high defense and a special move called "Crustacean Stance" that heals it.
* Gold is now obtainable from defeating enemies. Drops in somewhat random amounts. Can be viewed in "Display Player info." Currently doesn't do anything.
* Enemies now drop random-ish amounts of xp.
* Healing function is now more generalized for future use, so more future enemies can use it.
* Cleaned up code for incrementing gold and xp.
* Added berries, which are an item that heals when consumed. Well, they probably do that. The player can't access items yet, since there isn't an inventory or anything, but the code is in place.

### 0.5 (Spider Update):
* Implemented spiders, which can be encountered in the forest and are the strongest enemy in the game currently.
* Spiders use the new poisoning system.
* Oh yeah, there's a new poisoning system.

### 0.4 (XP Update):
* Implemented xp and max_xp. Xp increases upon defeating enemies. Different enemies call different functions upon death, but the default is 10xp. Max_xp increases exponentially with every level. Player levels up if is at camp and xp >= max_xp.

### 0.3 (Rabbit Update):
* Implemented Wild Rabbit encounter in forest. Rabbits almost always try to evade, and they have high speed.
* Player used to only die if health hit exactly 0. Now dies at negative health.
* Level up now available from camp. This increases all stats by 10, and max HP by 15.
* Inflated player and enemy stats to make my life easier
* Player now has 3% chance to get lost in forest and be forced to wander more. This might be more annoying than fun.
* Overall made everything even cleaner

### 0.2:
* Fixed fighting UI to be readable,
* Completely overhauled how the enemy takes a turn, allowing the possibility of different types of enemy attacks

### 0.1:
* Entering improper input in a fight won't cause you to die.

### 0.0:
* Game exists.
* There is camp, fighting system, and wolves to fight.
