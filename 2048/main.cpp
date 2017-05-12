//
//  main.cpp
//  2048
//
//  Created by haijian on 2017/05/11.
//  Copyright © 2017 haijian. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <termios.h>
#include <curses.h>
#include <math.h>
#include <stdlib.h>

#include "Controller.hpp"
#include "UILayout.hpp"
#include "Game2048.hpp"

// Class Initiate
Controller controller;
Game2048 game2048;
UILayout uiLayout;

void PrintScreen(){
  uiLayout.PositionY(4);
  uiLayout.PrintScore((80 - 32 - 2)/2);
  uiLayout.PositionY(2);
  game2048.PrintNumber((80 - 29 - 2)/2);
}

int main(void) {
  char direction; // For Values get from controller.GetDirection()
  // int x; // For Align Center Values

  // Random Seed Initiate
  srand((unsigned)time(NULL));

  // Initiate Screen
  system("clear");

  // Set Start Numbers the Print them
  game2048.StartNumber();

  PrintScreen();

  // Check if Game Over LOOP the Main Game
  while (!game2048.CheckGameOver()) {
    game2048.ResetIfMove();
    direction = controller.GetDirection();
    game2048.NumberCombine(direction);
    if (game2048.GetIfMove()) {
      game2048.AddNumber(direction);
      system("clear");
      PrintScreen();
    }
  }

  uiLayout.UIGameOver();

  getchar();

  return 0;
}
