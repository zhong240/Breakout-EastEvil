## Breakout - Part 3

<img align="right" width="150px" src="./../Media/Nolan_Bushnell_2013.jpg">
Ship it! Nolan has given you the greeenlight. As the game testers(i.e. your friends/roommates/etc) help you take care of the final bugs and pass Quality Assurance testing there are only a few steps left!


## Step 1 - Documentation
While Nolan has given the greenlight, he wants to ensure the code is wrapped up. Nolan has suggested using 'Doxygen' <a href="http://www.stack.nl/~dimitri/doxygen/">(Doxygen webpage)</a> to document the source code and automatically generate .html pages. Your documentation should cover your classes and functions.

## Step 2 - Build (binary file)
You need to have a compiled binary of your game. You can assume a target audience of either a 64-bit Mac, Ubuntu Linux, or Windows 10 machine. There should additionally be instructions about how to compile your code from source.

## Step 3 - Post mortem
A post mortem in games is a look back at what could be improved. Write a brief (2-3 paragraphs) on what could be improved if you had an additional 8 weeks to work on this project. Where would you allocate time, what tools would you build, would you use any different tools, etc.

## Step 4 - Website
Your documentation, a link to your binary, and your post mortem should be put together on a 1-page .html page. Additionally, provide a 1 minute video trailer(but 1 minute I suggest) and at least 3 screenshots of your game. This website will be the first place I look to grab your project. (Additionally, I think it is important to build a portfolio of your game development works!)

## Part 3 - Game Requirements (Summary)
### Part 3 - Rubric (5% of overall grade)

* (25%) Documentation - Did you generate something like "https://dbus.freedesktop.org/doc/api/html/index.html"
* (25%) Build - Does the build work when I download your repo and run the game.
* (25%) Post mortem - Did you learn anything?
* (25%) Website - Do you have a webpage that presents your project in a positive way with the above materials.

## Part 2 - Game Requirements (Summary)

### Part 2 - Rubric (5% of overall grade)

* (25%) There are at least 3 levels in the game
* (25%) The game is frame capped to 60 FPS
* (25%) A 'level loading' system is built in (No hard coded variables for loading levels!).
* (25%) All strings are loaded from a configuration file for the English Language and one other language of your choice. You may use google translate as required.

## Part 1 - Game Requirements (Summary)

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

### Part 1 - Rubric (5% of overall grade)

* (50%) The Game requirements should be met above.
* (50%) The game should feel polished
