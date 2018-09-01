#ifndef GUI_LAYOUT_WINDOW_H_
#define GUI_LAYOUT_WINDOW_H_

#include <memory>
#include <map>
#include <list>

namespace APP_NAME {

namespace gui {

class Window;
class FlexView;

class FlexLayoutItemWindow : public Window {
public:
  FlexLayoutItemWindow(Flex flex, Window* window);

  Flex& const flex() const;

private:
  Flex flex_;
  Window* window_;

} // struct LayoutRowItemWindow

class FlexLayoutWindow : public Window {
public:
  FlexLayoutWindow();

  void AddWindow(int index, Window* const window);
  Window* const GetWindowAt(int index);

  static const int LAYOUT_ITEM_GAP;

protected:
  void Draw() override;

private:
  std::vector<std::unique_ptr<FlexLayoutItemWindow>> children_;

} // class FlexLayoutWindow

} // namespace gui

} // namespace APP_NAME

#endif GUI_LAYOUT_WINDOW_H_