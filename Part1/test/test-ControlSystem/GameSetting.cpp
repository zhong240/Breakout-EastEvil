#include "./GameSetting.h"

GameSetting* GameSetting::g_gameSetting = NULL;

GameSetting::ControlSchemes GameSetting::CurrentPlayerControlSchemes[] 
            = {GameSetting::ControlSchemes::ArrowKeys};

GameSetting* GameSetting::instance() {
    if (!g_gameSetting) 
        g_gameSetting = new GameSetting();
    return g_gameSetting;
}

GameSetting::GameSetting(){
    
}


int GameSetting::getPlayerNum() {
    return playerNum;
}
void GameSetting::setPlayerNum(int pn) {
    playerNum = pn;
}
