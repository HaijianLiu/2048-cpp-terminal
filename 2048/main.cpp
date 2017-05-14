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

int main(void) {
  // curses init
  initscr();
  // capture special keystrokes
  keypad(stdscr, TRUE);
  // Random Seed Initiate
  srand((unsigned)time(NULL));
  // system("clear"); // terminal command
  clear(); // curses function

  // Class Initiate
  Game2048 game2048;

  // start main game
  game2048.MainGameLoop();

  // curses end
  endwin();
  return 0;
}
