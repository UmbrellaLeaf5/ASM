#pragma once

#include <logic.h>

namespace Logic {

// MEANS: выходной сигнал элемента с множественным количеством выходов
// (возможен к использованию только в наследниках MultiOutputElement)
class OutputElem : public Element {
 public:
  friend MultiOutputElement;

  explicit OutputElem(Out_state st = Out_state::direct,
                      Logic_callback f = nullptr)
      : Element(st, f) {}

 private:
  OutputElem& operator=(bool value) {
    set(value);
    return *this;
  }

  void calc() override {}
};

using MultiOutputContainer = std::vector<OutputElem>;

// MEANS: элемент с множественным количеством выходов
class MultiOutputElement : public Element {
 public:
  inline explicit MultiOutputElement(size_t output_amount = 1,
                                     multi_output_logic_callback f = nullptr)
      : output_elems_(output_amount), cb_{f} {}

  // MEANS: перегрузка, осуществляющая доступ к выходному сигналу по индексу
  // ARGS: [const size_t]: численный индекс
  // RETURNS: [OutputElem&]: ссылка на выходной сигнал
  inline OutputElem& operator[](const size_t index) {
    return output_elems_[index];
  };

  // MEANS: перегрузка, осуществляющая доступ к выходному сигналу по индексу
  // ARGS: [const size_t]: численный индекс
  // RETURNS: [const OutputElem&]: ссылка на выходной сигнал
  inline const OutputElem& operator[](const size_t index) const {
    return output_elems_[index];
  };

  // RETURNS: [const std::vector<OutputElem>&]: вектор выходных сигналов
  inline const MultiOutputContainer& GetOutputs() const {
    return output_elems_;
  }

  // RETURNS: [std::vector<OutputElem>&]: вектор выходных сигналов
  inline MultiOutputContainer& GetOutputs() { return output_elems_; }

 protected:
  // DOES: устанавливает значение на все выходные сигналы
  // ARGS: [bool]: устанавливаемое значение
  void Set(bool value);

  // DOES: устанавливает значения на все выходные сигналы
  // ARGS: [const std::vector<bool>&]: вектор устанавливаемых значений
  // (его размер должен совпадать с количеством выходных сигналов)
  void Set(const std::vector<bool>& values);

  // DOES: устанавливает значение на конкретный выходной сигнал
  // ARGS: [bool]: устанавливаемое значение; [const size_t]: численный индекс
  void Set(bool value, size_t index);

  // DOES: увеличивает кол-во выходных сигналов
  // ARGS: [size_t]: количество добавляемых новых вых. сигналов
  void AddOutputs(size_t amount);

  virtual void calc() override = 0;

 private:
  // MEANS: вектор выходных сигналов
  MultiOutputContainer output_elems_;

  multi_output_logic_callback cb_;
};

// MEANS: логическая операция с множественным количеством выходов
class MultiOutputOperation : public MultiOutputElement {
 public:
  inline explicit MultiOutputOperation(size_t output_amount = 1,
                                       multi_output_logic_callback f = nullptr)
      : MultiOutputElement(output_amount, f) {}

  // RETURNS: [const std::vector<Logic::ElemInput>]: вектор входных сигналов
  inline const Input_container& GetInputs() const { return inputs_; }

 private:
  // MEANS: вектор входных сигналов
  Input_container inputs_;

  // (объявлена в logic.h, определена в multi_output_logic.cpp)
  friend MultiOutputElement& operator>>(Element& lhs,
                                        MultiOutputOperation& rhs);
};

}  // namespace Logic
