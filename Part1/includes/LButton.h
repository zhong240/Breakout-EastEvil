//
//  LButton.h
//  BreakoutGame
//
//  Created by Tianxiang Dai on 2/21/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

// The mouse button

#ifndef LButton_h
#define LButton_h

#include <SDL2/SDL.h>
#include "LTexture.h"
#include "Constants.h"

enum LButtonSprite /**< Possible events for button */
{
    BUTTON_SPRITE_MOUSE_OUT = 0,
    BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
    BUTTON_SPRITE_MOUSE_DOWN = 2,
    BUTTON_SPRITE_MOUSE_UP = 3,
    BUTTON_SPRITE_TOTAL = 4
};

/**
 * @brief This class defines button pressing event.
 */
class LButton {
public:
    /**
     * @brief Initializes internal variables
     */
    LButton();
    
    /**
     * @brief Defualt Destructor
     */
    ~LButton();
    
    /**
     * @brief Sets top left position
     */
    void setPosition( int x, int y );
    
    /**
     * @brief Get the currentSprite
     */
    LButtonSprite getCurrentSprite();
    
    /**
     * @brief Set the currentSprite
     */
    void setCurrentSprite( LButtonSprite sprite );
    
    /**
     * @brief Handles mouse event
     */
    void handleEvent( SDL_Event* e );
    
    /**
     * @brief Shows button sprite
     * @param gButtonSpriteSheetTexture the texture to render
     * @param renderer the renderer to render texture
     * @param clip the clip
     */
    void render( LTexture* gButtonSpriteSheetTexture, SDL_Renderer* renderer, SDL_Rect clip );
    
private:

    
    //Top left position
    SDL_Point mPosition;
    
    //Currently used global sprite
    LButtonSprite mCurrentSprite;
};

#endif
