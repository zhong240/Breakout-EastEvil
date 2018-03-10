//
//  Brick.h
//  BreakoutGame
//
//  Created by Tianxiang Dai on 2/4/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#ifndef Brick_h
#define Brick_h

#include "GameObject.h"
#include "Collider.h"

/**
 * @brief This class defines obstacles that a ball can collide with
 */
class Brick: public GameObject, public Collider{
public:
    /**
     * @brief Default Constructor
     */
    Brick();
    /**
     * @brief Constructor
     *
     * @para pos the position of the brick
     * @para size the size of the brick
     */
    Brick(Vector2D pos, Vector2D size);
    /**
     * @brief Destructor
     */
    ~Brick();
    /**
     * @brief Init
     */
    bool init();
    /**
     * @brief Quit
     */
    void quit();
    // Collide, directly inherited from Collider class
    // void onCollide(Collider c);
    
    /**
     * @brief Called when the brick is collided
     *
     * @param collider the object it collides with
     * @param normal the normal vector of the collider
     */
    virtual void onTriggerCollide( Collider collider, Vector2D normal );
    /**
     * @brief Get the size (no setter for now)
     */
    Vector2D getSize();
    /**
     * @brief Set the size
     */
    void setSize( Vector2D size );
    
private:
    /**
     * @brief the size of the brick
     */
    Vector2D size = Vector2D (BRICK_INITIAL_WIDTH, BRICK_INITIAL_HEIGHT);
    
};


#endif /* Brick_h */
