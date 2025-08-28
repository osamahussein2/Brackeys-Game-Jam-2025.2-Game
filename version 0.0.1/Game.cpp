#include "Game.h"
#include "Global.h"

Game::Game(Scene* gameScene, Scene* UI_scene) : camera(gameScene), pointer(gameScene), x(0.0f), y(0.0f), 
gameMusic(gameScene), musicPlaying(false), ammoDrops{ gameScene, gameScene, gameScene, gameScene }, 
playerWeapons{ UI_scene, UI_scene, UI_scene, UI_scene }, shootDelay(0.3f), weaponIndex(1), keyPressed(false),
switchWeaponKeyPressed(false), velocityX(1.0f), velocityY(0.0f), player(gameScene), frameX(0)
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

    player.setTexture("Sprites/PlayerSprite.png");
    
    for (int j = 0; j < 8; j++)
    {
        player.addFrame(j, "", Rect(0.0 / 7, (j + 1.0) / 8, 1.0 / 7, 1.0 / 8));
    }

    player.setFrame(0);
    player.setPosition(x, y, 0);
    player.setName("Player");
    player.setSize(playerSizeX, playerSizeY);

    player.startAnimation(0, 7, 150, true);
    player.setVisible(false);

    // Initialize gameplay music
    gameMusic.loadAudio("Music/Gameplay 2.mp3");
    gameMusic.setSound3D(false);
    gameMusic.setLopping(true);

    // Initialize ammo drops
    ammoDrops[0].InitializeAmmoDrop(AmmoType::PistolAmmo, Vector3(200.0f, 200.0f, 0.1f));
    ammoDrops[1].InitializeAmmoDrop(AmmoType::ShotgunAmmo, Vector3(400.0f, 200.0f, 0.1f));
    ammoDrops[2].InitializeAmmoDrop(AmmoType::MicroSMGAmmo, Vector3(400.0f, 600.0f, 0.1f));
    ammoDrops[3].InitializeAmmoDrop(AmmoType::SMGAmmo, Vector3(800.0f, 800.0f, 0.1f));

    // Initialize player weapons
    playerWeapons[0].InitializeWeapon(WeaponType::Pistol);
    playerWeapons[1].InitializeWeapon(WeaponType::Shotgun);
    playerWeapons[2].InitializeWeapon(WeaponType::MicroSMG);
    playerWeapons[3].InitializeWeapon(WeaponType::SMG);
}

void Game::UpdateGame()
{
    // If music isn't playing, play game music and set the bool to true
    if (!musicPlaying)
    {
        gameMusic.play();
        musicPlaying = true;
    }

    HandleWeapons();
    SwitchBetweenWeapons();

    UpdatePlayerBullets();

    for (AmmoDrop& ammoDrop : ammoDrops)
    {
        ammoDrop.UpdateAmmoDrop();
    }

    HandleAmmoCollisions();

    camera.setPosition(x - 450.0f, y - 250.0f, 0.0f);
    
    // Make sure the camera is looking at the player on every frame
    camera.setTarget(camera.getPosition().x, camera.getPosition().y, -0.05f);

    // Update player animation
    for (int j = 0; j < 8; j++)
        player.addFrame(j, "", Rect((frameX - 1.0f) / 7, (j + 1.0) / 8, 1.0 / 7, 1.0 / 8));

    // Show the player
    player.setVisible(true);

    // Set the player's position using x and y values
    player.setPosition(x, y, 0.0f);

    IterateThroughVisibleAmmo();

    HandlePlayerInput();
}

void Game::HideGame()
{
    pointer.HidePointer();

    for (AmmoDrop& ammoDrop : ammoDrops) ammoDrop.HideAmmoDrop();
    for (PlayerWeapon& playerWeapon : playerWeapons) playerWeapon.HideWeapons();

    for (int i = 0; i < playerBullets.size(); i++) playerBullets[i]->HideBullet();

    player.setVisible(false);
}

void Game::ResetGame()
{
    if (x != 0.0f) x = 0.0f; 
    if (y != 0.0f) y = 0.0f;
    
    frameX = 0;

    // Stop playing the game music and set music playing to false
    if (musicPlaying)
    {
        gameMusic.stop();
        musicPlaying = false;
    }

    for (AmmoDrop& ammoDrop : ammoDrops) ammoDrop.ResetAmmoDropValues();
    for (PlayerWeapon& playerWeapon : playerWeapons) playerWeapon.ResetWeapons();

    if (!playerBullets.empty()) playerBullets.clear();

    if (weaponIndex != 1) weaponIndex = 1;

    if (velocityX != 1.0f) velocityX = 1.0f;
    if (velocityY != 0.0f) velocityY = 0.0f;
}

