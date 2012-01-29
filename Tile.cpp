#include "Tile.h"
#include "GameSettings.h"
#include "ImageManager.h"

Tile::Tile() : window ( 0 ) , type( 0 )
{
}

Tile::Tile( sf::RenderWindow * window , ImageManager * imgMgr ,
            int x , int y , int type ) 
    : window( window ) , 
      bounds( sf::IntRect( x , y , x + tileSize , y + tileSize ) ) ,
      type( type )
{
  tileSprite.SetImage( imgMgr->getImage( "grounds.png" ) );
  int x_offset = ( type % 9 ) * tileSize;
  int y_offset = ( type / 9 ) * tileSize;
  tileSprite.SetSubRect( sf::IntRect( x_offset + 1 , y_offset  + 1,
                                   x_offset + tileSize - 2, 
                                   y_offset + tileSize - 2) );
  tileSprite.SetScale( 1.1 , 1.1 );
  tileSprite.SetX( x );
  tileSprite.SetY( y );
}

Tile::~Tile()
{
}

void Tile::render()
{
  window->Draw( tileSprite );  
}

int Tile::getType()
{
  return type;
}

sf::IntRect Tile::getBox()
{
  return bounds;
}
