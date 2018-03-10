//
//  Brick.cpp
//  BreakoutGame-TX
//
//  Created by Yichen Wang on 2/4/18.
//  Modified by Tianxiang Dai on 2/17/18.
//  Copyright © 2018 Yichen Wang. All rights reserved.
//

#include "../includes/Brick.h"

// Default construtcor
Brick::Brick(): Collider( this ){
    this->tag = "Brick";
    setMass( BRICK_MASS );
    setBoundingBox( Vector2D( BRICK_BOUNDING_BOX_X, BRICK_BOUNDING_BOX_Y ) );
}

// Constructor
Brick::Brick(Vector2D pos, Vector2D size): GameObject( pos ), Collider( this ), size( size ){
    this->tag = "Brick";
    setMass( BRICK_MASS );
    setBoundingBox( Vector2D( BRICK_BOUNDING_BOX_X, BRICK_BOUNDING_BOX_Y ) );
}

// Destructor
Brick::~Brick(){
    
}

// onTriggerCollide
void Brick::onTriggerCollide( Collider collider, Vector2D normal ){
    // Called when the brick is collided.
    std::cout << "Brick Collide!\n";
    setState( IS_DEAD );
}

// getSize
Vector2D Brick::getSize(){
    return this->size;
}

// setSize
void Brick::setSize( Vector2D size ){
    this->size = size;
}


