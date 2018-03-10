//
//  ControlSystem.h
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/4/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#ifndef ControlSystem_h
#define ControlSystem_h

#include "./GameSetting.h"
#include <vector>
#include <map>
#include <stddef.h>
#include <SDL2/SDL.h>
// Control System - Singleton Design Pattern
class ControlSystem{
public:
    // get the only instance
    static ControlSystem* instance();
    // Destructor
    ~ControlSystem();
    // Initialization
    bool init();
    // getInputs
    Vector2D getInputs(int playerId);
    // update
    void update(SDL_Event e);
    
private:
    // private constructor
    ControlSystem();
    // the only instance
    static ControlSystem* g_controlSystem;
    // playerInputs
    vector<Vector2D> playerInputs;
};

#endif /* ControlSystem_h */
