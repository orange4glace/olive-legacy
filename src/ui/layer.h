#ifndef GUI_LAYER_H_
#define GUI_LAYER_H_

#include <set>

namespace APP_NAME {

namespace ui {

// Layer is a basic class of ui
class Layer {
public:
  Layer(int width, int height);

  virtual void Invalidate() const;

  int z_index() const;
  void z_index(int val);
  const Layer* parent();

private:
  int z_index_;
  std::set<Layer*> children_;
  Layer* parent_;

  int width_;
  int height_;

}

}

namespace 

} // namespace APP_NAME

#endif // GUI_LAYER_H_