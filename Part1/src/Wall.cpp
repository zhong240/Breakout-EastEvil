//
//  Wall.cpp
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/16/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//
#include "../includes/Wall.h"
// Default constructor
Wall::Wall(): Collider(this) {
    this->tag = "Wall";
    setMass( WALL_MASS );
    setBoundingBox( size );
}

// Constructor
Wall::Wall( Vector2D pos, Vector2D size , Vector2D normal ): GameObject( pos ), Collider( this ){
    this->tag = "Wall";
    this->size = size;
    setBoundingBox( size );
    setNormal( normal );
    setMass( WALL_MASS );
}

// Default destructor
Wall::~Wall(){
    
}

// OnTriggerCollide
void Wall::onTriggerCollide( Collider collider, Vector2D normal ){
    // Now Do nothing
}

// getSize()
Vector2D Wall::getSize(){
    return this->size;
}

// setSize()
void Wall::setSize( Vector2D size ){
    this->size = size;
}
