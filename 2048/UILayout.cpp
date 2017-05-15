//
//  UILayout.cpp
//  2048
//
//  Created by haijian on 2017/05/11.
//  Copyright © 2017 haijian. All rights reserved.
//

#include "UILayout.hpp"

#include <stdio.h>
#include <curses.h>

UILayout::UILayout()
{
  // get max stdscr size
  getmaxyx(stdscr,screenY,screenX);
  // initialize string variables
  strGameOver = "GAME OVER";
  strScore = "JOIN THE NUMBERS AND GET TO 2048";
  strStartGame = "PRESS ANY KEY";
  // initialize coordinates
  posXPrintTilte = PositionXCenter(36);
  posYPrintTilte = 4;
  posXStrStartGame = PositionXCenter((int)strStartGame.length());
  posYStrStartGame = 13;
  posXPrintScore = PositionXCenter((int)strScore.length());
  posYPrintScore = 4;
  posXPrintNumber = PositionXCenter(29);
  posYPrintNumber = 7;
}

UILayout::~UILayout()
{
}

void UILayout::PrintTilte(int x, int y){
  mvprintw(y+0,x," _______  _______  _   ___   _____  ");
  mvprintw(y+1,x,"|       ||  _    || | |   | |  _  | ");
  mvprintw(y+2,x,"|____   || | |   || |_|   | | |_| | ");
  mvprintw(y+3,x," ____|  || | |   ||       ||   _   |");
  mvprintw(y+4,x,"| ______|| |_|   ||___    ||  | |  |");
  mvprintw(y+5,x,"| |_____ |       |    |   ||  |_|  |");
  mvprintw(y+6,x,"|_______||_______|    |___||_______|");
  mvprintw(posYStrStartGame,posXStrStartGame,strStartGame.c_str());
}

void UILayout::UIGameOver(){
	printw(strGameOver.c_str());
}

void UILayout::PrintScore(){
	mvprintw(posYPrintScore,posXPrintScore,strScore.c_str());
}

int UILayout::PositionXCenter(int width){
  return (screenX - width)/2;
}

int UILayout::GetPosXPrintNumber(){
  return posXPrintNumber;
}
int UILayout::GetPosYPrintNumber(){
  return posYPrintNumber;
}
int UILayout::GetPosXPrintTilte(){
  return posXPrintTilte;
}
int UILayout::GetPosYPrintTilte(){
  return posYPrintTilte;
}
