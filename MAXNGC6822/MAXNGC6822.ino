//
// MAXNGC6822
//
// Code for videogame controller MAX-NGC-6822
// Developed with [embedXcode](http://embedXcode.weebly.com)
//
// Author 		Max Gribov
// 				Max Gribov
//
// Date			01/01/15 19:35
// Version		1.0
//
// Copyright	© Max Gribov, 2015
// Licence		MIT
//
// See         ReadMe.txt for references
//



#include "Arduino.h"
#include "LedControl.h"

#include "GlobalConstants.h"

#include "Display.h"
#include "Sprite.h"



Display mainDisplay = Display();
Sprite testSprite = Sprite(0x8C80, positionMake(0, 0), true);
Sprite testSprite2 = Sprite(0x8C80, positionMake(14, 3), true);
Sprite testSprite3 = Sprite(0x8C80, positionMake(5, -3), true);

void setup() {

   // Serial.begin(9600);

   // mainDisplay.test();
    


}

void loop() {
    
    for (int pos = 0; pos < 18; pos++) {
        
        testSprite.moveSprite(1, 0);
        testSprite2.moveSprite(-1, 0);
        testSprite3.moveSprite(0, 1);
        mainDisplay.clearDisplayMemory();
        mainDisplay.drawSprite(testSprite);
        mainDisplay.drawSprite(testSprite2);
        mainDisplay.drawSprite(testSprite3);
        mainDisplay.update();
        delay(100);
        
    }
    
    delay(300);
    
    for (int pos = 0; pos < 18; pos++) {
        
        testSprite.moveSprite(-1, 0);
        testSprite2.moveSprite(1, 0);
        testSprite3.moveSprite(0, -1);
        mainDisplay.clearDisplayMemory();
        mainDisplay.drawSprite(testSprite);
        mainDisplay.drawSprite(testSprite2);
        mainDisplay.drawSprite(testSprite3);
        mainDisplay.update();
        delay(100);
        
    }
    
    delay(300);
}
