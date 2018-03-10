//
//  Ball.h
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/4/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#ifndef Ball_h
#define Ball_h
#include <stdio.h>
#include "Vector2D.h"
#include "Constants.h"
#include "GameObject.h"
#include "Collider.h"
#include "Wall.h"
#include "Brick.h"
#include "Paddle.h"
#include "Boundary.h"
#include <SDL2_mixer/SDL_mixer.h>
#include "ResourceManager.h"
#include "ScoreSystem.h"
//#include "GameSetting.h"
#include <typeinfo>

/**
 * @brief This class defines the ball
 */
class Ball : public GameObject, public Collider {
public:
    /**
     * @brief Default Constructor
     */
    Ball();
    /**
     * @brief Constructor
     */
    Ball( Vector2D pos, float radius );
    /**
     * @brief Destructor
     */
    ~Ball();
    /**
     * @brief Get the identifier of the ball
     */
    int getId();
    /**
     * @brief Get the radius of the ball
     */
    float getRadius();
    /**
     * @brief Get collide tag
     */
    bool getCollideTag();
    /**
     * @brief Set collide tag
     */
    void setCollideTag( bool colllideTag );
    // Get the position of the ball
    //Vector2D getPosition();
    // Get the speed of the ball
    //Vector2D getVelocity();
    /**
     * @brief Set the identifier of the ball
     */
    void setId( int identifier );
    /**
     * @brief Set the radius of the ball
     */
    void setRadius( int radius );
    // Set the velocity of the ball
    //void setVelocity( float x, float y );
    // Set the position of the ball
    //void setPosition( float x, float y );
    // Collide
    // void onCollide( Collider collider );
    /**
     * @brief Callback for the collision triggered
     * 
     * @param collider the object it collides with
     * @param normal the normal vector of the the collider
     */
    virtual void onTriggerCollide( Collider collider, Vector2D normal );
    /**
     * @brief Callback for the collision with wall
     * 
     * @param collider the ball it collides with
     * @param normal the normal vector of the the collider
     */
    void onTriggerCollideWithBall( Collider collider, Vector2D normal );
    /**
     * @brief Callback for the collision with boundary
     * 
     * @param collider the boundary it collides with
     * @param normal the normal vector of the the collider
     */
    void onTriggerCollideWithBoundary( Collider collider, Vector2D normal );
    /**
     * @brief Callback for the collision with brick
     * 
     * @param collider the brick it collides with
     * @param normal the normal vector of the the collider
     */
    void onTriggerCollideWithBrick( Collider collider, Vector2D normal );
    /**
     * @brief Callback for the collision with wall
     * 
     * @param collider the wall it collides with
     * @param normal the normal vector of the the collider
     */
    void onTriggerCollideWithWall( Collider collider, Vector2D normal );
    /**
     * @brief Callback for the collision with paddle
     * 
     * @param collider the paddle it collides with
     * @param normal the normal vector of the the collider
     */
    void onTriggerCollideWithPaddle( Collider collider, Vector2D normal );

private:
    int identifier; /**< the identifier of the ball */
 
    float radius; /**< the radius of the ball */

    // the position of the ball
    // Vector2D position;
    // the velocity of the ball
    // Vector2D velocity;
    
    static int currentBallNum; /**< the current ball number */
    bool collideTag = false; /**< the collision tage */
};


#endif /* Ball_h */
