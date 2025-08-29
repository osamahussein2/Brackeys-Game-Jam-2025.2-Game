#include "BrackeysLogo.h"
#include "Global.h"

BrackeysLogo::BrackeysLogo(Scene* scene) : brackeysLogo(scene), animationStarted(false), frameNumber(0)
{
}

BrackeysLogo::~BrackeysLogo()
{
}

void BrackeysLogo::InitializeBrackeysLogo()
{
    // Initialize brackeys logo
    brackeysLogo.setTexture("Sprites/Logo-1.png");

    for (int i = 0; i < 12; i++)
    {
        brackeysLogo.addFrame(i, "", Rect((static_cast<int>(frameNumber) + 1.0) / 12, 0, 1.0 / 12, 1));
    }

    brackeysLogo.setFrame(0);
    brackeysLogo.setPosition(300.0f, 370.0f, 0.0f);
    brackeysLogo.setName("BrackeysLogo");
    brackeysLogo.setSize(400, 250);

    brackeysLogo.setVisible(false);
}

void BrackeysLogo::UpdateBrackeysLogo()
{
    if (!brackeysLogo.isVisible()) brackeysLogo.setVisible(true);

    if (!animationStarted)
    {
        brackeysLogo.startAnimation(0, 11, 200, true);

        animationStarted = true;
    }

    else
    {
        frameNumber += 0.016f * animationSpeed;

        for (int i = 0; i < 12; i++)
        {
            brackeysLogo.addFrame(i, "", Rect((static_cast<int>(frameNumber) + 1.0) / 12, 0, 1.0 / 12, 1));
        }

        if (frameNumber >= 11.0f)
        {
            Global::gameState = GameState::Playing;
            animationStarted = false;

            frameNumber = 0.0f;

            HideBrackeysLogo();
        }
    }
}

void BrackeysLogo::CleanBrackeysLogo()
{
    brackeysLogo.clearInstances();
}

void BrackeysLogo::HideBrackeysLogo()
{
    if (brackeysLogo.isVisible()) brackeysLogo.setVisible(false);
}