#include "multi_output_logic_shapes.h"

#include <logic/logic_shapes_ext.h>

#include <cassert>
#include <cmath>

using Graph_lib::Color;
using Graph_lib::Point;

namespace Logic {

OutputElemShape::OutputElemShape(SchemeShape& scheme, OutputElem& e,
                                 const std::string& name,
                                 const Point& pos,  // left top
                                 int width /* = DEFAULT_WIDTH / 4 */,
                                 int height /* = DEFAULT_WIDTH / 4 */)
    : ElementShape(scheme, e, name, pos, width, height),
      rect_(pos, width, height) {
  scheme.attach(*this);

  rect_.set_style(SHAPE_LINE_TYPE);
  rect_.set_color(e ? TRUE_COLOR : FALSE_COLOR);
}

void OutputElemShape::on_change(const Element& e) {
  ElementShape::on_change(e);

  rect_.set_color(e ? TRUE_COLOR : FALSE_COLOR);
}

void OutputElemShape::draw_lines() const {
  ElementShape::draw_lines();

  rect_.draw();
}

OperatorMultiOutputShape::OperatorMultiOutputShape(
    SchemeShape& scheme, MultiOutputOperation& e, const std::string& name,
    const Point& pos,  // left top
    int width /* = DEFAULT_WIDTH */, int height /* = DEFAULT_HEIGHT*2 */)
    : ElementShape(scheme, e, name, pos, width, height) {
  scheme.attach(*this);
  InitOutputs(scheme, e, pos, width, height);
}

void OperatorMultiOutputShape::on_change(const Element& e) {
  for (auto i = 0; i < output_shapes_.size(); i++)
    output_shapes_[i].on_change(e);
}

Graph_lib::Point OperatorMultiOutputShape::input_pos(const Element& e,
                                                     size_t i) const {
  Point left_top = point(0);
  const auto& elem_inputs = parent().GetInputs();

  if (elem_inputs.at(i).elem == &e)
    return left_top +
           Point{-CIRCLES_RADIUS, int((i + 1) * h / (int(inputs_count()) + 1))};

  assert(!"wrong input");
  return left_top;
}

void OperatorMultiOutputShape::InitOutputs(SchemeShape& scheme,
                                           MultiOutputOperation& e,
                                           const Graph_lib::Point& pos,
                                           int width, int height) {
  // if (output_shapes_.size() > 0) output_shapes_.clear();

  auto outputs_amount = e.GetOutputs().size();
  auto inputs_amount = e.GetInputs().size();

  for (size_t i = 0; i < outputs_amount; i++) {
    output_shapes_.push_back(new OutputElemShape(
        scheme, e.GetOutputs()[i], "",
        // более менее удачная формула для подсчета расстояния между выходами
        pos + Point(width, i * height / outputs_amount +
                               outputs_amount / inputs_amount)));
  }
}

}  // namespace Logic