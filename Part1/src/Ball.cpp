//
//  Ball.cpp
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/4/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#include "../includes/Ball.h"

int Ball::currentBallNum = 0;

// Default Constructor
Ball::Ball(): Collider(this) {
    this->radius = BALL_RADIUS;
    this->identifier = currentBallNum++;
    this->position = Vector2D( BALL_INITIAL_POSITION_X, BALL_INITIAL_POSITION_Y );
    this->velocity = Vector2D( BALL_INITIAL_VELOCITY_X, BALL_INITIAL_VELOCITY_Y );
    this->tag = "Ball";
    this->collideTag = false;
    setMass( BALL_MASS );
    setBoundingBox( Vector2D( radius, radius ) );
}

// Constructor
Ball::Ball( Vector2D pos, float radius ): GameObject(pos), radius(radius), Collider(this) {
    this->tag = "Ball";
    setMass( BALL_MASS );
    this->collideTag = false;
    setBoundingBox( Vector2D( radius, radius ) );
}

// Destructor
Ball::~Ball(){
    
}

// onTriggerCollide
void Ball::onTriggerCollide( Collider collider, Vector2D normal ){
    // When a ball is collided, since in in this game we do not consider acceleration, we can just reverse the velocity.
    //std::cout << "Ball onTriggerCollide" << endl;
    this->setCollideTag( true );
    if ( collider.getGameObject()->getTag() == "Ball" )
        onTriggerCollideWithBall(collider, normal);
    else if (collider.getGameObject()->getTag() == "Wall" )
        onTriggerCollideWithWall(collider, normal);
    else if ( collider.getGameObject()->getTag() == "Brick" )
        onTriggerCollideWithBrick(collider, normal);
    else if ( collider.getGameObject()->getTag() == "Paddle" )
        onTriggerCollideWithPaddle(collider, normal);
}

// onTriggerCollideWithBall
void Ball::onTriggerCollideWithBall( Collider collider, Vector2D normal ){
    // Called when a ball is collided with a ball.
    // Now it will do nothing, for this game
    std::cout << "When a ball is collided with a ball, do nothing\n";
}

// onTriggerCollideWithWall
void Ball::onTriggerCollideWithWall( Collider collider, Vector2D normal ){
    // Called when a ball is collided with a wall, change the velocity using reflection(in TinyMath)
    if ( collider.getGameObject()->getPosition()[0] == WALL_TOP_INITIAL_POS_X )
        normal = Vector2D( 0.0f, 1.0f );
    else if ( collider.getGameObject()->getPosition()[0] == WALL_LEFT_INITIAL_POS_X )
        normal = Vector2D( 1.0f, 0.0f );
    else if ( collider.getGameObject()->getPosition()[0] == WALL_RIGHT_INITIAL_POS_X )
        normal = Vector2D( -1.0f, 0.0f );
    
    this->velocity = BALL_VELOCITY_FACTOR * Normalize( reflection( getVelocity(), normal ) );
    std::cout << "Collide with wall!\n";
    Mix_PlayChannel(-1, ResourceManager::getInstance()->getChunkResource("sound_paddle_hit_border"), 0);
}

