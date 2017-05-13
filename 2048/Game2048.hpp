//
//  Game2048.hpp
//  2048
//
//  Created by haijian on 2017/05/11.
//  Copyright © 2017 haijian. All rights reserved.
//

#ifndef Game2048_hpp
#define Game2048_hpp

#include "UILayout.hpp" // where include:
// public:
// 	void MainGameLoop()
// private:
// 	 UILayout uiLayout
// 	 void PrintGameScreen()

#include "Controller.hpp" // where include:
// public:
// 	void MainGameLoop()
// private:
// 	 Controller controller

class Game2048
{
public:
	Game2048();
	~Game2048();

	// #include "UILayout.hpp"
	// #include "Controller.hpp"
	void MainTitle();
	void MainGameLoop();

private:
	int mainNumber[4][4]; // main number
	bool ifMove; // if any number moved after press controller
	int n; // A Position Variable For Add Number
	double bigNumber; // A BIGGEST Number Variable For Add Number
	bool ifAdd; // If A BIGGEST Number is Added
	bool gameOver; // A bool for CheckGameOver()

	// #include "UILayout.hpp"
	UILayout uiLayout; // UILayout object

	// #include "Controller.hpp"
	Controller controller; // Controller object
	char direction; // For Values get from controller.GetDirection()

	// Initiate Start Numbers
	// * 1. All Numbers RANDOMLY Begin with a ZERO OR 2
	void StartNumber();

	// Print MainNumber
	// * 1. If The Number is ZERO then Print NULL(SPACE)
	// 29 x 13
	void PrintNumber(int x, int y);

	// Number Combine
	// * 1. If The Same Number Then do a PLUS
	// * 2. If The Position is ZERO Then Move to It
	void NumberCombine(char direction);

	// Get bool of ifMove
	bool GetIfMove();

	// Reset ifMove to false
	void ResetIfMove();

	// Add a New Number
	// * 1A. When ifMove == true RANDOMLY Add A Number OR NOT
	// * 1B. When ifMove == true Add A Number
	// * 2. The Number is RANDOMLY Based on the BIGGEST Number
	// * 3. The Position is RANDOMLY on The Opsite side
	void AddNumber(char direction);

	// #include "UILayout.hpp"
	// print all of the screen finally
	void PrintGameScreen();

	// Game Over
	// * 1. When there is NO SPACE
	// * 2. When there is NO Numbers to Combine
	bool CheckGameOver();
};

#endif /* Game2048_hpp */
