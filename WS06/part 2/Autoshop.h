// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   10/25/2022

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include "Luxuryvan.h"
#include "Vehicle.h"
#include <list>
#include <vector>

namespace sdds {
   class Autoshop
   {
      std::vector<Vehicle*> m_vehicles{};
      std::vector<Luxuryvan*> m_lvehicles{};

    public:
      ~Autoshop();
      Autoshop& operator+=(Vehicle* vehicle);
      void display(std::ostream& out) const;
      template <typename T>
      void select(T test, std::list<const Vehicle*>& vehicles) {
         for (auto v = m_vehicles.cbegin(); v != m_vehicles.cend(); ++v) {
            if (test(*v)) {
               vehicles.push_back(*v);
            }
         }
      }
      template <typename T>
      void typev(T test, std::list<const Luxuryvan*>& lv) {
         for (auto v = m_lvehicles.cbegin(); v != m_lvehicles.cend(); ++v) {
            if (test(*v)) {
               lv.push_back(*v);
            }
         }
      }
   };
} // namespace sdds

#endif //! SDDS_AUTOSHOP_H
