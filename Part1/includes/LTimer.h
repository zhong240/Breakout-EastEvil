//
//  LTimer.h
//  BreakoutGame
//
//  Created by Tianxiang Dai on 1/30/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#ifndef LTimer_h
#define LTimer_h

#include <SDL2/SDL.h>

/**
 * @brief This class defines the timer used for the game.
 */
class LTimer {
public:
    /**
     * @brief Initializes variables
     */
    LTimer();

    /**
     * @brief Start the timer
     */
    void start();
    /**
     * @brief  Stop the timer
     */
    void stop();
    /**
     * @brief Pause the timer
     */
    void pause();
    /**
     * @brief Unpause the timer
     */
    void unpause();

    /**
     * @brief Get the current ticks
     */
    Uint32 getTicks();

    /**
     * @brief Check whether the timer has started
     */
    bool isStarted();
    /**
     * @brief Check whether the timer is paused
     */
    bool isPaused();

private:
    Uint32 mStartTicks; /**< The clock time when the timer starts */

    Uint32 mPausedTicks; /**< The ticks passed when the timer is paused */

    bool mPaused; /**< Whether the timer is paused */
    bool mStarted; /**< Whether the timer has started */
};

#endif /* LTimer_h */
