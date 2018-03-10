//
//  CollisionSystem.h
//  BreakoutGame
//
//  Created by Tianxiang Dai on 2/4/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#ifndef CollisionSystem_h
#define CollisionSystem_h
#include "System.h"
#include "GameSetting.h"
#include <iostream>

/**
 * @brief This class sets up the collision system
 *
 * Singleton design pattern is applied. There is only one collision system
 * for one game.
 */
class CollisionSystem: public System{
public:
    /**
     * @brief Get the only instance of collision system
     */
    static CollisionSystem* getInstance();
    /**
     * @brief Destructor
     */
    ~CollisionSystem();
    /**
     * @brief Initialize the collision system
     */
    bool init();
    /**
     * @brief Detect collision at every frame
     *
     * This function is called every frame to detect possible collisions between
     * the ball with the paddle, the ball with four walls, and the ball with
     * bricks
     */
    void update();
    /**
     * @brief Quit the collision system
     */
    bool quit();

private:
    /**
     * @brief Private constructor
     *
     * For a Singleton class the constructor is never used.
     */
    CollisionSystem();
    /**
     * @brief The only instance of collision system
     */
    static CollisionSystem* g_CollisionSystem;
};


#endif /* CollisionSystem_h */
