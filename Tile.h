#ifndef __TILE_H__
#define __TILE_H__

#include <SFML/Graphics.hpp>

class ImageManager;

class Tile {
  private:
    sf::RenderWindow * window;
    sf::IntRect bounds;
    int type;
    sf::Sprite tileSprite;

  public:
    Tile();
    Tile( sf::RenderWindow * , ImageManager * , int x , int y , int type );
    ~Tile();
    void render();
    int getType();
    sf::IntRect getBox();
};

#endif
