#include <iostream>
#include <cstdlib>
#include <time.h>
#include "LevelBuilder.h"

//#include <SFML/Randomizer.hpp>
//

using namespace std;

LevelBuilder::LevelBuilder()
{
}

LevelBuilder::~LevelBuilder() 
{
}

int * LevelBuilder::createMap( int width , int height )
{
  cout << "Starting building map" << endl;
  srand( time(NULL) );
  int * map = new int[ width * height ];

  // Randomize tiles
  for ( int i = 0 ; i < width * height ; ++i ) {
    map[i] = rand() % 2 + 12;
  }

  cout << "Filled map with random tiles" << endl;

  /*
  // Now fill edges with water
  for ( int i = 0 ; i < width * 3 ; ++i ) {
    // Water
    map[i] = 20;
  }

  cout << "Filled top edges with water" << endl;

  for ( int i = width * height - 1 ; i > width * (height - 3 ) ; --i ) {
    // Water
    map[i] = 20;
  }

  cout << "Filled bottom edges with water" << endl;

  for ( int i = 0 ; i < height ; ++i ) {
    // Water
    map[i*width] = 20;
    map[i*width + 1] = 20;
    map[i*width + 2] = 20;
    map[(i+1)*width - 1] = 20;
    map[(i+1)*width - 2] = 20;
    map[(i+1)*width - 3] = 20;
  }
*/
  cout << "Done building map" << endl;
  return map;
}

void LevelBuilder::setSeed( int seed )
{
  //sf::Randomizer::SetSeed( seed );
}
