#ifndef APP_HPP
#define APP_HPP

#include "creatures_manager.hpp"


class App {
  Graphics graphics;
  CreaturesManager creatures_manager;
public:
  App();

  void Exec();
};


#endif /* app.hpp */