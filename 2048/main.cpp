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
Controller controller;
Game2048 game2048;
UILayout uiLayout;

int main(void) {
  // curses init
  initscr();
  // capture special keystrokes
  keypad(stdscr, TRUE);

  char direction; // For Values get from controller.GetDirection()
  // int x; // For Align Center Values

  // Random Seed Initiate
  srand((unsigned)time(NULL));

  // Initiate Screen
  // system("clear"); // terminal command
  clear(); // curses function

  // Set Start Numbers the Print them
  game2048.StartNumber();

  game2048.PrintScreen();

  // Check if Game Over LOOP the Main Game
  while (!game2048.CheckGameOver()) {
    game2048.ResetIfMove();
    direction = controller.GetDirection();
    game2048.NumberCombine(direction);
    if (game2048.GetIfMove()) {
      game2048.AddNumber(direction);
      clear();
      game2048.PrintScreen();
    }
  }

  uiLayout.UIGameOver();

  getch();

  // curses end
  endwin();
  return 0;
}
