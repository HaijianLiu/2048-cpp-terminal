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

	// print game over UI
	void UIGameOver();

	// print title score part
	void PrintScore(int x, int y);
	
	// get screen size of default window
	void GetScreenSize();
	// get max window size x and y
	int GetScreenX();
	int GetScreenY();

private:
	// Variables for Screen Size X & Y
	int screenX;
	int screenY;
};

#endif /* UILayout_hpp */
