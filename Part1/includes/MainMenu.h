//
//  MainMenu.h
//  BreakoutGame
//
//  Created by Tianxiang Dai on 2/21/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#ifndef MainMenu_h
#define MainMenu_h

#include "LButton.h"
#include "LTexture.h"
#include "Constants.h"
#include <iostream>
#include <string>
#include <map>

/**
 * @brief This class defines the main menu that is loaded at the beginning of the game.
 *
 * Applied Singleton Design Pattern
 */
class MainMenu{
public:
    /**
     * @brief Get the only instance
     */
    static MainMenu* getInstance();
    /**
     * @brief Default constructor
     */
    ~MainMenu();
    /**
     * @brief Get PauseTextTexture
     */
    LTexture* getPauseTextTexture();
    /**
     * @brief Get QuitTextTexture
     */
    LTexture* getQuitTextTexture();
    /**
     * @brief Get StartTextTexture
     */
    LTexture* getStartTextTexture();
    /**
     * @brief Get MainMenuTextTexture
     */
    LTexture* getMainMenuTextTexture();
    /**
     * @brief Get LanguageSetting
     */
    LTexture* getLanguageSettingTextTexture();
    /**
     * @brief Get MainMenuButtonSpriteSheet
     */
    LTexture* getMainMenuButtonSpriteSheet();
    /**
     * @brief Get ReturnTextTexture();
     */
    LTexture* getReturnTextTexture();
    /**
     * @brief Set PauseTextTexture
     */
    void setPauseTextTexture( LTexture* gPauseTextTexture);
    /**
     * @brief Set QuitTextTexture
     * @param gQuitTextTexture [description]
     */
    void setQuitTextTexture( LTexture* gQuitTextTexture );
    /**
     * @brief Set StartTextTexture
     */
    void setStartTextTexture( LTexture* gStartTextTexture );
    /**
     * @brief Set MainMenuTextTexture
     */
    void setMainMenuTextTexture( LTexture* gMainMenuTextTexture );
    /**
     * @brief Set LanguageSetting
     */
    void setLanguageSettingTextTexture( LTexture* gLanguageSettingTextTexture );
    /**
     * @brief Set MainMenuButtonSpriteSheet
     */
    void setMainMenuButtonSpriteSheet( LTexture* gMainMenuButtonSpriteSheet );
    /**
     * @brief Set ReturnTextTexture
     */
    void setReturnTextTexture( LTexture* gReturnTextTexture );
    /**
     * @brief Get Button
     */
    LButton* getButton( std::string name );
    /**
     * @brief Get SpriteClips
     */
    SDL_Rect getSpriteClips( LButtonSprite mCurrentSprite );

private:
    /**
     * @brief the only instance
     */
    static MainMenu* g_mainMenu;
    /**
     * @brief private constructor
     */
    MainMenu();
    
    /** the map from name to LButton */
    std::map<std::string, LButton*> buttons;
    /** PauseTextTexture */
    LTexture* gPauseTextTexture = new LTexture();
    /** QuitTextTexture */
    LTexture* gQuitTextTexture = new LTexture();
    /** StartTextTexture */
    LTexture* gStartTextTexture = new LTexture();
    /** MainMeneuTextTexture */
    LTexture* gMainMenuTextTexture = new LTexture();
    /** Language Setting textures */
    LTexture* gLanguageSettingTextTexture = new LTexture();
    /** Button Sprite Sheet */
    LTexture* gMainMenuButtonSpriteSheet = new LTexture();
    /** ReturnTextTexture */
    LTexture* gReturnTextTexture = new LTexture();
    /** Mouse button sprites */
    SDL_Rect gSpriteClips[ BUTTON_SPRITE_TOTAL ];
};

#endif
