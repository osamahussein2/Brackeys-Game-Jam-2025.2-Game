#include "MainMenu.h"
#include "Global.h"

MainMenu::MainMenu(Scene* scene) : playButton{ scene, scene }, creditsButton{ scene, scene }, quitButton{ scene, scene }
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
            MouseCursor::mouseY <= playButton[i].getPosition().y + buttonSizeY)
        {
            // Show highlighted play button and hide the normal play button
            if (!playButton[1].isVisible())
            {
                if (playButton[0].isVisible()) playButton[0].setVisible(false);
                playButton[1].setVisible(true);
            }
        }

        // Otherwise, hide highlighted play button and show the normal play button again
        else
        {
            if (!playButton[0].isVisible())
            {
                playButton[0].setVisible(true);
                if (playButton[1].isVisible()) playButton[1].setVisible(false);
            }
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
            MouseCursor::mouseY <= creditsButton[i].getPosition().y + buttonSizeY)
        {
            // Show highlighted credits button and hide the normal credits button
            if (!creditsButton[1].isVisible())
            {
                if (creditsButton[0].isVisible()) creditsButton[0].setVisible(false);
                creditsButton[1].setVisible(true);
            }
        }

        // Otherwise, hide highlighted credits button and show the normal credits button again
        else
        {
            if (!creditsButton[0].isVisible())
            {
                creditsButton[0].setVisible(true);
                if (creditsButton[1].isVisible()) creditsButton[1].setVisible(false);
            }
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
            MouseCursor::mouseY <= quitButton[i].getPosition().y + buttonSizeY)
        {
            // Show highlighted quit button and hide the normal quit button
            if (!quitButton[1].isVisible())
            {
                if (quitButton[0].isVisible()) quitButton[0].setVisible(false);
                quitButton[1].setVisible(true);
            }
        }

        // Otherwise, hide highlighted quit button and show the normal quit button again
        else
        {
            if (!quitButton[0].isVisible())
            {
                quitButton[0].setVisible(true);
                if (quitButton[1].isVisible()) quitButton[1].setVisible(false);
            }
        }
    }
}
