//
//  Controller.hpp
//  2048
//
//  Created by haijian on 2017/05/11.
//  Copyright © 2017 haijian. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp


class Controller
{
public:
	Controller();
	~Controller();

	// Get Direction
	char GetDirection();

private:
	char dirction;
	// int key;
};

#endif /* Controller_hpp */
