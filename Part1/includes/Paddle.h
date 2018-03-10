//
//  Paddle.h
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/4/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#ifndef Paddle_h
#define Paddle_h
#include "GameObject.h"
#include "Collider.h"

/**
 * @brief This class set up the paddle
 */
class Paddle : public GameObject, public Collider {
public:
    /**
     * @brief Default Contructor
     */
    Paddle();
    /**
     * @brief Constructor
     *
     * @param pos the position
     * @param size the size 
     */
    Paddle( Vector2D pos, Vector2D size );
    /**
     * @brief Destructor
     */
    ~Paddle();
    // OnCollide
    // void onCollide( Collider collider );
    
    /**
     * @brief Callback for collision 
     * 
     * @param collider the object that paddle collides with
     * @param normal the normal vector of the collider
     */
    virtual void onTriggerCollide( Collider collider, Vector2D normal );
    /**
     * @brief Get the size of the paddle
     */
    Vector2D getSize();
    /**
     * @brief Set the size of the paddle
     */
    void setSize( Vector2D );
    
private:
    /** size of the paddle */
    Vector2D size = Vector2D( PADDLE_INITIAL_SIZE_X, PADDLE_INITIAL_SIZE_Y );
    
};

#endif /* Paddle_h */
