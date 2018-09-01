#include "gui/layout_window.h"

#include <algorithm>

namespace APP_NAME {

namespace gui {

FlexLayoutItemWindow::FlexLayoutItemWindow(Flex flex, Window* window) :
    flex_(flex),
    window_(window) {}

FlexLayoutWindow::FlexLayoutWindow() {}

void FlexLayoutWindow::AddWindow(int index, Window* const window) {
  std::unique_ptr<FlexLayoutItemWindow> item_window =
      std::make_unique<FlexLayoutItemWindow>(window->layout_item_behavior().flex, window)
  if (index < 0)
    children_.emplace(children_.begin(), std::move(item_window));
  else {
    children_.emplace(children_.begin() + std::max(children_.size(), index),
        std::move(item_window));
  }
  Invalidate();
}

void LayoutWindow::Draw() {
  // Todo:: flex-direction: column
  int flex_basis_sum = 0;
  float flex_grow_sum = 0;
  float flex_shrink_sum = 0;
  
  for (auto& flex_layout_item_window : children_) {
    flex_basis_sum += flex_layout_item_window->flex().basis;
    flex_grow_sum += flex_layout_item_window->flex().grow;
    flex_shrink_sum += flex_layout_item_window->flex().shrink;
  }

  int blank_space = width_ - flex_basis_sum;

  auto& this_position = position();
  int current_x = this_position.x;
  int current_y = this_position.y;
  if (blank_space >= 0) {
    // Grow
    for (auto& flex_layout_item_window : children) {
      auto child_flex = flex_layout_item_window->flex();
      int size = child_flex.grow / flex_grow_sum * blank_space + child_flex.basis;
      flex_layout_item_window->SetWidth(size);
      flex_layout_item_window->SetHeight(height_);
      flex_layout_item_window->SetX(current_x);
      flex_layout_item_window->SetY(current_y);
      current_x += size;
    }
  }
  else {
    // Shrink
    for (auto& flex_layout_item_window : children) {
      auto child_flex = flex_layout_item_window->flex();
      int size = child_flex.basis - child_flex.shrink / flex_shrink_sum * blank_space;
      flex_layout_item_window->SetWidth(size);
      flex_layout_item_window->SetHeight(height_);
      flex_layout_item_window->SetX(current_x);
      flex_layout_item_window->SetY(current_y);
      current_x += size;
    }
  }

  for (auto& flex_layout_item_window : children)
    flex_layout_item_window->Draw();
}

} // namespace gui

} // namespace APP_NAME