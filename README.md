# Game loop
This is a simple game loop implementation in C using the SDL2 library. I made this implementation following [this free course from Gustavo Pezzi](https://www.udemy.com/course/game-loop-c-sdl/).

A game loop, as the term implies, is a loop which does the following steps:
1. Process input: Check for events.
2. Update: Update the objects. Their position, their angle, their size, etc.
3. Render: Render things in the back buffer and then swap buffers.

Some key concepts are:
* Time step
* Delta time factor
