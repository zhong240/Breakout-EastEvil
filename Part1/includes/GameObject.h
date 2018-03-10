//
//  GameObject.h
//
//  Created by Tianxiang Dai on 2/4/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#ifndef GameObject_h
#define GameObject_h

#include <iostream>
#include "Vector2D.h"
#include "Constants.h"
#include <string>

/**
 * @brief This class defines the game object.
 *
 * Every game object should implement GameObject class
 */
class GameObject{
public:
    /**
     * @brief Default Contructor
     */
    GameObject();
    /**
     * @brief Constructor - Only initialize position for now
     */
    GameObject(Vector2D pos);
    
    /**
     * @brief Destructor
     */
    ~GameObject();
    /**
     * @brief Initialization
     */
    bool init();
    /**
     * @brief Quit
     */
    void quit();
    
    /**
     * @brief Set the state of the game obejct
     *
     * @param s whether the object is active or not
     */
    void setState(bool s);
    /**
     * @brief Get the state of the game object
     */
    bool getState();
    
    /**
     * @brief Get the position of the game object
     */
    Vector2D getPosition();
    /**
     * @brief Set the position of the game object
     *
     * @param pos the position of the game object
     */
    void setPosition(Vector2D pos);
    
    /**
     * @brief Get the position of the game object
     */
    Vector2D getVelocity();
    /**
     * @brief Set the velocity of the game object
     *
     * @param v the velocity of the game object
     */
    void setVelocity(Vector2D v);
    
    /**
     * @brief Get the acceleration of the game object
     */
    Vector2D getAcceleration();
    /**
     * @brief Set the acceleration of the game object
     *
     * @param a the acceleration of the game object
     */
    void setAcceleration(Vector2D a);
    
    float getElastic(); /**< Get the elastic of the game obejct */
    float getMass(); /**< Get the mass of the game obejct */
    void setMass( float mass ); /**< Set the mass of the game obejct */

    /**
     * @brief Get the tag
     */
    string getTag();
    
protected:
    Vector2D position = Vector2D (COLLIDER_INITIAL_POSITION_X, COLLIDER_INITIAL_POSITION_Y);
    /**< the position of the game object */
    float mass = COLLIDER_INITIAL_MASS; /**< the mass of the game object */
    float elastic = COLLIDER_INITIAL_ELASTIC;
    /**< the elastic of the game obejct */
    Vector2D velocity = Vector2D (COLLIDER_INITIAL_VELOCITY_X, COLLIDER_INITIAL_POSITION_Y);
    /**< the velocity of the game obejct */
    Vector2D acceleration = Vector2D (COLLIDER_INITIAL_ACCELERATION_X, COLLIDER_INITIAL_ACCELERATION_Y);
    /**< the acceleration of the game obejct */

    bool state = IS_ALIVE; /**< the state of the game obejct */
    string tag = "GameObject"; /**< the tage of the game object */
};

inline string GameObject::getTag(){
    return this->tag;
}

// inline definitions
inline GameObject::GameObject(){
    
}

inline GameObject::GameObject(Vector2D pos){
    this->position = pos;
}

inline GameObject::~GameObject(){
    
}

inline bool GameObject::getState() {
    return state;
}
inline void GameObject::setState(bool s) {
    state = s;
}
inline Vector2D GameObject::getAcceleration() {
    return acceleration;
}
inline void GameObject::setAcceleration(Vector2D a) {
    acceleration = a;
}
inline Vector2D GameObject::getVelocity() {
    return velocity;
}
inline void GameObject::setVelocity(Vector2D v) {
    velocity = v;
}
inline Vector2D GameObject::getPosition() {
    return position;
}
inline void GameObject::setPosition(Vector2D p) {
    //std::cout << "Set Position : " << p[0] << " " << p[1] << endl;
    position = p;
    //std::cout << "Position : " << position[0] << position[1] << endl;
}
inline float GameObject::getMass() {
    return mass;
}
inline float GameObject::getElastic() {
    return elastic;
}
inline void GameObject::setMass( float mass ) {
    this->mass = mass;
}

#endif /* GameObject_h */
