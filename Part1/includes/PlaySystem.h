//
//  PlaySystem.h
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/18/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

// This class sets the Playsystem, control the game in the play process.
// Singleton Design Pattern

#ifndef PlaySystem_h
#define PlaySystem_h
#include "System.h"
#include "GameSetting.h"
#include <SDL2/SDL.h>

/**
 * @brief  This class sets up the play system.
 *
 * PlaySystem monitors the state of the game. 
 * Applied Singleton Design Pattern
 */
class PlaySystem: public System{
public:
    /**
     * @brief Get the PlaySystem instance
     */
    static PlaySystem* getInstance();
    /**
     * @brief Default destructor
     */
    ~PlaySystem();
    /**
     * @brief Initialization
     */
    bool init();
    /**
     * @brief Update
     */
    void update();
    /**
     * @brief Quit play system
     */
    bool quit();
    /**
     * @brief Reset game state
     */
    void reset();
    /**
     * @return true if the player wins 
     */
    bool isWin();
    /**
     * @return true if the play loses
     */
    bool isLose();
    // AddScore
    // void addScore();
    
private:
    /** the only instance */
    static PlaySystem* g_playSystem;
    /**
     * @brief Default Contructor
     */
    PlaySystem();
    
    bool winState = false; /**< whether the player wins */
    bool loseState = false; /**< whether the player loses */
};

#endif
