#pragma once

#include <logic.h>

#include <cmath>
#include <stdexcept>
#include <vector>

using BoolRow = std::vector<bool>;
using TruthTable = std::vector<BoolRow>;

// MEANS: функция, формирующая таблицу истинности
// ARGS: [size_t]: размер таблицы (кол-во строк/столбцов)
// RETURNS: [std::vector<std::vector<bool>>]: таблица истинности
TruthTable GetTruthTable(size_t n);

// DOES: позволяет сравнивать вектор bool с входными сигналами
// ARGS: [const std::vector<bool>&]: строка таблицы истинности
// ARGS: [const std::vector<Logic::ElemInput>&]: входные сигналы
// RETURNS: [bool]: факт соответствия двух величин
bool operator==(const BoolRow& row, const Logic::Input_container& inputs);
