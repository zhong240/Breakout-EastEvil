//
//  DisplaySystem.cpp
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/18/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#include "../includes/DisplaySystem.h"

// Define the static variable
DisplaySystem* DisplaySystem::g_DisplaySystem = NULL;

// getInstance function
DisplaySystem* DisplaySystem::getInstance(){
    if (!g_DisplaySystem)
        g_DisplaySystem = new DisplaySystem();
    return g_DisplaySystem;
}

// Default Constructor
DisplaySystem::DisplaySystem(){
    // Now do nothing
}

// Default Destructor
DisplaySystem::~DisplaySystem(){
    // Now do nothing
}

// Init
bool DisplaySystem::init(){
    // Init all the parameters to the display
    // Initialization flag
    bool success = true;
    // First, init SDL
    if (SDL_Init( SDL_INIT_EVERYTHING ) < 0){
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << "\n";
        success = false;
    } else {
        //Create window
        gWindow = SDL_CreateWindow( "BreakOut", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN );

        // Check if Window did not create.
        if( gWindow == NULL ){
            std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << "\n";
            success = false;
        }

        //Create a Renderer to draw on
        gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
        // Check if Renderer did not create.
        if( gRenderer == NULL ){
            std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << "\n";
            success = false;
        } else {
            //Initialize renderer color
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                success = false;
            }

            //Initialize SDL_mixer
            if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
            {
                printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                success = false;
            }

            //Initialize SDL_ttf
            if( TTF_Init() == -1 )
            {
                printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                success = false;
            }
        }
    }
    // Load Media
    if ( !loadMedia() ){
        std::cout << "Unable to load Media!\n";
        success = false;
    }
    return success;
}

// LoadMedia
bool DisplaySystem::loadMedia(){
    // Loading success flag
    bool success = true;

//    // Load gFont
//    gFont = ResourceManager::getInstance()->loadTureTypeFontResource( gRenderer,
//                                                                     "../Assets/fonts/lazy.ttf",
//                                                                     30, "main_font" );
//    if ( gFont == NULL ){
//        std::cout << "Failed to load gFont!\n";
//        success = false;
//    }
//
//    // Load Ball textures
//    gBallTexture = ResourceManager::getInstance()->loadTextureResource( gRenderer,
//                                                                       "../Assets/images/ballGrey.png", "texture_ball" );
//    if ( gBallTexture == NULL ){
//        std::cout << "Failed to load gBallTexture!\n";
//        success = false;
//    }
//
//    // Load Brick textures
//    gBrickTexture = ResourceManager::getInstance()->loadTextureResource( gRenderer,
//                                                                        "../Assets/images/element_blue_rectangle.png",
//                                                                        "texture_brick" );
//
//    // Load Paddle textures
//    gPaddleTexture = ResourceManager::getInstance()->loadTextureResource( gRenderer,
//                                                                         "../Assets/images/paddleRed.png",
//                                                                         "texture_paddle" );
//    if ( gPaddleTexture == NULL ){
//        std::cout << "Failed to load gPaddleTexture!\n";
//        success = false;
//    }
    std::cout << "Resource Manager init gRenderer!\n";

    success = ResourceManager::getInstance()->init(gRenderer);

    gFont = ResourceManager::getInstance()->getTureTypeFontResource( "font_main" );
    if ( gFont == NULL ){
        std::cout << "Failed to load gFont!\n";
        success = false;
    }

    gBallTexture = ResourceManager::getInstance()->getTextureResource( "texture_ball" );
    if ( gBallTexture == NULL ){
        std::cout << "Failed to load gBallTexture!\n";
        success = false;
    }

    gBrickTexture = ResourceManager::getInstance()->getTextureResource( "texture_brick" );
    if ( gBrickTexture == NULL ){
        std::cout << "Failed to load gBrickTexture!\n";
        success = false;
    }

    gPaddleTexture = ResourceManager::getInstance()->getTextureResource( "texture_paddle" );
    if ( gPaddleTexture == NULL ){
        std::cout << "Failed to load gPaddleTexture!\n";
        success = false;
    }


    if ( !loadMainMenu() ){
        std::cout << "Failed to load MenuMenu!\n";
        success = false;
    }

    if ( !loadSettingMenu() ){
        std::cout << "Failed to load SettingMenu!\n";
        success = false;
    }

    return success;
}

