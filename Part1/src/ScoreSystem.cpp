//
//  ScoreSystem.cpp
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/21/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#include "../includes/ScoreSystem.h"

ScoreSystem* ScoreSystem::g_scoreSystem = NULL;

// getInstance
ScoreSystem* ScoreSystem::getInstance(){
    if ( !g_scoreSystem )
        g_scoreSystem = new ScoreSystem();
    return g_scoreSystem;
}

// default constructor
ScoreSystem::ScoreSystem(){
    // Do nothing
    score = 0;
}

// default destructor
ScoreSystem::~ScoreSystem(){
    // Do nothing
}

// init
bool ScoreSystem::init(){
    bool success = true;
    score = 0;
    return success;
}

// quit
bool ScoreSystem::quit(){
    bool success = true;
    return success;
}

// update
void ScoreSystem::update(){
    // Do nothing
}

// setScore
void ScoreSystem::setScore( long int score ){
    this->score = score;
}

// getScore
long int ScoreSystem::getScore(){
    return this->score;
}

// reset
void ScoreSystem::reset(){
    score = 0;
}
