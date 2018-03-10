//
//  MainProgram.cpp
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/4/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#include "../includes/MainProgram.h"
MainProgram* MainProgram::g_mainProgram = NULL;

// getInstance()
MainProgram* MainProgram::getInstance(){
    if ( !g_mainProgram )
        g_mainProgram = new MainProgram();
    return g_mainProgram;
}

// Constructor
MainProgram::MainProgram(){
    // Do Nothing
}

// Destructor
MainProgram::~MainProgram(){
    // Do Nothing
}

// Init the program
bool MainProgram::init(){
    bool success = true;
    // In init function of main program, init each subsystem
    // Init GameSetting
    if ( !GameSetting::getInstance()->init() ){
        std::cout << "Unable to init GameSetting subsystem!\n";
        success = false;
    }
    std::cout << "Init ResourceManager ! \n";
    // Init ResourceManager
    if ( !ResourceManager::getInstance()->init() ){
        std::cout << "Unable to init ResourceManager subsystem!\n";
        success = false;
    }
    std::cout << "Init ControlSystem ! \n";
    // Init Control System
    if ( !ControlSystem::getInstance()->init() ){
        std::cout << "Unable to init ControlSystem subsystem!\n";
        success = false;
    }
    // Init PlaySystem
    if ( !PlaySystem::getInstance()->init() ){
        std::cout << "Unable to init PlaySystem subsystem!\n";
        success = false;
    }
    // Init Collision System
    if ( !CollisionSystem::getInstance()->init() ){
        std::cout << "Unable to init CollisionSystem subsystem!\n";
        success = false;
    }

    // Init DisplaySystem
    if ( !DisplaySystem::getInstance()->init() ){
        std::cout << "Unable to init DisplaySystem subsystem!\n";
        success = false;
    }
    cout << "Init DisplaySystem !\n";
    return success;
}

// Run the program
void MainProgram::run(){
    // Now do nothing, loop
    Mix_PlayMusic( ResourceManager::getInstance()->getMixMusicResource("music_background"), -1 );
    loop();
}


// Per frame update
void MainProgram::update(){
    // Update each subsystem
    // ControlSystem
//    ControlSystem::getInstance()->update();
    // PlaySystem
    PlaySystem::getInstance()->update();
    // DisplaySystem
    DisplaySystem::getInstance()->update();
    // CollisionSystem
    CollisionSystem::getInstance()->update();
}

// Loop that runs forever
void MainProgram::loop(){
    //while( ControlSystem::getInstance()->getInputs() != QUIT ){
    //The frames per second timer
    LTimer fpsTimer;
    //The frames per second cap timer
    LTimer capTimer;
    //Start counting frames per second
    int countedFrames = 0;
    fpsTimer.start();
    running = true;
    main = true;
    setting = true;
    bool pause = false;
    while( running ){
        //Start cap timer
        capTimer.start();
        //Calculate and correct fps
        float avgFPS = countedFrames / ( fpsTimer.getTicks() / 1000.f );
        if( avgFPS > 2000000 )
        {
            avgFPS = 0;
        }
        SDL_Event event;

        if (countedFrames == 0){
            mainMenuLoop( &event );
//            bool menu = true;
//            while(menu){
//                while(SDL_PollEvent(&event)){
//                    DisplaySystem::getInstance()->renderMainMenu( event );
//                    switch(event.type){
//                            if (event.key.keysym.sym == SDLK_q){
//                                menu = false;
//                                running = false;
//                                break;
//                            }
//                    }
//                    if ( MainMenu::getInstance()->getButton( "start_button" )->getCurrentSprite() == BUTTON_SPRITE_MOUSE_UP ){
//                        menu = false;
//                        break;
//                    }
//                    if ( MainMenu::getInstance()->getButton( "start_button" )->getCurrentSprite() == BUTTON_SPRITE_MOUSE_UP ){
//                        menu = false;
//                        break;
//                    }
//                }
//            }
        }
        
        while(SDL_PollEvent(&event) || pause)
        {
            
            switch(event.type)
            {
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_q)
                        running = false;
                    else if (event.key.keysym.sym == SDLK_SPACE){
                        DisplaySystem::getInstance()->renderPauseMenu();
                        pause = !pause;
                    } else if (event.key.keysym.sym == SDLK_ESCAPE){
                        GameSetting::getInstance()->init();
                        loop();
                        return;
                    }
                    else ControlSystem::getInstance()->update(event);
                    
                case SDL_KEYUP:
                    ControlSystem::getInstance()->update(event);
            }
            
            if (!running) break;
            if (pause) continue;
        }
        
        update();
        
        ++countedFrames;
        
        //If frame finished early
        int frameTicks = capTimer.getTicks();
        if( frameTicks < screenTickPerFrame )
        {
            //Wait remaining time
            SDL_Delay( screenTickPerFrame - frameTicks );
        }
    }
    //}
    quit();
}
// Pause
void MainProgram::pause(){
    
}

