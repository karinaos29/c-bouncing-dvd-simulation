# Terminal Bouncing DVD Logo

A terminal-based animation of the iconic DVD logo bouncing around the screen, implemented in **C** using a custom terminal drawing library. 

The logo moves diagonally, bounces off the screen borders, and changes color on each collision, recreating the classic DVD screensaver behavior—now directly in your terminal.

---

## Overview

This project demonstrates several core programming and graphics concepts:
* **Terminal Graphics Rendering:** Directly manipulating terminal output.
* **Basic Animation Loops:** Handling frame rates and movement.
* **Collision Detection:** Implementing rectangle-based physics.
* **Unicode-aware Text Rendering:** Printing complex multi-byte characters.
* **ANSI Color Control:** Dynamically updating text styles.

Unlike a simple bouncing ball, the DVD logo is implemented as a **multi-line sprite**, requiring rectangle-based movement and boundary logic.

The logo is stored as a UTF-8 multi-line string array:

C
const char *DVD_LOGO[] = {
    "⠀⠀⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⡀",
    "⠀⢠⣿⣿⡿⠀⠀⠈⢹⣿⣿⡿⣿⣿⣇⠀⣠⣿⣿⠟⣽⣿⣿⠇⠀⠀⢹⣿⣿⣿",
    "⠀⢸⣿⣿⡇⠀⢀⣠⣾⣿⡿⠃⢹⣿⣿⣶⣿⡿⠋⢰⣿⣿⡿⠀⠀⣠⣼⣿⣿⠏",
    "⠀⣿⣿⣿⣿⣿⣿⠿⠟⠋⠁⠀⠀⢿⣿⣿⠏⠀⠀⢸⣿⣿⣿⣿⣿⡿⠟⠋⠁⠀",
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣸⣟⣁⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
    "⣠⣴⣶⣾⣿⣿⡟⣻⣿⢻⣿⡟⣛⢻⣿⡟⣛⣿⡿⣛⣛⢻⣿⣿⣶⣦⣄⡀⠀",
    "⠉⠛⠻⠿⠿⠿⠷⣼⣿⣿⣼⣿⣧⣭⣼⣿⣧⣭⣿⣿⣬⡭⠾⠿⠿⠿⠛⠉⠀"
};

---

## Features

* **Sprite Physics:** Rectangle-based movement anchored at the top-left.
* **Color Cycling:** Colors update dynamically on every collision.
* **Accurate Detection:** Precise border collision handling based on sprite dimensions.
* **Unicode Support:** High-fidelity rendering of the DVD logo.
* **Smooth Animation:** Frame timing logic for consistent movement speed.

---

## Technologies Used

* **C** (Standard C99/C11)
* **ANSI Escape Codes** for color and cursor positioning
* **Custom Library:** `terminal_draw.h`

---

## Project Structure

.
├── bouncing_dvd.c        
├── terminal_draw.h      
└── README.md    

## How to Run

gcc bouncing_dvd.c -o dvd
./dvd

Ensure your terminal supports UTF-8 and ANSI colors for the best experience.