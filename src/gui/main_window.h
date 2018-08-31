#ifndef GUI_MAIN_WINDOW_H_
#define GUI_MAIN_WINDOW_H_

#include <memory>

#include "gfx/vector2i.h"

namespace ui {
class Layer
}

namespace APP_NAME {

namespace gui {

class Window;

class MainWindow : public ui::Layer {
public:
  MainWindow(int width, int height);

private:
  std::unique_ptr<TimelineWindow*> timeline_window_;

} // class MainWindow

} // namespace gui

} // namespace APP_NAME

#endif GUI_MAIN_WINDOW_H_