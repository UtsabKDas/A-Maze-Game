# A Maze Game: 
### A C++ game project created using Visual Studio
Created by Utsab Das
==================================================================
A Maze Game is exactly what the title says. In this top-down 2D game, the player 
navigates progressively larger procedurally generated mazes, finding the key to get to the next level while avoiding obstacles. 


Contents
--------
- [Intro](#intro)
- [Installation](#installation)
- [Summary](#quick-feature-summary)
- [Player](#player)
- [Classes](#classes)
	- [main](#main)
 	- [Room](#Room)
 	- [Coordinate](#Coordinate)
 	- [Maze](#Maze)
	- 
- [Functions](#functions)

- [Contact](#contact)
- [License](#license)

### Intro
-----

A Maze Game is a simple maze-solving puzzle game in which the player must reach the end of the level. In order to do so, the player must retrieve a key that opens the lock leading to the next level. Upon reaching that lock, the next level will be randomly generated using 

![Alt Text](https://media.giphy.com/media/7OWuHSh9pxhAZq9Kqw/giphy.gif)

While this begins very simple, later levels have obstacles. These obstacles have certain patterns of activation or motion. Since the obstacles only change their state when the player moves, the player must watch for the patterns to reach the destination in the shortest number of steps. If the player runs into any obstacles (traps or guards), the player will restart at the first position in that maze and lose one life. 

![Alt Text](https://media.giphy.com/media/55236IJUlI0JyUal4b/giphy.gif)

If a level is particularly challenging, the player can choose to reset the level at the cost of one life. This will create a new maze of the same size. As such, it may not be any less difficult. If the player can continue to get past each level, the game will simply continue to create larger and larger mazes until the player loses all of their lives.

![Alt Text](https://media.giphy.com/media/oNUSOyjlgQxVhGzITd/giphy.gif)

When all lives have been lost, the game is over, and the only options are to quit or return to the front end menu and try to get even further. 

![Alt Text](https://media.giphy.com/media/4EEV4s1rA3JH9hsGZs/giphy.gif)


### Overview
--------

Created using 
- Microsoft Visual C++
- Microsoft Visual Studio 2017
- Simple DirectMedia Layer Development Libraries (version 2.0.8)
- Miss Ellen Font (TrueType Font) created by Samuel Marcius 
	- [Font Page] (http://www.1001fonts.com/miss-ellen-font.html)
- PNG Images created by me

### Installation
----------------
#### Getting the Project

- Download the project
- Open the Solution in Visual Studio 
 	- Download [Visual Studio 2017] (https://www.visualstudio.com/downloads/) if needed
- Change the Build Configuration to x86

![AltText](https://i.imgur.com/jU3OUEC.png)

#### To Play the Game 

- Use the Local Windows Debugger to Build and Run the game

![AltText](https://i.imgur.com/XkS86d6.png)

OR 

- Build the Project (in Debug or Release)

![AltText](https://i.imgur.com/qHUKXMl.png)

- Launch the application from your file explorer (look in the proper Output Directory)

![AltText](https://i.imgur.com/vMiiWvU.png)

### Features
------------

- Front End Menu
	- Goes into the gameplay
	- Exits the game
- Interactive Player
 	- Movement based off arrow keys
 	- Begins with a number of lives and loses them when you:
  		- Reset the maze
  		- Hit any obstacle
 	- When the player is out of lives, the game is over and the game returns to the Front End
- Procedural Game levels 
 	- Procedurally generates mazes that become increasingly larger
 	- Spawns obstacles in randomized locations in the level
 	- Must find key to get to next level


### Classes
-------

#### main
---------

The main.cpp class initializes the game and has the gameplay loops. This class handles creating the window and renderer, rendering the objects and displaying information. The `int main` function carries out the brunt of the game. If initialization is successful, then the game goes into the main game while loop, which carries out actually playing the game. Inside this loop, there are four sub-while loops delineating different states of the game: Front End, Gameplay, Level Complete, and Game Over. If at any of these points, the player closes the window, the game quits all loops and will end. 

The front end loop is very short. Only active when the `curGameState == Menu`, it uses the `FrontScreen` function to display the menu to the player. The only options the player has here is to close the window or press the ESC key to quit, or to press any other key to continue. If the player continues, the `curGameState` is set to `InGame` and it enters the Gameplay loop.

The gameplay loop is the most extensive. First, the game will display information to the screen (level number, steps, lives, etc.) using the `DrawInGameUI` function and the various `DrawText...` functions. After this, it shows the creation of the maze, then waits for player input to determine what to do. The player can press the ESC key to return to the Menu, the R key to reset the current maze and lose one life, or press one of &larr; &uarr; &rarr; &darr keys to move the player. Any other key press, mouse click, or other input will do nothing.

If the player retrieves the key and reaches the end, `curGameState` is then set to `LevelComplete`, and we move to the Level Complete loop, which displays the information about how the player performed in that level. The player can then press the space key to contine. This generates the next level and returns `curGameState` to `InGame`.

If the player runs out of lives at any point, `curGameState` is set to `GameOver`, and the game goes into the game over loop. Again, the player has few options; the player can close the window or return to the front end. Returning to the front end will reset the maze back to the first size behind the scenes so that, if the player chooses to start the game again from the front end menu, the game starts anew.


#### Coordinate
---------------

The Coordinate struct is used to tell me the position of anything in the maze, including Rooms, any Maze Objects (Traps, Guards, Keys and Doors), and the Player.

#### Room
---------

The Room class gives us a point in the grid required to build the play area. Each Room has information about its position, direction of walls, rendering area, and texture. These help to indicate where it will be rendered and what it will look like.

Additionally, the room has pointers to the rooms that are connected to it. This influences which it will display and how it fits into the maze. The connections of all of these rooms creates the maze.

However, since each room does not know what direction the connected rooms are to itself, it has a function called `CheckAdjRoomDir` that allows it to determine what direction any adjacent room may be. This allows it to remove that direction

#### Maze
---------

The Maze class creates the actual maze of the game. It begins this process by using the `CreateRooms` function to create a grid of rooms, giving each a unique position. 
