## Breakout - Part 1

<img align="right" width="150px" src="./../Media/Nolan_Bushnell_2013.jpg">
Welcome to our first game project! This is the first in a series of 3 Breakout Assignments! But this assignment does not come to us for free--we are under contract! Nolan Busnell(https://en.wikipedia.org/wiki/Nolan_Bushnell) himself has contracted us to build a more powerful version of his 1976 arcade class game! He thinks we could have some success by recreating and distributing the game in Boston, Massachusetts.

Now it is time to get organized and start building the game! 

## Step 1 play the game!
<img align="left" width="250px" src="./../Media/breakout.png">
The first part of this assignment is to play the game here: https://www.atari.com/arcade#!/arcade/superbreakout/play There are many versions of the game, and I encourage you to be creative. The basic premise is a ball, a paddle, and bricks that are destroyed when they are hit. 

The history of the game itself is quite interesting and worth reading as insipiring game programmers!

* https://en.wikipedia.org/wiki/Breakout_(video_game)
* https://en.wikipedia.org/wiki/Arkanoid

## Step 2 - Form a team!

https://docs.google.com/spreadsheets/d/1bglePE3sfvoe5yCSCp8BKBt8lg0e9SQcGptQPyVkkTU/edit?usp=sharing

Make sure you form a team!
(If you are reading this, make sure your teammates join your same repository)

## Our technology stack

Nolan has decided that you will be using the following technology stack:

* Modern C++ (11/14/17)
* SDL library

Nolan prefers these tools because SDL is an industry standard, cross platform, and using C++ will give us some additional speed. 

Right now, Nolan wants us to produce the game quickly however, as demand is high for this title!

## Project Hieararchy

In the future, other engineers may take on our project, so we'll have to keep it organized given the following requirements below.
Forming some good habits now will help us later on when our project grows.

Game

- Docs -- Source Code Documentation
- Assets -- Art assets (With the Sub directories music, sound, images, and anything else)
- src -- source code(.cpp files) The make file or any build scripts that automate the building of your project should reside here.
- include -- header files(.h files)
- lib -- libraries (.so, .dll, .a, .dylib files). Note this is a good place to put SDL
- temp -- This is the directory where your built executable(.exe for windows, .app for Mac, or a.out for Linux) and any additional generated files are put after each build.
- Game -- Your final deliverable. One should be able to copy and paste this directory, and only this directory onto another machine and be able to run the game.
- ThirdParty - Code that you have not written if any.

Note that src should only contain ".cpp" or ".h" files. Why? It makes it very fast to do a backup of your src directory as one example. Secondly, binary files that are generated often clutter up directories. I should not see any binaries in your repository. 

## Game Requirements

The breakout game you are building in part 1 has the following requirements.

- There is at least one level with blue bricks with 4 rows of 12 bricks.
- The User interface displays the number of "lives" available (3 to start)
- The User interface displays the score, correlating to how many bricks have been removed
- You have a paddle, that is controlled with either:
  - The left and right arrow keys (To move the paddle left and right respectively)
  - 'a' and 'd' keys  (To move the paddle left and right respectively)
- When the ball collides with the paddle, it should change velocity in the opposite direction.
  - You may choose to make use of, or add to your TinyMath.h to handle things like collision, Vectors of different dimensions, etc.
  - A sound clip should play
- When the user hits 'q' the program terminates.
- When all blocks are removed, the game should pause and display "You win!" (Or something equally enthusiastic).
- If all lives are lost, the game should pause and display "You Lose!" (Or something equally sad).
- There should be a music track looping in the background.

Beyond those requirements, you may get as creative as you like.

Tips:
* Think about good object-oriented programming style
  * (Nolan Bushnell changes his mind a lot--because the game industry moves fast! I wonder what will happen in part 2?)
* Special effects and cool features are encouraged!

## Rubric (5% of overall grade)

* (50%) The Game requirements should be met above.
* (50%) The game should feel polished


## More Resources

* https://wiki.libsdl.org/APIByCategory
* Free sound effects
  * https://assetstore.unity.com/packages/audio/sound-fx/free-sound-fx-31837
* Free breakout graphics
  * https://assetstore.unity.com/packages/templates/packs/2d-breakout-example-project-107757



