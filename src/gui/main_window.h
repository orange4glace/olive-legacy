#ifndef GUI_MAIN_WINDOW_H_
#define GUI_MAIN_WINDOW_H_

#include <memory>

#include "gfx/vector2i.h"

namespace APP_NAME {

namespace gui {

class Window;

class MainWindow : public Window {
public:
  MainWindow();

  void Draw() override;

private:

} // class MainWindow

} // namespace gui

} // namespace APP_NAME

#endif GUI_MAIN_WINDOW_H_