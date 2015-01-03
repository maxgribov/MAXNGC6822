//
//  Sprite.h
//  MAXNGC6822
//
//  Created by Max Gribov on 02/01/15.
//  Copyright (c) 2015 Max Gribov. All rights reserved.
//

#ifndef __MAXNGC6822__Sprite__
#define __MAXNGC6822__Sprite__

#include <Arduino.h>
#include "GlobalConstants.h"

class Sprite {
 
private:
    
    word _texture; // 4x4 pixels
    position _position;
    bounds _bounds;
    bool _enabled;
    
public:
    
    Sprite();
    Sprite(const Sprite &my);
    
    Sprite(word texture, position position, bool enabled);
    
    void setSpriteTexture(word texture);
    word getSpriteTexture();
    
    void setSpritePosition(position position);
    position getSpritePosition();
    
    void setSpriteEnabled(bool enabled);
    bool isSpriteEnabled();
    
    bounds getSpriteBounds();
    byte getTextureLineAtIndex(byte index);
    
    void moveSprite(int offsetX, int offsetY);
    bool isSpriteInDisplayBounds();
    
    ~Sprite();


};

#endif /* defined(__MAXNGC6822__Sprite__) */
