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
}

UILayout::~UILayout()
{
}

void UILayout::GetScreenSize(){
  getmaxyx(stdscr,screenY,screenX);
  posXPrintScore = PositionXCenter(32);
  posYPrintScore = 4;
  posXPrintNumber = PositionXCenter(29);
  posYPrintNumber = 7;
}

void UILayout::UIGameOver(){
	printw("GAME OVER\n");
}

void UILayout::PrintScore(int x, int y){
	move(y,x);
	printw("JOIN THE NUMBERS AND GET TO 2048\n");
}

int UILayout::GetScreenX(){
	return screenX;
}

int UILayout::GetScreenY(){
	return screenY;
}

int UILayout::PositionXCenter(int width){
  return (screenX - width)/2;
}

int UILayout::GetPosXPrintScore(){
  return posXPrintScore;
}
int UILayout::GetPosYPrintScore(){
  return posYPrintScore;
}
int UILayout::GetPosXPrintNumber(){
  return posXPrintNumber;
}
int UILayout::GetPosYPrintNumber(){
  return posYPrintNumber;
}
