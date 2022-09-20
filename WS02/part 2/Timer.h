// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   09/19/2022 (Happy birthday to me!)

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

#include <chrono>

namespace sdds {

class Timer
{
   std::chrono::time_point<std::chrono::system_clock> m_start;

 public:
   void start();     // Store current time in member variable
   long long stop(); // Nanoseconds since start
};

} // namespace sdds
#endif // SDDS_TIMER_H
