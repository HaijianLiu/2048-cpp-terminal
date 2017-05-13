//
//  Game2048.cpp
//  2048
//
//  Created by haijian on 2017/05/11.
//  Copyright © 2017 haijian. All rights reserved.
//

#include "Game2048.hpp"

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <curses.h>


Game2048::Game2048()
{
  gameOver = false; // A bool for CheckGameOver()
}


Game2048::~Game2048()
{
}

// Print X of spaces
void Game2048::PositionX(int x){
  for (int i = 0; i < x; i++) {
    printw(" ");
  }
}

// Print MainNumber
// * 1. If The Number is ZERO then Print NULL(SPACE)
// 29 x 13

void Game2048::PrintNumber(int x){
  PositionX(x);
  printw("+------+------+------+------+\n");
  for (int i = 0; i < 4; i++) {
    PositionX(x);
    printw("|");
    for (int j = 0; j < 4; j++) {
      if(mainNumber[i][j] == 0){
        printw("      ");
      }else{
        printw(" %4d ", mainNumber[i][j]*2);
      }
      printw("|");
    }
    printw("\n");
    PositionX(x);
    printw("|      |      |      |      |\n");
    PositionX(x);
    printw("+------+------+------+------+\n");
  }

  // Test
  // printw("ifMove = %d , ifAdd = %d \n", ifMove , ifAdd);
}

// Initiate Start Numbers
// * 1. All Numbers RANDOMLY Begin with a ZERO OR 2
void Game2048::StartNumber(){
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      mainNumber[i][j] = rand()%2;
    }
  }
}

// Number Combine
// * 1. If The Same Number Then do a PLUS
// * 2. If The Position is ZERO Then Move to It
void Game2048::NumberCombine(char direction){

  if (direction == 'r') {
    // Right
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 3; j++) {
        if(mainNumber[i][2-j] == mainNumber[i][3-j] || mainNumber[i][3-j] == 0){
          if (ifMove == false && mainNumber[i][2-j] != 0) {
            ifMove = true;
          }
          mainNumber[i][3-j] += mainNumber[i][2-j];
          mainNumber[i][2-j] = 0;
        }
      }
    }
  }

  if (direction == 'l') {
    // Left
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 3; j++) {
        if(mainNumber[i][1+j] == mainNumber[i][0+j] || mainNumber[i][0+j] == 0){
          if (ifMove == false && mainNumber[i][1+j] != 0) {
            ifMove = true;
          }
          mainNumber[i][0+j] += mainNumber[i][1+j];
          mainNumber[i][1+j] = 0;
        }
      }
    }
  }

  if (direction == 'u') {
    // Up
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 3; j++) {
        if(mainNumber[1+j][i] == mainNumber[0+j][i] || mainNumber[0+j][i] == 0){
          if (ifMove == false && mainNumber[1+j][i] != 0) {
            ifMove = true;
          }
          mainNumber[0+j][i] += mainNumber[1+j][i];
          mainNumber[1+j][i] = 0;
        }
      }
    }
  }

  if (direction == 'd') {
    // Down
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 3; j++) {
        if(mainNumber[2-j][i] == mainNumber[3-j][i] || mainNumber[3-j][i] == 0){
          if (ifMove == false && mainNumber[2-j][i] != 0) {
            ifMove = true;
          }
          mainNumber[3-j][i] += mainNumber[2-j][i];
          mainNumber[2-j][i] = 0;
        }
      }
    }
  }
}

// Get bool of ifMove
bool Game2048::GetIfMove(){
  return ifMove;
}

// Reset ifMove to false
void Game2048::ResetIfMove(){
  ifMove = false;
}

// Add a New Number
// * 1A. When ifMove == true RANDOMLY Add A Number OR NOT
// * 1B. When ifMove == true Add A Number
// * 2. The Number is RANDOMLY Based on the BIGGEST Number
// * 3. The Position is RANDOMLY on The Opsite side
void Game2048::AddNumber(char direction){

  // * 2. Check the BIGGEST Number
  bigNumber = mainNumber[0][0];

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (mainNumber[i][j] > bigNumber) {
        bigNumber = mainNumber[i][j];
      }
    }
  }

  // * 2. Get the BIGGEST Number to Add
  bigNumber = log2(bigNumber);
  // Adjust The BIGGEST Number!!
  if (bigNumber < 4.0) {
    bigNumber = 1.0;
  }else if (bigNumber < 8.0) {
    bigNumber = 4.0;
  }else {
    bigNumber = 8.0;
  }
  // Random The BIGGEST Number
  bigNumber = 2*exp2(rand()%(int)bigNumber);


  // // * 1A. OR NOT : When there is NOT a ZERO in the RANDOM Position
  // // * 3. The Position is RANDOMLY on The Opsite side
  //
  // // Get The Romdom Position
  // n = rand()%4;
  // // Add the BIGGEST Number
  // switch (direction) {
  // 	case 'r': if (mainNumber[n][0] == 0) mainNumber[n][0] = bigNumber; break;
  // 	case 'l': if (mainNumber[n][3] == 0) mainNumber[n][3] = bigNumber; break;
  // 	case 'u': if (mainNumber[3][n] == 0) mainNumber[3][n] = bigNumber; break;
  // 	case 'd': if (mainNumber[0][n] == 0) mainNumber[0][n] = bigNumber; break;
  // }

  // * 1B. When ifMove == true Add A Number
  // * 3. The Position is RANDOMLY on The Opsite side
  do {
    // Set ifAdd
    ifAdd = false;
    // Get The Romdom Position
    n = rand()%4;
    // Add the BIGGEST Number
    switch (direction) {
      case 'r': if (mainNumber[n][0] == 0) {mainNumber[n][0] = (int)bigNumber; ifAdd = true;} break;
      case 'l': if (mainNumber[n][3] == 0) {mainNumber[n][3] = (int)bigNumber; ifAdd = true;} break;
      case 'u': if (mainNumber[3][n] == 0) {mainNumber[3][n] = (int)bigNumber; ifAdd = true;} break;
      case 'd': if (mainNumber[0][n] == 0) {mainNumber[0][n] = (int)bigNumber; ifAdd = true;} break;
    }
  } while(!ifAdd);

}

// Game Over
// * 1. When there is NO SPACE
// * 2. When there is NO Numbers to Combine
bool Game2048::CheckGameOver(){
  gameOver = true;

  // * 1. When there is NO SPACE
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (mainNumber[i][j] == 0) {
        gameOver = false;
        return gameOver;
      }
    }
  }

  // * 2. When there is NO Numbers to Combines
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (mainNumber[i][j] == mainNumber[i][j+1] || mainNumber[i][j] == mainNumber[i+1][j]) {
        gameOver = false;
        return gameOver;
      }
    }
  }
  return gameOver;
}