void Game::HandlePlayerInput()
{
    if (Input::isKeyPressed(S_KEY_UP)) {

        y += 1;
        if (velocityY != 1.0f) velocityY = 1.0f;

        frameX = 5;

        // Update shooting velocities
        if (!Input::isKeyPressed(S_KEY_LEFT) && !Input::isKeyPressed(S_KEY_RIGHT))
        {
            if (velocityX != 0.0f) velocityX = 0.0f;
        }

        else if (Input::isKeyPressed(S_KEY_RIGHT))
        {
            if (velocityX != 1.0f) velocityX = 1.0f;
        }

        else if (Input::isKeyPressed(S_KEY_LEFT))
        {
            if (velocityX != -1.0f) velocityX = -1.0f;
        }
    }

    if (Input::isKeyPressed(S_KEY_DOWN))
    {
        y -= 1;
        if (velocityY != -1.0f) velocityY = -1.0f;

        frameX = 4;

        // Update shooting velocities
        if (!Input::isKeyPressed(S_KEY_LEFT) && !Input::isKeyPressed(S_KEY_RIGHT))
        {
            if (velocityX != 0.0f) velocityX = 0.0f;
        }

        else if (Input::isKeyPressed(S_KEY_RIGHT))
        {
            if (velocityX != 1.0f) velocityX = 1.0f;
        }

        else if (Input::isKeyPressed(S_KEY_LEFT))
        {
            if (velocityX != -1.0f) velocityX = -1.0f;
        }
    }

    else if (!Input::isKeyPressed(S_KEY_UP) && !Input::isKeyPressed(S_KEY_DOWN)) // Only for determining bullet velocity
    {
        if (velocityY != 0.0f) velocityY = 0.0f;
        if (velocityX != 1.0f) velocityX = 1.0f;
    }

    if (Input::isKeyPressed(S_KEY_LEFT))
    {
        x -= 1;
        if (velocityX != -1.0f) velocityX = -1.0f;
        
        frameX = 7;
    }

    if (Input::isKeyPressed(S_KEY_RIGHT))
    {
        x += 1;
        if (velocityX != 1.0f) velocityX = 1.0f;

        frameX = 6;
    }

    else if (!Input::isKeyPressed(S_KEY_UP) && !Input::isKeyPressed(S_KEY_DOWN) && !Input::isKeyPressed(S_KEY_LEFT) &&
        !Input::isKeyPressed(S_KEY_RIGHT))
    {
        frameX = 1;
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
            pointer.UpdatePointer(Vector2(x, y), Vector2(ammoDrop.GetAmmoPosition().x, ammoDrop.GetAmmoPosition().y),
                Vector2(50.0f, 200.0f));
        }
    }

    if (ammoDrops[0].GetHideAmmo() && ammoDrops[1].GetHideAmmo() && ammoDrops[2].GetHideAmmo() &&
        ammoDrops[3].GetHideAmmo())
    {
        pointer.HidePointer();
    }
}

void Game::HandleWeapons()
{
    switch (weaponIndex)
    {
    case 1: // Pistol

        playerWeapons[0].UpdateWeapon();
        playerWeapons[1].HideWeapons();
        playerWeapons[2].HideWeapons();
        playerWeapons[3].HideWeapons();

        if (shootDelay <= 0.3f) shootDelay += 0.016f;

        // Fire weapon
        if (Input::isKeyPressed(S_KEY_SPACE) && playerWeapons[0].GetClipInMagazine() > 0 && shootDelay >= 0.2f
            && !keyPressed)
        {
            playerWeapons[0].ShootWeapon();

            playerBullets.push_back(std::make_unique<PlayerBullet>(BulletType::PistolBullet, &Global::scene,
                Vector3(GetPlayerCenterPoint().x, GetPlayerCenterPoint().y, camera.getPosition().z), 
                Vector2(velocityX, velocityY)));

            keyPressed = true;

            shootDelay = 0.0f;
        }

        else if (!Input::isKeyPressed(S_KEY_SPACE) && keyPressed)
        {
            keyPressed = false;
        }

        // Reload weapon
        if (Input::isKeyPressed(S_KEY_R))
        {
            playerWeapons[0].ReloadWeapon();
        }

        break;

    case 2: // Shotgun

        playerWeapons[0].HideWeapons();
        playerWeapons[1].UpdateWeapon();
        playerWeapons[2].HideWeapons();
        playerWeapons[3].HideWeapons();

        if (shootDelay <= 0.3f) shootDelay += 0.016f;

        // Fire weapon
        if (Input::isKeyPressed(S_KEY_SPACE) && playerWeapons[1].GetClipInMagazine() > 0 && shootDelay >= 0.2f
            && !keyPressed)
        {
            playerWeapons[1].ShootWeapon();

            playerBullets.push_back(std::make_unique<PlayerBullet>(BulletType::ShotgunBullet, &Global::scene,
                Vector3(GetPlayerCenterPoint().x, GetPlayerCenterPoint().y, camera.getPosition().z), 
                Vector2(velocityX, velocityY)));

            keyPressed = true;

            shootDelay = 0.0f;
        }

        else if (!Input::isKeyPressed(S_KEY_SPACE) && keyPressed)
        {
            keyPressed = false;
        }

        // Reload weapon
        if (Input::isKeyPressed(S_KEY_R))
        {
            playerWeapons[1].ReloadWeapon();
        }

        break;

    case 3: // Micro SMG

        playerWeapons[0].HideWeapons();
        playerWeapons[1].HideWeapons();
        playerWeapons[2].UpdateWeapon();
        playerWeapons[3].HideWeapons();

        if (shootDelay <= 0.3f) shootDelay += 0.016f;

        // Fire weapon
        if (Input::isKeyPressed(S_KEY_SPACE) && playerWeapons[2].GetClipInMagazine() > 0 && shootDelay >= 0.2f
            && !keyPressed)
        {
            playerWeapons[2].ShootWeapon();

            playerBullets.push_back(std::make_unique<PlayerBullet>(BulletType::MicroSMGBullet, &Global::scene,
                Vector3(GetPlayerCenterPoint().x, GetPlayerCenterPoint().y, camera.getPosition().z), 
                Vector2(velocityX, velocityY)));

            keyPressed = true;

            shootDelay = 0.0f;
        }

        else if (!Input::isKeyPressed(S_KEY_SPACE) && keyPressed)
        {
            keyPressed = false;
        }

        // Reload weapon
        if (Input::isKeyPressed(S_KEY_R))
        {
            playerWeapons[2].ReloadWeapon();
        }

        break;

    case 4: // SMG

        playerWeapons[0].HideWeapons();
        playerWeapons[1].HideWeapons();
        playerWeapons[2].HideWeapons();
        playerWeapons[3].UpdateWeapon();

        if (shootDelay <= 0.3f) shootDelay += 0.016f;

        // Fire weapon
        if (Input::isKeyPressed(S_KEY_SPACE) && playerWeapons[3].GetClipInMagazine() > 0 && shootDelay >= 0.2f
            && !keyPressed)
        {
            playerWeapons[3].ShootWeapon();

            playerBullets.push_back(std::make_unique<PlayerBullet>(BulletType::SMGBullet, &Global::scene,
                Vector3(GetPlayerCenterPoint().x, GetPlayerCenterPoint().y, camera.getPosition().z), 
                Vector2(velocityX, velocityY)));

            keyPressed = true;

            shootDelay = 0.0f;
        }

        else if (!Input::isKeyPressed(S_KEY_SPACE) && keyPressed)
        {
            keyPressed = false;
        }

        // Reload weapon
        if (Input::isKeyPressed(S_KEY_R))
        {
            playerWeapons[3].ReloadWeapon();
        }

        break;

    default:
        break;
    }
}

