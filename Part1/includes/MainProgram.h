//
//  MainProgram.h
//  BreakoutGame
//
//  Created by Tianxiang Dai on 2/4/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#ifndef MainProgram_h
#define MainProgram_h

#include "CollisionSystem.h"
#include "PlaySystem.h"
#include "DisplaySystem.h"
#include "ControlSystem.h"
#include "ResourceManager.h"
#include "GameSetting.h"
#include "System.h"
#include "LTimer.h"
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <SDL2_mixer/SDL_mixer.h>

/**
 * @brief This class sets up the main program for the game
 *
 * Applied Singleton Design Pattern
 */
class MainProgram: public System{
public:
    /**
     * @brief Get the only instance 
     */
    static MainProgram* getInstance();
    /**
     * @brief Destructor
     */
    ~MainProgram();
    /**
     * @brief Init the program
     */
    bool init();
    /**
     * @brief Run the program
     */
    void run();
    /**
     * @brief Per frame update
     */
    void update();
    /**
     * @brief Loop that runs forever
     */
    void loop();
    /**
     * @brief Loop the mainMenu
     */
    void mainMenuLoop( SDL_Event* event );
    /**
     * @brief Loop the settingMenu
     */
    void settingMenuLoop( SDL_Event* event );
    /**
     * @brief Pause
     */
    void pause();
    /**
     * @brief Resume
     */
    void resume();
    /**
     * @brief Quit
     */
    bool quit();

private:
    /**
     * @brief Private constructor
     */
    MainProgram();
    
    static MainProgram* g_mainProgram; /**< The only instance */
    
    int screenTickPerFrame = 60; /**< The screenTickPerFrame */
    
    bool running = true; /**< The running status */
    bool main = true; /**< The main menu status */
    bool setting = true; /**< The setting menu status */
};


#endif /* MainProgram_h */
