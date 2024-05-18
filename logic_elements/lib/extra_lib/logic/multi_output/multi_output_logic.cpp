#include "multi_output_logic.h"

#include <stdexcept>

namespace Logic {

MultiOutputElement& operator>>(Element& lhs, MultiOutputOperation& rhs) {
  rhs.inputs_.push_back(ElemInput{lhs, false});
  lhs.outputs.push_back(&rhs);

  rhs.calc();
  return rhs;
}

void MultiOutputElement::Set(bool value) {
  for (auto& output : output_elems_) {
    output = value;
  }
}

void MultiOutputElement::Set(const std::vector<bool>& values) {
  if (values.size() != output_elems_.size())
    throw std::invalid_argument(
        "size of values does not match output elems size");

  for (size_t i = 0; i < values.size(); i++) output_elems_[i] = values[i];
}

void MultiOutputElement::Set(bool value, size_t index) {
  output_elems_[index] = value;
}

void MultiOutputElement::AddOutputs(size_t amount) {
  for (size_t i = 0; i < amount; i++) output_elems_.push_back(OutputElem());
}

}  // namespace Logic