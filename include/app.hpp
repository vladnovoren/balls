#ifndef APP_HPP
#define APP_HPP

#include "creatures_manager.hpp"


const double ppu = 1;

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;
const Vector2f WINDOW_SIZE(WINDOW_WIDTH, WINDOW_HEIGHT);


const Vector2f P_CENTER(0, WINDOW_HEIGHT);
const Vector2f MIN_POINT(0, 0);
const Vector2f MAX_POINT(WINDOW_WIDTH / ppu, WINDOW_HEIGHT / ppu);
const Ranges RANGES(MAX_POINT, MIN_POINT);
const CoordSys COORD_SYS(P_CENTER, RANGES, ppu);



class App {
  Graphics graphics;
  CreaturesManager creatures_manager;
public:
  App();

  void Exec();
};


#endif /* app.hpp */
