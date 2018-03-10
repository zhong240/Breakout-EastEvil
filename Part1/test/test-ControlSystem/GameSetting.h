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
#include "./Vector2D.h"
#include <map>
#include <stddef.h>
#include <string>

using namespace std;

// Global Game Setting - Singleton Design Pattern
class GameSetting {
public:
    static GameSetting* instance();
    //static map<string, int> ControlSchemes;
    enum ControlSchemes {
        WASD,
        IJKL,
        ArrowKeys
    };
    static ControlSchemes CurrentPlayerControlSchemes[];
    void setPlayerNum(int pn);
    int getPlayerNum();
    // Destructor
    ~GameSetting();
    // Initialization
    bool init();
    
private:
    // Private constructor
    GameSetting();
    // the only instance
    static GameSetting* g_gameSetting;
    // the playerNum
    int playerNum = 1;

    
};

#endif /* GameSetting_h */
