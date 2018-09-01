#ifndef GFX_RECT_H_
#define GFX_RECT_H_

namespace APP_NAME {

namespace gfx {

struct Rect {

  inline Rect(int x, int y, int w, int h) 
    : x(x_), y(y_), w(w_), h(h_) {
  
  }

  int x, y, w, h;

} // struct Rect

} // namespace gfx

} // namespace APP_NAME

#endif // GFX_RECT_H_