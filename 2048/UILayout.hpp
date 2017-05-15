//
//  UILayout.hpp
//  2048
//
//  Created by haijian on 2017/05/11.
//  Copyright © 2017 haijian. All rights reserved.
//

#ifndef UILayout_hpp
#define UILayout_hpp

#include <string>
using namespace std;

class UILayout
{
public:
	UILayout();
	~UILayout();

	// print title
	void PrintTilte();
	// print game over UI
	void UIGameOver();
	// print title score part
	void PrintScore();

	// position X to center according to given width of itself
	int PositionXCenter(int width);

	// get location values of every parts
	int GetPosXPrintNumber();
	int GetPosYPrintNumber();

private:
	// Variables for Screen Size X & Y
	int screenX;
	int screenY;

	// strings
	string strGameOver;
	string strScore;
	string strStartGame;
	string strCopyRight1;
	string strCopyRight2;
	string strCopyRight3;


	// UI position of every parts
	int posXPrintTilte;
	int posYPrintTilte;
	int posXPrintScore;
	int posYPrintScore;
	int posXPrintNumber;
	int posYPrintNumber;
	int posXStrStartGame;
	int posYStrStartGame;
	int posXStrCopyRight1;
	int posXStrCopyRight2;
	int posXStrCopyRight3;
	int posYStrCopyRight;

};

#endif /* UILayout_hpp */
