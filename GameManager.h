#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <GLFW/glfw3.h>
#include "RenderSystem.h"

using namespace std;

class GameManager
{
    private:

        bool _running;
        RenderSystem *_renderSystem;
        GLFWwindow *_window;

        GameManager(bool running);
        ~GameManager();
    
    public:
        void runGameLoop();

        static GameManager& getGameManager();
        static void destroyGameManager();
};

#endif