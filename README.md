# Plants vs. Zombies Game Project

This is a fun and engaging Plants vs. Zombies game project written in C++ using the SFML library. The game showcases strategic gameplay where players use various plants to defend their garden from waves of quirky and relentless zombies. The project is built with over 2000 lines of code, utilizing Object-Oriented Programming (OOP) concepts for modular and maintainable design.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Gameplay](#gameplay)
- [Installation](#installation)
- [How to Play](#how-to-play)
- [Demo Video](#demo-video)
- [Additional Information](#additional-information)

## Introduction

Welcome to our exciting tower defense game where plants and zombies go head-to-head in a battle for the garden. This project is designed to provide a fun and challenging experience, highlighting strategic thinking and resource management.

## Features

- A variety of plant types, each with unique abilities.
- Multiple types of zombies, each presenting different challenges.
- Charming graphics and immersive sound effects.
- Progressive levels with increasing difficulty.
- Built using Object-Oriented Programming concepts for clean and modular code.

## Gameplay

In Plants vs. Zombies, players must strategically place different types of plants to stop waves of zombies from reaching their house. Each plant has unique abilities and costs a certain amount of sunlight to place. Zombies come in various types, each with distinct behaviors and strengths, requiring players to adapt their strategies.

## Installation

### Requirements

Before compiling and running the game, make sure you have the following installed:

1. GNU G++ Compiler
   ```bash
   sudo apt-get install g++
   ```

2. SFML library
   ```bash
   sudo apt-get install libsfml-dev
   ```

### Compilation

To compile the game, follow these steps:

1. Navigate to the project directory.
2. Open a terminal window.
3. Run the following commands:
   ```bash
   g++ -c main.cpp
   g++ main.o -o pvz-app -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
   ```

### Running the Game

After successfully compiling the game, run the following command to start the game:
```bash
./pvz-app
```

## How to Play

- Use the mouse to select and place plants in your garden.
- Collect sunlight to earn points and deploy more plants.
- Strategically position your plants to fend off waves of zombies.
- Adapt your strategy to counter different types of zombies and their unique abilities.

## Demo Video

Watch the project in action:

[![Plants vs. Zombies Game Demo](https://img.youtube.com/vi/IPXCAc4Vuzg/0.jpg)](https://youtu.be/IPXCAc4Vuzg)

## Additional Information

- The game features background music, sound effects, and multiple levels.
- As the player progresses through the levels, the difficulty increases.
- Collect points by defeating zombies and preventing them from reaching your house.

Feel free to explore and modify the code to enhance the game further!
