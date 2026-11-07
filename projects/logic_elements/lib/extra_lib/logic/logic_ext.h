#pragma once

#include <logic.h>

namespace Logic {

class Xor : public Operation {
 public:
  inline explicit Xor(Out_state out_inverted = Out_state::direct,
                      Logic_callback f = nullptr)
      : Operation(out_inverted, f) {}

 private:
  void calc() override;
};

class Buffer : public Operation {
  // (чтобы не перегружать Connection новым функционалом)
  // (пришлось наследоваться от Operation, а не от Element)
 public:
  inline explicit Buffer(Out_state out_inverted = Out_state::direct,
                         Logic_callback f = nullptr)
      : Operation(out_inverted, f) {}

 private:
  void calc() override;
};

}  // namespace Logic