// load MainMenu
bool DisplaySystem::loadMainMenu(){
    // Load MainMenu
    bool success = true;
    // The Main Menu text
    std::stringstream mainMenuText;
    // The Start Menu text
    std::stringstream startText;
    // The Quit Menu text
    std::stringstream quitText;
    // The Pause Menu text
    std::stringstream pauseText;
    // The Language Setting text
    std::stringstream languageSettingText;
    // The Return text
    std::stringstream returnText;

    // PauseTextTexture
    LTexture* gPauseTextTexture = new LTexture();
    // QuitTextTexture
    LTexture* gQuitTextTexture = new LTexture();
    // StartTextTexture
    LTexture* gStartTextTexture = new LTexture();
    // MainMeneu Texture
    LTexture* gMainMenuTextTexture = new LTexture();
    // Language Setting textures
    LTexture* gLanguageSettingTextTexture = new LTexture();
    // Button Sprite Sheet
    LTexture* gMainMenuButtonSpriteSheet = new LTexture();
    // Return Texture
    LTexture* gReturnTextTexture = new LTexture();

    // Set main menu text to be rendered
    mainMenuText.str( "" );
    mainMenuText << ResourceManager::getInstance()->getCurrentLanguageMap()["mainMenu"];
    if ( !gMainMenuTextTexture->loadFromRenderedText( mainMenuText.str().c_str(), textColor, gFont, gRenderer ) ){
        success = false;
        std::cout << "Unable to load Main Menu Text Texture!\n";
    }
    // set main texture in main menu
    MainMenu::getInstance()->setMainMenuTextTexture( gMainMenuTextTexture );

    // Set start text to be rendered
    startText.str( "" );
    startText << ResourceManager::getInstance()->getCurrentLanguageMap()["press2start"];
    if ( !gStartTextTexture->loadFromRenderedText( startText.str().c_str(), textColor, gFont, gRenderer ) ){
        success = false;
        std::cout << "Unable to load Start Text Texture!\n";
    }
    // set start texture in main menu
    MainMenu::getInstance()->setStartTextTexture( gStartTextTexture );

    // Set Quit text to be rendered
    quitText.str( "" );
    quitText << ResourceManager::getInstance()->getCurrentLanguageMap()["press2quit"];
    if ( !gQuitTextTexture->loadFromRenderedText( quitText.str().c_str(), textColor, gFont, gRenderer ) ){
        success = false;
        std::cout << "Unable to load Quit Text Texture!\n";
    }
    // set quit text in main menu
    MainMenu::getInstance()->setQuitTextTexture( gQuitTextTexture );

    // Set Pause text to be rendered
    pauseText.str( "" );
    pauseText << ResourceManager::getInstance()->getCurrentLanguageMap()["press2pause"];
    if ( !gPauseTextTexture->loadFromRenderedText( pauseText.str().c_str(), textColor, gFont, gRenderer ) ){
        success = false;
        std::cout << "Unable to load Pause Text Texture!\n";
    }
    // set pause texture in main menu
    MainMenu::getInstance()->setPauseTextTexture( gPauseTextTexture );

    // Set Return text to be rendered
    returnText.str( "" );
    returnText << ResourceManager::getInstance()->getCurrentLanguageMap()["back2menu"];
    if ( !gReturnTextTexture->loadFromRenderedText( returnText.str().c_str(), textColor, gFont, gRenderer ) ){
        success = false;
        std::cout << "Unable to load Return Text Texture!\n";
    }
    // set return texture in main menu
    MainMenu::getInstance()->setReturnTextTexture( gReturnTextTexture );

    // Set Language Setting to be rendered
    languageSettingText.str( "" );
    languageSettingText << ResourceManager::getInstance()->getCurrentLanguageMap()["setting"];
    if ( !gLanguageSettingTextTexture->loadFromRenderedText( languageSettingText.str().c_str(), textColor, gFont, gRenderer )){
        success = false;
        std::cout << "Unable to load Language Setting Text Texture!\n";
    }
    // set return texture in main menu

    MainMenu::getInstance()->setLanguageSettingTextTexture( gLanguageSettingTextTexture );

    // Set Main Menu Button Sprite Sheet
    gMainMenuButtonSpriteSheet = ResourceManager::getInstance()->getTextureResource( "texture_main_menu_button_sprite_sheet" );
    if ( !gMainMenuButtonSpriteSheet ){
        success = false;
        std::cout << "Unable to load Main Menu Button Sprite Sheet!\n";
    }
    MainMenu::getInstance()->setMainMenuButtonSpriteSheet( gMainMenuButtonSpriteSheet );

    return success;
}

