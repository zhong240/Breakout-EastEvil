//
//  DisplaySystem.h
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/18/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

// This class sets the displaysystem
// Singleton Design Pattern

#ifndef DisplaySystem_h
#define DisplaySystem_h

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include "LTexture.h"
#include "Paddle.h"
#include "MainMenu.h"
#include "SettingMenu.h"
#include "PlaySystem.h"
#include "Ball.h"
#include "CollisionSystem.h"
#include "ControlSystem.h"
#include "ResourceManager.h"
#include "Constants.h"
#include "System.h"
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>

/**
 * @brief This class defines the display system.
 *
 * The display system creates game window, renders image for game objects, and 
 * plays sound and music. 
 */
class DisplaySystem: public System{
public:
    /**
     * @brief static instance function
     * 
     * @return the only instance
     */
    static DisplaySystem* getInstance();
    /**
     * @brief Default destructor
     */
    ~DisplaySystem();
    /**
     * @brief Initialization
     * 
     * @return true if succeeds
     */
    bool init();
    /**
     * @brief Quit the display system
     * 
     * @return true if succeeds
     */
    bool quit();
    /**
     * @brief Load image/sound/music media
     * 
     * @return true if succeeds
     */
    bool loadMedia();
    /**
     * @brief load the main menu
     */
    bool loadMainMenu();
    /**
     * @brief load game setting
     */
    bool loadSettingMenu();
    /**
     * @brief Render loaded textures
     */
    void render();
    /**
     * @brief render the lose scene
     */
    void renderLose();
    /**
     * @brief render the win scene
     */
    void renderWin();
    /**
     * @brief render main menu on event
     */
    void renderMainMenu( SDL_Event* event );
    /**
     * @brief render setting menu on event
     */
    void renderSettingMenu( SDL_Event* event );
    /**
     * @brief render pause scene
     */
    void renderPauseMenu();
    /**
     * @brief Update the window at every frame
     */
    void update();
    /**
     * @brief Get SDL_Window
     */
    SDL_Window* getSDLWindow();
    /**
     * @brief Get SDL_Renderer
     */
    SDL_Renderer* getSDLRenderer();

private:
    /**
     * @brief Private default constructor
     */
    DisplaySystem();

    static DisplaySystem* g_DisplaySystem; /**< the only instance */
    SDL_Window* gWindow = NULL; /**< the window we will be rendering to */
    SDL_Renderer* gRenderer = NULL; /**< SDL Renderer */

    LTexture* gResumeTextTexture = new LTexture(); /**< resume text texture */
    LTexture* gPauseMenuTexture = new LTexture(); /**< pause menu texture */
    LTexture* gPauseTextTexture = new LTexture(); /**< pause text texture */
    LTexture* gQuitTextTexture = new LTexture(); /**< quit text texture */
    LTexture* gStartTextTexture = new LTexture(); /**< start texture */
    LTexture* gMainMenuTexture = new LTexture(); /**< main meneu texture */

    LTexture* gLifeTextTexture = new LTexture(); /**< life texture */
    LTexture* gScoreTextTexture = new LTexture(); /**< score texture */
    LTexture* gLevelTextTexture = new LTexture(); /**< level texture */

    LTexture* gWinTextTexture = new LTexture(); /**< win scene texture */
    LTexture* gLoseTextTexture = new LTexture(); /**< lose scene texture */

    LTexture* gBallTexture = new LTexture(); /**< ball texture */
    LTexture* gBrickTexture = new LTexture(); /**< brick texture */
    LTexture* gPaddleTexture = new LTexture(); /**< paddle texture */

    TTF_Font* gFont = NULL; /**< globally used font */
    SDL_Color textColor = { 255, 255, 255, 255 }; /**< set the text color to white */
};

#endif
