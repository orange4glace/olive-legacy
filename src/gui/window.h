#ifndef GUI_WINDOW_H_
#define GUI_WINDOW_H_

#include <memory>

#include "gui/layout_item_behavior.h"

namespace APP_NAME {

namespace gui {

class Window {
public:
  Window(int width, int height);

  void Draw();

  LayoutItemBehavior& const layout_item_behavior() const;

protected:
  int width_, height_;
  Window* parent_;

private:
  LayoutItemBehavior layout_item_behavior_;

} // class Window

} // namespace gui

} // namespace APP_NAME

#endif GUI_WINDOW_H_