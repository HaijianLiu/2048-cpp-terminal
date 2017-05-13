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
  // GetScreenSize();
}

UILayout::~UILayout()
{
}

void UILayout::UIGameOver(){
	printw("GAME OVER\n");
}

void UILayout::PrintScore(){
	// printw("+---------------------------+\n");
	// printw("|    SCORE          BEST    |\n");
	// printw("|                           |\n");
	// printw("+---------------------------+\n");
	printw("JOIN THE NUMBERS AND GET TO 2048\n");
}
