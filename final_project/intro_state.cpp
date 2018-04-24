

#include "intro_state.h"


intro_state* intro_state::pinstance = 0;
intro_state* intro_state::Instance()
{
    if(pinstance == 0)
    {
        pinstance = new intro_state;
    }
    return pinstance;
}

intro_state::intro_state()
{
    Init();
}

void intro_state::Init()
{
    background.setSpriteTexture(INTRO_STATE_BACKGROUND_FILEPATH);
    background.setAlpha(0);
    //background.getSprite()->setColor(sf::Color(255, 255, 255, 0));

    skipText.setText("Press Space to skip");
    skipText.setSize(24);
    skipText.setColor(0, 0, 0);
    skipText.setOriginCenter();
    skipText.setPos(WINDOW_WIDTH - (skipText.getText().getGlobalBounds().width * 0.6), WINDOW_HEIGHT / 1.07);
    
    
    
    
    
    
    f.setSize(200.f, 200.f);
    f.setTexture(MENU_STATE_BACKGROUND_FILEPATH);
//    f.setColor(255, 0, 0);
    f.setOutlineThickness(3.f);
//    f.setOutlineColor(0, 0, 0);
    f.setOriginCenter();
    f.setPos(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    
    
    Motor2D::Instance()->getWindow()->setMouseCursorVisible(false);
}

void intro_state::HandleInput()
{
    sf::Event evento;
    while(Motor2D::Instance()->getWindow()->pollEvent(evento))
    {
        if(sf::Event::Closed == evento.type)
        {
            Motor2D::Instance()->closeWindow();
        }
        if(Keyboard::isKeySpacePressed())
        {
            Game::instance()->setState(menu_state::Instance());
        }
    }
}

void intro_state::Update()
{
    if(stateTimer.getSeconds() >= INTRO_STATE_TIME)
    {
        Game::instance()->setState(menu_state::Instance());
    }

    if(skipTextTimer.getSeconds() >= 0.5f)
    {
        static_cast<int>(skipText.getAlpha()) == 0 ? skipText.setAlpha(255) : skipText.setAlpha(0);
        skipTextTimer.reset();
    }
    
    if(stateTimer.getSeconds() < INTRO_STATE_TRANSITION_TIME) 
    {
        beginAlpha();
    }
    
    if(stateTimer.getSeconds() > INTRO_STATE_TRANSITION_TIME + INTRO_STATE_TIME / 4) 
    {
        endAlpha();
    }   
}

void intro_state::Draw()
{
    background.draw();
    skipText.draw();
    b.draw();
}

void intro_state::beginAlpha() // animacion del principio
{
    int alpha = background.getAlpha() + INTRO_STATE_TRANSITION_SPEED;
    
    if(alpha >= 255)
    {
        alpha = 255;
    }
    background.setAlpha(alpha);
}
void intro_state::endAlpha() // animacion del final
{
    int alpha = background.getAlpha() - (INTRO_STATE_TRANSITION_SPEED);
        
    if(alpha <= 0)
    {
        alpha = 0;
    }
    background.setAlpha(alpha);
}