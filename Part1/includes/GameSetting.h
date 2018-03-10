//
//  GameSetting.h
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/4/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#ifndef GameSetting_h
#define GameSetting_h

#include <vector>
#include "Vector2D.h"
#include "Constants.h"
#include "Ball.h"
#include "Brick.h"
#include "Boundary.h"
#include "Paddle.h"
#include "DisplaySystem.h"
#include "System.h"
#include <map>
#include <stddef.h>
#include <string>

/**
 * @brief This class defines the game setting.
 * 
 * Applied Singleton Design Pattern
 */
class GameSetting: public System{
public:
    /**
     * @brief Get the only distance
     */
    static GameSetting* getInstance();
    //static map<string, int> ControlSchemes;
    
    enum ControlSchemes { /**< set of keys that a player can use for movement */
        WASD,
        IJKL,
        ArrowKeys
    };
    static ControlSchemes CurrentPlayerControlSchemes[];
    /**
     * @brief Set the player number
     */
    void setPlayerNum(int pn);
    /**
     * @brief Get the player number
     */
    int getPlayerNum();
    /**
     * @brief Destructor
     */
    ~GameSetting();
    /**
     * @brief Initialization
     */
    bool init();
    /**
     * @brief Quit
     */
    bool quit();
    /**
     * @brief Update the player movement at every frame
     */
    void update();
    /**
     * @brief Load brick position from file
     */
    bool loadBrickPosition();
    /**
     * @brief Init level info
     */
    bool initLevel();

    // // InitLevelOne
    // bool initLevelOne();
    // // InitLevelTwo
    // bool initLevelTwo();
    // // InitLevelThree
    // bool initLevelThree();
    // Win
    void win();
    // Lose
    void lose();
    /**
     * @brief Get the ball of the game
     */
    Ball* getBall();
    /**
     * @brief Get a vector of all bricks of the game
     */
    std::vector<Brick*> getBrick();
    /**
     * @brief Get the paddle of the game
     */
    Paddle* getPaddle();
    /**
     * @brief Get the boundary of the game
     */
    std::vector<Wall*> getBoundary();

    /**
     * @brief Set level
     */
    void setLevel( int level );
    /**
     * @brief Set life
     */
    void setLife( int life );
    // set Score
    //void setScore( long int score );
    
    /**
     * @brief Get current level
     */
    int getLevel();
    /**
     * @brief Get the number of lives that the player has
     */
    int getLife();
    // get Score
    //long int getScore();
    
    /**
     * @brief Reset score to default
     */
    void resetScore();
    /**
     * @brief Reset level to default
     */
    void resetLevel();
    /**
     * @brief Reset level to default
     */
    void resetLife();
    /**
     * @brief Reset ball to original state
     */
    void resetBall();

private:
    /**
     * @brief Private constructor
     */
    GameSetting();

    static GameSetting* g_gameSetting; /**< the only instance */
    
    int playerNum = 1; /**< the player number */
    
    Ball* ball; /**< the Ball in the game */
    
    std::vector<Brick*> brick; /**< the vector of the Bricks in the game */
    
    std::vector<Vector2D> brickPosition; /**< the vector of brick position */
  
    std::vector<Wall*> boundary; /**< the Boundary in the game */
    
    Paddle* paddle; /**< the Paddle in the game */
    
    int level; /**< the Level in the game */

    // the Score in the game
    //long int score;
    
    int life; /**< the Life in the game */

};

#endif /* GameSetting_h */
