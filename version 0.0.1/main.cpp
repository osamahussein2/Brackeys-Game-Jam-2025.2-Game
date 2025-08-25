#include "SplashScreen.h"
#include "MainMenu.h"
#include "MouseCursor.h"
#include "CreditsMenu.h"

#include "Global.h"

// Create scene instances
Scene scene;
Scene UI_scene;

// Create our own instances
SplashScreen splashScreen(&UI_scene);
MainMenu mainMenu(&UI_scene);
CreditsMenu creditsMenu(&UI_scene);

// Add functions for updating/quitting the game
void update();
void quit();

void onMouseMove(float x, float y, int mods);

void init()
{
    // Make sure the game state starts at the splash screen
    Global::gameState = GameState::SupernovaEngine;

    // Initialize menus
    splashScreen.InitializeSplashScreen();
    mainMenu.InitializeMainMenu();
    creditsMenu.InitializeCreditsMenu();

    // Set engine parameters
    Engine::setScalingMode(Scaling::STRETCH);
    Engine::setCanvasSize(1000, 600);
    Engine::setScene(&scene);
    Engine::addSceneLayer(&UI_scene);

    // Set engine callbacks
    Engine::onMouseMove = onMouseMove;
    Engine::onUpdate = update;
    Engine::onShutdown = quit;
}

void update()
{
    switch (Global::gameState)
    {
    case GameState::SupernovaEngine:

        // Update splash screen
        splashScreen.UpdateSplashScreen();

        break;

    case GameState::MainMenu:

        // Update main menu buttons
        mainMenu.UpdateMainMenu();

        // Hide any other menu
        creditsMenu.HideCreditsMenu();

        break;

    case GameState::Credits:

        // Update credits menu
        creditsMenu.UpdateCreditsMenu();

        // Hide any other menu
        mainMenu.HideMainMenu();

        break;

    case GameState::Playing:

        // Hide any other menu
        mainMenu.HideMainMenu();

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