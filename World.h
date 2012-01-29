#ifndef __WORLD_H__
#define __WORLD_H__

class World {
  private:
    Area * areas;
  public:
    World();
    ~World();

    void render();
    void update();
};

#endif
