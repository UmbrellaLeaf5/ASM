#include <Graph.h>
#include <Simple_window.h>
#include <Window.h>
#include <logic.h>
#include <logic/logic_ext.h>
#include <logic/logic_shapes_ext.h>
#include <logic/multi_output/decoder_elem.h>
#include <logic/multi_output/decoder_elem_shape.h>
#include <logic/multi_output/utils.h>
#include <logic_shapes.h>

#include <cmath>
#include <exception>
#include <iostream>
#include <memory>

using namespace Logic;
using std::cout, std::endl;

auto column_x = [](double c) -> int { return int(30 + 100 * c); };

auto line_y = [](double l) -> int { return int(40 + 75 * l); };

struct BeautifulDecoder {
 public:
  BeautifulDecoder(SchemeShape& scheme, size_t inputs_amount,
                   size_t dec_column = 3, size_t dec_line = 2)
      : dec(inputs_amount) {
    srcs.resize(inputs_amount);
    for (size_t inp_i = 0; inp_i < inputs_amount; inp_i++) {
      srcs[inp_i] >> dec;
      vec_src_shapes.emplace_back(new SourceShape(
          scheme, srcs[inp_i], "src " + std::to_string(inp_i + 1),
          {column_x(dec_column - 2), line_y(inp_i + 2)}));
    }

    auto outputs_amount = pow(2, inputs_amount);
    buffs.resize(outputs_amount);

    for (size_t out_i = 0; out_i < outputs_amount; out_i++) {
      dec[out_i] >> buffs[out_i];
      vec_buf_shapes.emplace_back(new BufferShape(
          scheme, buffs[out_i], "out " + std::to_string(out_i + 1),
          {column_x(dec_column + 2 +
                    ((out_i % size_t(outputs_amount)) >= (outputs_amount / 2)) *
                        (inputs_amount > 3)),
           line_y(out_i -
                  ((outputs_amount / 2) *
                   ((out_i % size_t(outputs_amount)) >= (outputs_amount / 2))) *
                      (inputs_amount > 3) +
                  2)}));
    }

    dec_shape = std::make_unique<DecoderShape>(
        scheme, dec, "dec",
        Graph_lib::Point(column_x(dec_column), line_y(dec_line)),
        DEFAULT_WIDTH / 2,
        DEFAULT_HEIGHT * pow(4, inputs_amount / 2) /
            (2 / ((inputs_amount % 2 != 0) + 1)));
  }

  Decoder dec;
  std::vector<Source> srcs;
  std::vector<Buffer> buffs;

  std::vector<std::unique_ptr<SourceShape>> vec_src_shapes;
  std::vector<std::unique_ptr<BufferShape>> vec_buf_shapes;
  std::unique_ptr<DecoderShape> dec_shape;
};

int main() try {
  int win_w = 800;
  int win_h = 800;

  Graph_lib::Point lt(Graph_lib::x_max() / 2 - win_w / 2,
                      Graph_lib::y_max() / 2 - win_h / 2);

  Simple_window win(lt, win_w, win_h, "Scheme of Logic Elements: Decoder");

  SchemeShape scheme{{5, 5}, win_w - 80, win_h - 10};

  win.attach(scheme);

  //-------------------------------------------------------------------------

  BeautifulDecoder decoder(scheme, 4);

  //-------------------------------------------------------------------------

  scheme.update_connections();

  //-------------------------------------------------------------------------
  auto dec_size = decoder.srcs.size();
  auto table = GetTruthTable(dec_size);

  for (const auto& row : table) {
    for (size_t i = 0; i < dec_size; i++) {
      decoder.srcs[i] = row[dec_size - i - 1];
    }
    win.wait_for_button();
  }

  return 0;
}

//-------------------------------------------------------------------------

catch (std::exception& e) {
  std::cerr << e.what() << std::endl;
  return 1;
} catch (...) {
  std::cerr << "Oops, something went wrong..." << std::endl;
  return 2;
}
