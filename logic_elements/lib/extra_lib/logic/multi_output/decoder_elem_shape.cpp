#include "decoder_elem_shape.h"

using Graph_lib::Color;
using Graph_lib::Point;

namespace Logic {

DecoderShape::DecoderShape(SchemeShape& scheme, Decoder& e,
                           const std::string& name,
                           const Point& pos,  // left top
                           int width /* = DEFAULT_WIDTH / 2 */,
                           int height /* = DEFAULT_HEIGHT*2 */)
    : OperatorMultiOutputShape(scheme, e, name, pos, width, height) {
  base_rect_.add(pos + Point(width, 0));
  base_rect_.add(pos);
  base_rect_.add(pos + Point(0, height));
  base_rect_.add(pos + Point(width, height));

  base_rect_.set_style(SHAPE_LINE_TYPE);
  auto c = MULTI_OUTPUT_ELEM_COLOR;
  base_rect_.set_color(c);

  InitOutputs(scheme, e, pos, width, height);
}

void DecoderShape::draw_lines() const {
  OperatorMultiOutputShape::draw_lines();

  base_rect_.draw();
}

}  // namespace Logic