void Game::SwitchBetweenWeapons()
{
    if (Input::isKeyPressed(S_KEY_Z) && weaponIndex > 1 && !switchWeaponKeyPressed)
    {
        weaponIndex -= 1;
        switchWeaponKeyPressed = true;
    }

    if (Input::isKeyPressed(S_KEY_X) && weaponIndex >= 1 && weaponIndex < 4 && !switchWeaponKeyPressed)
    {
        weaponIndex += 1;
        switchWeaponKeyPressed = true;
    }
    
    else if (!Input::isKeyPressed(S_KEY_Z) && !Input::isKeyPressed(S_KEY_X) && switchWeaponKeyPressed)
    {
        switchWeaponKeyPressed = false;
    }
}

void Game::HandleAmmoCollisions()
{
    // If player collides with pistol ammo
    if (ammoDrops[0].AmmoDropCollision(Vector2(x, y), Vector2(playerSizeX, playerSizeY)))
    {
        playerWeapons[0].IncreaseAmmo(8);
        ammoDrops[0].SetHideAmmo();
    }

    // If player collides with shotgun ammo
    else if (ammoDrops[1].AmmoDropCollision(Vector2(x, y), Vector2(playerSizeX, playerSizeY)))
    {
        playerWeapons[1].IncreaseAmmo(4);
        ammoDrops[1].SetHideAmmo();
    }

    // If player collides with micro SMG ammo
    else if (ammoDrops[2].AmmoDropCollision(Vector2(x, y), Vector2(playerSizeX, playerSizeY)))
    {
        playerWeapons[2].IncreaseAmmo(25);
        ammoDrops[2].SetHideAmmo();
    }

    // If player collides with SMG ammo
    else if (ammoDrops[3].AmmoDropCollision(Vector2(x, y), Vector2(playerSizeX, playerSizeY)))
    {
        playerWeapons[3].IncreaseAmmo(30);
        ammoDrops[3].SetHideAmmo();
    }
}

void Game::UpdatePlayerBullets()
{
    // Update player bullets for all elements
    for (int i = 0; i < playerBullets.size(); i++)
    {
        playerBullets[i]->UpdateBullet();
    }

    for (auto bulletIterator = playerBullets.begin(); bulletIterator != playerBullets.end();)
    {
        PlayerBullet* playerBullet = bulletIterator->get();

        // Destroy the bullet once its lifetime goes past a certain value
        if (playerBullet->GetBulletLifeTime() >= 1.5f)
        {
             bulletIterator = playerBullets.erase(bulletIterator);
        }

        else
        {
            ++bulletIterator; // Keep iterating through the player bullets
        }
    }
}

Vector2 Game::GetPlayerCenterPoint() const
{
    return Vector2(x + (static_cast<float>(playerSizeX) / 2.5f), y + (static_cast<float>(playerSizeY) / 2.5f));
}