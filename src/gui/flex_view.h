#ifndef GUI_FLEX_VIEW_H_
#define GUI_FLEX_VIEW_H_

namespace APP_NAME {

namespace gui {

class FlexView {
public:
  inline Flex() {}
  
  inline Flex& const flex() const {
    return flex_;
  }

private:
  Flex flex_;

}

}

}

#endif GUI_FLEX_VIEW_H_