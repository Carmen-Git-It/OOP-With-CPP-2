// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   10/25/2022

#ifndef SDDS_VAN_H
#define SDDS_VAN_H

#include "Vehicle.h"

namespace sdds {
   class Van : public Vehicle
   {
      enum Condition { New, Used, Broken };
      enum Type { Pickup, Minibus, Camper };
      enum Purpose { Delivery, Passenger, Camping };
      std::string m_maker{};
      Condition m_condition{};
      Type m_type{};
      Purpose m_purpose{};
      double m_topSpeed{};

    public:
      Van();
      Van(std::istream& is);
      std::string condition() const;
      std::string type() const;
      std::string usage() const;
      double topSpeed() const;
      void display(std::ostream& out) const;
   };
} // namespace sdds

#endif //! SDDS_VAN_H
