#pragma once

#include <Graph.h>
#include <Graph/Graph_ext.h>
#include <logic/multi_output/multi_output_logic.h>
#include <logic_shapes.h>

namespace Logic {

// MEANS: фигура выходного сигнал элемента с множественным количеством выходов
class OutputElemShape : public ElementShape {
  // IDK: как сделать его недоступным для пользователя, но доступным для класса?
 public:
  OutputElemShape(SchemeShape& scheme, OutputElem& e, const std::string& name,
                  const Graph_lib::Point& pos,  // left top
                  int width = DEFAULT_WIDTH / 4,
                  int height = DEFAULT_WIDTH / 4);

  virtual void on_change(const Element& e) override;

 private:
  virtual void draw_lines() const override;

  // фигуры, из которых состоит:
  Graph_lib::Rectangle rect_;
};

// класса OperatorMultiElementShape не может существовать, так как
// элемент не может распределить вход на множеств. кол-во выходов
// (без каких либо операций)

// MEANS: фигура логической операция с множественным количеством выходов
class OperatorMultiOutputShape : public ElementShape {
  // конструктор абстрактного класса пусть вызывают только наследники
 protected:
  OperatorMultiOutputShape(SchemeShape& scheme, MultiOutputOperation& e,
                           const std::string& name,
                           const Graph_lib::Point& pos,  // left top
                           int width = DEFAULT_WIDTH,
                           int height = DEFAULT_HEIGHT * 2);

 public:
  virtual void on_change(const Element& e) override;

  virtual Graph_lib::Point input_pos(const Element& e, size_t i) const;

  const MultiOutputOperation& parent() const {
    return static_cast<const MultiOutputOperation&>(elem);
  }

 protected:
  // DOES: инициализирует (отрисовывает) выходные выходные сигналы элемента
  // ARGS: [SchemeShape&]: схема, на которой будут выходы;
  // ARGS: [MultiOutputOperation&]: ссылка на лог. операцию;
  // ARGS: [const Graph_lib::Point&]: точка - правый верхний угол;
  // ARGS: [int] ширина; [int] высота
  // (кол-во аргументов связано с нежеланием хранить это всё в приватных полях)
  virtual void InitOutputs(SchemeShape& scheme, MultiOutputOperation& e,
                           const Graph_lib::Point& pos, int width, int height);

  size_t inputs_count() const { return parent().GetInputs().size(); }

 private:
  // MEANS: вектор (ref) фигур выходных сигналов
  Graph_lib::Vector_ref<OutputElemShape> output_shapes_;
};

}  // namespace Logic