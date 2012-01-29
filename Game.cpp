#include "Game.h"
#include "Tile.h"
#include "PlayerEntity.h"
#include "ImageManager.h"
#include "LevelBuilder.h"
#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace std;

Game::Game() :  imageManager( 0 ) , player( 0 ) , running( false )
{
}

Game::~Game()
{
}

void Game::handleEvent( const sf::Event & event ) {
  if ( event.Type == sf::Event::Closed ) {
    running = false;
  }
  if ( event.Type == sf::Event::KeyPressed ) {
    switch ( event.Key.Code ) {
      case sf::Key::Escape :
          running = false;
          break;
      default :
          break;
    }
  }
}

void Game::init()
{
  cout << "Initializing..." << endl;
  window = new sf::RenderWindow( sf::VideoMode( 800 , 600 , 32 ) , "Game" );
  window->UseVerticalSync( true );
  window->SetFramerateLimit( 60 );
  imageManager = new ImageManager;

  running = true;

  player = new PlayerEntity( window , imageManager, 100 , 100 );
  builder = new LevelBuilder();

  int * map = builder->createMap( 50 , 50 );
  tileMap = new Tile[50*50];
  for ( int i = 0 ; i < 2500 ; ++i ) {
    tileMap[i] = Tile( window , imageManager , i % 50 * 32 ,
                       i / 50 * 32 , map[i] );
  }

  window->SetView( *(player->getPlayerView()) );

  cout << "Finished initialization..." << endl;

}

void Game::updateLogic()
{
  float elapsedTime = window->GetFrameTime();
  if ( window->GetInput().IsKeyDown( sf::Key::Left ) ) {
    player->moveLeft( elapsedTime );
  }
  if ( window->GetInput().IsKeyDown( sf::Key::Right ) ) {
    player->moveRight( elapsedTime );
  }
  if ( window->GetInput().IsKeyDown( sf::Key::Up ) ) {
    player->moveUp( elapsedTime );
  }
  if ( window->GetInput().IsKeyDown( sf::Key::Down ) ) {
    player->moveDown( elapsedTime );
  }
}

void Game::draw()
{
  window->Clear();
  for ( int i = 0 ; i < 2500 ; ++i ) {
    tileMap[i].render();
  }
  player->render();
  window->Display();
}

void Game::run()
{
  init();
  
  float timePerFrame = 1.0;

  sf::Clock clock;

  while ( running ) {
    sf::Event event;

    while ( window->GetEvent( event ) ) {
      handleEvent( event );
    }

    updateLogic();

    draw();
    if ( clock.GetElapsedTime() < timePerFrame )  {
      usleep( 1000 * ( timePerFrame - clock.GetElapsedTime() )  );
    }
    clock.Reset();
  }

  cleanup();
}

void Game::cleanup()
{
  window->Close();
  delete imageManager;
  delete player;
  delete builder;
  delete[] tileMap;
  delete window;
}

