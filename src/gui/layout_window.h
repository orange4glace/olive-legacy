#ifndef GUI_LAYOUT_WINDOW_H_
#define GUI_LAYOUT_WINDOW_H_

#include <memory>
#include <map>
#include <list>

namespace APP_NAME {

namespace gui {

class Window;
class FlexView;

class LayoutRowItemWindow : public Window {
public:
  LayoutRowItemWindow(Flex flex, Window* window);

private:
  Flex flex_;
  Window* window_;

} // struct LayoutRowItemWindow

class LayoutRowWindow : public Window,
                        public FlexView {
public:
  LayoutRowWindow();
  void AddItem(int index, Window* const window);

private:
  std::vector<std::unique_ptr<LayoutRowItemWindow>> items_;
  
} // class LayoutRowWindow

class LayoutWindow : public Window {
public:
  LayoutWindow();

  void AddWindow(int x, int y, Window* const window);
  Window* const GetWindowAt(int x, int y) const;

  static const int LAYOUT_ITEM_GAP;

protected:
  void Draw() override;

private:
  std::vector<std::unique_ptr<LayoutRowWindow>> rows_;

} // class Window

} // namespace gui

} // namespace APP_NAME

#endif GUI_LAYOUT_WINDOW_H_