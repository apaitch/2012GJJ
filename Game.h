#ifndef __GAME_H__
#define __GAME_H__

class ImageManager;

namespace sf {
  class Event;
  class RenderWindow;
  class Sprite;
  class View;
}

class Game {
  private:
    ImageManager * imageManager;
    sf::Sprite * sprite;
    sf::View * view;

    sf::RenderWindow * window;
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