void Ball::onTriggerCollideWithBrick( Collider collider, Vector2D normal ){
    //std::cout << "Ball collide with Brick!\n";
//    Vector2D normal;
//    // collide from left, abs(Vx) > abs(Vy) and Vx > 0
//    if ((abs(this->getVelocity()[0]) > abs(this->getVelocity()[1])) && (this->getVelocity()[0] > 0)){
//        normal = Vector2D( -1.0, 0.0 );
//    } else if ((abs(this->getVelocity()[0]) > abs(this->getVelocity()[1])) && (this->getVelocity()[0] < 0)){
//        // collide from right
//        normal = Vector2D( 1.0, 0.0 );
//    } else if ((abs(this->getVelocity()[0]) < abs(this->getVelocity()[1])) && (this->getVelocity()[1] > 0)){
//        // collide from top
//        normal = Vector2D( 0.0, 1.0 );
//    } else if ((abs(this->getVelocity()[0]) <= abs(this->getVelocity()[1])) && (this->getVelocity()[1] < 0)){
//        normal = Vector2D( 0.0, -1.0 );
//    }
    // Called when a ball is collided with a brick
//    if ( Dot( getVelocity(), normal ) == 0 ){// perpendicular
//        this->velocity = - this->velocity;
//        // collider.getComponent()->setInactive();
//    } else if ( Dot( getVelocity(), normal ) > 0 ){// angular > 90
//        this->velocity = BALL_VELOCITY_FACTOR * Normalize( reflection( getVelocity(), normal ));
//        // collider.getComponent()->setInactive();
//    } else if ( Dot( getVelocity(), normal ) < 0 ){// angular < 90
//        this->velocity = BALL_VELOCITY_FACTOR * Normalize( reflection( getVelocity(), normal ));
//        // collider.getComponent()->setInactive();
//    }
    this->velocity = BALL_VELOCITY_FACTOR * Normalize( reflection( - getVelocity(), normal ));
    std::cout << "Velocity : " << this->velocity[0] << " " << this->velocity[1] << endl;
    std::cout << "Normal : " << normal[0] << " " << normal[1] << endl;
    //std::cout << "Velocity : " << getVelocity()[0] << " " << getVelocity()[1] << endl;
    collider.getGameObject()->setState( IS_DEAD );
    Mix_PlayChannel(-1, ResourceManager::getInstance()->getChunkResource("sound_ball_hit_brick"), 0);
    ScoreSystem::getInstance()->setScore( ScoreSystem::getInstance()->getScore() + 10);
    // When a ball collides with a brick, + 10 scores
    //GameSetting::getInstance()->getScore() += 10;
}

void Ball::onTriggerCollideWithPaddle( Collider collider, Vector2D normal ){
    std::cout << "Ball Collide with Paddle \n";
    // Called when a ball is collided with a paddle
    normal = Vector2D( 0.0, -1.0 );
    float collisionElastic = 0.8f;
    // Three cases, to judge the ball collides with different part of the paddle
    if ( ( this->getPosition()[0] > collider.getGameObject()->getPosition()[0] - PADDLE_INITIAL_SIZE_X / 4.0f )
    && ( this->getPosition()[0] < collider.getGameObject()->getPosition()[0] + PADDLE_INITIAL_SIZE_X / 4.0f ) ){
        collisionElastic = 0.6f;
    }
    Vector2D collideVelocity = Vector2D( this->getVelocity()[0] + collisionElastic * collider.getGameObject()->getVelocity()[0],
                                        this->getVelocity()[1] );
    //std::cout << "collideVelocity : " << collideVelocity[0] << " " << collideVelocity[1] << endl;
    this->velocity = BALL_VELOCITY_FACTOR * Normalize( reflection( collideVelocity, normal ));
    this->velocity[1] = (this->velocity[1] < 0.0f) ? BALL_INITIAL_VELOCITY_Y : - BALL_INITIAL_VELOCITY_Y;
    std::cout << "Ball Velocity : " << getVelocity()[0] << " " << getVelocity()[1] << endl;
    Mix_PlayChannel(-1, ResourceManager::getInstance()->getChunkResource("sound_paddle_hit_border"), 0);

}

// Get the identifier of the ball
int Ball::getId(){
    return this->identifier;
}

// Get the radius of the ball
float Ball::getRadius(){
    return this->radius;
}

// Set the identifier of the ball
void Ball::setId( int identifier ){
    this->identifier = identifier;
}

// Set the radius of the ball
void Ball::setRadius( int radius ){
    this->radius = radius;
}

// getCollideTag
bool Ball::getCollideTag(){
    return this->collideTag;
}
// setCollideTag
void Ball::setCollideTag( bool collideTag ){
    this->collideTag = collideTag;
}

