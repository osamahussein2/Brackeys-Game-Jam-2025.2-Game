#include "PauseMenu.h"
#include "Global.h"

PauseMenu::PauseMenu(Scene* scene) : resumeButton{ scene, scene }, quitButton{ scene, scene }, selectedOption(0), 
keyPressed(false), pauseTitleText(scene)
{

}

PauseMenu::~PauseMenu()
{

}

void PauseMenu::InitializePauseMenu()
{
    for (int i = 0; i < resumeButton.size(); i++) resumeButton[i].setAnchorPreset(AnchorPreset::CENTER);

    resumeButton[0].setTexture("Buttons/ResumeButtonNormal.png"); // Normal button
    resumeButton[1].setTexture("Buttons/ResumeButtonHighlighted.png"); // Highlighted button

    for (int i = 0; i < resumeButton.size(); i++)
    {
        resumeButton[i].setTexturePressed("Buttons/ResumeButtonClicked.png");
        resumeButton[i].setPositionYOffset(20.0f);
        resumeButton[i].setSize(buttonSizeX, buttonSizeY);
        resumeButton[i].getComponent<ButtonComponent>().onRelease = ResumeGame;
    }

    for (int i = 0; i < quitButton.size(); i++) quitButton[i].setAnchorPreset(AnchorPreset::CENTER);

    quitButton[0].setTexture("Buttons/ExitButtonNormal.png"); // Normal button
    quitButton[1].setTexture("Buttons/ExitButtonHighlighted.png"); // Highlighted button

    for (int i = 0; i < quitButton.size(); i++)
    {
        quitButton[i].setTexturePressed("Buttons/ExitButtonClicked.png");
        quitButton[i].setPositionYOffset(120.0f);
        quitButton[i].setSize(buttonSizeX, buttonSizeY);
        quitButton[i].getComponent<ButtonComponent>().onRelease = QuitToMain;
    }

    // Initialize pause title text
    pauseTitleText.setAnchorPreset(AnchorPreset::CENTER_TOP);
    pauseTitleText.setPositionYOffset(30.0f);
    pauseTitleText.setText("Game Paused!");
    pauseTitleText.setFontSize(40);
    pauseTitleText.setColor(1.0f, 1.0f, 1.0f);

    // Set all buttons to be invisible at start of game
    resumeButton[0].setVisible(false);
    resumeButton[1].setVisible(false);

    quitButton[0].setVisible(false);
    quitButton[1].setVisible(false);

    // Make the pause title text invisible as well
    pauseTitleText.setVisible(false);
}

void PauseMenu::UpdatePauseMenu()
{
    if (!pauseTitleText.isVisible()) pauseTitleText.setVisible(true);

    UpdateResumeButtonInteraction();
    UpdateQuitButtonInteraction();

    SwitchBetweenMenuOption();

    HandleInput();
}

void PauseMenu::HidePauseMenu()
{
    if (pauseTitleText.isVisible()) pauseTitleText.setVisible(false);

    if (resumeButton[0].isVisible()) resumeButton[0].setVisible(false);
    if (resumeButton[1].isVisible()) resumeButton[1].setVisible(false);

    if (quitButton[0].isVisible()) quitButton[0].setVisible(false);
    if (quitButton[1].isVisible()) quitButton[1].setVisible(false);

    if (selectedOption != 0) selectedOption = 0; // Default to highlight the resume button
}

void PauseMenu::ResumeGame()
{
    Global::gameState = GameState::Playing;
}

void PauseMenu::QuitToMain()
{
    Global::gameState = GameState::MainMenu;
}

void PauseMenu::UpdateResumeButtonInteraction()
{
    // Update resume button
    for (int i = 0; i < resumeButton.size(); i++)
    {
        // If mouse hovers on resume button
        if (MouseCursor::mouseX >= resumeButton[i].getPosition().x &&
            MouseCursor::mouseX <= resumeButton[i].getPosition().x + buttonSizeX &&
            MouseCursor::mouseY >= resumeButton[i].getPosition().y &&
            MouseCursor::mouseY <= resumeButton[i].getPosition().y + buttonSizeY && selectedOption != 0)
        {
            // Show highlighted resume button and hide the normal resume button
            selectedOption = 0;
        }
    }
}

void PauseMenu::UpdateQuitButtonInteraction()
{
    // Update quit button
    for (int i = 0; i < quitButton.size(); i++)
    {
        // If mouse hovers on quit button
        if (MouseCursor::mouseX >= quitButton[i].getPosition().x &&
            MouseCursor::mouseX <= quitButton[i].getPosition().x + buttonSizeX &&
            MouseCursor::mouseY >= quitButton[i].getPosition().y &&
            MouseCursor::mouseY <= quitButton[i].getPosition().y + buttonSizeY && selectedOption != 1)
        {
            // Show highlighted quit button and hide the normal quit button
            selectedOption = 1;
        }
    }
}

void PauseMenu::SwitchBetweenMenuOption()
{
    switch (selectedOption)
    {
    case 0: // Play button

        if (Input::isKeyPressed(S_KEY_ENTER))
        {
            Global::gameState = GameState::Playing;
        }

        if (!resumeButton[1].isVisible()) // Show hightlighted resume button
        {
            if (resumeButton[0].isVisible()) resumeButton[0].setVisible(false);
            resumeButton[1].setVisible(true);
        }

        if (quitButton[1].isVisible() || !quitButton[0].isVisible()) // Hide highlighted quit button
        {
            quitButton[0].setVisible(true);
            quitButton[1].setVisible(false);
        }

        break;

    case 1: // Quit button

        if (Input::isKeyPressed(S_KEY_ENTER) && !Global::enterKeyPressed)
        {
            Global::gameState = GameState::MainMenu;
            Global::enterKeyPressed = true;
        }

        else if (!Input::isKeyPressed(S_KEY_ENTER) && Global::enterKeyPressed)
        {
            Global::enterKeyPressed = false;
        }

        if (!quitButton[1].isVisible()) // Show hightlighted quit button
        {
            if (quitButton[0].isVisible()) quitButton[0].setVisible(false);
            quitButton[1].setVisible(true);
        }

        if (resumeButton[1].isVisible() || !resumeButton[0].isVisible()) // Hide highlighted resume button
        {
            resumeButton[0].setVisible(true);
            resumeButton[1].setVisible(false);
        }

        break;

    default:

        selectedOption = 0; // Reset to first option
        break;
    }
}

void PauseMenu::HandleInput()
{
    // Press ESCAPE to resume gameplay
    if (Input::isKeyPressed(S_KEY_ESCAPE) && !Global::escapeKeyPressed)
    {
        Global::gameState = GameState::Playing;
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
    if (Input::isKeyPressed(S_KEY_DOWN) && selectedOption >= 0 && selectedOption < 1 && !keyPressed)
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