#include "Object.h"
#include <SFML/Graphics.hpp>

using namespace std;

Object::Object( sf::RenderWindow * window , ImageManager * imgMgr ,
                int x , int y )
    : window( window ) , imageManager( imgMgr ) , sprite( new sf::Sprite ) ,
      posn( make_pair( x , y ) )
{
}

Object::~Object()
{
  delete sprite;
}

pair< int , int > Object::getPosn()
{
  return posn;
}
