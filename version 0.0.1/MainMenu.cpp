#include "MainMenu.h"
#include "Global.h"

MainMenu::MainMenu(Scene* scene) : playButton{ scene, scene }, creditsButton(scene), quitButton{ scene, scene }
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
        playButton[i].setPositionYOffset(-150.0f);
        playButton[i].setSize(200, 100);
        playButton[i].getComponent<ButtonComponent>().onRelease = PlayGame;
    }

    creditsButton.setAnchorPreset(AnchorPreset::CENTER);
    creditsButton.setColor(1.0f, 0.0f, 0.0f);
    creditsButton.setColorPressed(0.5f, 0.0f, 0.0f);
    creditsButton.setSize(buttonSizeX, buttonSizeY);
    creditsButton.setLabel("Credits");
    creditsButton.setLabelFontSize(50);
    creditsButton.setLabelColor(Vector4(0.2f, 0.2f, 0.2f, 1.0f));
    creditsButton.getComponent<ButtonComponent>().onRelease = Credits;
    
    for (int i = 0; i < quitButton.size(); i++) quitButton[i].setAnchorPreset(AnchorPreset::CENTER);
    
    quitButton[0].setTexture("Buttons/ExitButtonNormal.png"); // Normal button
    quitButton[1].setTexture("Buttons/ExitButtonHighlighted.png"); // Highlighted button

    for (int i = 0; i < quitButton.size(); i++)
    {
        quitButton[i].setTexturePressed("Buttons/ExitButtonClicked.png");
        quitButton[i].setPositionYOffset(150.0f);
        quitButton[i].setSize(200, 100);
        quitButton[i].getComponent<ButtonComponent>().onRelease = QuitGame;
    }

    // 
    playButton[0].setVisible(false);
    playButton[1].setVisible(false);

    creditsButton.setVisible(false);

    // 
    quitButton[0].setVisible(false);
    quitButton[1].setVisible(false);
}

void MainMenu::UpdateMainMenu()
{
    if (!creditsButton.isVisible()) creditsButton.setVisible(true);

    UpdatePlayButtonInteraction();
    UpdateQuitButtonInteraction();
}

void MainMenu::HideMainMenu()
{
    if (playButton[0].isVisible()) playButton[0].setVisible(false);
    if (playButton[1].isVisible()) playButton[1].setVisible(false);

    if (creditsButton.isVisible()) creditsButton.setVisible(false);

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
            MouseCursor::mouseY <= playButton[i].getPosition().y + buttonSizeY &&
            !playButton[i].getComponent<ButtonComponent>().pressed)
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

void MainMenu::UpdateQuitButtonInteraction()
{
    // Update quit button
    for (int i = 0; i < quitButton.size(); i++)
    {
        // If mouse hovers on quit button
        if (MouseCursor::mouseX >= quitButton[i].getPosition().x &&
            MouseCursor::mouseX <= quitButton[i].getPosition().x + buttonSizeX &&
            MouseCursor::mouseY >= quitButton[i].getPosition().y &&
            MouseCursor::mouseY <= quitButton[i].getPosition().y + buttonSizeY &&
            !quitButton[i].getComponent<ButtonComponent>().pressed)
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