// load SettingMenu
bool DisplaySystem::loadSettingMenu(){
    // Load SettingMenu
    bool success = true;
    // The Setting Menu text
    std::stringstream settingMenuText;
    // The First Language text
    std::stringstream firstLanguageText;
    // The Second Language text
    std::stringstream secondLanguageText;
    // The Return text
    std::stringstream returnText;

    // SettingMeneu Texture
    LTexture* gSettingMenuTextTexture = new LTexture();
    // First Language textures
    LTexture* gFirstLanguageTextTexture = new LTexture();
    // Second Language textures
    LTexture* gSecondLanguageTextTexture = new LTexture();
    // Button Sprite Sheet
    LTexture* gSettingMenuButtonSpriteSheet = new LTexture();
    // Return Texture
    LTexture* gReturnTextTexture = new LTexture();

    // Set setting menu text to be rendered
    settingMenuText.str( "" );
    settingMenuText <<ResourceManager::getInstance()->getCurrentLanguageMap()["setting"];
    if ( !gSettingMenuTextTexture->loadFromRenderedText( settingMenuText.str().c_str(), textColor, gFont, gRenderer ) ){
        success = false;
        std::cout << "Unable to load Setting Menu Text Texture!\n";
    }
    // set setting menu texture in setting menu
    SettingMenu::getInstance()->setSettingMenuTextTexture( gSettingMenuTextTexture );

    // Set Return text to be rendered
    returnText.str( "" );
    returnText << ResourceManager::getInstance()->getCurrentLanguageMap()["return"];
    if ( !gReturnTextTexture->loadFromRenderedText( returnText.str().c_str(), textColor, gFont, gRenderer ) ){
        success = false;
        std::cout << "Unable to load Return Text Texture!\n";
    }
    // set return texture in setting menu
    SettingMenu::getInstance()->setReturnTextTexture( gReturnTextTexture );

    // Set First Language to be rendered
    firstLanguageText.str( "" );
    firstLanguageText << ResourceManager::getInstance()->getCurrentLanguageMap()["english"];;
    if ( !gFirstLanguageTextTexture->loadFromRenderedText( firstLanguageText.str().c_str(), textColor, gFont, gRenderer )){
        success = false;
        std::cout << "Unable to load First Language Text Texture!\n";
    }
    // set return texture in setting menu

    SettingMenu::getInstance()->setFirstLanguageTextTexture( gFirstLanguageTextTexture );

    // Set First Language to be rendered
    secondLanguageText.str( "" );
    secondLanguageText << ResourceManager::getInstance()->getCurrentLanguageMap()["chinese"];
    if ( !gSecondLanguageTextTexture->loadFromRenderedText( secondLanguageText.str().c_str(), textColor, gFont, gRenderer )){
        success = false;
        std::cout << "Unable to load Second Language Text Texture!\n";
    }
    // set return texture in setting menu

    SettingMenu::getInstance()->setSecondLanguageTextTexture( gSecondLanguageTextTexture );

    // Set Setting Menu Button Sprite Sheet
    gSettingMenuButtonSpriteSheet = ResourceManager::getInstance()->getTextureResource( "texture_setting_menu_button_sprite_sheet" );
    if ( !gSettingMenuButtonSpriteSheet ){
        success = false;
        std::cout << "Unable to load Setting Menu Button Sprite Sheet!\n";
    }
    SettingMenu::getInstance()->setSettingMenuButtonSpriteSheet( gSettingMenuButtonSpriteSheet );

//    // SettingMeneu Texture
//    gSettingMenuTextTexture->free();
//    // First Language textures
//    gFirstLanguageTextTexture->free();
//    // Second Language textures
//    gSecondLanguageTextTexture->free();
//    // Button Sprite Sheet
//    gSettingMenuButtonSpriteSheet->free();
//    // Return Texture
//    gReturnTextTexture->free();

    return success;
}

