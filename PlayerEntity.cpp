#include <iostream>
#include "PlayerEntity.h"
#include "ImageManager.h"
#include <SFML/Graphics.hpp>

using namespace std;

PlayerEntity::PlayerEntity( sf::RenderWindow * window ,
                            ImageManager * imgMgr ,
                            int x , int y ) 
      : Entity( window , imgMgr , x , y ) ,
        speed( 150 ) ,
        frame( 0 ) ,
        moving_up( false ) ,
        moving_down( false ) ,
        moving_left( false ) ,
        moving_right( false ) ,
        last_move_up( false ) ,
        sprite_width( 27 ) ,
        sprite_height( 45 ) ,
        x_offset( 0 ) ,
        y_offset( 0 ) 
{
  sf::Image spriteImage = imageManager->getImage( "Bob_Sprite_Sheet.png" );
  sprite->SetImage( imageManager->getImage( "Bob_Sprite_Sheet.png" ) );
  sprite->SetSubRect( sf::IntRect( x_offset , y_offset , sprite_width , sprite_height ) );
  sprite->SetPosition( x , y );
  sprite->SetCenter( sprite_width / 2 , sprite_height / 2);
  playerView = new sf::View( sprite->TransformToGlobal(sprite->GetCenter()) ,
                             sf::Vector2f( 200 , 150 ) );
}

PlayerEntity::~PlayerEntity()
{
  delete playerView;
}

void PlayerEntity::move( int x , int y )
{
  posn.first += x;
  posn.second += y;
  sprite->Move( x , y ); 
  playerView->Move( x , y );
}

void PlayerEntity::render()
{
  framecounter = (framecounter + 1) % 10;
  if ( framecounter == 0 ) {
    frame = frame % 2 + 1;
  }

  if ( moving_up ) {
    sprite->SetSubRect( 
      sf::IntRect( frame * sprite_width , sprite_height , 
                   ( frame + 1 ) * sprite_width , 2 * sprite_height ) );
    last_move_up = true;
  }
  else if ( moving_down ) {
    sprite->SetSubRect( 
      sf::IntRect( frame * sprite_width , 0 , 
                   ( frame + 1 ) * sprite_width , sprite_height ) );
    last_move_up = false;
  }
  else if ( moving_left ) {
    sprite->SetSubRect( 
      sf::IntRect( ( frame - 1 ) * sprite_width , 2 * sprite_height  , 
                   ( frame ) * sprite_width , 3 * sprite_height ) );
    sprite->FlipX( true );
  }
  else if ( moving_right ) {
    sprite->SetSubRect( 
      sf::IntRect( ( frame - 1 ) * sprite_width , 2 * sprite_height  , 
                   ( frame ) * sprite_width , 3 * sprite_height ) );
    sprite->FlipX( false );
  }
  else {
    if ( last_move_up ) {
      sprite->SetSubRect( sf::IntRect( 0 , sprite_height , sprite_width , 2 * sprite_height ) );
    }
    else {
      sprite->SetSubRect( sf::IntRect( 0 , 0 , sprite_width , sprite_height ) );
    }
  }
  window->Draw( *sprite );
  moving_up = moving_down = moving_left = moving_right = false;
}

void PlayerEntity::update()
{
}

void PlayerEntity::moveLeft( float delta )
{
  move( (int) -speed * delta , 0 );
  moving_left = true;
}

void PlayerEntity::moveRight( float delta )
{
  move( (int) speed * delta , 0 );
  moving_right = true;
}

void PlayerEntity::moveUp( float delta )
{
  move( 0 , (int) -speed * delta );
  moving_up = true;
}

void PlayerEntity::moveDown( float delta )
{
  move( 0 , (int) speed * delta );
  moving_down = true;
}

sf::View * PlayerEntity::getPlayerView() {
  return playerView;
}

