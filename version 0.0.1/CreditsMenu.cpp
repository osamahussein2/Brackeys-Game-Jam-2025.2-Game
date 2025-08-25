#include "CreditsMenu.h"
#include "Global.h"

CreditsMenu::CreditsMenu(Scene* scene) : backButton{ scene, scene }, creditMembersText{ scene, scene, scene, scene, scene,
scene, scene }, textPosY(100.0f)
{
}

CreditsMenu::~CreditsMenu()
{
}

void CreditsMenu::InitializeCreditsMenu()
{
    // Back button initialization
    for (int i = 0; i < backButton.size(); i++) backButton[i].setAnchorPreset(AnchorPreset::CENTER_BOTTOM);

    backButton[0].setTexture("Buttons/BackButtonNormal.png"); // Normal button
    backButton[1].setTexture("Buttons/BackButtonHighlighted.png"); // Highlighted button

    for (int i = 0; i < backButton.size(); i++)
    {
        backButton[i].setTexturePressed("Buttons/BackButtonClicked.png");
        backButton[i].setPositionYOffset(-30.0f);
        backButton[i].setSize(buttonSizeX, buttonSizeY);
        backButton[i].getComponent<ButtonComponent>().onRelease = GoBackToMain;
    }

    backButton[0].setVisible(false);
    backButton[1].setVisible(false);

    // Credit members text initialization
    for (int i = 0; i < creditMembersText.size(); i++) creditMembersText[i].setAnchorPreset(AnchorPreset::CENTER);
    
    creditMembersText[0].setText("Programmers");
    creditMembersText[0].setColor(240.0f / 255.0f, 73.0f / 255.0f, 60.0f / 255.0f);
    creditMembersText[0].setFontSize(25.0f);

    creditMembersText[1].setText("Osama Hussein");
    creditMembersText[1].setColor(212.0f / 255.0f, 73.0f / 255.0f, 60.0f / 255.0f);
    creditMembersText[1].setFontSize(20.0f);

    creditMembersText[2].setText("XPG");
    creditMembersText[2].setColor(212.0f / 255.0f, 73.0f / 255.0f, 60.0f / 255.0f);
    creditMembersText[2].setFontSize(20.0f);

    creditMembersText[3].setText("2D Artist");
    creditMembersText[3].setColor(26.0f / 255.0f, 220.0f / 255.0f, 156.0f / 255.0f);
    creditMembersText[3].setFontSize(25.0f);

    creditMembersText[4].setText("Ali Wahbi");
    creditMembersText[4].setColor(26.0f / 255.0f, 188.0f / 255.0f, 156.0f / 255.0f);
    creditMembersText[4].setFontSize(20.0f);

    creditMembersText[5].setText("Sound/Music Composer");
    creditMembersText[5].setColor(52.0f / 255.0f, 143.0f / 255.0f, 235.0f / 255.0f);
    creditMembersText[5].setFontSize(25.0f);

    creditMembersText[6].setText("SquidTim");
    creditMembersText[6].setColor(52.0f / 255.0f, 143.0f / 255.0f, 206.0f / 255.0f);
    creditMembersText[6].setFontSize(20.0f);

    creditMembersText[0].setPositionOffset(Vector2(10.0f, 75.0f));
    creditMembersText[1].setPositionOffset(Vector2(10.0f, 100.0f));
    creditMembersText[2].setPositionOffset(Vector2(10.0f, 125.0f));
    creditMembersText[3].setPositionOffset(Vector2(10.0f, 175.0f));
    creditMembersText[4].setPositionOffset(Vector2(10.0f, 200.0f));
    creditMembersText[5].setPositionOffset(Vector2(10.0f, 250.0f));
    creditMembersText[6].setPositionOffset(Vector2(10.0f, 275.0f));

    for (int i = 0; i < creditMembersText.size(); i++)
    {
        creditMembersText[i].setVisible(false);
    }
}

void CreditsMenu::UpdateCreditsMenu()
{
    ScrollingCredits();
    UpdateBackButtonInteraction();
}

void CreditsMenu::HideCreditsMenu()
{
    if (backButton[0].isVisible()) backButton[0].setVisible(false);
    if (backButton[1].isVisible()) backButton[1].setVisible(false);

    for (int i = 0; i < creditMembersText.size(); i++)
    {
        if (creditMembersText[i].isVisible()) creditMembersText[i].setVisible(false);
    }

    if (textPosY != 100.0f) textPosY = 100.0f; // Reset credit members texts back to its original position
}

void CreditsMenu::GoBackToMain()
{
	Global::gameState = GameState::MainMenu;
}

void CreditsMenu::ScrollingCredits()
{
    // Start scrolling credit members text
    textPosY -= 0.016f * 100.0f;

    // Change its position over time
    creditMembersText[0].setPositionOffset(Vector2(10.0f, 75.0f + textPosY));
    creditMembersText[1].setPositionOffset(Vector2(10.0f, 100.0f + textPosY));
    creditMembersText[2].setPositionOffset(Vector2(10.0f, 125.0f + textPosY));
    creditMembersText[3].setPositionOffset(Vector2(10.0f, 175.0f + textPosY));
    creditMembersText[4].setPositionOffset(Vector2(10.0f, 200.0f + textPosY));
    creditMembersText[5].setPositionOffset(Vector2(10.0f, 250.0f + textPosY));
    creditMembersText[6].setPositionOffset(Vector2(10.0f, 275.0f + textPosY));

    for (int i = 0; i < creditMembersText.size(); i++)
    {
        // Show the credit members texts once they are nearly at the center of the screen
        if (creditMembersText[i].getPositionYOffset() <= 125.0f)
        {
            if (!creditMembersText[i].isVisible()) creditMembersText[i].setVisible(true);
        }

        // Otherwise, hide the credit members texts
        else
        {
            if (creditMembersText[i].isVisible()) creditMembersText[i].setVisible(false);
        }
    }

    // Reset scrolling credits after they all reach the top of the screen
    if (creditMembersText[0].getPositionYOffset() <= -350.0f && creditMembersText[1].getPositionYOffset() <= -350.0f &&
        creditMembersText[2].getPositionYOffset() <= -350.0f && creditMembersText[3].getPositionYOffset() <= -350.0f &&
        creditMembersText[4].getPositionYOffset() <= -350.0f && creditMembersText[5].getPositionYOffset() <= -350.0f &&
        creditMembersText[6].getPositionYOffset() <= -350.0f)
    {
        textPosY = 100.0f;
    }
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
            MouseCursor::mouseY <= backButton[i].getPosition().y + buttonSizeY)
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