// render Setting Menu
void DisplaySystem::renderSettingMenu( SDL_Event* event ){
    // Clear the Screen
    SDL_SetRenderDrawColor(gRenderer, 0x22,0x22,0x22,0xFF);
    SDL_RenderClear(gRenderer);

    SettingMenu::getInstance()->getButton( "first_language_button" )->handleEvent( event );
    SettingMenu::getInstance()->getButton( "second_language_button" )->handleEvent( event );
    SettingMenu::getInstance()->getButton( "return_button" )->handleEvent( event );
    // Render Buttons
    SettingMenu::getInstance()->getButton( "first_language_button" )->render(
                                                                 SettingMenu::getInstance()->getSettingMenuButtonSpriteSheet(), gRenderer,
                                                                 SettingMenu::getInstance()->getSpriteClips( SettingMenu::getInstance()->getButton( "first_language_button" )->getCurrentSprite()) );
    SettingMenu::getInstance()->getButton( "second_language_button" )->render(
                                                                            SettingMenu::getInstance()->getSettingMenuButtonSpriteSheet(), gRenderer,
                                                                            SettingMenu::getInstance()->getSpriteClips( SettingMenu::getInstance()->getButton( "second_language_button" )->getCurrentSprite() ) );
    SettingMenu::getInstance()->getButton( "return_button" )->render(
                                                                              SettingMenu::getInstance()->getSettingMenuButtonSpriteSheet(), gRenderer,
                                                                              SettingMenu::getInstance()->getSpriteClips( SettingMenu::getInstance()->getButton( "return_button" )->getCurrentSprite() ) );

    // First, render setting menu texture
    SettingMenu::getInstance()->getSettingMenuTextTexture()->render( SETTING_MENU_TEXTURE_POSITION_X -
                                                              SettingMenu::getInstance()->getSettingMenuTextTexture()->getWidth()
                                                              / 2.0,
                                                              SETTING_MENU_TEXTURE_POSITION_Y -
                                                              SettingMenu::getInstance()->getSettingMenuTextTexture()->getHeight()
                                                              / 2.0,
                                                              gRenderer );

    // Then, render return texture
    SettingMenu::getInstance()->getReturnTextTexture()->render(
                                                            SETTING_MENU_RETURN_BUTTON_TEXT_TEXTURE_POSITION_X -
                                                            SettingMenu::getInstance()->getReturnTextTexture()->getWidth() / 2.0,
                                                            SETTING_MENU_RETURN_BUTTON_TEXT_TEXTURE_POSITION_Y -
                                                            SettingMenu::getInstance()->getReturnTextTexture()->getHeight() / 2.0,
                                                            gRenderer );

    // Then, render First Language texture
    SettingMenu::getInstance()->getFirstLanguageTextTexture()->render(
                                                                     FIRST_LANGUAGE_TEXT_TEXTURE_POSITION_X -
                                                                     SettingMenu::getInstance()->getFirstLanguageTextTexture()->getWidth()
                                                                     / 2.0,
                                                                     FIRST_LANGUAGE_TEXT_TEXTURE_POSITION_Y -
                                                                     SettingMenu::getInstance()->getFirstLanguageTextTexture()->getHeight()
                                                                     / 2.0,
                                                                     gRenderer );
    // Then, render Second Language texture
    SettingMenu::getInstance()->getSecondLanguageTextTexture()->render(
                                                                      SECOND_LANGUAGE_TEXT_TEXTURE_POSITION_X -
                                                                      SettingMenu::getInstance()->getSecondLanguageTextTexture()->getWidth()
                                                                      / 2.0,
                                                                      SECOND_LANGUAGE_TEXT_TEXTURE_POSITION_Y -
                                                                      SettingMenu::getInstance()->getSecondLanguageTextTexture()->getHeight()
                                                                      / 2.0,
                                                                      gRenderer );

    //Update screen of our specified window
    SDL_GL_SwapWindow(getSDLWindow());

}


