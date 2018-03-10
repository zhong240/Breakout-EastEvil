//
//  Boundary.h
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/18/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#ifndef Boundary_h
#define Boundary_h
#include "GameObject.h"
#include "Collider.h"
#include "Vector2D.h"
#include "Constants.h"
#include "Wall.h"

/**
 * @brief This class represents the boundary, or, wall of this game.
 */
class Boundary : public GameObject{
public:
    /**
     * @brief Default Constructor
     */
    Boundary();
    /**
     * @brief Constructor
     * @param pos the center of the boundary
     * @param size the width and height of the boundary
     */
    Boundary( Vector2D pos, Vector2D size);
    /**
     * @brief Default Destructor
     */
    ~Boundary();
    /**
     * @brief Get the size
     */
    Vector2D getSize();
    /**
     * @brief Set the size
     */
    void setSize( Vector2D size );
    /**
     * @brief Create the wall
     */
    void createWall();
    /**
     * @brief Get the wall
     */
    Wall* getWall();

private:
    /**
     * @brief the size of the boundary.
     */
    Vector2D size = Vector2D( BOUNDARY_INITIAL_WIDTH, BOUNDARY_INITIAL_HEIGHT );
    /**
     * @brief The boundary consists of 4 walls in this game.
     *
     * wall[0] represents for the top,
     * wall[1] represents for the bottom,
     * wall[2] represents for the left,
     * and wall[3] represents for the right.
     */
    Wall wall[4];
};

#endif
