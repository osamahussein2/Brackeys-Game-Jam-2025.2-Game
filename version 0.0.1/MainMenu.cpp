#include "MainMenu.h"
#include "Global.h"

MainMenu::MainMenu(Scene* scene) : playButton{ scene, scene }, creditsButton{ scene, scene }, quitButton{ scene, scene },
selectedOption(0), keyPressed(false)
{

}

MainMenu::~MainMenu()
{

}

void MainMenu::InitializeMainMenu()
{
    for (int i = 0; i < playButton.size(); i++) playButton[i].setAnchorPreset(AnchorPreset::CENTER);

    playButton[0].setTexture("Buttons/StartButtonNormal.png"); // Normal button
    playButton[1].setTexture("Buttons/StartButtonHighlighted.png"); // Highlighted button

    for (int i = 0; i < playButton.size(); i++)
    {
        playButton[i].setTexturePressed("Buttons/StartButtonClicked.png");
        playButton[i].setPositionYOffset(20.0f);
        playButton[i].setSize(buttonSizeX, buttonSizeY);
        playButton[i].getComponent<ButtonComponent>().onRelease = PlayGame;
    }

    for (int i = 0; i < creditsButton.size(); i++) creditsButton[i].setAnchorPreset(AnchorPreset::CENTER);

    creditsButton[0].setTexture("Buttons/CreditsButtonNormal.png"); // Normal button
    creditsButton[1].setTexture("Buttons/CreditsButtonHighlighted.png"); // Highlighted button

    for (int i = 0; i < creditsButton.size(); i++)
    {
        creditsButton[i].setTexturePressed("Buttons/CreditsButtonClicked.png");
        creditsButton[i].setPositionYOffset(110.0f);
        creditsButton[i].setSize(buttonSizeX, buttonSizeY);
        creditsButton[i].getComponent<ButtonComponent>().onRelease = Credits;
    }
    
    for (int i = 0; i < quitButton.size(); i++) quitButton[i].setAnchorPreset(AnchorPreset::CENTER);
    
    quitButton[0].setTexture("Buttons/ExitButtonNormal.png"); // Normal button
    quitButton[1].setTexture("Buttons/ExitButtonHighlighted.png"); // Highlighted button

    for (int i = 0; i < quitButton.size(); i++)
    {
        quitButton[i].setTexturePressed("Buttons/ExitButtonClicked.png");
        quitButton[i].setPositionYOffset(200.0f);
        quitButton[i].setSize(buttonSizeX, buttonSizeY);
        quitButton[i].getComponent<ButtonComponent>().onRelease = QuitGame;
    }

    // Set all buttons to be invisible at start of game
    playButton[0].setVisible(false);
    playButton[1].setVisible(false);

    creditsButton[0].setVisible(false);
    creditsButton[1].setVisible(false);

    quitButton[0].setVisible(false);
    quitButton[1].setVisible(false);
}

void MainMenu::UpdateMainMenu()
{
    UpdatePlayButtonInteraction();
    UpdateCreditsButtonInteraction();
    UpdateQuitButtonInteraction();

    SwitchBetweenMenuOption();

    HandleInput();
}

void MainMenu::HideMainMenu()
{
    if (playButton[0].isVisible()) playButton[0].setVisible(false);
    if (playButton[1].isVisible()) playButton[1].setVisible(false);

    if (creditsButton[0].isVisible()) creditsButton[0].setVisible(false);
    if (creditsButton[1].isVisible()) creditsButton[1].setVisible(false);

    if (quitButton[0].isVisible()) quitButton[0].setVisible(false);
    if (quitButton[1].isVisible()) quitButton[1].setVisible(false);
}

void MainMenu::PlayGame()
{
    Global::gameState = GameState::Playing;
}

void MainMenu::Credits()
{
    Global::gameState = GameState::Credits;
}

void MainMenu::QuitGame()
{
    sapp_request_quit();
}

void MainMenu::UpdatePlayButtonInteraction()
{
    // Update play button
    for (int i = 0; i < playButton.size(); i++)
    {
        // If mouse hovers on play button
        if (MouseCursor::mouseX >= playButton[i].getPosition().x &&
            MouseCursor::mouseX <= playButton[i].getPosition().x + buttonSizeX &&
            MouseCursor::mouseY >= playButton[i].getPosition().y &&
            MouseCursor::mouseY <= playButton[i].getPosition().y + buttonSizeY && selectedOption != 0)
        {
            // Show highlighted play button and hide the normal play button
            selectedOption = 0;
        }
    }
}