// render Main Menu
void DisplaySystem::renderMainMenu( SDL_Event* event ){
    // Clear the Screen
    SDL_SetRenderDrawColor(gRenderer, 0x22,0x22,0x22,0xFF);
    SDL_RenderClear(gRenderer);

    MainMenu::getInstance()->getButton( "start_button" )->handleEvent( event );
    MainMenu::getInstance()->getButton( "language_setting_button" )->handleEvent( event );
    // Render Buttons
    MainMenu::getInstance()->getButton( "start_button" )->render(
            MainMenu::getInstance()->getMainMenuButtonSpriteSheet(), gRenderer,
            MainMenu::getInstance()->getSpriteClips( MainMenu::getInstance()->getButton( "start_button" )->getCurrentSprite()) );
    MainMenu::getInstance()->getButton( "language_setting_button" )->render(
            MainMenu::getInstance()->getMainMenuButtonSpriteSheet(), gRenderer,
            MainMenu::getInstance()->getSpriteClips( MainMenu::getInstance()->getButton( "language_setting_button" )->getCurrentSprite() ) );

    // First, render main menu texture
    MainMenu::getInstance()->getMainMenuTextTexture()->render( MAIN_MENU_TEXTURE_POSITION_X -
                                                              MainMenu::getInstance()->getMainMenuTextTexture()->getWidth()
                                                              / 2.0,
                                                              MAIN_MENU_TEXTURE_POSITION_Y -
                                                              MainMenu::getInstance()->getMainMenuTextTexture()->getHeight()
                                                              / 2.0,
                                                              gRenderer );

    // Then, render start texture
    MainMenu::getInstance()->getStartTextTexture()->render(
                                                           START_TEXT_TEXTURE_POSITION_X -
                                                           MainMenu::getInstance()->getStartTextTexture()->getWidth() / 2.0,
                                                           START_TEXT_TEXTURE_POSITION_Y -
                                                           MainMenu::getInstance()->getStartTextTexture()->getHeight() / 2.0,
                                                           gRenderer );

    // Then, render quit texture
    MainMenu::getInstance()->getQuitTextTexture()->render( QUIT_TEXT_TEXTURE_POSITION_X -
                                                          MainMenu::getInstance()->getQuitTextTexture()->getWidth() / 2.0,
                                                          QUIT_TEXT_TEXTURE_POSITION_Y -
                                                          MainMenu::getInstance()->getQuitTextTexture()->getHeight() / 2.0,
                                                          gRenderer );
    // Then, render pause texture
    MainMenu::getInstance()->getPauseTextTexture()->render(
                                                           PAUSE_TEXT_TEXTURE_POSITION_X -
                                                           MainMenu::getInstance()->getPauseTextTexture()->getWidth() / 2.0,
                                                           PAUSE_TEXT_TEXTURE_POSITION_Y -
                                                           MainMenu::getInstance()->getPauseTextTexture()->getHeight() / 2.0,
                                                           gRenderer );
    // Then, render return texture
    MainMenu::getInstance()->getReturnTextTexture()->render(
                                                            RETURN_TEXT_TEXTURE_POSITION_X -
                                                            MainMenu::getInstance()->getReturnTextTexture()->getWidth() / 2.0,
                                                            RETURN_TEXT_TEXTURE_POSITION_Y -
                                                            MainMenu::getInstance()->getReturnTextTexture()->getHeight() / 2.0,
                                                            gRenderer );

    // Then, render Language Setting texture
    MainMenu::getInstance()->getLanguageSettingTextTexture()->render(
                                                                     LANGUAGE_SETTING_TEXT_TEXTURE_POSITION_X -
                                                                     MainMenu::getInstance()->getLanguageSettingTextTexture()->getWidth()
                                                                     / 2.0,
                                                                     LANGUAGE_SETTING_TEXT_TEXTURE_POSITION_Y -
                                                                     MainMenu::getInstance()->getLanguageSettingTextTexture()->getHeight()
                                                                     / 2.0,
                                                                     gRenderer );

    //Update screen of our specified window
    SDL_GL_SwapWindow(getSDLWindow());

}

// render Pause Menu
void DisplaySystem::renderPauseMenu(){
    // Clear the Screen
    SDL_SetRenderDrawColor(gRenderer, 0x22,0x22,0x22,0xFF);
    SDL_RenderClear(gRenderer);
    // The Pause Menu Text
    std::stringstream pauseMenuText;
    // The Resume Menu text
    std::stringstream resumeText;

    // Set pause menu text to be rendered
    pauseMenuText.str( "" );
    pauseMenuText << ResourceManager::getInstance()->getCurrentLanguageMap()["gamePause"];;
    if ( !gPauseMenuTexture->loadFromRenderedText( pauseMenuText.str().c_str(), textColor, gFont, gRenderer ) ){
        std::cout << "Unable to render Pause Menu Text Texture!\n";
    }

    // Set resume text to be rendered
    resumeText.str( "" );
    resumeText << ResourceManager::getInstance()->getCurrentLanguageMap()["press2resume"];;
    if ( !gResumeTextTexture->loadFromRenderedText( resumeText.str().c_str(), textColor, gFont, gRenderer ) ){
        std::cout << "Unable to render Resume Text Texture!\n";
    }

    // Then, render pause texture
    gPauseMenuTexture->render( PAUSE_MENU_TEXTURE_POSITION_X - gPauseMenuTexture->getWidth() / 2.0,
                              PAUSE_MENU_TEXTURE_POSITION_Y - gPauseMenuTexture->getHeight() / 2.0,
                              gRenderer );
    // Then, render resume texture
    gResumeTextTexture->render( RESUME_TEXT_TEXTURE_POSITION_X - gResumeTextTexture->getWidth() / 2.0,
                               RESUME_TEXT_TEXTURE_POSITION_Y - gResumeTextTexture->getHeight() / 2.0,
                               gRenderer );

    //Update screen of our specified window
    SDL_GL_SwapWindow(getSDLWindow());
}

