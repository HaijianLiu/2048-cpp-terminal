//
//  main.cpp
//  2048
//
//  Created by haijian on 2017/05/11.
//  Copyright © 2017 haijian. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <math.h>

#include "Controller.hpp"
#include "UILayout.hpp"
#include "Game2048.hpp"

// Class Initiate
Game2048 game2048;

int main(void) {
  // curses init
  initscr();
  // capture special keystrokes
  keypad(stdscr, TRUE);
  // Random Seed Initiate
  srand((unsigned)time(NULL));

  // Initiate Screen
  // system("clear"); // terminal command
  clear(); // curses function

  game2048.MainGameLoop();

  // curses end
  endwin();
  return 0;
}
