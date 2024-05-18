#include "decoder_elem.h"

#include <logic/multi_output/utils.h>

#include <stdexcept>


namespace Logic {

void Decoder::calc() {
  if (pow(2, GetInputs().size()) > GetOutputs().size()) {
    throw std::logic_error("decoder inputs amount does not match outputs");
  }

  auto table = GetTruthTable(GetInputs().size());

  // MEANS: единственный индекс, являющийся истиной
  size_t true_output_index = 0;

  for (const auto& row : table) {
    if (row == GetInputs()) {
      for (size_t i = 0; i < row.size(); i++) {
        true_output_index += row[i] * pow(2, i);
      }
      break;
    }
  }

  // всё ложь, кроме найденного индекса
  Set(false);
  Set(true, true_output_index);
}

}  // namespace Logic