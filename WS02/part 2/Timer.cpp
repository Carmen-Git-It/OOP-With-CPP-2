// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   09/19/2022 (Happy birthday to me!)

#include "Timer.h"

namespace sdds {

// Take current time and store it in a member variable
void Timer::start() { m_start = std::chrono::system_clock::now(); }

// Take difference between current time and start time
// Returns duration in nanoseconds
long long Timer::stop() {
   auto end = std::chrono::system_clock::now();
   auto duration =
       std::chrono::duration_cast<std::chrono::nanoseconds>(end - m_start);
   return duration.count();
}

} // namespace sdds
