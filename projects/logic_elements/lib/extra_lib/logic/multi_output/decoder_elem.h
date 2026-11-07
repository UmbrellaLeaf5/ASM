#pragma once

#include <logic/multi_output/multi_output_logic.h>

#include <cmath>
#include <vector>

namespace Logic {

// MEANS: логический элемент декодера
class Decoder : public MultiOutputOperation {
 public:
  inline explicit Decoder(size_t input_amount,
                          multi_output_logic_callback f = nullptr)
      // (кол-во выходов = 2^кол-во входов)
      : MultiOutputOperation(size_t(pow(2, input_amount)), f) {}

 protected:
  virtual void calc() override;
};

}  // namespace Logic