//
//  CollisionSystem.cpp
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/4/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//
#include "../includes/CollisionSystem.h"

CollisionSystem* CollisionSystem::g_CollisionSystem = NULL;

// getInstance function
CollisionSystem* CollisionSystem::getInstance(){
    if (!g_CollisionSystem)
        g_CollisionSystem = new CollisionSystem();
    return g_CollisionSystem;
}

// Default constructor
CollisionSystem::CollisionSystem(){
    // Do Nothing Now
}

// Default destructor
CollisionSystem::~CollisionSystem(){
    // Do Nothing Now
}

// init
bool CollisionSystem::init(){
    bool success = true;
    std::cout << "Initialize CollisionSystem!\n";
    return success;
}

// update
void CollisionSystem::update(){
    // This update function is called each frame to detect collision
    // For collision in this game, first, we detect the ball with the paddle
    if (GameSetting::getInstance()->getBall()->getCollideTag() == true){
        GameSetting::getInstance()->getBall()->setCollideTag( false );
        return;
    }
    GameSetting::getInstance()->getBall()->onCollide( GameSetting::getInstance()->getPaddle() );
    // Then, we detect the ball with the boundary(4 walls)
    //std::cout << "111111\n";
    for (int i = 0; i < 3; i++){
        GameSetting::getInstance()->getBall()->onCollide( GameSetting::getInstance()->getBoundary()[i] );
    }
    // Then, we detect the ball with the bircks, and bricks with the ball
    for (int i = 0; i < GameSetting::getInstance()->getBrick().size(); i++){
        GameSetting::getInstance()->getBall()->onCollide( GameSetting::getInstance()->getBrick()[i] );
        //GameSetting::getInstance()->getBrick()[i]->onCollide( GameSetting::getInstance()->getBall() );
    }
    
}

// quit
bool CollisionSystem::quit(){
    if(g_CollisionSystem)
        delete[] g_CollisionSystem;
    return ( g_CollisionSystem = NULL );
}


