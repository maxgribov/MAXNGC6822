//
//  Display.h
//  MAXNGC6822
//
//  Created by Max Gribov on 02/01/15.
//  Copyright (c) 2015 Max Gribov. All rights reserved.
//

#ifndef __MAXNGC6822__Display__
#define __MAXNGC6822__Display__

//#include <stdio.h>

#include <Arduino.h>
#include "GlobalConstants.h"
#include "LedControl.h"
#include "Sprite.h"

class Display {
 
public:
   
    Display();
    
    void draw(Sprite *sprites);
    
    void drawSprite(Sprite sprite);
    void update();
    
    void test();
    void clearDisplay();
    void clearDisplayMemory();
    
    int getDisplaysCount();
    
    
private:
    
    LedControl* _ledControl;
    word _displayLines[8];
    bounds currentDisplayBounds;

    

};

#endif /* defined(__MAXNGC6822__Display__) */
