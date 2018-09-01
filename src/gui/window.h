#ifndef GUI_WINDOW_H_
#define GUI_WINDOW_H_

#include <memory>

#include "gfx/rect.h"

#include "gui/layout_item_behavior.h"

#define window_id int

namespace APP_NAME {

namespace gui {

enum class ClipStyle;

class Window {
public:
  Window(int x, int y, int w, int h);

  void Draw();

  LayoutItemBehavior& const layout_item_behavior() const;
  Rect GetClippingRect() const;

  void SetPosition(Vector2i);
  void SetPosition(int x, int y);
  Vector2i position() const;
  void SetX(int x);
  int x() const;
  void SetY(int y);
  int y() const;

  // SDL Event
  void __OnMouseDown();
  void __OnMouseUp();

  void RegisterChildWindow(Window* const window);
  void DeregisterChildWindow(int window_id);

  void __Predraw();
  void __Postdraw();
  void __DrawPhase();

protected:
  Vector2i position_;
  int width_, height_;
  Window* parent_;
  
  virtual void OnMouseDown() = 0;
  virtual void OnMouseUp() = 0;

private:
  std::map<window_id, Window*> __child_windows_;
  LayoutItemBehavior layout_item_behavior_;
  ClipStyle clip_style_;

} // class Window

} // namespace gui

} // namespace APP_NAME

#endif GUI_WINDOW_H_