#include "gui/main_window.h"

#include "gui/timeline_window.h"

namespace APP_NAME {

namespace gui {

MainWindow::MainWindow(int width, int height)
  : ui::Layer(width, height) {
  timeline_window_.reset(new TimelineWindow())
}

// private
const Vector2i MainWindow::GetTimelineWindowSize() {
}

}

}