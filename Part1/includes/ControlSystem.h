//
//  ControlSystem.h
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/4/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#ifndef ControlSystem_h
#define ControlSystem_h

#include <SDL2/SDL.h>
#include <vector>
#include "Vector2D.h"
#include <map>
#include <stddef.h>
#include "GameSetting.h"
#include "System.h"

/**
 * @brief This class defines Control System
 *
 * Applied Singleton Design Pattern
 */
class ControlSystem: public System{
public:
    /**
     * @brief Get the only instance
     */
    static ControlSystem* getInstance();
    /**
     * @brief Destructor
     */
    ~ControlSystem();
    /**
     * @brief Initialization
     */
    bool init();
    /**
     * @brief Get the player inputs
     *
     * @param playerId An integer represents the designated player
     */
    Vector2D getInputs(int playerId);
    /**
     * @brief Capture the player input at every frame
     *
     * @param e Keyboard event
     */
    void update(SDL_Event e);
    /**
     * @brief Update
     */
    void update();
    /**
     * @brief Quit
     */
    bool quit();

private:
    /**
     * @brief private constructor
     */
    ControlSystem();
    /**
     * @brief the only instance
     */
    static ControlSystem* g_controlSystem;
    /**
     * @brief playerInputs
     */
    vector<Vector2D> playerInputs;
};

#endif /* ControlSystem_h */
