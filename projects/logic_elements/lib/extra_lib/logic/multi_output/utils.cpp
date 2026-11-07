#include "utils.h"

TruthTable GetTruthTable(size_t n) {
  size_t row_count = std::pow(2, n);  // кол-во строк в таблице

  // создание вектора векторов для хранения таблицы истинности
  TruthTable truthTable(row_count, std::vector<bool>(n));

  for (size_t i = 0; i < row_count; ++i) {
    size_t value = i;
    for (size_t j = n; j > 0; --j) {
      // вычисление значения каждой переменной
      truthTable[i][j - 1] = value % 2;
      value /= 2;
    }
  }

  return truthTable;
}

bool operator==(const BoolRow& row, const Logic::Input_container& inputs) {
  if (row.size() != inputs.size())
    throw std::invalid_argument(
        "size of inputs does not match output row of bool size");

  size_t matches_amount = 0;

  for (size_t i = 0; i < row.size(); i++) {
    if (inputs[i] == row[i]) matches_amount++;
  }

  if (matches_amount == row.size()) {
    return true;
  }
  return false;
}