// update
void DisplaySystem::update(){
    // Clear the Screen
    SDL_SetRenderDrawColor(gRenderer, 0x22,0x22,0x22,0xFF);
    SDL_RenderClear(gRenderer);
    // In DisplaySystem::update() function, we update the text texture,
    // and we check if the game is lose or win.
    // The life text
    std::stringstream lifeText;
    // The Score text
    std::stringstream scoreText;
    // The Level text
    std::stringstream levelText;
    // The Win text
    std::stringstream winText;
    // The Lose text
    std::stringstream loseText;

    // Set life text to be rendered
    lifeText.str( "" );
    lifeText << ResourceManager::getInstance()->getCurrentLanguageMap()["life"] << " : " << GameSetting::getInstance()->getLife();
    if ( !gLifeTextTexture->loadFromRenderedText( lifeText.str().c_str(), textColor, gFont, gRenderer ) ){
        std::cout << "Unable to render Life Text Texture!\n";
    }

    // Set score text to be rendered
    scoreText.str( "" );
    scoreText << ResourceManager::getInstance()->getCurrentLanguageMap()["score"] << " : " << ScoreSystem::getInstance()->getScore();
    if ( !gScoreTextTexture->loadFromRenderedText( scoreText.str().c_str(), textColor, gFont, gRenderer ) ){
        std::cout << "Unable to render Score Text Texture!\n";
    }

    // Set level text to be rendered
    levelText.str( "" );
    levelText << ResourceManager::getInstance()->getCurrentLanguageMap()["level"] << " : " << GameSetting::getInstance()->getLevel();
    if ( !gLevelTextTexture->loadFromRenderedText( levelText.str().c_str(), textColor, gFont, gRenderer ) ){
        std::cout << "Unable to render Level Text Texture!\n";
    }

    // Set win text to be rendered
    winText.str( "" );
    winText << ResourceManager::getInstance()->getCurrentLanguageMap()["winMessage"];
    if ( !gWinTextTexture->loadFromRenderedText( winText.str().c_str(), textColor, gFont, gRenderer ) ){
        std::cout << "Unable to render Win Text Texture!\n";
    }

    // Set lose text to be rendered
    loseText.str( "" );
    loseText << ResourceManager::getInstance()->getCurrentLanguageMap()["loseMessage"];
    if ( !gLoseTextTexture->loadFromRenderedText( loseText.str().c_str(), textColor, gFont, gRenderer ) ){
        std::cout << "Unable to render Lose Text Texture!\n";
    }

    // First, check if the game is lose
    if ( PlaySystem::getInstance()->isLose() ){
        // Game Over
        renderLose();
        // Reset the game setting
        GameSetting::getInstance()->init();
        // Reset the score
        ScoreSystem::getInstance()->reset();
        //std::cout << "init\n";
        // Reset the win / lose state.
        PlaySystem::getInstance()->reset();
        return;
    }
    // Second, check if the game is win
    if ( PlaySystem::getInstance()->isWin() ){
        // All bricks are removed
        renderWin();
        if ( GameSetting::getInstance()->getLevel() != 0 ){
            // there are more levels available
            // // the Game level is not more than max
            // if ( GameSetting::getInstance()->getLevel() == 2){
            //     GameSetting::getInstance()->initLevelTwo();
            // } else{
            //     GameSetting::getInstance()->initLevelThree();
            // }
            GameSetting::getInstance()->initLevel();
        } else {
            // No more levels available, restart the game
            GameSetting::getInstance()->init();
            // Reset the score;
            ScoreSystem::getInstance()->reset();
        }
        // Reset the win / lose state.
        PlaySystem::getInstance()->reset();
        return;
    }
    // Then, if the game is running, render
    render();
}

