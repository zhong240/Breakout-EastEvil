//
//  SettingMenu.cpp
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/21/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#include "../includes/SettingMenu.h"

SettingMenu* SettingMenu::g_settingMenu = NULL;

// the getInstance
SettingMenu* SettingMenu::getInstance(){
    if ( !g_settingMenu )
        g_settingMenu = new SettingMenu();
    return g_settingMenu;
}

// Default Constructor
SettingMenu::SettingMenu(){
    // Init map
    // First Language Button
    LButton* firstLanguageButton = new LButton();
    firstLanguageButton->setPosition( SETTING_MENU_FIRST_LANGUAGE_BUTTON_POSITION_X,
                                     SETTING_MENU_FIRST_LANGUAGE_BUTTON_POSITION_Y );
    buttons[ "first_language_button" ] = firstLanguageButton;
    // Second Language Button
    LButton* secondLanguageButton = new LButton();
    secondLanguageButton->setPosition( SETTING_MENU_SECOND_LANGUAGE_BUTTON_POSITION_X,
                                       SETTING_MENU_SECOND_LANGUAGE_BUTTON_POSITION_Y );
    buttons[ "second_language_button" ] = secondLanguageButton;
    
    // Return Button
    LButton* returnButton = new LButton();
    returnButton->setPosition( RETURN_BUTTON_POSITION_X,
                              RETURN_BUTTON_POSITION_Y );
    buttons[ "return_button" ] = returnButton;
    
    // Init Sprite position (clip)
    //    BUTTON_SPRITE_MOUSE_OUT = 0,
    //    BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
    //    BUTTON_SPRITE_MOUSE_DOWN = 2,
    //    BUTTON_SPRITE_MOUSE_UP = 3,
    //    BUTTON_SPRITE_TOTAL = 4
    //Set sprites
    // When mouse out
    gSpriteClips [ BUTTON_SPRITE_MOUSE_OUT ].x = 0;
    gSpriteClips [ BUTTON_SPRITE_MOUSE_OUT ].y = 49;
    gSpriteClips [ BUTTON_SPRITE_MOUSE_OUT ].w = 190;
    gSpriteClips [ BUTTON_SPRITE_MOUSE_OUT ].h = 45;
    
    // When mouse hover
    gSpriteClips [ BUTTON_SPRITE_MOUSE_OVER_MOTION ].x = 0;
    gSpriteClips [ BUTTON_SPRITE_MOUSE_OVER_MOTION ].y = 94;
    gSpriteClips [ BUTTON_SPRITE_MOUSE_OVER_MOTION ].w = 190;
    gSpriteClips [ BUTTON_SPRITE_MOUSE_OVER_MOTION ].h = 49;
    
    // When mouse down
    gSpriteClips [ BUTTON_SPRITE_MOUSE_DOWN ].x = 190;
    gSpriteClips [ BUTTON_SPRITE_MOUSE_DOWN ].y = 49;
    gSpriteClips [ BUTTON_SPRITE_MOUSE_DOWN ].w = 190;
    gSpriteClips [ BUTTON_SPRITE_MOUSE_DOWN ].h = 45;
    
    // When mouse up
    gSpriteClips [ BUTTON_SPRITE_MOUSE_UP ].x = 0;
    gSpriteClips [ BUTTON_SPRITE_MOUSE_UP ].y = 0;
    gSpriteClips [ BUTTON_SPRITE_MOUSE_UP ].w = 190;
    gSpriteClips [ BUTTON_SPRITE_MOUSE_UP ].h = 49;
}

// get Button
LButton* SettingMenu::getButton( std::string name ){
    if ( buttons[ name ] == NULL )
        std::cout << "Unable to get " << name << " button !\n";
    return buttons[ name ];

}
// set First Language Text Texture
void SettingMenu::setFirstLanguageTextTexture( LTexture* gFirstLanguageTextTexture ){
    this->gFirstLanguageTextTexture = gFirstLanguageTextTexture;
}
// set Second Language Text Texture
void SettingMenu::setSecondLanguageTextTexture( LTexture* gSecondLanguageTextTexture ){
    this->gSecondLanguageTextTexture = gSecondLanguageTextTexture;
}
// set SettingMenuButtonSpriteSheet
void SettingMenu::setSettingMenuButtonSpriteSheet( LTexture* gSettingMenuButtonSpriteSheet ){
    this->gSettingMenuButtonSpriteSheet = gSettingMenuButtonSpriteSheet;
}
// set ReturnTextTexture
void SettingMenu::setReturnTextTexture( LTexture* gReturnTextTexture ){
    this->gReturnTextTexture = gReturnTextTexture;
}

// set SettingMenuTextTexture
void SettingMenu::setSettingMenuTextTexture( LTexture* gSettingMenuTextTexture ){
    this->gSettingMenuTextTexture = gSettingMenuTextTexture;
}

// get Setting Menu Text Texture
LTexture* SettingMenu::getSettingMenuTextTexture(){
    if ( !gSettingMenuTextTexture )
        std::cout << "Unable to get Setting Menu Text Texture !\n";
    return this->gSettingMenuTextTexture;
}

// get First Language Text Texture
LTexture* SettingMenu::getFirstLanguageTextTexture(){
    if ( !gFirstLanguageTextTexture )
        std::cout << "Unable to get Frist Language Text Texture !\n";
    return this->gFirstLanguageTextTexture;
}
// get Second Language Text Texture
LTexture* SettingMenu::getSecondLanguageTextTexture(){
    if ( !gSecondLanguageTextTexture )
        std::cout << "Unable to get Second Language Text Texture !\n";
    return this->gSecondLanguageTextTexture;
}
// get SettingMenuButtonSpriteSheet
LTexture* SettingMenu::getSettingMenuButtonSpriteSheet(){
    if ( !gSettingMenuButtonSpriteSheet )
        std::cout << "Unable to get SettingMenu Button SpriteSheet !\n";
    return gSettingMenuButtonSpriteSheet;
}
// get ReturnTextTexture
LTexture* SettingMenu::getReturnTextTexture(){
    if ( !gReturnTextTexture )
        std::cout << "Unable to get Return Text Texture !\n";
    return gReturnTextTexture;
}

SDL_Rect SettingMenu::getSpriteClips( LButtonSprite mCurrentSprite ){
    return gSpriteClips [ mCurrentSprite ];
}

// Default Destructor
SettingMenu::~SettingMenu(){
    
}
