//
//  Boundary.cpp
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/16/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#include "../includes/Boundary.h"

// Default constructor
Boundary::Boundary(){
    this->position = Vector2D( BOUNDARY_INITIAL_WIDTH / 2, BOUNDARY_INITIAL_HEIGHT / 2 );
    this->size = Vector2D( BOUNDARY_INITIAL_WIDTH, BOUNDARY_INITIAL_HEIGHT );
    this->tag = "Boundary";
    createWall();
}

// Constructor
Boundary::Boundary( Vector2D pos, Vector2D size ): GameObject(pos){
    this->tag = "Boundary";
    this->size = size;
    createWall();
}

// createWall
void Boundary::createWall(){
    // set the 4 walls around the boundary
    wall[0] = Wall( Vector2D( position[0], position[1] - size[1] / 2 - WALL_INITIAL_HEIGHT / 2 ),
                   Vector2D( WALL_INITIAL_WIDTH + 2 * WALL_INITIAL_HEIGHT, WALL_INITIAL_HEIGHT ),
                   Vector2D( NORMAL_INITIAL_X, - NORMAL_INITIAL_Y ) );
    // Top
    wall[1] = Wall( Vector2D( position[0], position[1] + size[1] / 2 + WALL_INITIAL_HEIGHT / 2 ),
                   Vector2D( WALL_INITIAL_WIDTH + 2 * WALL_INITIAL_HEIGHT, WALL_INITIAL_HEIGHT ),
                   Vector2D( NORMAL_INITIAL_X, NORMAL_INITIAL_Y ));
    // Bottom
    wall[2] = Wall( Vector2D( position[0] - size[0] / 2 - WALL_INITIAL_HEIGHT / 2, position[1] ),
                   Vector2D( WALL_INITIAL_HEIGHT, WALL_INITIAL_WIDTH + 2 * WALL_INITIAL_HEIGHT ),
                   Vector2D( - NORMAL_INITIAL_Y, NORMAL_INITIAL_X ));
    // Left
    wall[3] = Wall( Vector2D( position[0] + size[0] / 2 + WALL_INITIAL_HEIGHT / 2, position[1] ),
                   Vector2D( WALL_INITIAL_HEIGHT, WALL_INITIAL_WIDTH + 2 * WALL_INITIAL_HEIGHT ),
                   Vector2D( NORMAL_INITIAL_Y, NORMAL_INITIAL_X ));
    // Right
}

// getWall
Wall* Boundary::getWall(){
    return this->wall;
}

// Default Destructor
Boundary::~Boundary(){
    
}

// GetSize
Vector2D Boundary::getSize(){
    return this->size;
}

// SetSize
void Boundary::setSize( Vector2D size ){
    this->size = size;
}
