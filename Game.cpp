#include "Game.h"
#include "ImageManager.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Game::Game() :  imageManager( 0 ) , sprite( 0 ), running( false )
{
}

Game::~Game()
{
}

void Game::handleEvent( const sf::Event & event ) {
  if ( event.Type == sf::Event::Closed ) {
    window->Close();
    running = false;
  }
}

void Game::init()
{
  window = new sf::RenderWindow( sf::VideoMode( 800 , 600 , 32 ) , "Game" );
  imageManager = new ImageManager;

  sprite = new sf::Sprite;
  sprite->SetImage( imageManager->getImage( "pony.png" ) );
  sprite->SetPosition( 200.f , 100.f );

  view = new sf::View( sf::FloatRect( 300 , 350 , 700 , 650 ) );
  running = true;

  window->SetView( *view );
}

void Game::updateLogic()
{
  float elapsedTime = window->GetFrameTime();
  if ( window->GetInput().IsKeyDown( sf::Key::Left ) ) {
    view->Move( -100 * elapsedTime , 0 );
  }
  if ( window->GetInput().IsKeyDown( sf::Key::Right ) ) {
    view->Move( 100 * elapsedTime , 0 );
  }
  if ( window->GetInput().IsKeyDown( sf::Key::Up ) ) {
    view->Move( 0 , -100 * elapsedTime );
  }
  if ( window->GetInput().IsKeyDown( sf::Key::Down ) ) {
    view->Move( 0 , 100 * elapsedTime );
  }
}

void Game::draw()
{
  window->Clear();
  window->Draw( *sprite );
  window->Display();
}

void Game::run()
{
  init();
  
  while ( running ) {
    sf::Event event;

    while ( window->GetEvent( event ) ) {
      handleEvent( event );
    }

    updateLogic();

    draw();
  }

  cleanup();
}

void Game::cleanup()
{
  delete imageManager;
  delete window;
  delete view;
  delete sprite;
}

