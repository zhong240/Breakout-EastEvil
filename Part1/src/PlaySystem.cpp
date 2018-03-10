//
//  PlaySystem.cpp
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/18/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#include "../includes/PlaySystem.h"

PlaySystem* PlaySystem::g_playSystem = NULL;

// getInstance function
PlaySystem* PlaySystem::getInstance(){
    if (!g_playSystem)
        g_playSystem = new PlaySystem();
    return g_playSystem;
}

// Default destructor
PlaySystem::~PlaySystem(){
    // Now do nothing
}

// Default constructor
PlaySystem::PlaySystem(){
    // Now do nothing
}

// init
bool PlaySystem::init(){
    // Now do nothing
    bool success = true;
    return success;
}

// update
void PlaySystem::update(){
    // First, check if the game is over
    if ( GameSetting::getInstance()->getBall()->getPosition()[1] > SCREEN_HEIGHT )
        GameSetting::getInstance()->getBall()->setState( IS_DEAD );
    if ( GameSetting::getInstance()->getBall()->getState() == IS_DEAD ){
        // Game Over
        std::cout << "Game Over!\n";
        if( GameSetting::getInstance()->getLife() != 0 ){
            GameSetting::getInstance()->setLife( GameSetting::getInstance()->getLife() - 1 );// Lose one life
            GameSetting::getInstance()->resetBall();
        } else{
            this->loseState = true;
        }
        //SDL_Delay( 1000 );
        return;
    }
    // Second, check if the player wins
    // The win flag
    bool isWin = true;
//    int deadNum = 0;
    for (int i = 0; i < GameSetting::getInstance()->getBrick().size(); i++){
        if ( GameSetting::getInstance()->getBrick()[i]->getState() == IS_ALIVE )
            isWin = false;
    }
    if (isWin){
        std::cout << "You Win!\n";
        // Win the current level
        GameSetting::getInstance()->setLevel( GameSetting::getInstance()->getLevel() + 1 );// get one level up
        this->winState = true;
        return;
    }
    // Then, if the game is not over or the player does not win, continue
    // First, getInputs from keyboard and apply to the paddle
    GameSetting::getInstance()->getPaddle()->setPosition( Vector2D( GameSetting::getInstance()->getPaddle()->getPosition()[0]
                                                                  + ControlSystem::getInstance()->getInputs( GameSetting::getInstance()->getPlayerNum() - 1 )[0] * PADDLE_VELOCITY_FACTOR,
                                                                  GameSetting::getInstance()->getPaddle()->getPosition()[1] ) );
    GameSetting::getInstance()->getPaddle()->setVelocity( Vector2D( ControlSystem::getInstance()->getInputs( GameSetting::getInstance()->getPlayerNum() - 1 )[0] * PADDLE_VELOCITY_FACTOR,
                                                                   0.0f ) );
    if ( GameSetting::getInstance()->getPaddle()->getPosition()[0] < PADDLE_INITIAL_SIZE_X / 2.0 ){
        GameSetting::getInstance()->getPaddle()->setPosition( Vector2D( PADDLE_INITIAL_SIZE_X / 2.0,
                                                                       GameSetting::getInstance()->getPaddle()->getPosition()[1] ) );
        GameSetting::getInstance()->getPaddle()->setVelocity( Vector2D( 0.0f, 0.0f ) );
    }
    if ( GameSetting::getInstance()->getPaddle()->getPosition()[0] > SCREEN_WIDTH - PADDLE_INITIAL_SIZE_X / 2.0 ){
        GameSetting::getInstance()->getPaddle()->setPosition( Vector2D( SCREEN_WIDTH - PADDLE_INITIAL_SIZE_X / 2.0,
                                                                       GameSetting::getInstance()->getPaddle()->getPosition()[1] ) );
        GameSetting::getInstance()->getPaddle()->setVelocity( Vector2D( 0.0f, 0.0f ) );
    }
    // In this case, the paddle can only move horizentally.
    // Second, let ball runs in its orbit
    GameSetting::getInstance()->getBall()->setPosition( Vector2D( GameSetting::getInstance()->getBall()->getPosition()[0]
                                                                + GameSetting::getInstance()->getBall()->getVelocity()[0],
                                                                GameSetting::getInstance()->getBall()->getPosition()[1]
                                                                + GameSetting::getInstance()->getBall()->getVelocity()[1] ) );
    
    //std::cout << GameSetting::getInstance()->getBall().getVelocity()[0] << " "
    //<< GameSetting::getInstance()->getBall().getVelocity()[1] << endl;
    //std::cout << "PlaySystem : " << GameSetting::getInstance()->getBall()->getPosition()[0] << " " << GameSetting::getInstance()->getBall()->getPosition()[1] << endl;
}

// quit
bool PlaySystem::quit(){
    if (!g_playSystem)
        delete[] g_playSystem;
    return (g_playSystem = NULL);
}

// isWin
bool PlaySystem::isWin(){
    return this->winState;
}
// isLose
bool PlaySystem::isLose(){
    return this->loseState;
}

// reset the win/lose state
void PlaySystem::reset(){
    this->winState = false;
    this->loseState = false;
}

// add Score
//void PlaySystem::addScore(){
//    GameSetting::getInstance()->setScore( GameSetting::getInstance()->getScore() + 10 );
//}

