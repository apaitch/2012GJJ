#ifndef __IMAGEMANAGER_H__
#define __IMAGEMANAGER_H__

#include <map>
#include <string>

namespace sf {
  class Image;
}

class ImageManager {
  private:
    std::map< std::string , sf::Image > images;

  public:
    ImageManager();
    ~ImageManager();

    void loadImage( const std::string & );
    const sf::Image & getImage( const std::string & );
};

#endif