// setting menu Loop
void MainProgram::settingMenuLoop( SDL_Event* event ){
    setting = true;
    while( setting )
        while( SDL_PollEvent( event )){
            DisplaySystem::getInstance()->renderSettingMenu( event );
            switch( event->type ){
                case SDL_KEYDOWN:
                    if ( event->key.keysym.sym == SDLK_q){
                        running = false;
                        main = false;
                        return;
                    }
            }
            if ( SettingMenu::getInstance()->getButton( "return_button" )->getCurrentSprite() == BUTTON_SPRITE_MOUSE_UP ){
                SettingMenu::getInstance()->getButton( "return_button" )->setCurrentSprite( BUTTON_SPRITE_MOUSE_OUT );
                std::cout << "Setting Menu Return Button pressed!\n";
                return;
            }
            if ( SettingMenu::getInstance()->getButton( "first_language_button" )->getCurrentSprite() == BUTTON_SPRITE_MOUSE_UP ){
                SettingMenu::getInstance()->getButton( "first_language_button" )->setCurrentSprite( BUTTON_SPRITE_MOUSE_OUT );
                
                if (ResourceManager::getInstance()->getCurrentLanguageMap()["life"] != "Life"){
                    ResourceManager::getInstance()->setCurrentLanguageMap("english");
                    DisplaySystem::getInstance()->loadMainMenu();
                    DisplaySystem::getInstance()->loadSettingMenu();
                // change language
                }
            }
            if ( SettingMenu::getInstance()->getButton( "second_language_button" )->getCurrentSprite() == BUTTON_SPRITE_MOUSE_UP ){
                SettingMenu::getInstance()->getButton( "second_language_button" )->setCurrentSprite( BUTTON_SPRITE_MOUSE_OUT );
                if (ResourceManager::getInstance()->getCurrentLanguageMap()["life"] == "Life"){

                    ResourceManager::getInstance()->setCurrentLanguageMap("chinese");
                    DisplaySystem::getInstance()->loadMainMenu();
                    DisplaySystem::getInstance()->loadSettingMenu();
                // change language
                }
            }
        }
}

// main menu Loop
void MainProgram::mainMenuLoop( SDL_Event* event ){
    main = true;
    while( main ){
        while(SDL_PollEvent( event )){
            DisplaySystem::getInstance()->renderMainMenu( event );
            switch(event->type){
                case SDL_KEYDOWN:
                    if (event->key.keysym.sym == SDLK_q){
                        running = false;
                        return;
                    }
            }
            if ( MainMenu::getInstance()->getButton( "start_button" )->getCurrentSprite() == BUTTON_SPRITE_MOUSE_UP ){
                std::cout << "Main Menu Start Button pressed!\n";
                MainMenu::getInstance()->getButton( "start_button" )->setCurrentSprite( BUTTON_SPRITE_MOUSE_OUT );
                return;
            }
            if ( MainMenu::getInstance()->getButton( "language_setting_button" )->getCurrentSprite() == BUTTON_SPRITE_MOUSE_UP ){
                std::cout << "Main Menu Setting Button pressed!\n";
                MainMenu::getInstance()->getButton( "language_setting_button" )->setCurrentSprite( BUTTON_SPRITE_MOUSE_OUT );
                settingMenuLoop( event );
                if (main == false)
                    return;
            }
        }
    }
}

// Resume
void MainProgram::resume(){
    
}

// Quit
bool MainProgram::quit(){
    bool success;
    return success;
}
