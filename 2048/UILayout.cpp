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
  getmaxyx(stdscr,screenY,screenX);
}

UILayout::~UILayout()
{
}

int UILayout::GetMaxX(){
	return screenX;
}

int UILayout::GetMaxY(){
	return screenY;
}


void UILayout::UIGameOver(){
	printw("GAME OVER\n");
}

void UILayout::PrintScore(int x, int y){
	move(y,x);
	printw("JOIN THE NUMBERS AND GET TO 2048\n");
}
