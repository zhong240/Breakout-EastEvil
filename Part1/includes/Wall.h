//
//  Wall.h
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/16/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#ifndef Wall_h
#define Wall_h

#include "GameObject.h"
#include "Collider.h"
#include "Constants.h"
#include "Vector2D.h"

/**
 * @brief This class defines the wall of the game.
 */
class Wall: public GameObject, public Collider{
public:
    /**
     * @brief Default constructor
     */
    Wall();
    /**
     * @brief Constructor
     *
     * @param pos position of the wall
     * @param size size of the wall
     * @param normal the normal vector of the wall
     */
    Wall( Vector2D pos, Vector2D size, Vector2D normal );
    /**
     * @brief Default Destructor
     */
    ~Wall();
    /**
     * @brief Callback for collision with collider
     * 
     * @param collider the game object that wall collides with
     * @param normal the normal vector of the collider
     */
    virtual void onTriggerCollide( Collider collider, Vector2D normal );
    /**
     * @brief Get the size
     */
    Vector2D getSize();
    /**
     * @brief Set the size 
     */
    void setSize( Vector2D size );
private:
    /** the size of the wall */
    Vector2D size = Vector2D( WALL_INITIAL_WIDTH, WALL_INITIAL_HEIGHT );
};

#endif