void MainMenu::UpdateCreditsButtonInteraction()
{
    // Update credits button
    for (int i = 0; i < creditsButton.size(); i++)
    {
        // If mouse hovers on credits button
        if (MouseCursor::mouseX >= creditsButton[i].getPosition().x &&
            MouseCursor::mouseX <= creditsButton[i].getPosition().x + buttonSizeX &&
            MouseCursor::mouseY >= creditsButton[i].getPosition().y &&
            MouseCursor::mouseY <= creditsButton[i].getPosition().y + buttonSizeY && selectedOption != 1)
        {
            // Show highlighted credits button and hide the normal credits button
            selectedOption = 1;
        }
    }
}

void MainMenu::UpdateQuitButtonInteraction()
{
    // Update quit button
    for (int i = 0; i < quitButton.size(); i++)
    {
        // If mouse hovers on quit button
        if (MouseCursor::mouseX >= quitButton[i].getPosition().x &&
            MouseCursor::mouseX <= quitButton[i].getPosition().x + buttonSizeX &&
            MouseCursor::mouseY >= quitButton[i].getPosition().y &&
            MouseCursor::mouseY <= quitButton[i].getPosition().y + buttonSizeY && selectedOption != 2)
        {
            // Show highlighted quit button and hide the normal quit button
            selectedOption = 2;
        }
    }
}

void MainMenu::SwitchBetweenMenuOption()
{
    switch (selectedOption)
    {
    case 0: // Play button

        if (Input::isKeyPressed(S_KEY_ENTER))
        {
            Global::gameState = GameState::Playing;
        }

        if (!playButton[1].isVisible()) // Show hightlighted play button
        {
            if (playButton[0].isVisible()) playButton[0].setVisible(false);
            playButton[1].setVisible(true);
        }

        if (creditsButton[1].isVisible() || !creditsButton[0].isVisible()) // Hide highlighted credits button
        {
            creditsButton[0].setVisible(true);
            creditsButton[1].setVisible(false);
        }

        if (quitButton[1].isVisible() || !quitButton[0].isVisible()) // Hide highlighted quit button
        {
            quitButton[0].setVisible(true);
            quitButton[1].setVisible(false);
        }

        break;

    case 1: // Credits button

        if (Input::isKeyPressed(S_KEY_ENTER))
        {
            Global::gameState = GameState::Credits;
        }

        if (!creditsButton[1].isVisible()) // Show hightlighted credits button
        {
            if (creditsButton[0].isVisible()) creditsButton[0].setVisible(false);
            creditsButton[1].setVisible(true);
        }

        if (playButton[1].isVisible() || !playButton[0].isVisible()) // Hide highlighted play button
        {
            playButton[0].setVisible(true);
            playButton[1].setVisible(false);
        }

        if (quitButton[1].isVisible() || !quitButton[0].isVisible()) // Hide highlighted quit button
        {
            quitButton[0].setVisible(true);
            quitButton[1].setVisible(false);
        }

        break;

    case 2: // Exit button

        if (Input::isKeyPressed(S_KEY_ENTER))
        {
            sapp_request_quit();
        }

        if (!quitButton[1].isVisible()) // Show hightlighted quit button
        {
            if (quitButton[0].isVisible()) quitButton[0].setVisible(false);
            quitButton[1].setVisible(true);
        }

        if (playButton[1].isVisible() || !playButton[0].isVisible()) // Hide highlighted play button
        {
            playButton[0].setVisible(true);
            playButton[1].setVisible(false);
        }

        if (creditsButton[1].isVisible() || !creditsButton[0].isVisible()) // Hide highlighted credits button
        {
            creditsButton[0].setVisible(true);
            creditsButton[1].setVisible(false);
        }

        break;

    default:

        selectedOption = 0; // Reset to first option
        break;
    }
}

void MainMenu::HandleInput()
{
    // Press ESCAPE in the main menu to quit the game
    if (Input::isKeyPressed(S_KEY_ESCAPE) && !Global::escapeKeyPressed)
    {
        sapp_request_quit();
        Global::escapeKeyPressed = true;
    }

    // Disable the escape key press once ESCAPE key is released
    else if (!Input::isKeyPressed(S_KEY_ESCAPE) && Global::escapeKeyPressed)
    {
        Global::escapeKeyPressed = false;
    }

    // Navigate the selected button by going up
    if (Input::isKeyPressed(S_KEY_UP) && selectedOption > 0 && !keyPressed)
    {
        selectedOption -= 1;
        keyPressed = true;
    }

    // Navigate the selected button by going down
    if (Input::isKeyPressed(S_KEY_DOWN) && selectedOption >= 0 && selectedOption < 2 && !keyPressed)
    {
        selectedOption += 1;
        keyPressed = true;
    }

    // Disable key press once both inputs aren't pressed
    else if (!Input::isKeyPressed(S_KEY_UP) && !Input::isKeyPressed(S_KEY_DOWN) && keyPressed)
    {
        keyPressed = false;
    }
}
