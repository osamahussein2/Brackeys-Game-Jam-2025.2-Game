#include "SplashScreen.h"
#include "MainMenu.h"
#include "MouseCursor.h"

// Game state declaration
enum class GameState
{
    SupernovaEngine,
    MainMenu,
    Credits,
    Playing,
    Paused
};

GameState gameState;

// Create scene instances
Scene scene;
Scene UI_scene;

// Create our own instances
SplashScreen* splashScreen = nullptr;
MainMenu* mainMenu = nullptr;

// Add functions for updating/quitting the game
void update();
void quit();

void onMouseMove(float x, float y, int mods);

void init(){

    gameState = GameState::SupernovaEngine;

    // Set engine parameters
    Engine::setScalingMode(Scaling::STRETCH);
    Engine::setCanvasSize(1000, 600);
    Engine::setScene(&scene);
    Engine::addSceneLayer(&UI_scene);

    Engine::onMouseMove = onMouseMove;
    Engine::onUpdate = update;
    Engine::onShutdown = quit;
}

void update()
{
    switch (gameState)
    {
    case GameState::SupernovaEngine:

        // Make sure to allocate memory on splash screen instance if it's valid and initialize instances
        if (!splashScreen)
        {
            splashScreen = new SplashScreen(&UI_scene);
            splashScreen->InitializeSplashScreen();
        }

        // Once it points to the splashscreen instance, update the splash screen and begin transitioning to main menu state
        else
        {
            splashScreen->UpdateSplashScreen();

            if (splashScreen->SplashScreenFinished())
            {
                gameState = GameState::MainMenu;

                delete splashScreen; // Also delete its memory to prevent memory leaks
                splashScreen = nullptr;
            }
        }

        break;

    case GameState::MainMenu:

        // Make sure to allocate memory on main menu instance if it's valid and initialize instances
        if (!mainMenu)
        {
            mainMenu = new MainMenu(&UI_scene);
            mainMenu->InitializeMainMenu();
        }

        // Once it points to the main menu instance, check for game state transition to playing
        else
        {
            // Update main menu buttons
            mainMenu->UpdateMainMenu();

            if (mainMenu->GetGameState() == "Playing")
            {
                gameState = GameState::Playing;

                delete mainMenu; // Also delete its memory to prevent memory leaks
                mainMenu = nullptr;
            }

            else if (mainMenu->GetGameState() == "Credits")
            {
                gameState = GameState::Credits;

                delete mainMenu; // Also delete its memory to prevent memory leaks
                mainMenu = nullptr;
            }
        }
        break;

    case GameState::Credits:
        break;

    case GameState::Playing:
        break;

    case GameState::Paused:
        break;

    default:
        break;
    }
}

void quit()
{
    scene.destroy();
    UI_scene.destroy();
}

void onMouseMove(float x, float y, int mods)
{
    MouseCursor::mouseX = x;
    MouseCursor::mouseY = y;
}