#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "ImageManager.h"

using namespace std;

int main()
{
  sf::RenderWindow app( sf::VideoMode( 800, 600 , 32 ), "Game" );

  ImageManager imgManager;

  sf::Sprite sprite;
  sprite.SetImage( imgManager.getImage( "pony.png" ));
  sprite.SetPosition( 200.f , 100.f );

  sf::View view( sf::FloatRect( 300 , 350 , 700 , 650 ) );


  float elapsedTime = app.GetFrameTime();

  app.SetView( view );
  bool flag = true;
  while( app.IsOpened() )
  {
    sf::Event event;
    while ( app.GetEvent( event ) ) {
      if ( event.Type == sf::Event::Closed ) {
        app.Close();
      }
    }
    
    elapsedTime = app.GetFrameTime();

    if ( app.GetInput().IsKeyDown( sf::Key::Left ) ) view.Move( - 100 * elapsedTime , 0 );
    if ( app.GetInput().IsKeyDown( sf::Key::Right ) ) view.Move( 100 * elapsedTime , 0 );
    if ( app.GetInput().IsKeyDown( sf::Key::Up ) ) view.Move( 0 , - 100 * elapsedTime );
    if ( app.GetInput().IsKeyDown( sf::Key::Down ) ) view.Move( 0 , 100 * elapsedTime );

    cout << "Elapsed Time: " << elapsedTime << endl;
    if ( app.GetInput().IsKeyDown( sf::Key::A ) ) view.Zoom( 0.99f );
    if ( app.GetInput().IsKeyDown( sf::Key::Z ) ) view.Zoom( 1.01f );

    if ( app.GetInput().IsKeyDown( sf::Key::Space ) ) {
      if ( flag ) {
        sprite.SetImage( imgManager.getImage( "hotpony.png" ));
        flag = false;
      }
      else {
        sprite.SetImage( imgManager.getImage( "pony.png" ));
        flag = true;
      } }


    app.Clear();
    app.Draw( sprite );
    app.Display();

  }

  return EXIT_SUCCESS;
}