// render()
void DisplaySystem::render(){
    // in render function, we need to render all the objects and text we need
    // First, render the paddle
    gPaddleTexture->render( GameSetting::getInstance()->getPaddle()->getPosition()[0] - PADDLE_INITIAL_SIZE_X / 2.0,
                          GameSetting::getInstance()->getPaddle()->getPosition()[1] - PADDLE_INITIAL_SIZE_Y / 2.0,
                          gRenderer );

    // Second, render the ball
    gBallTexture->render( GameSetting::getInstance()->getBall()->getPosition()[0] - BALL_RADIUS / 2.0,
                        GameSetting::getInstance()->getBall()->getPosition()[1] - BALL_RADIUS / 2.0,
                        gRenderer );
    //std::cout << GameSetting::getInstance()->getBall().getPosition()[0] << " " << GameSetting::getInstance()->getBall().getPosition()[1] << endl;
    // Third, render all the bricks
    for (int i = 0; i < GameSetting::getInstance()->getBrick().size(); i++){
        if ( GameSetting::getInstance()->getBrick()[i]->getState() == IS_ALIVE )
            gBrickTexture->render( GameSetting::getInstance()->getBrick()[i]->getPosition()[0] - BRICK_INITIAL_WIDTH / 2.0,
                                 GameSetting::getInstance()->getBrick()[i]->getPosition()[1] - BRICK_INITIAL_HEIGHT / 2.0,
                                 gRenderer );
    }
    // Then, render life texture
    gLifeTextTexture->render( LIFE_TEXTURE_POSITION_X - gLifeTextTexture->getWidth() / 2.0,
                             LIFE_TEXTURE_POSITION_Y - gLifeTextTexture->getHeight() / 2.0,
                             gRenderer );
    // Then, render score texture
    gScoreTextTexture->render( SCORE_TEXTURE_POSITION_X - gScoreTextTexture->getWidth() / 2.0,
                              SCORE_TEXTURE_POSITION_Y - gScoreTextTexture->getHeight() / 2.0,
                              gRenderer );
    // Then, render level texture
    gLevelTextTexture->render( LEVEL_TEXTURE_POSITION_X - gLevelTextTexture->getWidth() / 2.0,
                              LEVEL_TEXTURE_POSITION_Y - gLevelTextTexture->getHeight() / 2.0,
                              gRenderer );
    //Update screen of our specified window
    SDL_GL_SwapWindow(getSDLWindow());
}

// renderLose
void DisplaySystem::renderLose(){
    // In renderLose function, we just need to render the lose text
    gLoseTextTexture->render( LOSE_TEXTURE_POSITION_X - gLoseTextTexture->getWidth() / 2.0,
                             LOSE_TEXTURE_POSITION_Y - gLoseTextTexture->getHeight() / 2.0,
                             gRenderer );
    //Update screen of our specified window
    SDL_GL_SwapWindow(getSDLWindow());
    Mix_PlayChannel(-1, ResourceManager::getInstance()->getChunkResource("sound_gameover"), 0);
    // When game lose, wait for 1 s
    SDL_Delay( 1000 );
}

// renderWin
void DisplaySystem::renderWin(){
    // In renderWin function, we just need to render the win text
    gWinTextTexture->render( WIN_TEXTURE_POSITION_X - gWinTextTexture->getWidth() / 2.0,
                            WIN_TEXTURE_POSITION_Y - gWinTextTexture->getHeight() / 2.0,
                            gRenderer );
    //Update screen of our specified window
    SDL_GL_SwapWindow(getSDLWindow());
    // When game wins, wait for 1 s
    SDL_Delay( 1000 );
}

// quit
bool DisplaySystem::quit(){
    bool success = true;
    // Destroy Renderer
    SDL_DestroyRenderer( gRenderer );
    //Destroy window
    SDL_DestroyWindow( gWindow );
    // Point gWindow to NULL to ensure it points to nothing.
    gRenderer = NULL;
    gWindow = NULL;
    TTF_CloseFont(gFont);
    gFont = NULL;
    //Quit SDL subsystems
    SDL_Quit();
    return success;
}

SDL_Window* DisplaySystem::getSDLWindow(){
    return this->gWindow;
}

SDL_Renderer* DisplaySystem::getSDLRenderer(){
    return this->gRenderer;
}
