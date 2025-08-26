#include "SplashScreen.h"
#include "MainMenu.h"
#include "MouseCursor.h"
#include "CreditsMenu.h"
#include "Game.h"

#include "Global.h"

// Create our own instances
SplashScreen splashScreen(&Global::UI_scene);
MainMenu mainMenu(&Global::UI_scene);
CreditsMenu creditsMenu(&Global::UI_scene);
Game game(&Global::scene, &Global::UI_scene);

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

    // Initialize game
    game.InitializeGame();

    // Set engine parameters
    Engine::setScalingMode(Scaling::STRETCH);
    Engine::setCanvasSize(1000, 600);
    Engine::setScene(&Global::scene);
    Engine::addSceneLayer(&Global::UI_scene);

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

        game.HideGame();

        break;

    case GameState::Credits:

        // Update credits menu
        creditsMenu.UpdateCreditsMenu();

        // Hide any other menu
        mainMenu.HideMainMenu();

        break;

    case GameState::Playing:

        game.UpdateGame();

        // Hide any other menu
        mainMenu.HideMainMenu();

        break;

    case GameState::Paused:

        game.HideGame();

        break;

    default:
        break;
    }
}

void quit()
{
    Global::scene.destroy();
    Global::UI_scene.destroy();
}

void onMouseMove(float x, float y, int mods)
{
    MouseCursor::mouseX = x;
    MouseCursor::mouseY = y;
}