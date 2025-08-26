#include "Game.h"
#include "Global.h"

Game::Game(Scene* gameScene, Scene* UI_scene) : camera(gameScene), pointer(gameScene), x(0.0f), y(0.0f)
{

}

Game::~Game()
{
}

void Game::InitializeGame()
{
    // Initialize camera
    camera.setType(CameraType::CAMERA_ORTHO);

    Global::scene.setCamera(camera.getEntity());

    // Initialize game objects
    pointer.InitializePointer("Pointers/YellowPointer.png");
}

void Game::UpdateGame()
{
    camera.setPosition(x - 450.0f, y - 250.0f, 0.05f);
    
    // Make sure the camera is looking at the player on every frame (z needs to be negative for game to be visible)
    camera.setTarget(camera.getPosition().x, camera.getPosition().y, 0.0f);

    pointer.UpdatePointer(Vector2(x, y), Vector2(400.0f, 200.0f));

    HandlePlayerInput();
}

void Game::HideGame()
{
    pointer.HidePointer();
}

void Game::HandlePlayerInput()
{
    if (Input::isKeyPressed(S_KEY_UP)) {

        y += 1;
    }

    if (Input::isKeyPressed(S_KEY_DOWN))
    {
        y -= 1;
    }

    if (Input::isKeyPressed(S_KEY_LEFT))
    {
        x -= 1;
    }

    if (Input::isKeyPressed(S_KEY_RIGHT))
    {
        x += 1;
    }

    // For now, just quit to main menu
    if (Input::isKeyPressed(S_KEY_ESCAPE) && !Global::escapeKeyPressed)
    {
        Global::gameState = GameState::MainMenu;
        Global::escapeKeyPressed = true;
    }

    else if (!Input::isKeyPressed(S_KEY_ESCAPE) && Global::escapeKeyPressed)
    {
        Global::escapeKeyPressed = false;
    }
}