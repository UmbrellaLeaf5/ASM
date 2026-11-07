#include "logic_shapes_ext.h"

#include <cassert>
#include <cmath>

using Graph_lib::Color;
using Graph_lib::Point;

namespace Logic {

XorShape::XorShape(SchemeShape& scheme, Xor& e, const std::string& name,
                   const Point& pos,  // left top
                   int width /* = DEFAULT_WIDTH */,
                   int height /* = DEFAULT_HEIGHT */)
    : OperatorShape(scheme, e, name, pos, width, height),
      left_side_({pos.x, pos.y + height / 2 + 1}, width / 4, height / 2 + 1,
                 -90, 90),
      right_side_({pos.x, pos.y + height / 2 + 1}, width / 1, height / 2 + 1,
                  -90, 90),
      extra_side_({pos.x - 5, pos.y + height / 2 + 1}, width / 4,
                  height / 2 + 1, -90, 90) {
  left_side_.set_style(SHAPE_LINE_TYPE);
  right_side_.set_style(SHAPE_LINE_TYPE);
  extra_side_.set_style(SHAPE_LINE_TYPE);

  Graph_lib::Color c = elem.inverted() ? (elem ? FALSE_COLOR : TRUE_COLOR)
                                       : (elem ? TRUE_COLOR : FALSE_COLOR);
  left_side_.set_color(c);
  right_side_.set_color(c);
  extra_side_.set_color(c);
}

void XorShape::on_change(const Element& e) {
  OperatorShape::on_change(e);

  Graph_lib::Color c = e.inverted() ? (e ? FALSE_COLOR : TRUE_COLOR)
                                    : (e ? TRUE_COLOR : FALSE_COLOR);
  left_side_.set_color(c);
  right_side_.set_color(c);
  extra_side_.set_color(c);
}

void XorShape::draw_lines() const {
  OperatorShape::draw_lines();

  left_side_.draw();
  right_side_.draw();
  extra_side_.draw();
}

BufferShape::BufferShape(SchemeShape& scheme, Buffer& e,
                         const std::string& name,
                         const Point& pos,  // left top
                         int width /* = DEFAULT_WIDTH */,
                         int height /* = DEFAULT_HEIGHT */)
    : OperatorShape(scheme, e, name, pos, width, height) {
  triangle_.add(pos);
  triangle_.add(pos + Point(0, height));
  triangle_.add(pos + Point(width / 2, height / 2));

  triangle_.set_style(SHAPE_LINE_TYPE);

  Graph_lib::Color c = elem.inverted() ? (elem ? FALSE_COLOR : TRUE_COLOR)
                                       : (elem ? TRUE_COLOR : FALSE_COLOR);
  triangle_.set_color(c);
}

void BufferShape::on_change(const Element& e) {
  OperatorShape::on_change(e);

  Graph_lib::Color c = e.inverted() ? (e ? FALSE_COLOR : TRUE_COLOR)
                                    : (e ? TRUE_COLOR : FALSE_COLOR);
  triangle_.set_color(c);
}

Graph_lib::Point BufferShape::output_pos() const {
  return (triangle_.point(triangle_.number_of_points() - 1));
}

void BufferShape::draw_lines() const {
  OperatorShape::draw_lines();

  triangle_.draw();
}

}  // namespace Logic
