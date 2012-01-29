#ifndef __GAME_H__
#define __GAME_H__

class ImageManager;
class Tile;
class PlayerEntity;
class LevelBuilder;

namespace sf {
  class Event;
  class RenderWindow;
  class Sprite;
  class View;
}

class Game {
  private:
    ImageManager * imageManager;
    PlayerEntity * player;
    sf::View * view;
    LevelBuilder * builder;

    Tile * tileMap;
    sf::RenderWindow * window;
    sf::RenderWindow * bigWindow;

    bool running;

    void init();

    void handleEvent( const sf::Event & event );
    void updateLogic();
    void draw();

    void cleanup();

  public:
    Game();
    ~Game();
    void run();
};

#endif
