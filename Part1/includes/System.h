//
//  System.h
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/18/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#ifndef System_h
#define System_h

/**
 * @brief This class defines the base class for all systems used in the game.
 */
class System{
public:
    /**
     * @brief Initialization
     */
    virtual bool init()=0;
    /**
     * @brief Quit
     */
    virtual bool quit()=0;
    /**
     * @brief Update
     */
    virtual void update()=0;
};

#endif
