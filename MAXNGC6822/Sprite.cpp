//
//  Sprite.cpp
//  MAXNGC6822
//
//  Created by Max Gribov on 02/01/15.
//  Copyright (c) 2015 Max Gribov. All rights reserved.
//

#include "Sprite.h"

Sprite::Sprite(){
    
    //basic constructor
    
    _texture = 0;
    _position = positionMake(0, 0);
    _bounds = boundsMake(_position.x, _position.y, kSpriteWidth, kSpriteHeight);
    _enabled = false;
    
    
}

Sprite::Sprite(const Sprite &my){
    
    //copy constructor
    
    _texture = my._texture;
    _position = my._position;
    _bounds = my._bounds;
    _enabled = my._enabled;
}

Sprite::Sprite(word texture, position position, bool enabled) {
    
    //advanced constructor
    
    _texture = texture;
    _position = position;
    _bounds = boundsMake(_position.x, _position.y, kSpriteWidth, kSpriteHeight);
    _enabled = enabled;
    
}

void Sprite::setSpriteTexture(word texture) {
    
    _texture = texture;
    
}

word Sprite::getSpriteTexture() {
    
    return _texture;
}

void Sprite::setSpritePosition(position position) {
    
    _position = position;
}


position Sprite::getSpritePosition() {
    
    return _position;
}

void Sprite::setSpriteEnabled(bool enabled) {
    
    _enabled = enabled;
}

bool Sprite::isSpriteEnabled(){
    
    return _enabled;
}

bounds Sprite::getSpriteBounds() {
    
    return _bounds;
}

byte Sprite::getTextureLineAtIndex(byte index) {

    switch (index) {
        case 0:
            return highByte(_texture) & B11110000;
            break;
            
        case 1:
            return (highByte(_texture) & B00001111) << 4;
            break;
            
        case 2:
            return lowByte(_texture) & B11110000;
            break;
            
        case 3:
            return (lowByte(_texture) & B00001111) << 4;
            break;
            
        default:
            return 0;
            break;
    }
    
    
}

void Sprite::moveSprite(int offsetX, int offsetY) {
    
    _position.x += offsetX;
    _position.y += offsetY;
    _bounds = boundsMake(_position.x, _position.y, kSpriteWidth, kSpriteHeight);
}

bool Sprite::isSpriteInDisplayBounds(){
    
    bounds _displayBounds = displayBounds();
    
    if (_bounds.topEdge > _displayBounds.bottomEdge ||
        _bounds.bottomEdge < _displayBounds.topEdge ||
        _bounds.leftEdge > _displayBounds.rightEdge ||
        _bounds.rightEdge < _displayBounds.leftEdge    ) {
        
        return false;
        
    } else {
        
        return true;
    }
}

Sprite::~Sprite() {
    
    //destructor
}
