// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   10/25/2022

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include "Vehicle.h"
#include <vector>

namespace sdds {
   class Autoshop
   {
      std::vector<Vehicle*> m_vehicles{};

    public:
      Autoshop& operator+=(Vehicle* vehicle);
      void display(std::ostream& out) const;
   };
} // namespace sdds

#endif //! SDDS_AUTOSHOP_H
