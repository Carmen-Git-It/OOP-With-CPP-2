// Name: Carmen Whitton
// Seneca Student ID: 102710217
// Seneca email: cwihtton@myseneca.ca
// Date of completion: 11/29/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Workstation.h"

namespace sdds {
   // Parameterized constructor, just passes the string to the base class constructor
   Workstation::Workstation(const std::string& file) : Station{file} {

   }

   // Fills the order at the front of the queue
   void Workstation::fill(std::ostream& os) {
      if (m_orders.size()) {
         m_orders.front().fillItem(*this, os);
      }
   }

   // Attempts to move the front order to the next station
   bool Workstation::attemptToMoveOrder() {
      bool moved = false;
      // Move item if out of inventory, or
      // TODO: DOUBLE CHECK THIS ASSUMPTION
      // if there are no more items of the type this station carries to be filled
      if (!Station::getQuantity() || m_orders.front().isItemFilled(Station::getItemName())) {
         moved = true;
         if (m_pNextStation) {
            *m_pNextStation += std::move(m_orders.front());
            // TODO: Not sure if this extra pop is necessary, check if it's double popping
            m_orders.pop_front();
         }
         else if(m_orders.front().isOrderFilled()){
            g_completed.push_back(std::move(m_orders.front()));
            m_orders.pop_front();
         }
         else {
            g_incomplete.push_back(std::move(m_orders.front()));
            m_orders.pop_front();
         }
      }

      return moved;
   }

   void Workstation::setNextStation(Workstation* station = nullptr) {
      m_pNextStation = station;
   }

   Workstation* Workstation::getNextStation() const {
      return m_pNextStation;
   }

   void Workstation::display(std::ostream& os) const {
      std::cout << Station::getItemName() << " --> ";
      if (m_pNextStation) {
         std::cout << ((Station*)m_pNextStation)->getItemName();
      }
      else {
         std::cout << "End of Line";
      }
      std::cout << "\n";
   }

   Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
      m_orders.push_back(std::move(newOrder));
   }
}