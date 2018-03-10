//
//  MainMenu.cpp
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/21/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#include "../includes/MainMenu.h"

// the only instance
MainMenu* MainMenu::g_mainMenu = NULL;

// getInstance()
MainMenu* MainMenu::getInstance(){
    if ( !g_mainMenu )
        g_mainMenu = new MainMenu();
    return g_mainMenu;
}

// get PauseTextTexture
LTexture* MainMenu::getPauseTextTexture(){
    if ( !gPauseTextTexture )
        std::cout << "Unable to get gPauseTextTexture!\n";
    return gPauseTextTexture;
}

// get QuitTextTexture
LTexture* MainMenu::getQuitTextTexture(){
    if ( !gQuitTextTexture )
        std::cout << "Unable to get gQuitTextTexture!\n";
    return gQuitTextTexture;
}
// get StartTextTexture
LTexture* MainMenu::getStartTextTexture(){
    if ( !gStartTextTexture )
        std::cout << "Unable to get gStartTextTexture!\n";
    return gStartTextTexture;
}
// get MainMenuTextTexture
LTexture* MainMenu::getMainMenuTextTexture(){
    if ( !gMainMenuTextTexture )
        std::cout << "Unable to get gMainMenuTextTexture!\n";
    return gMainMenuTextTexture;
}
// get LanguageSetting
LTexture* MainMenu::getLanguageSettingTextTexture(){
    if ( !gLanguageSettingTextTexture )
        std::cout << "Unable to get gLanguageSettingTextTexture!\n";
    return gLanguageSettingTextTexture;
}

// getReturnTextTexture
LTexture* MainMenu::getReturnTextTexture(){
    if ( !gReturnTextTexture )
        std::cout << "Unable to get gReturnTextTexture!\n";
    return gReturnTextTexture;
}
// get MainMenuButtonSpriteSheet
LTexture* MainMenu::getMainMenuButtonSpriteSheet(){
    if ( !gMainMenuButtonSpriteSheet )
        std::cout << "Unable to get gMainMenuButtonSpriteSheet!\n";
    return gMainMenuButtonSpriteSheet;
}
// get Button
LButton* MainMenu::getButton( std::string name ){
    if ( buttons[name] == NULL)
        std::cout << "Unable to get " << name << " button !\n";
    return buttons[name];
}

// set PauseTextTexture
void MainMenu::setPauseTextTexture( LTexture* gPauseTextTexture ){
    this->gPauseTextTexture = gPauseTextTexture;
}
// set QuitTextTexture
void MainMenu::setQuitTextTexture( LTexture* gQuitTextTexture ){
    this->gQuitTextTexture = gQuitTextTexture;
}
// set StartTextTexture
void MainMenu::setStartTextTexture( LTexture* gStartTextTexture ){
    this->gStartTextTexture = gStartTextTexture;
}
// set MainMenuTextTexture
void MainMenu::setMainMenuTextTexture( LTexture* gMainMenuTextTexture ){
    this->gMainMenuTextTexture = gMainMenuTextTexture;
}
// set LanguageSetting
void MainMenu::setLanguageSettingTextTexture( LTexture* gLanguageSettingTextTexture ){
    this->gLanguageSettingTextTexture = gLanguageSettingTextTexture;
}
// set MainMenuButtonSpriteSheet
void MainMenu::setMainMenuButtonSpriteSheet( LTexture* gMainMenuButtonSpriteSheet ){
    this->gMainMenuButtonSpriteSheet = gMainMenuButtonSpriteSheet;
}

// set ReturnTextTexture
void MainMenu::setReturnTextTexture( LTexture* gReturnTextTexture ){
    this->gReturnTextTexture = gReturnTextTexture;
}

// Default destructor
MainMenu::~MainMenu(){
    // Now do nothing
}


// Default constructor
MainMenu::MainMenu(){
    // Init map
    // Start Button
    LButton* startButton = new LButton();
    startButton->setPosition( MAIN_MENU_START_BUTTON_POSITION_X, MAIN_MENU_START_BUTTON_POSITION_Y );
    buttons[ "start_button" ] = startButton;
    // Language Setting Button
    LButton* languageSettingButton = new LButton();
    languageSettingButton->setPosition( MAIN_MENU_LANGUAGE_SETTING_BUTTON_POSITION_X,
                                       MAIN_MENU_LANGUAGE_SETTING_BUTTON_POSITION_Y );
    buttons[ "language_setting_button" ] = languageSettingButton;
    
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

SDL_Rect MainMenu::getSpriteClips( LButtonSprite mCurrentSprite ){
    return gSpriteClips [ mCurrentSprite ];
}

