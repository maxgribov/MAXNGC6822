//
//  Display.cpp
//  MAXNGC6822
//
//  Created by Max Gribov on 02/01/15.
//  Copyright (c) 2015 Max Gribov. All rights reserved.
//

#include "Display.h"
#include <array>

Display::Display() {
    
    _ledControl = new LedControl(12, 11, 10, 2);

    for (int displayIndex = 0; displayIndex < 2; displayIndex++) {
        _ledControl->shutdown(displayIndex, false);
        _ledControl->setIntensity(displayIndex, 5);
    }
    
    clearDisplay();
    
    currentDisplayBounds = displayBounds();
}



void Display::draw(Sprite *sprites) {
    
    clearDisplay();
    
    for (int spriteIndex = 0; spriteIndex < kMaxNumberOfSprites; spriteIndex++) {

            if (sprites[spriteIndex].isSpriteEnabled() && sprites[spriteIndex].isSpriteInDisplayBounds()) {
                
                //draw sprite
                
                bounds spriteBounds = sprites[spriteIndex].getSpriteBounds();
                bounds _displayBounds = displayBounds();
                
                int startDisplayLine = spriteBounds.topEdge < _displayBounds.topEdge ? _displayBounds.topEdge : spriteBounds.topEdge;
                int endDisplayLine = spriteBounds.bottomEdge > _displayBounds.bottomEdge ? _displayBounds.bottomEdge : spriteBounds.bottomEdge;
                
                for (int lineIndex = startDisplayLine; lineIndex <= endDisplayLine; lineIndex++) {
                    
                    byte leftDisplayLine = lowByte(_displayLines[lineIndex]);
                    byte rightDisplayLine = highByte(_displayLines[lineIndex]);
                    
                    byte spriteTextureLine = sprites[spriteIndex].getTextureLineAtIndex(lineIndex - spriteBounds.topEdge);
                    leftDisplayLine = leftDisplayLine | spriteTextureLine >> spriteBounds.leftEdge;
                    rightDisplayLine = rightDisplayLine | spriteTextureLine >> spriteBounds.leftEdge;
                    
                    word displayLine = displayLine | leftDisplayLine << 8 | rightDisplayLine;
                    
                    _displayLines[lineIndex] = displayLine;
                   
                    
                }
                
            }

    }
}


void Display::drawSprite(Sprite sprite) {
    
    if (sprite.isSpriteEnabled() && sprite.isSpriteInDisplayBounds()) {
        
        //draw sprite
        
        bounds spriteBounds = sprite.getSpriteBounds();
        bounds _displayBounds = displayBounds();

        int startDisplayLine = spriteBounds.topEdge < _displayBounds.topEdge ? _displayBounds.topEdge : spriteBounds.topEdge;
        int endDisplayLine = spriteBounds.bottomEdge > _displayBounds.bottomEdge ? _displayBounds.bottomEdge : spriteBounds.bottomEdge;
        
        for (int lineIndex = startDisplayLine; lineIndex < endDisplayLine; lineIndex++) {

            
            byte spriteTextureLine = sprite.getTextureLineAtIndex(lineIndex - spriteBounds.topEdge);
            
            word spriteTextureLineDisplayWidth = spriteTextureLine << 8;

            word displayLine = _displayLines[lineIndex];

            
            if (spriteBounds.leftEdge >= 0) {
                
                displayLine = displayLine | spriteTextureLineDisplayWidth >> spriteBounds.leftEdge;
                
            } else {
                
                displayLine = displayLine | spriteTextureLineDisplayWidth << abs(spriteBounds.leftEdge);
            }
            
            _displayLines[lineIndex] = displayLine;

        }
        
    } else {
        

         Serial.println("Sprite not processed");

    }
 
}

void Display::update(){
    

    
    for (int lineIndex = 0; lineIndex < 8; lineIndex++) {
        
        byte leftDisplayLine = highByte(_displayLines[lineIndex]);
        byte rightDisplayLine = lowByte(_displayLines[lineIndex]);
        
        _ledControl->setRow(0, lineIndex, leftDisplayLine);
        _ledControl->setRow(1, lineIndex, rightDisplayLine);
    }
    
    
}

void Display::clearDisplay() {
    
    for (int lineIndex = 0; lineIndex < 8; lineIndex++) {
        
        _displayLines[lineIndex] = 0;
    }
    
    for (int displayIndex = 0; displayIndex < getDisplaysCount(); displayIndex++) {
        
        _ledControl->clearDisplay(displayIndex);
    }
    
    
}

void Display::clearDisplayMemory() {
    
    for (int lineIndex = 0; lineIndex < 8; lineIndex++) {
        
        _displayLines[lineIndex] = 0;
    }
    
}

void Display::test(){
    
    for (int displayIndex = 0; displayIndex < getDisplaysCount(); displayIndex++) {
        
        for (int lineIndex = 0; lineIndex < 8; lineIndex++) {
            
            
            _ledControl->setRow(displayIndex, lineIndex, B11111111);
            delay(50);
            _ledControl->setRow(displayIndex, lineIndex, B00000000);

        }
    }
    
}



int Display::getDisplaysCount() {
    
    return _ledControl->getDeviceCount();
}
