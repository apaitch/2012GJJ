#ifndef __PLAYERENTITY_H__
#define __PLAYERENTITY_H__

#include "Entity.h"
#include <SFML/Graphics.hpp>

class ImageManager;

namespace sf {
  class RenderWindow;
}

class PlayerEntity : Entity {
  private:
    int speed;
    int frame;
    int framecounter;

    bool moving_up;
    bool moving_down;
    bool moving_left;
    bool moving_right;
    bool last_move_up;

    int sprite_width;
    int sprite_height;
    int x_offset;
    int y_offset;

    sf::View * playerView;
    void move( int x , int y );

  public:
    PlayerEntity( sf::RenderWindow * , ImageManager * , int , int );
    ~PlayerEntity();
    void update();
    void moveUp( float );
    void moveDown( float );
    void moveLeft( float );
    void moveRight( float );
    void render();

    sf::View * getPlayerView();
};

#endif
