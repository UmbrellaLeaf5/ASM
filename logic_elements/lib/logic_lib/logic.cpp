#include "logic.h"

#include <stdexcept>

namespace Logic {

ElemInput::operator bool() const {
  if (elem)
    return inv ? !*elem : *elem;
  else
    return inv;
}

void Element::set(bool value) {
  if (inverted_out) value = !value;

  if (out != value) {
    out = value;

    if (cb) cb(*this);

    for (auto elem : outputs) elem->calc();
  }
}

Element& operator>>(Element& lhs, Operation& rhs) {
  check_loop(rhs, lhs);

  rhs.inputs.push_back(ElemInput{lhs, false});
  lhs.outputs.push_back(&rhs);

  rhs.calc();
  return rhs;
}

Element& operator>>(Element& lhs, Connection rhs) {
  check_loop(rhs.oper_elem, lhs);

  rhs.oper_elem.inputs.push_back(ElemInput{lhs, rhs.inverted});
  lhs.outputs.push_back(&rhs.oper_elem);

  rhs.oper_elem.calc();
  return rhs.oper_elem;
}

void check_loop(const Element& loop, const Element& elem) {
  // checking if elem is the loop
  if (&loop == &elem)
    throw std::runtime_error{"loop detected in connections of logic elements"};

  for (const auto& output : loop.get_outputs()) check_loop(*output, elem);
}

void Source::calc() {
  // nothing to do here
}

void And::calc() {
  bool res{get_inputs().size() != 0};

  for (const auto& input : get_inputs()) {
    if (!input) {
      res = false;
      break;
    }
  }

  set(res);
}

void Or::calc() {
  bool res{false};

  for (const auto& input : get_inputs()) {
    if (input) {
      res = true;
      break;
    }
  }

  set(res);
}

}  // namespace Logic
