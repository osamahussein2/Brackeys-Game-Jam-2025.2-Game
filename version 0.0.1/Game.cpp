#include "Game.h"
#include "Global.h"

Game::Game(Scene* gameScene, Scene* UI_scene) : camera(gameScene), pointer(gameScene), x(0.0f), y(0.0f), 
gameMusic(gameScene), musicPlaying(false), ammoDrops{ gameScene, gameScene, gameScene, gameScene }
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

    // Initialize ammo drops
    ammoDrops[0].InitializeAmmoDrop(AmmoType::PistolAmmo, Vector3(200.0f, 200.0f, 0.1f));
    ammoDrops[1].InitializeAmmoDrop(AmmoType::ShotgunAmmo, Vector3(400.0f, 200.0f, 0.1f));
    ammoDrops[2].InitializeAmmoDrop(AmmoType::MicroSMGAmmo, Vector3(400.0f, 600.0f, 0.1f));
    ammoDrops[3].InitializeAmmoDrop(AmmoType::SMGAmmo, Vector3(800.0f, 800.0f, 0.1f));
}

void Game::UpdateGame()
{
    // If music isn't playing, play game music and set the bool to true
    if (!musicPlaying)
    {
        gameMusic.play();
        musicPlaying = true;
    }

    for (AmmoDrop& ammoDrop : ammoDrops)
    {
        ammoDrop.UpdateAmmoDrop();

        if (ammoDrop.AmmoDropCollision(Vector2(x, y)))
        {
            ammoDrop.SetHideAmmo();
        }
    }

    camera.setPosition(x - 450.0f, y - 250.0f, 0.05f);
    
    // Make sure the camera is looking at the player on every frame
    camera.setTarget(camera.getPosition().x, camera.getPosition().y, 0.0f);

    IterateThroughVisibleAmmo();

    HandlePlayerInput();
}

void Game::HideGame()
{
    pointer.HidePointer();
    for (AmmoDrop& ammoDrop : ammoDrops) ammoDrop.HideAmmoDrop();
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

    for (AmmoDrop& ammoDrop : ammoDrops) ammoDrop.ResetAmmoDropValues();
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

void Game::IterateThroughVisibleAmmo()
{
    for (AmmoDrop& ammoDrop : ammoDrops)
    {
        if (!ammoDrop.GetHideAmmo())
        {
            pointer.UpdatePointer(Vector2(x, y), Vector2(ammoDrop.GetAmmoPosition().x, ammoDrop.GetAmmoPosition().y));
        }
    }

    if (ammoDrops[0].GetHideAmmo() && ammoDrops[1].GetHideAmmo() && ammoDrops[2].GetHideAmmo() &&
        ammoDrops[3].GetHideAmmo())
    {
        pointer.HidePointer();
    }
}
