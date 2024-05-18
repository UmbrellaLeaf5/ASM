#ifndef TIMER_H
#define TIMER_H 1

#include <chrono>

using namespace std::chrono;

class Timer {
 public:
  Timer() { Start(); }

  void Start() { s = f = high_resolution_clock::now(); }
  void Stop() { f = high_resolution_clock::now(); }

  double Elapsed() const;  // elapsed time in milliseconds

 private:
  high_resolution_clock::time_point s,  // start
      f;                                // finish
};

inline double Timer::Elapsed() const {
  return duration_cast<microseconds>(f - s).count() / 1000.;
}

#endif  // #ifndef TIMER_H
