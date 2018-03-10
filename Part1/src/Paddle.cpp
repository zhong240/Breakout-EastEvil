//
//  Paddle.cpp
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/17/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//
#include "../includes/Paddle.h"

// Default Constructor
Paddle::Paddle(): Collider(this) {
    this->position = Vector2D( PADDLE_INITIAL_POS_X, PADDLE_INITIAL_POS_Y );
    this->size = Vector2D( PADDLE_INITIAL_SIZE_X, PADDLE_INITIAL_SIZE_Y );
    this->tag = "Paddle";
    setMass( PADDLE_MASS );
    setBoundingBox( Vector2D( PADDLE_BOUNDING_BOX_X, PADDLE_BOUNDING_BOX_Y ) );
}

// Constructor
Paddle::Paddle( Vector2D pos, Vector2D size ): GameObject(pos), Collider(this){
    this->size = size;
    this->tag = "Paddle";
    setMass( PADDLE_MASS );
    setBoundingBox( Vector2D( PADDLE_BOUNDING_BOX_X, PADDLE_BOUNDING_BOX_Y ) );
}

// Destructor
Paddle::~Paddle(){
    
}

// onTriggerCollide
void Paddle::onTriggerCollide( Collider collider, Vector2D normal ){
    // Called when a paddle is collided, do nothing.
    std::cout << "This is the onTriggerCollide function in Paddle class!\n";
}

// getSize
Vector2D Paddle::getSize(){
    return this->size;
}

// setSize
void Paddle::setSize( Vector2D size ){
    this->size = size;
}
