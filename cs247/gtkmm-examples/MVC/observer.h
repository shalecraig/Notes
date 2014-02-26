/*
* Observer class.  Abstract class for Observer Pattern
*
*
*  Created by Jo Atlee on 06/07/09.
*  Copyright 2009 UW. All rights reserved.
*
*/


#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;


class Observer {
public:
	virtual void update () = 0;
};


#endif