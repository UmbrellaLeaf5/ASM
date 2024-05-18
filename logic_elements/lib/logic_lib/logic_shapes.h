#ifndef LOGIC_SHAPES_H
#define LOGIC_SHAPES_H 1

#include <Graph.h>
#include <Graph/Graph_ext.h>

#include "logic.h"

namespace Logic {

//--------- added by me ---------
class OperatorMultiOutputShape;
//--------- added by me ---------

const Graph_lib::Color BACKGROUND_COLOR{Graph_lib::Color::Color_type::white};
const Graph_lib::Color FALSE_COLOR{Graph_lib::Color::Color_type::dark_red};
const Graph_lib::Color TRUE_COLOR{Graph_lib::Color::Color_type::dark_green};
const Graph_lib::Color LABEL_COLOR{Graph_lib::Color::Color_type::dark_cyan};

//--------- added by me ---------
const Graph_lib::Color MULTI_OUTPUT_ELEM_COLOR{
    Graph_lib::Color::Color_type::dark_blue};
//--------- added by me ---------

const Graph_lib::Line_style SHAPE_LINE_TYPE{
    Graph_lib::Line_style::Line_style_type::solid, 3};
const Graph_lib::Line_style CONNECTION_LINE_TYPE{
    Graph_lib::Line_style::Line_style_type::solid, 2};
const Graph_lib::Line_style CIRCLE_LINE_TYPE{
    Graph_lib::Line_style::Line_style_type::solid, 2};

const Graph_lib::Font LABEL_FONT{Graph_lib::Font::Font_type::helvetica_bold};

constexpr int DEFAULT_WIDTH = 40;
constexpr int DEFAULT_HEIGHT = 30;
constexpr int CIRCLES_RADIUS = 4;
constexpr int LABEL_MARGIN_Y = 3;

class ElementShape;
class OperatorShape;
class ConnectionShape;

class SchemeShape : public Graph_lib::Rectangle {
 public:
  SchemeShape(const Graph_lib::Point& pos, int width, int height);

  void attach(ElementShape& elem_shape);
  void attach(OperatorShape& elem_shape);

  //--------- added by me ---------
  void attach(OperatorMultiOutputShape& multi_output_logic_shape);
  //--------- added by me ---------

  void update_connections();

 protected:
  virtual void draw_lines() const override;

  Graph_lib::Vector_ref<ElementShape> elem_shapes;     // to be drawn
  Graph_lib::Vector_ref<ConnectionShape> connections;  // to be drawn

  //--------- added by me ---------
  Graph_lib::Vector_ref<OperatorMultiOutputShape>
      multi_output_logic_shapes;  // not to be draw (used to determine
                                  // connections)
  //--------- added by me ---------

  Graph_lib::Vector_ref<OperatorShape>
      oper_shapes;  // not to be draw (used to determine connections)
};

class ElementShape : public Graph_lib::Shape {
 protected:
  ElementShape(SchemeShape& s, Element& e, const std::string& name,
               const Graph_lib::Point& pos,  // left top
               int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);

 public:
  virtual ~ElementShape() override { elem.set_callback(nullptr); }

  //--------- modified by me ---------
  virtual Graph_lib::Point output_pos() const {
    return point(0) + Graph_lib::Point{w, h / 2};
  }
  //--------- modified by me ---------

  const Element& parent() const { return elem; }

  // method to be called when elem out is changed
  virtual void on_change(const Element& e);

  void callback_func(const Element& e);

 protected:
  virtual void draw_lines() const override;

  SchemeShape& scheme;
  Element& elem;
  int w, h;
  Graph_lib::Text label;
  Graph_lib::Circle out_circle;
};

class SourceShape : public ElementShape {
 public:
  SourceShape(SchemeShape& scheme, Source& e, const std::string& name,
              const Graph_lib::Point& pos,  // left top
              int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);

  virtual void on_change(const Element& e) override;

 protected:
  virtual void draw_lines() const override;

  // shapes of the body
  Graph_lib::Rectangle body;
};

// connection consist of line and may be circle if needed
class ConnectionShape : public Graph_lib::Shape {
 public:
  ConnectionShape(const ElementShape& elem, const OperatorShape& oper,
                  size_t i);

  //--------- added by me ---------
  ConnectionShape(const ElementShape& elem,
                  const OperatorMultiOutputShape& oper, size_t i);
  //--------- added by me ---------

 protected:
  virtual void draw_lines() const override;

  Graph_lib::Line line;
  Graph_lib::Line dash;
  Graph_lib::Circle circle;
  bool inverted{false};
};

class OperatorShape : public ElementShape {
 protected:
  OperatorShape(SchemeShape& scheme, Operation& e, const std::string& name,
                const Graph_lib::Point& pos,  // left top
                int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);

 public:
  virtual Graph_lib::Point input_pos(const Element& e, size_t i) const;

  const Operation& parent() const {
    return static_cast<const Operation&>(elem);
  }

 protected:
  virtual void draw_lines() const override;

  size_t inputs_count() const { return parent().get_inputs().size(); }
};

class AndShape : public OperatorShape {
 public:
  AndShape(SchemeShape& scheme, And& e, const std::string& name,
           const Graph_lib::Point& pos,  // left top
           int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);

  virtual void on_change(const Element& e) override;

 protected:
  virtual void draw_lines() const override;

  // shapes of the body
  Graph_lib::Open_polyline left_side;
  Graph_lib::Arc right_side;
};

class OrShape : public OperatorShape {
 public:
  OrShape(SchemeShape& scheme, Or& e, const std::string& name,
          const Graph_lib::Point& pos,  // left top
          int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);

  virtual Graph_lib::Point input_pos(const Element& e, size_t i) const override;

  virtual void on_change(const Element& e) override;

 protected:
  virtual void draw_lines() const override;

  // shapes of the body
  Graph_lib::Arc left_side;
  Graph_lib::Arc right_side;
};

}  // namespace Logic

#endif  // LOGIC_SHAPES_H
