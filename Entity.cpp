#include "Entity.h"
#include <SFML/Graphics.hpp>

using namespace std;

Entity::Entity( sf::RenderWindow * window , ImageManager * imgMgr , 
                int x , int y ) : 
      
                                        posn( make_pair( x , y ) ) ,
                                        window( window ) ,
                                        imageManager( imgMgr ) ,
                                        sprite( new sf::Sprite )
{
}

Entity::~Entity()
{
}

std::pair<int , int> Entity::getPosn()
{
  return posn;
}
