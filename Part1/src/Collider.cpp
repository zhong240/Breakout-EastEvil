//
//  Collider.cpp
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/4/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#include <stdio.h>
#include "../includes/Collider.h"

// Constructor
Collider::Collider( GameObject* gameObject ){
    this->gameObject = gameObject;
    //setBoundingBox( gameObject->getSize() );
}

// Destructor
Collider::~Collider(){
    // Note : Here we can not free the gameObject pointer, because it will be destrcuted by its inherited class
}

// onCollide
void Collider::onCollide( Collider collider ){
    //std::cout << "onCollide !\n";
    string tag = collider.getGameObject()->getTag();
    // if the gameobject is dead, return
    if ( !getGameObject()->getState() || !collider.getGameObject()->getState() )
        return;

    Vector2D aColliderPos = this->getGameObject()->getPosition();
    Vector2D aColliderBoundingBox = this->getBoundingBox();
    Vector2D bColliderPos = collider.getGameObject()->getPosition();
    Vector2D bColliderBoundingBox;

    if ( tag == "Ball" ){
        bColliderBoundingBox = Vector2D( BALL_BOUNDING_BOX_X, BALL_BOUNDING_BOX_Y );
    } else if ( tag == "Brick" ){
        bColliderBoundingBox = Vector2D( BRICK_BOUNDING_BOX_X, BRICK_BOUNDING_BOX_Y);
    } else if ( tag == "Paddle" ){
        //cout << "OnCollide with paddle\n";
        bColliderBoundingBox = Vector2D( PADDLE_BOUNDING_BOX_X, PADDLE_BOUNDING_BOX_Y);
    } else if ( tag == "Wall" ){

        if ( collider.getGameObject()->getPosition()[0] == WALL_TOP_INITIAL_POS_X )
            bColliderBoundingBox = Vector2D( WALL_TOP_INITIAL_WIDTH, WALL_TOP_INITIAL_HEIGHT );
        else if ( collider.getGameObject()->getPosition()[0] == WALL_LEFT_INITIAL_POS_X )
            bColliderBoundingBox = Vector2D( WALL_LEFT_INITIAL_WIDTH, WALL_LEFT_INITIAL_HEIGHT );
        else if ( collider.getGameObject()->getPosition()[0] == WALL_RIGHT_INITIAL_POS_X )
            bColliderBoundingBox = Vector2D( WALL_RIGHT_INITIAL_WIDTH, WALL_RIGHT_INITIAL_HEIGHT );

    }

    float aLeft = aColliderPos[0] - aColliderBoundingBox[0] / 2.0;
    float aRight = aColliderPos[0] + aColliderBoundingBox[0] / 2.0;
    float aTop = aColliderPos[1] - aColliderBoundingBox[1] / 2.0;
    float aDown = aColliderPos[1] + aColliderBoundingBox[1] / 2.0;


    float bLeft = bColliderPos[0] - bColliderBoundingBox[0] / 2.0;
    float bRight = bColliderPos[0] + bColliderBoundingBox[0] / 2.0;
    float bTop = bColliderPos[1] - bColliderBoundingBox[1] / 2.0;
    float bDown = bColliderPos[1] + bColliderBoundingBox[1] / 2.0;
//    std::cout << "aColliderLeftMargin : " << aColliderLeftMargin << endl;
//    std::cout << "aColliderRightMargin : " << aColliderRightMargin << endl;
//    std::cout << "aColliderTopMargin : " << aColliderTopMargin << endl;
//    std::cout << "aColliderBottomMargin : " << aColliderBottomMargin << endl;
//    std::cout << "bColliderLeftMargin : " << bColliderLeftMargin << endl;
//    std::cout << "bColliderRightMargin : " << bColliderRightMargin << endl;
//    std::cout << "bColliderTopMargin : " << bColliderTopMargin << endl;
//    std::cout << "bColliderBottomMargin : " << bColliderBottomMargin << endl;
    
    
    bool xCollide = false;
    bool yCollide = false;

    // b-> a
    bool x_case_1 = (aLeft >= bLeft && aLeft <= bRight) 
                    || (bLeft>aLeft && bLeft<aRight && collider.getGameObject()->getVelocity()[0]>0);

    // a <-b
    bool x_case_2 = (aRight >= bLeft && aRight <= bRight) 
                    || (bRight>aLeft && bRight<aRight && collider.getGameObject()->getVelocity()[0]<0);

    // b
    // V
    // a
    bool y_case_1 = (aTop <= bDown && aTop >= bTop)
                    || (bTop < aTop && bTop > aDown && collider.getGameObject()->getVelocity()[1]>0);

    // a
    // ^
    // b
    bool y_case_2 = (aDown <= bDown && aDown >= bTop)
                    || (bDown < aDown && bDown > aTop && collider.getGameObject()->getVelocity()[1]<0);
    

    Vector2D normal;

    if (x_case_1 && y_case_1) {

        if ( (bRight - aLeft) > (bDown - aTop) ) 
            normal = Vector2D(-1.0, 0.0);//this->setNormal(Vector2D(1.0, 0.0));
        else 
            normal = Vector2D(0.0, -1.0);//this->setNormal(Vector2D(0.0, -1.0));
    }   

    if (x_case_2 && y_case_1) {

        if ( (aRight - bLeft) > (bDown - aTop) ) 
            normal = Vector2D(1.0, 0.0);//this->setNormal(Vector2D(-1.0, 0.0));
        else normal = Vector2D(0.0, -1.0);//this->setNormal(Vector2D(0.0, -1.0));
    }

    if (x_case_1 && y_case_2) {

        if ( (bRight - aLeft) > (bDown - aTop) ) 
            normal = Vector2D(-1.0, 0.0);//this->setNormal(Vector2D(1.0, 0.0));
        else normal = Vector2D(0.0, 1.0);//this->setNormal(Vector2D(0.0, -1.0));
    }

    if (x_case_2 && y_case_2) {

        if ( (aRight - bLeft) > (aDown - bTop) ) 
            normal = Vector2D(1.0, 0.0);//this->setNormal(Vector2D(-1.0, 0.0));
        else normal = Vector2D(0.0, 1.0);//this->setNormal(Vector2D(0.0, 1.0));
    }


    if (x_case_1||x_case_2){
        
        xCollide = true;

    }

    if (y_case_1 || y_case_2){

        yCollide = true;

    }
    
//    if (x_case_1){
//        setNormal( Vector2D( 1.0f, 0.0f ) );
//    } else if (x_case_2)
//        setNormal( Vector2D( -1.0f, 0.0f ) );
//    else if (y_case_1)
//        setNormal( Vector2D( 0.0f, 1.0f ) );
//    else if (y_case_2)
//        setNormal( Vector2D( 0.0f, -1.0f ) );
//    
//    std::cout << "Normal : " << this->getNormal()[0] << " " << this->getNormal()[1] << endl;
//    
    
    
    if (yCollide && xCollide){
        this->onTriggerCollide(collider, normal);
    }
    
}

// onTriggerCollide
void Collider::onTriggerCollide( Collider collider, Vector2D normal ){
    std::cout << "This is the onTriggerCollider function in Collider\n";
}

// Set bounding box
void Collider::setBoundingBox( Vector2D boundingBox ){
    this->boundingBox[0] = boundingBox[0];
    this->boundingBox[1] = boundingBox[1];
}

// Get bounding box
Vector2D Collider::getBoundingBox(){
    return this->boundingBox;
}

// Set Normal Vector
void Collider::setNormal( Vector2D normal ){
    this->normal[0] = normal[0];
    this->normal[1] = normal[1];
}

// Get Normal Vector
Vector2D Collider::getNormal(){
    return this->normal;
}

// Get GameObject
GameObject* Collider::getGameObject(){
    return this->gameObject;
}

