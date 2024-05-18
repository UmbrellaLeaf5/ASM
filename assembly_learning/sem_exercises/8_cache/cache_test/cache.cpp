#include <algorithm>
#include <array>
#include <iostream>
// #include <iterator>
#include <limits>
#include <random>
#include <stdexcept>
#include <vector>

#include "timer.h"

#ifndef LINE_SIZE
#define LINE_SIZE 512
#endif

struct Data {
  const int id;
  std::array<char, LINE_SIZE> line{};

  Data(const int an_id) : id{an_id} {}
};

auto GenerateData(size_t n, int high = std::numeric_limits<int>::max()) {
  std::default_random_engine ran{};
  std::uniform_int_distribution<> uni{0, high};

  std::vector<Data> data;
  data.reserve(n);

  for (size_t i = 0; i < n; ++i) {
    int id = uni(ran);
    data.emplace_back(id);
  }

  return data;
}

auto GetOrder_1(const std::vector<Data>& data) {
  std::vector<const Data*> data_ptrs;

  // (reserve удобно использовать, когда известен точный размер)
  data_ptrs.reserve(data.size());

  std::transform(data.begin(), data.end(), std::back_inserter(data_ptrs),
                 [](const Data& obj) { return &obj; });

  std::sort(data_ptrs.begin(), data_ptrs.end(),
            [](const Data* p1, const Data* p2) { return p1->id < p2->id; });

  return data_ptrs;
}

auto GetOrder_2(const std::vector<Data>& data) {
  std::vector<std::pair<const Data*, int>> data_pairs;
  data_pairs.reserve(data.size());

  std::transform(data.begin(), data.end(), std::back_inserter(data_pairs),
                 [](const auto& obj) { return std::make_pair(&obj, obj.id); });

  std::sort(
      data_pairs.begin(), data_pairs.end(),
      [](const auto& p1, const auto& p2) { return p1.second < p2.second; });

  std::vector<const Data*> res;
  res.reserve(data.size());
  for (const auto& obj : data_pairs) res.push_back(obj.first);

  return res;
}

void Test(size_t n) {
  auto data = GenerateData(n);

  std::vector<const Data*> ord;

  std::cout << sizeof(Data) << " " << data.size() << std::flush;

  for (auto& GetOrder : {GetOrder_1, GetOrder_2}) {
    Timer timer;
    auto tmp = GetOrder(data);
    timer.Stop();

    if (ord.empty())
      ord = tmp;
    else if (ord != tmp)
      throw std::runtime_error{"sorting order not the same"};

    std::cout << " " << timer.Elapsed() << std::flush;
  }

  std::cout << std::endl;
}

int main() try {
  std::vector<size_t> lengths{
      200,    500,     1'000,   5'000,   10'000,
      50'000, 100'000, 200'000, 500'000,  // 800'000, 1'000'000,
  };

  for (size_t n : lengths) Test(n);

} catch (std::exception& e) {
  std::cerr << e.what() << std::endl;

} catch (...) {
  std::cerr << "Oops! Unknown exception..." << std::endl;
}
