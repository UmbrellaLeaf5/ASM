#include "logic_shapes.h"

//--------- added by me ---------
#include <logic/multi_output/multi_output_logic_shapes.h>
//--------- added by me ---------

#include <cassert>
#include <functional>

using Graph_lib::Color;
using Graph_lib::Point;

namespace Logic {

SchemeShape::SchemeShape(const Point& pos, int width, int height)
    : Graph_lib::Rectangle{pos, width, height} {
  set_color(BACKGROUND_COLOR);
  set_fill_color(BACKGROUND_COLOR);
}

void SchemeShape::attach(ElementShape& elem_shape) {
  elem_shapes.push_back(elem_shape);
  update_connections();
}

void SchemeShape::attach(OperatorShape& oper_shape) {
  oper_shapes.push_back(oper_shape);
  attach(static_cast<ElementShape&>(oper_shape));
}

//--------- added by me ---------
void SchemeShape::attach(OperatorMultiOutputShape& multi_output_logic_shape) {
  multi_output_logic_shapes.push_back(multi_output_logic_shape);
  attach(static_cast<ElementShape&>(multi_output_logic_shape));
}
//--------- added by me ---------

void SchemeShape::draw_lines() const {
  Graph_lib::Rectangle::draw_lines();

  for (int i = 0; i < connections.size(); ++i) connections[i].draw();
  for (int i = 0; i < elem_shapes.size(); ++i) elem_shapes[i].draw();
}

void SchemeShape::update_connections() {
  connections.clear();

  // determine all connections
  for (int i = 0; i < elem_shapes.size(); ++i) {
    ElementShape& from = elem_shapes[i];

    for (int j = 0; j < oper_shapes.size(); ++j) {
      OperatorShape& to = oper_shapes[j];

      // try to find connection
      const auto& to_inputs = to.parent().get_inputs();
      for (size_t k = 0; k < to_inputs.size(); ++k) {
        const auto& input_pair = to_inputs[k];
        if (&from.parent() == input_pair.elem)
          connections.push_back(new ConnectionShape{from, to, k});
      }
    }  // for j

    //--------- added by me ---------
    for (int j = 0; j < multi_output_logic_shapes.size(); ++j) {
      OperatorMultiOutputShape& to = multi_output_logic_shapes[j];

      // try to find connection
      const auto& to_inputs = to.parent().GetInputs();
      for (size_t k = 0; k < to_inputs.size(); ++k) {
        const auto& input_pair = to_inputs[k];
        if (&from.parent() == input_pair.elem)
          connections.push_back(new ConnectionShape{from, to, k});
      }
    }  // for j
    //--------- added by me ---------

  }  // for i
}

ElementShape::ElementShape(SchemeShape& s, Element& e, const std::string& name,
                           const Point& pos,  // left top
                           int width /* = DEFAULT_WIDTH */,
                           int height /* = DEFAULT_HEIGHT */)
    : Graph_lib::Shape{pos},
      scheme{s},
      elem{e},
      w{width},
      h{height},
      label{pos + Point{0, -LABEL_MARGIN_Y}, name},
      out_circle{Point{pos.x + w + CIRCLES_RADIUS, pos.y + h / 2 + 1},
                 CIRCLES_RADIUS} {
  using namespace std::placeholders;
  Logic_callback cb = std::bind(&ElementShape::callback_func, this, _1);
  e.set_callback(cb);

  // set style
  label.set_font(LABEL_FONT);
  label.set_color(LABEL_COLOR);

  out_circle.set_style(CIRCLE_LINE_TYPE);
  out_circle.set_color(elem ? TRUE_COLOR : FALSE_COLOR);
}

void ElementShape::on_change(const Element& e) {
  out_circle.set_color(e ? TRUE_COLOR : FALSE_COLOR);
}

void ElementShape::callback_func(const Element& e) {
  on_change(e);
  scheme.update_connections();
}

void ElementShape::draw_lines() const {
  label.draw();

  // we should draw output circle if only output is inverted
  if (elem.inverted()) out_circle.draw();
}

SourceShape::SourceShape(SchemeShape& scheme, Source& e,
                         const std::string& name,
                         const Point& pos,  // left top
                         int width /* = DEFAULT_WIDTH */,
                         int height /* = DEFAULT_HEIGHT */)
    : ElementShape{scheme, e, name, pos, width, height},
      body{pos, width, height} {
  scheme.attach(*this);

  body.set_style(SHAPE_LINE_TYPE);
  body.set_color(elem.inverted() ? (elem ? FALSE_COLOR : TRUE_COLOR)
                                 : (elem ? TRUE_COLOR : FALSE_COLOR));
}

void SourceShape::on_change(const Element& e) {
  ElementShape::on_change(e);

  body.set_color(e.inverted() ? (e ? FALSE_COLOR : TRUE_COLOR)
                              : (e ? TRUE_COLOR : FALSE_COLOR));
}

void SourceShape::draw_lines() const {
  ElementShape::draw_lines();

  body.draw();
}

ConnectionShape::ConnectionShape(const ElementShape& elem,
                                 const OperatorShape& oper, size_t i)
    : line{elem.output_pos(), oper.input_pos(elem.parent(), i)},
      dash{oper.input_pos(elem.parent(), i),
           oper.input_pos(elem.parent(), i) + Point{CIRCLES_RADIUS, 0}},
      circle{oper.input_pos(elem.parent(), i), CIRCLES_RADIUS} {
  // determine if inverted
  inverted = false;
  for (const auto& inputs_pair : oper.parent().get_inputs()) {
    if (inputs_pair.elem == &elem.parent()) {
      inverted = inputs_pair.inv;
      break;
    }
  }

  // set styles
  line.set_style(CONNECTION_LINE_TYPE);
  dash.set_style(CONNECTION_LINE_TYPE);
  circle.set_style(CIRCLE_LINE_TYPE);

  line.set_color(elem.parent() ? TRUE_COLOR : FALSE_COLOR);
  dash.set_color(elem.parent() ? TRUE_COLOR : FALSE_COLOR);
  circle.set_color(elem.parent() ? FALSE_COLOR : TRUE_COLOR);
}

//--------- added by me ---------
ConnectionShape::ConnectionShape(const ElementShape& elem,
                                 const OperatorMultiOutputShape& oper, size_t i)
    : line{elem.output_pos(), oper.input_pos(elem.parent(), i)},
      dash{oper.input_pos(elem.parent(), i),
           oper.input_pos(elem.parent(), i) + Point{CIRCLES_RADIUS, 0}},
      circle{oper.input_pos(elem.parent(), i), CIRCLES_RADIUS} {
  // set styles
  line.set_style(CONNECTION_LINE_TYPE);
  dash.set_style(CONNECTION_LINE_TYPE);
  circle.set_style(CIRCLE_LINE_TYPE);

  line.set_color(elem.parent() ? TRUE_COLOR : FALSE_COLOR);
  dash.set_color(elem.parent() ? TRUE_COLOR : FALSE_COLOR);
  circle.set_color(elem.parent() ? FALSE_COLOR : TRUE_COLOR);
}
//--------- added by me ---------

void ConnectionShape::draw_lines() const {
  line.draw();
  if (inverted)
    circle.draw();
  else
    dash.draw();
}

OperatorShape::OperatorShape(SchemeShape& scheme, Operation& e,
                             const std::string& name,
                             const Point& pos,  // left top
                             int width /* = DEFAULT_WIDTH */,
                             int height /* = DEFAULT_HEIGHT */)
    : ElementShape{scheme, e, name, pos, width, height} {
  scheme.attach(*this);
}

Point OperatorShape::input_pos(const Element& e, size_t i) const {
  Point left_top = point(0);
  const auto& elem_inputs = parent().get_inputs();

  if (elem_inputs.at(i).elem == &e)
    return left_top +
           Point{-CIRCLES_RADIUS, int((i + 1) * h / (int(inputs_count()) + 1))};

  assert(!"wrong input");
  return left_top;
}

void OperatorShape::draw_lines() const { ElementShape::draw_lines(); }

AndShape::AndShape(SchemeShape& scheme, And& e, const std::string& name,
                   const Point& pos,  // left top
                   int width /* = DEFAULT_WIDTH */,
                   int height /* = DEFAULT_HEIGHT */)
    : OperatorShape{scheme, e, name, pos, width, height},
      right_side{Point{pos.x + width / 2, pos.y + height / 2 + 1}, width / 2,
                 height / 2 + 1, -90, 90}

{
  left_side.add(pos + Point{width / 2, 0});
  left_side.add(pos);
  left_side.add(pos + Point{0, height});
  left_side.add(pos + Point{width / 2, height});

  left_side.set_style(SHAPE_LINE_TYPE);
  right_side.set_style(SHAPE_LINE_TYPE);

  Graph_lib::Color c = elem.inverted() ? (elem ? FALSE_COLOR : TRUE_COLOR)
                                       : (elem ? TRUE_COLOR : FALSE_COLOR);
  left_side.set_color(c);
  right_side.set_color(c);
}

void AndShape::on_change(const Element& e) {
  OperatorShape::on_change(e);

  Graph_lib::Color c = e.inverted() ? (e ? FALSE_COLOR : TRUE_COLOR)
                                    : (e ? TRUE_COLOR : FALSE_COLOR);
  left_side.set_color(c);
  right_side.set_color(c);
}

void AndShape::draw_lines() const {
  OperatorShape::draw_lines();

  left_side.draw();
  right_side.draw();
}

OrShape::OrShape(SchemeShape& scheme, Or& e, const std::string& name,
                 const Point& pos,  // left top
                 int width /* = DEFAULT_WIDTH */,
                 int height /* = DEFAULT_HEIGHT */)
    : OperatorShape{scheme, e, name, pos, width, height},
      left_side{Point{pos.x, pos.y + height / 2 + 1}, width / 4, height / 2 + 1,
                -90, 90},
      right_side{Point{pos.x, pos.y + height / 2 + 1}, width / 1,
                 height / 2 + 1, -90, 90} {
  left_side.set_style(SHAPE_LINE_TYPE);
  right_side.set_style(SHAPE_LINE_TYPE);

  Graph_lib::Color c = elem.inverted() ? (elem ? FALSE_COLOR : TRUE_COLOR)
                                       : (elem ? TRUE_COLOR : FALSE_COLOR);
  left_side.set_color(c);
  right_side.set_color(c);
}

Point OrShape::input_pos(const Element& e, size_t i) const {
  auto pos = point(0);
  auto p = OperatorShape::input_pos(e, i);
  double rx = left_side.major();
  double ry = left_side.minor();
  double dy = p.y - pos.y;
  double y = std::abs(ry - dy);
  double x = rx * std::sqrt(1.0 - y * y / (ry * ry));
  return p + Point{int(x), 0};
}

void OrShape::on_change(const Element& e) {
  OperatorShape::on_change(e);

  Graph_lib::Color c = e.inverted() ? (e ? FALSE_COLOR : TRUE_COLOR)
                                    : (e ? TRUE_COLOR : FALSE_COLOR);
  left_side.set_color(c);
  right_side.set_color(c);
}

void OrShape::draw_lines() const {
  OperatorShape::draw_lines();

  left_side.draw();
  right_side.draw();
}

}  // namespace Logic
