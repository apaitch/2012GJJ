#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <utility>

class ImageManager;
class Entity;

namespace sf {
  class Sprite;
  class RenderWindow;
}

class Object {
  protected:
    sf::RenderWindow * window;
    ImageManager * imageManager;
    sf::Sprite * sprite;
    std::pair< int , int > posn;

  public:
    Object( sf::RenderWindow * , ImageManager * , int , int );
    virtual ~Object();

    virtual void render() = 0;
    virtual void collision( Entity * ) = 0;
    std::pair< int , int > getPosn();
};

#endif
