// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   10/25/2022

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include "Car.h"

namespace sdds {
   class Racecar : public Car
   {
      double m_booster{};

    public:
      Racecar(std::istream& in);
      void display(std::ostream& out) const;
      double topSpeed() const;
   };
} // namespace sdds

#endif //! SDDS_RACECAR_H
