#include "ImageManager.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

ImageManager::ImageManager() 
{
}

ImageManager::~ImageManager()
{
  images.clear();  
}

const sf::Image & ImageManager::getImage( const string & filename )
{
  for ( map< string , sf::Image >::const_iterator it = images.begin() ;
        it != images.end(); ++it ) {
    if ( filename == it->first ) {
      return it->second;
    }
  }

  sf::Image targetImage;

  if ( ! targetImage.LoadFromFile( filename ) ) {
    cerr << "Image manager had a problem loading. Using empty image " << filename << endl;
  }

  images[ filename ] = targetImage;
  return images[ filename ];
}

