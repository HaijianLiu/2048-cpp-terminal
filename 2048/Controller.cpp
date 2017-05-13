//
//  Controller.cpp
//  2048
//
//  Created by haijian on 2017/05/11.
//  Copyright © 2017 haijian. All rights reserved.
//

#include "Controller.hpp"

#include <stdio.h>
#include <curses.h>


Controller::Controller()
{
}

Controller::~Controller()
{
}

char Controller::GetDirection(){

  // // Terminal Command
  // system ("/bin/stty raw");
  // key = getchar();
  // system ("/bin/stty cooked");

  // curses
  move(0,0);
  switch(getch()){
    case 'w': dirction = 'u'; break;
    case 'a': dirction = 'l'; break;
    case 's': dirction = 'd'; break;
    case 'd': dirction = 'r'; break;
    case 'W': dirction = 'u'; break;
    case 'A': dirction = 'l'; break;
    case 'S': dirction = 'd'; break;
    case 'D': dirction = 'r'; break;
    case KEY_UP: dirction = 'u'; break;
    case KEY_LEFT: dirction = 'l'; break;
    case KEY_DOWN: dirction = 'd'; break;
    case KEY_RIGHT: dirction = 'r'; break;
    // case 72: dirction = 'u'; break;
    // case 75: dirction = 'l'; break;
    // case 80: dirction = 'd'; break;
    // case 77: dirction = 'r'; break;
    default : dirction = '0';
  }
  return dirction;
}
