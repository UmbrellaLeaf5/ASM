#pragma once

#include <Graph.h>
#include <Graph/Graph_ext.h>
#include <logic/multi_output/decoder_elem.h>
#include <logic/multi_output/multi_output_logic_shapes.h>
#include <logic_shapes.h>

namespace Logic {

// MEANS: фигура логического элемента декодера
class DecoderShape : public OperatorMultiOutputShape {
 public:
  DecoderShape(SchemeShape& scheme, Decoder& e, const std::string& name,
               const Graph_lib::Point& pos,  // left top
               int width = DEFAULT_WIDTH / 2, int height = DEFAULT_HEIGHT * 2);

 private:
  virtual void draw_lines() const override;

  // shapes of the body
  Graph_lib::Open_polyline base_rect_;
};

}  // namespace Logic