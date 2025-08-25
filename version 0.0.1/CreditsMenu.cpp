#include "CreditsMenu.h"
#include "Global.h"

CreditsMenu::CreditsMenu(Scene* scene) : backButton{ scene, scene }
{
}

CreditsMenu::~CreditsMenu()
{
}

void CreditsMenu::InitializeCreditsMenu()
{
    for (int i = 0; i < backButton.size(); i++) backButton[i].setAnchorPreset(AnchorPreset::CENTER_BOTTOM);

    backButton[0].setTexture("Buttons/StartButtonNormal.png"); // Normal button
    backButton[1].setTexture("Buttons/StartButtonHighlighted.png"); // Highlighted button

    for (int i = 0; i < backButton.size(); i++)
    {
        backButton[i].setTexturePressed("Buttons/StartButtonClicked.png");
        backButton[i].setPositionYOffset(-100.0f);
        backButton[i].setSize(buttonSizeX, buttonSizeY);
        backButton[i].getComponent<ButtonComponent>().onRelease = GoBackToMain;
    }

    backButton[0].setVisible(false);
    backButton[1].setVisible(false);
}

void CreditsMenu::UpdateCreditsMenu()
{
	UpdateBackButtonInteraction();
}

void CreditsMenu::HideCreditsMenu()
{
    if (backButton[0].isVisible()) backButton[0].setVisible(false);
    if (backButton[1].isVisible()) backButton[1].setVisible(false);
}

void CreditsMenu::GoBackToMain()
{
	Global::gameState = GameState::MainMenu;
}

void CreditsMenu::UpdateBackButtonInteraction()
{
    // Update back button
    for (int i = 0; i < backButton.size(); i++)
    {
        // If mouse hovers on back button
        if (MouseCursor::mouseX >= backButton[i].getPosition().x &&
            MouseCursor::mouseX <= backButton[i].getPosition().x + buttonSizeX &&
            MouseCursor::mouseY >= backButton[i].getPosition().y &&
            MouseCursor::mouseY <= backButton[i].getPosition().y + buttonSizeY &&
            !backButton[i].getComponent<ButtonComponent>().pressed)
        {
            // Show highlighted back button and hide the normal back button
            if (!backButton[1].isVisible())
            {
                if (backButton[0].isVisible()) backButton[0].setVisible(false);
                backButton[1].setVisible(true);
            }
        }

        // Otherwise, hide highlighted back button and show the normal back button again
        else
        {
            if (!backButton[0].isVisible())
            {
                backButton[0].setVisible(true);
                if (backButton[1].isVisible()) backButton[1].setVisible(false);
            }
        }
    }
}
