//
//  SettingMenu.h
//  BreakoutGame
//
//  Created by Tianxiang Dai on 2/21/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#ifndef SettingMenu_h
#define SettingMenu_h

#include "LButton.h"
#include "LTexture.h"
#include "Constants.h"
#include <iostream>
#include <string>
#include <map>

/**
 * @brief This class defines the setting scene.
 * 
 * Applied Singleton Design Pattern
 */
class SettingMenu{
public:
    /**
     * @brief Get the only instance
     */
    static SettingMenu* getInstance();
    /**
     * @brief Default Destructor
     */
    ~SettingMenu();
    /**
     * @brief Get button by name
     */
    LButton* getButton( std::string name );
    /**
     * @brief Get SpriteClips by button
     */
    SDL_Rect getSpriteClips( LButtonSprite mCurrentSprite );
    /**
     * @brief Set First Language Text Texture
     */
    void setFirstLanguageTextTexture( LTexture* gFirstLanguageTextTexture );
    /**
     * @brief Set Second Language Text Texture
     */
    void setSecondLanguageTextTexture( LTexture* gSecondLanguageTextTexture );
    /**
     * @brief Set SettingMenuButtonSpriteSheet
     */
    void setSettingMenuButtonSpriteSheet( LTexture* gSettingMenuButtonSpriteSheet );
    /**
     * @brief Set ReturnTextTexture
     */
    void setReturnTextTexture( LTexture* gReturnTextTexture );
    /**
     * @brief Set SettingMenuTextTexture
     */
    void setSettingMenuTextTexture( LTexture* gSettingMenuTextTexture );
    /**
     * @brief Get SettingMenuTextTexture
     */
    LTexture* getSettingMenuTextTexture();
    /**
     * @brief Get First Language Text Texture
     */
    LTexture* getFirstLanguageTextTexture();
    /**
     * @brief Get Second Language Text Texture
     */
    LTexture* getSecondLanguageTextTexture();
    /**
     * @brief Get SettingMenuButtonSpriteSheet
     */
    LTexture* getSettingMenuButtonSpriteSheet();
    /**
     * @brief Get ReturnTextTexture
     */
    LTexture* getReturnTextTexture();

private:
    static SettingMenu* g_settingMenu; /**< the only instance */
    
    /**
     * @brief the Default constructor
     */
    SettingMenu();

    std::map<std::string, LButton*> buttons; /** the map from name to LButton */
    SDL_Rect gSpriteClips[ BUTTON_SPRITE_TOTAL ]; /**< Mouse button sprites */
    
    LTexture* gFirstLanguageTextTexture = new LTexture(); /**< the First Language Text Texture */
    LTexture* gSecondLanguageTextTexture = new LTexture(); /**< the Second Language Text Texture */

    LTexture* gReturnTextTexture = new LTexture(); /**< the return Text Texture */
    LTexture* gSettingMenuTextTexture = new LTexture(); /**< the Setting Menu Text Texture */
    LTexture* gSettingMenuButtonSpriteSheet = new LTexture(); /**< Button Sprite Sheet */
};


#endif
