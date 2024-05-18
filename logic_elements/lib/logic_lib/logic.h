#ifndef LOGIC_H
#define LOGIC_H 1

#include <functional>
#include <vector>

namespace Logic {

class Element;
class Source;
class Operation;
struct Connection;

//--------- added by me ---------
class MultiOutputElement;
class MultiOutputOperation;

using multi_output_logic_callback =
    std::function<void(const MultiOutputElement&)>;
//--------- added by me ---------

enum class Out_state {
  direct = 0,
  inverted = 1,
};

// represents a pair of element and state of inverted property
struct ElemInput {
  ElemInput() = delete;
  ElemInput(const ElemInput& input) = default;

  ElemInput(const Element& input_elem, bool inverted)
      : elem{&input_elem}, inv{inverted} {}

  ElemInput& operator=(const ElemInput& input) = default;

  operator bool() const;

  const Element* elem;
  bool inv;
};

using Logic_callback = std::function<void(const Element&)>;

using Input_container = std::vector<ElemInput>;
using Output_container = std::vector<Element*>;

// abstract logic element
class Element {
 public:
  explicit Element(Out_state st = Out_state::direct, Logic_callback f = nullptr)
      : inverted_out{st == Out_state::inverted}, out{inverted_out}, cb{f} {}

  operator bool() const { return out; }
  bool inverted() const { return inverted_out; }
  const Output_container& get_outputs() const { return outputs; }

  void set_callback(Logic_callback f) { cb = f; }

 protected:
  void set(bool value);
  // abstract method, set() should be called in calc()
  virtual void calc() = 0;

 private:
  bool inverted_out{false};
  bool out{false};
  Logic_callback cb;

  // connections
  Output_container outputs;

  friend Element& operator>>(Element& lhs, Operation& rhs);
  friend Element& operator>>(Element& lhs, Connection rhs);
  friend void check_loop(const Element& loop, const Element& elem);

  //--------- added by me ---------
  friend MultiOutputElement& operator>>(Element& lhs,
                                        MultiOutputOperation& rhs);
  //--------- added by me ---------
};

class Source : public Element {
 public:
  explicit Source(Out_state st = Out_state::direct, Logic_callback f = nullptr)
      : Element{st, f} {}

  Source& operator=(bool value) {
    set(value);
    return *this;
  }

 protected:
  virtual void calc() override;
};

// must be used only for connection operation
struct Connection {
  Connection() = delete;
  Connection(const Connection&) = default;

  // constructor without "explicit" keyword
  Connection(Operation& oper, bool inv = false)
      : oper_elem{oper}, inverted{inv} {}

  Connection& operator=(const Connection&) = delete;

  Connection& operator~() {
    inverted = !inverted;
    return *this;
  }

  Operation& oper_elem;
  bool inverted;
};

class Operation : public Element {
 public:
  explicit Operation(Out_state st = Out_state::direct,
                     Logic_callback f = nullptr)
      : Element{st, f} {}

  const Input_container& get_inputs() const { return inputs; }

  Connection operator~() { return Connection{*this, true}; }

 private:
  Input_container inputs;

  friend Element& operator>>(Element& lhs, Operation& rhs);
  friend Element& operator>>(Element& lhs, Connection rhs);
};

Element& operator>>(Element& lhs, Operation& rhs);
Element& operator>>(Element& lhs, Connection rhs);
void check_loop(const Element& loop, const Element& elem);

//--------- added by me ---------
MultiOutputElement& operator>>(Element& lhs, MultiOutputOperation& rhs);
//--------- added by me ---------

class And : public Operation {
 public:
  explicit And(Out_state out_inverted = Out_state::direct,
               Logic_callback f = nullptr)
      : Operation{out_inverted, f} {}

 protected:
  virtual void calc() override;
};

class Or : public Operation {
 public:
  explicit Or(Out_state st = Out_state::direct, Logic_callback f = nullptr)
      : Operation{st, f} {}

 protected:
  virtual void calc() override;
};

}  // namespace Logic

#endif  // LOGIC_H
