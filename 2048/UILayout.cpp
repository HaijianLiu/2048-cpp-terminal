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
  strGameOver =  "       GAME   OVER       ";
  strGameReset = "  <R> RESTART  <E> EXIT  ";
  strScore = "JOIN THE NUMBERS AND GET TO 2048";
  strStartGame = "PRESS ANY KEY";
  strCopyRight1 = "(C)2048 IS ORIGINALLY DEVELOPED BY GABRIELE CIRULLI";
  strCopyRight2 = "(C)2048 IS A CLONE OF VEEWO STUDIOS' APP (C)1024";
  strCopyRight3 = "(C)1024 IS A CLONE OF (C)THREES";

  // initialize coordinates
  // title screen
  posXPrintTilte = PositionXCenter(36);
  posYPrintTilte = (screenY-16)/2;
  posXStrStartGame = PositionXCenter((int)strStartGame.length());
  posYStrStartGame = posYPrintTilte+10;
  posXStrCopyRight1 = PositionXCenter((int)strCopyRight1.length());
  posXStrCopyRight2 = PositionXCenter((int)strCopyRight2.length());
  posXStrCopyRight3 = PositionXCenter((int)strCopyRight3.length());
  posYStrCopyRight = posYStrStartGame+4;
  // game screen
  posXPrintScore = PositionXCenter((int)strScore.length());
  posYPrintScore = (screenY-16)/2;
  posXPrintNumber = PositionXCenter(29);
  posYPrintNumber = posYPrintScore+3;
  // gameover screen
  posXStrGameOver = PositionXCenter((int)strGameOver.length());
  posYStrGameOver = (screenY-2)/2;
  posXStrGameReset = PositionXCenter((int)strGameReset.length());
  posYStrGameReset = posYStrGameOver+1;
}

UILayout::~UILayout()
{
}

void UILayout::PrintTilte(){
  mvprintw(posYPrintTilte+0,posXPrintTilte," _______  _______  _   ___   _____  ");
  mvprintw(posYPrintTilte+1,posXPrintTilte,"|       ||  _    || | |   | |  _  | ");
  mvprintw(posYPrintTilte+2,posXPrintTilte,"|____   || | |   || |_|   | | |_| | ");
  mvprintw(posYPrintTilte+3,posXPrintTilte," ____|  || | |   ||       ||   _   |");
  mvprintw(posYPrintTilte+4,posXPrintTilte,"| ______|| |_|   ||___    ||  | |  |");
  mvprintw(posYPrintTilte+5,posXPrintTilte,"| |_____ |       |    |   ||  |_|  |");
  mvprintw(posYPrintTilte+6,posXPrintTilte,"|_______||_______|    |___||_______|");
  attron(A_BLINK);
  mvprintw(posYStrStartGame,posXStrStartGame,strStartGame.c_str());
  attroff(A_BLINK);
  mvprintw(posYStrCopyRight+0,posXStrCopyRight1,strCopyRight1.c_str());
  mvprintw(posYStrCopyRight+1,posXStrCopyRight2,strCopyRight2.c_str());
  mvprintw(posYStrCopyRight+2,posXStrCopyRight3,strCopyRight3.c_str());
}

void UILayout::UIGameOver(){
  attron(A_REVERSE);
	mvprintw(posYStrGameOver,posXStrGameOver,strGameOver.c_str());
  mvprintw(posYStrGameReset,posXStrGameReset,strGameReset.c_str());
  attroff(A_REVERSE);
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
