#include "Game.h"
#include "Global.h"

Game::Game(Scene* gameScene, Scene* UI_scene) : camera(gameScene), pointer(gameScene), x(0.0f), y(0.0f), 
gameMusic(gameScene), musicPlaying(false)
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

    // Initialize gameplay music
    gameMusic.loadAudio("Music/Gameplay 2.mp3");
    gameMusic.setSound3D(false);
    gameMusic.setLopping(true);
}

void Game::UpdateGame()
{
    // If music isn't playing, play game music and set the bool to true
    if (!musicPlaying)
    {
        gameMusic.play();
        musicPlaying = true;
    }

    camera.setPosition(x - 450.0f, y - 250.0f, 0.05f);
    
    // Make sure the camera is looking at the player on every frame
    camera.setTarget(camera.getPosition().x, camera.getPosition().y, 0.0f);

    pointer.UpdatePointer(Vector2(x, y), Vector2(400.0f, 200.0f));

    HandlePlayerInput();
}

void Game::HideGame()
{
    pointer.HidePointer();
}

void Game::ResetGame()
{
    if (x != 0.0f) x = 0.0f; 
    if (y != 0.0f) y = 0.0f;

    // Stop playing the game music and set music playing to false
    if (musicPlaying)
    {
        gameMusic.stop();
        musicPlaying = false;
    }
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

    // Pause the game when pressing ESCAPE
    if (Input::isKeyPressed(S_KEY_ESCAPE) && !Global::escapeKeyPressed)
    {
        Global::gameState = GameState::Paused;
        Global::escapeKeyPressed = true;
    }

    else if (!Input::isKeyPressed(S_KEY_ESCAPE) && Global::escapeKeyPressed)
    {
        Global::escapeKeyPressed = false;
    }
}