#include "gui/layout_window.h"

#include <algorithm>

namespace APP_NAME {

namespace gui {

LayoutRowItemWindow::LayoutRowItemWindow(Flex flex, Window* window) :
    flex_(flex),
    window_(window) {}

void LayoutRowWindow::AddItem(int index, Window* const window) {
    std::unique_ptr<LayoutRowItemWindow> row_item_window =
        std::make_unique<LayoutRowItemWindow>(window->layout_item_behavior().flex, window)
    if (index < 0)
      items_.emplace(items_.begin(), std::move(row_item_window));
    else {
      items_.emplace(items_.begin() + std::max(items_.size(), index),
          std::move(row_item_window));
    }
}

LayoutWindow::LayoutWindow() {}

void LayoutWindow::AddWindow(int x, int y, Window* const window) {
  LayoutRowWindow* target_row_window;
  if (y < 0) {
    std::unique_ptr<LayoutRowWindow> row(std::make_unique<LayoutRowWindow>())
    target_row_window = row.get();
    rows_.insert(rows_.begin(), std::move(row));
  }
  else if (y >= rows_.size()) {
    std::unique_ptr<LayoutRowWindow> row(std::make_unique<LayoutRowWindow>())
    target_row_window = row.get();
    rows_.emplace_back(std::move(row));
  }
  else {
    target_row_window = rows_[y].get();
  }
  assert(target_row_window);

  Invalidate();
}

void LayoutWindow::Draw() {
  float flex_sum = 0;
  for (auto& layout_row_window : rows_) {
    flex_sum += rows_->flex().flex;
  }
}

}

}