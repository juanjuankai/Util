// COLMAP - Structure-from-Motion.
// Copyright (C) 2016  Johannes L. Schoenberger <jsch at cs.unc.edu>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef SRC_UTIL_TIMER_H_
#define SRC_UTIL_TIMER_H_

#include <chrono>
#include <iomanip>
#include <iostream>

namespace util {

class Timer {
 public:
  Timer();

  void Start();
  void Restart();
  void Pause();
  void Resume();
  void Reset();

  double ElapsedMicroSeconds() const;
  double ElapsedSeconds() const;
  double ElapsedMinutes() const;
  double ElapsedHours() const;

  void PrintMicroSeconds() const;
  void PrintSeconds() const;
  void PrintMinutes() const;
  void PrintHours() const;

 private:
  bool started_;
  bool paused_;
  std::chrono::high_resolution_clock::time_point start_time_;
  std::chrono::high_resolution_clock::time_point pause_time_;
};

}  // namespace util

#endif  // SRC_UTIL_TIMER_H_
