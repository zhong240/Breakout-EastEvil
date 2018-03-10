#include "../includes/GameSetting.h"

GameSetting* GameSetting::g_gameSetting = NULL;

GameSetting::ControlSchemes GameSetting::CurrentPlayerControlSchemes[]
            = {GameSetting::ControlSchemes::WASD};

GameSetting* GameSetting::getInstance() {
    if (!g_gameSetting)
        g_gameSetting = new GameSetting();
    return g_gameSetting;
}

GameSetting::GameSetting(){

}

bool GameSetting::init(){
    std::cout << "Init GameSetting!\n";
    ball = new Ball();
    paddle = new Paddle();
    if (!boundary.empty())
        boundary.clear();
    Wall* top = new Wall( Vector2D( WALL_TOP_INITIAL_POS_X, WALL_TOP_INITIAL_POS_Y ),
                         Vector2D( WALL_TOP_INITIAL_WIDTH, WALL_TOP_INITIAL_HEIGHT ),
                         Vector2D( WALL_TOP_NORMAL_X, WALL_TOP_NORMAL_Y ) );
    Wall* left = new Wall( Vector2D( WALL_LEFT_INITIAL_POS_X, WALL_LEFT_INITIAL_POS_Y ),
                          Vector2D( WALL_LEFT_INITIAL_WIDTH, WALL_LEFT_INITIAL_HEIGHT ),
                          Vector2D( WALL_LEFT_NORMAL_X, WALL_LEFT_NORMAL_Y ) );
    Wall* right = new Wall( Vector2D( WALL_RIGHT_INITIAL_POS_X, WALL_RIGHT_INITIAL_POS_Y ),
                           Vector2D( WALL_RIGHT_INITIAL_WIDTH, WALL_RIGHT_INITIAL_HEIGHT ),
                           Vector2D( WALL_RIGHT_NORMAL_X, WALL_RIGHT_NORMAL_Y ) );
    boundary.push_back( top );
    boundary.push_back( left );
    boundary.push_back( right );
    level = 1;
    //ScoreSystem::getInstance()->init();
    life = 3;
    return initLevel();
}

bool GameSetting::loadBrickPosition() {
    if( !brickPosition.empty() )
        brickPosition.clear();

    // Read brick position from file
    string levelFile = "Assets/levels/level" + to_string(level) + ".txt";
    ifstream fin(levelFile);
    if (!fin.good()) {
      level = 0;
      return false;
    }
    string s;

    while (getline(fin,s)) {
      if ((s == "") || (s.substr(0,1)==" ")) {
        continue;
      }
      size_t pos = s.find(" ");
      float x = stof(s.substr(0, pos));
      float y = stof(s.substr(pos+1, string::npos));
      brickPosition.push_back(Vector2D(x, y));
    }

    return true;
}

bool GameSetting::initLevel(){
    // Init Level One Brick Array
    bool success = true;
    if( !brick.empty() )
        brick.clear();

    loadBrickPosition();
    for (int i = 0; i < brickPosition.size(); i++) {
        Brick* temp = new Brick();
        temp->setPosition(brickPosition[i]);
        brick.push_back( temp );
    }

    return success;
}

// bool GameSetting::initLevelOne(){
//     // Init Level One Brick Array
//     bool success = true;
//     if( !brick.empty() )
//         brick.clear();
//     for (int i = 0; i < BRICK_LEVEL_ONE_NUM; i++) {
//         Brick* temp = new Brick();
//         brick.push_back( temp );
//     }
//     int row = 4;
//     int column = 12;
//     Vector2D center = Vector2D( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 );
//     Vector2D startPosition = Vector2D( center[0] - ((column - 1) / 2) * brick[0]->getSize()[0],
//                                       center[1] - ((row - 1) / 2) * brick[0]->getSize()[1] );
//     Vector2D size = brick[0]->getSize();
//     for (int i = 0; i < BRICK_LEVEL_ONE_NUM; i++){
//         int xOffset = i % column;
//         int yOffset = i / column;
//         brick[i]->setPosition( Vector2D( startPosition[0] + xOffset * size[0],
//                                        startPosition[1] + yOffset * size[1] ) );
//     }
//     return success;
// }
//
// bool GameSetting::initLevelTwo(){
//     bool success = true;
//     ball = new Ball();
//     paddle = new Paddle();
//     level = 2;
//     return initLevelOne();
//     // Init Level One Brick Array
//     if( !brick.empty() )
//         brick.clear();
//     for (int i = 0; i < BRICK_LEVEL_ONE_NUM; i++) {
//         Brick* temp = new Brick();
//         brick.push_back( temp );
//     }    int row = 4;
//     int column = 12;
//     Vector2D center = Vector2D( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 );
//     Vector2D startPosition = Vector2D( center[0] - ((column - 1) / 2) * brick[0]->getSize()[0],
//                                       center[1] - ((row - 1) / 2) * brick[0]->getSize()[1] );
//     Vector2D size = brick[0]->getSize();
//     for (int i = 0; i < BRICK_LEVEL_TWO_NUM; i++){
//         int xOffset = i % column;
//         int yOffset = i / column;
//         brick[i]->setPosition( Vector2D( startPosition[0] + xOffset * size[0],
//                                        startPosition[1] + yOffset * size[1] ) );
//     }
//     return success;
// }
//
// bool GameSetting::initLevelThree(){
//     bool success = true;
//     ball = new Ball();
//     paddle = new Paddle();
//     level = 3;
//     // Init Level One Brick Array
//     if( !brick.empty() )
//         brick.clear();
//     for (int i = 0; i < BRICK_LEVEL_ONE_NUM; i++) {
//         Brick* temp = new Brick();
//         brick.push_back( temp );
//     }    int row = 4;
//     int column = 12;
//     Vector2D center = Vector2D( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 );
//     Vector2D startPosition = Vector2D( center[0] - ((column - 1) / 2) * brick[0]->getSize()[0],
//                                       center[1] - ((row - 1) / 2) * brick[0]->getSize()[1] );
//     Vector2D size = brick[0]->getSize();
//     for (int i = 0; i < BRICK_LEVEL_THREE_NUM; i++){
//         int xOffset = i % column;
//         int yOffset = i / column;
//         brick[i]->setPosition( Vector2D( startPosition[0] + xOffset * size[0],
//                                        startPosition[1] + yOffset * size[1] ) );
//     }
//     return success;
// }

Ball* GameSetting::getBall(){
    return this->ball;
}

std::vector<Brick*> GameSetting::getBrick(){
    return this->brick;
}

Paddle* GameSetting::getPaddle(){
    return this->paddle;
}

std::vector<Wall*> GameSetting::getBoundary(){
    return this->boundary;
}

//long int GameSetting::getScore(){
//    return this->score;
//}

int GameSetting::getLife(){
    return this->life;
}

int GameSetting::getLevel(){
    return this->level;
}

void GameSetting::win(){
    //DisplaySystem::getInstance()->win();
}

void GameSetting::lose(){
    //DisplaySystem::getInstance()->lose();
}

int GameSetting::getPlayerNum() {
    return playerNum;
}
void GameSetting::setPlayerNum(int pn) {
    playerNum = pn;
}

void GameSetting::setLevel( int level ){
    this->level = level;
}

//void GameSetting::setScore( long int score ){
//    this->score = score;
//}

void GameSetting::setLife( int life ){
    this->life = life;
}

bool GameSetting::quit(){
    // Now Do nothing
    bool success = true;
    return success;
}

void GameSetting::update(){
    // Now do nothing
}

void GameSetting::resetBall(){
    ball = new Ball();
}
