//
//  Controller.hpp
//  2048
//
//  Created by haijian on 2017/05/11.
//  Copyright © 2017 haijian. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <stdio.h>
#include <stdlib.h>

#endif /* Controller_hpp */

#pragma once
class Controller
{
public:
	Controller();
	~Controller();

	// Get Direction
	char GetDirection(){
		system ("/bin/stty raw");
		switch(getchar()){
			case 'w': dirction = 'u'; break;
			case 'a': dirction = 'l'; break;
			case 's': dirction = 'd'; break;
			case 'd': dirction = 'r'; break;
			case 'W': dirction = 'u'; break;
			case 'A': dirction = 'l'; break;
			case 'S': dirction = 'd'; break;
			case 'D': dirction = 'r'; break;
			case 72: dirction = 'u'; break;
			case 75: dirction = 'l'; break;
			case 80: dirction = 'd'; break;
			case 77: dirction = 'r'; break;
			default : dirction = '0';
		}
		system ("/bin/stty cooked");
		return dirction;
	}

private:
	char dirction;
};
