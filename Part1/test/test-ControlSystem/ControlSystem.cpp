#include "./ControlSystem.h"

ControlSystem* ControlSystem::g_controlSystem = NULL;

ControlSystem* ControlSystem::instance()
{
    if (!g_controlSystem)
        g_controlSystem = new ControlSystem();

    return g_controlSystem;
}

ControlSystem::ControlSystem(): playerInputs({Vector2D(0.0f, 0.0f), Vector2D(0.0f, 0.0f)})
{
    // initialization.
}

ControlSystem::~ControlSystem()
{
    // destroy.
}

Vector2D ControlSystem::getInputs (int playerId)
{
    if (playerId < playerInputs.size()) 
        return playerInputs[playerId];
    else 
        return Vector2D(0.0f, 0.0f);
}

void ControlSystem::update (SDL_Event e)
{

    for (int i=0; i<GameSetting::instance()->getPlayerNum(); ++i)
    {
        if (playerInputs.size() < i) 
            playerInputs.push_back(Vector2D(0.0f, 0.0f));

        switch (GameSetting::CurrentPlayerControlSchemes[i])
        {
            case GameSetting::ControlSchemes::WASD:
                playerInputs[i] = Vector2D((e.key.keysym.sym==SDLK_d?1.0f:0.0f)-
                                            (e.key.keysym.sym==SDLK_a?1.0f:0.0f),
                                            (e.key.keysym.sym==SDLK_w?1.0f:0.0f)-
                                            (e.key.keysym.sym==SDLK_s?1.0f:0.0f));
                break;
            case GameSetting::ControlSchemes::IJKL:
                playerInputs[i] = Vector2D((e.key.keysym.sym==SDLK_l?1.0f:0.0f)-
                                            (e.key.keysym.sym==SDLK_j?1.0f:0.0f),
                                            (e.key.keysym.sym==SDLK_i?1.0f:0.0f)-
                                            (e.key.keysym.sym==SDLK_k?1.0f:0.0f));
                break;
            case GameSetting::ControlSchemes::ArrowKeys:
                playerInputs[i] = Vector2D((e.key.keysym.sym==SDLK_RIGHT?1.0f:0.0f)-
                                            (e.key.keysym.sym==SDLK_LEFT?1.0f:0.0f),
                                            (e.key.keysym.sym==SDLK_UP?1.0f:0.0f)-
                                            (e.key.keysym.sym==SDLK_DOWN?1.0f:0.0f));
                break;
            default:
                playerInputs[i] = Vector2D(0.0f, 0.0f);
        }
    }

}
