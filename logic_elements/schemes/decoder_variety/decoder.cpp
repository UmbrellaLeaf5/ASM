#include <Graph.h>
#include <Simple_window.h>
#include <Window.h>
#include <logic.h>
#include <logic/logic_ext.h>
#include <logic/logic_shapes_ext.h>
#include <logic/multi_output/decoder_elem.h>
#include <logic/multi_output/decoder_elem_shape.h>
#include <logic_shapes.h>

#include <exception>
#include <iostream>

int main() try {
  int win_w = 800;
  int win_h = 600;

  Graph_lib::Point lt(Graph_lib::x_max() / 2 - win_w / 2,
                      Graph_lib::y_max() / 2 - win_h / 2);

  Simple_window win(lt, win_w, win_h, "Scheme of Logic Elements: Decoder");

  using namespace Logic;

  auto column_x = [](double c) -> int { return int(30 + 100 * c); };

  auto line_y = [](double l) -> int { return int(40 + 75 * l); };

  SchemeShape scheme{{5, 5}, win_w - 80, win_h - 10};

  win.attach(scheme);

  //-------------------------------------------------------------------------

  Source src1;
  Source src2;
  Source src3;
  Source src4;

  Decoder dec1(1);
  Decoder dec2(2);
  Decoder dec3(3);
  Decoder dec4(4);

  src1 >> dec1;

  src1 >> dec2;
  src2 >> dec2;

  src1 >> dec3;
  src2 >> dec3;
  src3 >> dec3;

  src1 >> dec4;
  src2 >> dec4;
  src3 >> dec4;
  src4 >> dec4;

  //-------------------------------------------------------------------------

  SourceShape src_shape12(scheme, src1, "src1", {column_x(0), line_y(1)});
  SourceShape src_shape22(scheme, src2, "src2", {column_x(0), line_y(2)});
  SourceShape src_shape32(scheme, src3, "src3", {column_x(0), line_y(3)});
  SourceShape src_shape42(scheme, src4, "src4", {column_x(0), line_y(4)});

  DecoderShape dec_shape1(scheme, dec1, "1_input_dec", {column_x(3), line_y(1)},
                          DEFAULT_WIDTH / 2, DEFAULT_HEIGHT);

  DecoderShape dec_shape2(scheme, dec2, "2_inputs_dec",
                          {column_x(4), line_y(1.5)});

  DecoderShape dec_shape3(scheme, dec3, "3_inputs_dec",
                          {column_x(5), line_y(2)}, DEFAULT_WIDTH / 2,
                          DEFAULT_HEIGHT * 4);

  DecoderShape dec_shape4(scheme, dec4, "4_inputs_dec",
                          {column_x(6), line_y(2.5)}, DEFAULT_WIDTH / 2,
                          DEFAULT_HEIGHT * 8);

  scheme.update_connections();

  //-------------------------------------------------------------------------

  // цикл перебора таблицы истинности
  for (int i = 0; i < 2; i++) {
    src4 = i % 2 == 1;
    for (int j = 0; j < 2; j++) {
      src3 = j % 2 == 1;
      for (int k = 0; k < 2; k++) {
        src2 = k % 2 == 1;
        for (int l = 0; l < 2; l++) {
          src1 = l % 2 == 1;
          win.wait_for_button();
        }
      }
    }
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
