#include "gui/window.h"

namespace APP_NAME {

namespace gui {

void Window::RegisterChildWindow(Window* const window) {
  assert(child_windows_.count(window->id()) == 0);
  child_windows_.insert({window->id(), window});
}

void Window::DeregisterChildWindow(window_id id) {
  assert(child_windows_.count(id));
  child_windows_.erase(id);
}

// Window::__Predraw()
// Called before Draw()
// Never call this method directly.
void Window::__Predraw() {
  canvas.save();
  SkCanvas& canvas = // Todo:: Get global recording canvas
  // Clip operation
  canvas->ClipRect(SkRect::MakeXYWH(x_, y_, width_, height_), SkClipOp::kIntersect, false);
}

// Window::__Postdraw()
// Called after Draw()
// Never call this method directly.
void Window::__Postdraw() {
  canavs.restore();
}

void Window::__Draw() {
  __Predraw();
  Draw();
  for (auto& kv : __child_windows_)
    kv.second->__Draw();
  __Postdraw();
}

} // namespace gui

} // namespace APP_NAME