// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   10/25/2022

#include "Racecar.h"

namespace sdds {
   // Reads values from an input stream to member variables
   Racecar::Racecar(std::istream& in) : Car(in) {
      std::string token{};
      std::getline(in, token);
      m_booster = std::stod(token);
   }
   void Racecar::display(std::ostream& out) const {
      Car::display(out);
      out << "*";
   }
   double Racecar::topSpeed() const {
      return Car::topSpeed() + (Car::topSpeed() * m_booster);
   }

} // namespace sdds
