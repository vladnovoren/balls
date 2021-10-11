#ifndef APP_HPP
#define APP_HPP

#include "creatures_manager.hpp"
#include "view.hpp"


class App {
  Graphics graphics;
  WindowView root_view;
public:
  App();

  void Exec();
};


#endif /* app.hpp */
