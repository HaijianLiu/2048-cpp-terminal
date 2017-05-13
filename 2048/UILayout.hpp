//
//  UILayout.hpp
//  2048
//
//  Created by haijian on 2017/05/11.
//  Copyright © 2017 haijian. All rights reserved.
//

#ifndef UILayout_hpp
#define UILayout_hpp


class UILayout
{
public:
	UILayout();
	~UILayout();

	// get screen size of default window and initiate UI position
	void GetScreenSize();

	// print game over UI
	void UIGameOver();
	// print title score part
	void PrintScore(int x, int y);

	// get max window size x and y
	int GetScreenX();
	int GetScreenY();

	// position X to center according to given width of itself
	int PositionXCenter(int width);

	// get location values of every parts
	int GetPosXPrintScore();
	int GetPosYPrintScore();
	int GetPosXPrintNumber();
	int GetPosYPrintNumber();

private:
	// Variables for Screen Size X & Y
	int screenX;
	int screenY;

	// UI position of every parts
	int posXPrintScore;
	int posYPrintScore;
	int posXPrintNumber;
	int posYPrintNumber;
};

#endif /* UILayout_hpp */
