#include "SplashScreen.h"
#include "Global.h"

SplashScreen::SplashScreen(Scene* scene) : supernovaLogo(scene), alpha(0.0f), timeUntilSwitchImages(0.0f),
alphaStateChanged(false), whenToShowImage(0.0f)
{
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::InitializeSplashScreen()
{
    supernovaLogo.setAnchorPreset(AnchorPreset::CENTER);
    supernovaLogo.setTexture("supernova.png");

    supernovaLogo.setAlpha(alpha);
    supernovaLogo.setVisible(false);
}

void SplashScreen::UpdateSplashScreen()
{
    if (!supernovaLogo.isVisible()) supernovaLogo.setVisible(true);

    supernovaLogo.setAlpha(alpha);

    // Increment the timer until a certain time threshold for showing the image
    if (whenToShowImage <= 1.1f) whenToShowImage += 0.016f;

    // Decrease its alpha once it's changed
    if (alphaStateChanged && alpha > -0.01f) alpha -= 0.016f;

    // Increase its alpha whenever it's not changed yet
    else if (!alphaStateChanged && alpha < 1.01f && whenToShowImage >= 1.0f) alpha += 0.016f;

    // Increase the time for transition
    if (alpha <= 0.0f && alphaStateChanged)
    {
        timeUntilSwitchImages += 0.016f;
    }

    // Increase the time for transition here as well
    else if (alpha >= 1.0f && !alphaStateChanged)
    {
        timeUntilSwitchImages += 0.016f;

        // Change alpha state after the set threshold
        if (timeUntilSwitchImages >= 1.0f)
        {
            alphaStateChanged = true;
        }
    }

    if (SplashScreenFinished())
    {
        Global::gameState = GameState::MainMenu;
    }
}

bool SplashScreen::SplashScreenFinished()
{
    return alpha <= 0.0f && alphaStateChanged && timeUntilSwitchImages >= 1.0f;
}
