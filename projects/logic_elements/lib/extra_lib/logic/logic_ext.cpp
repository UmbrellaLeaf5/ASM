#include "logic_ext.h"

#include <stdexcept>

namespace Logic {

void Xor::calc() {
  bool res{false};

  for (const auto& input : get_inputs()) {
    res ^= input;
  }

  set(res);
}

void Buffer::calc() {
  bool res{get_inputs()[0]};

  if (get_inputs().size() > 1)
    throw std::logic_error(
        "amount of logic buffer inputs can not be more than one");

  set(res);
}

}  // namespace Logic