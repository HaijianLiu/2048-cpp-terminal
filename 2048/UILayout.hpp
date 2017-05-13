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

	// Print X of spaces
	void PositionX(int x);

	// Print Y of \n
	void PositionY(int y);

	// Get screenX to int
	// int GetScreenX(){
	// 	return screenX;
	// }

	void UIGameOver();

	void PrintScore(int x);

private:
	// Variables for Screen Size X & Y
	// int screenX;
	// int screenY;
};

#endif /* UILayout_hpp */
