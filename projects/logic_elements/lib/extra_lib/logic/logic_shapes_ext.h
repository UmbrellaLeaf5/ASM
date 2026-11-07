#pragma once

#include <Graph.h>
#include <Graph/Graph_ext.h>
#include <logic_shapes.h>

#include "logic_ext.h"

namespace Logic {

class XorShape : public OperatorShape {
 public:
  XorShape(SchemeShape& scheme, Xor& e, const std::string& name,
           const Graph_lib::Point& pos,  // left top
           int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);

  virtual void on_change(const Element& e) override;

 private:
  virtual void draw_lines() const override;

  // shapes of the body
  Graph_lib::Arc left_side_;
  Graph_lib::Arc right_side_;
  Graph_lib::Arc extra_side_;
};

class BufferShape : public OperatorShape {
 public:
  BufferShape(SchemeShape& scheme, Buffer& e, const std::string& name,
              const Graph_lib::Point& pos,  // left top
              int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);

  virtual void on_change(const Element& e) override;

  Graph_lib::Point output_pos() const override;

 private:
  virtual void draw_lines() const override;

  // shapes of the body
  Graph_lib::Closed_polyline triangle_;
};

}  // namespace Logic