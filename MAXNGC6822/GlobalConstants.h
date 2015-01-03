//
//  GlobalConstants.h
//  MAXNGC6822
//
//  Created by Max Gribov on 03/01/15.
//  Copyright (c) 2015 Max Gribov. All rights reserved.
//

#ifndef __MAXNGC6822__GlobalConstants__
#define __MAXNGC6822__GlobalConstants__

//#include <stdio.h>


#define kMaxNumberOfSprites     20

#define kSpriteWidth            4
#define kSpriteHeight           4

#define kDisplayWidth           16
#define kDisplayHeight          8


//position
struct position {
    int x, y;
};


static inline position positionMake(int x, int y){
    
    position position;
    position.x = x;
    position.y = y;
    
    return position;
}

//bounds
struct bounds {
    int leftEdge;
    int rightEdge;
    int bottomEdge;
    int topEdge;
};

static inline bounds boundsMake(int originX, int originY, int width, int  height){
    
    bounds resultBounds;
    resultBounds.leftEdge = originX;
    resultBounds.topEdge = originY;
    resultBounds.rightEdge = originX + width;
    resultBounds.bottomEdge = originY + height;
    
    return resultBounds;
}

static inline bounds displayBounds() {
    
    return boundsMake(0, 0, kDisplayWidth, kDisplayHeight);
    
}


#endif /* defined(__MAXNGC6822__GlobalConstants__) */
