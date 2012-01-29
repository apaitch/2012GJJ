#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <utility>

class ImageManager;

namespace sf {
  class RenderWindow;
  class Sprite;
}

class Entity {
  private:

  protected:
    std::pair< int , int > posn;
    sf::RenderWindow * window;
    ImageManager * imageManager;
    sf::Sprite * sprite;


  public:
    Entity( sf::RenderWindow * , ImageManager * , int , int );
    virtual ~Entity();
    virtual void update() = 0;
    virtual void render() = 0;
    std::pair< int , int > getPosn();
};

#endif
