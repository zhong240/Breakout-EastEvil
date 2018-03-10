//
//  ScoreSystem.h
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/21/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#ifndef ScoreSystem_h
#define ScoreSystem_h

#include <stddef.h>
#include "System.h"

/**
 * @brief This class sets up the score system.
 *
 * Applied Singleton Design Pattern
 */
class ScoreSystem: public System{
public:
    /**
     * @brief Get the only instance
     */
    static ScoreSystem* getInstance();
    /**
     * @brief Default destructor
     */
    ~ScoreSystem();
    /**
     * @brief Set score
     */
    void setScore( long int score );
    /**
     * @brief Initialization
     */
    bool init();
    /**
     * @brief Update the score at every frame
     */
    void update();
    /**
     * @brief Quit score system
     */
    bool quit();
    /**
     * @brief Get score
     */
    long int getScore();
    /**
     * @brief Reset score
     */
    void reset();

private:
    static ScoreSystem* g_scoreSystem; /** the only instance */
    /**
     * @brief Default constructor
     */
    ScoreSystem();
    long int score; /**< current score */
};


#endif
