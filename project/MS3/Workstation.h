// Name: Carmen Whitton
// Seneca Student ID: 102710217
// Seneca email: cwihtton@myseneca.ca
// Date of completion: 11/29/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <deque>
#include <string>
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds {

   extern std::deque<CustomerOrder> g_pending;
   extern std::deque<CustomerOrder> g_completed;
   extern std::deque<CustomerOrder> g_incomplete;

   class Workstation : public Station{
      std::deque<CustomerOrder> m_orders{};
      Workstation* m_pNextStation{};
   public:
      Workstation(const std::string&);
      void fill(std::ostream& os);
      bool attemptToMoveOrder();
      void setNextStation(Workstation* station);
      Workstation* getNextStation() const;
      void display(std::ostream& os) const;
      Workstation& operator+=(CustomerOrder&& newOrder);
   };
}

#endif //!SDDS_WORKSTATION_H