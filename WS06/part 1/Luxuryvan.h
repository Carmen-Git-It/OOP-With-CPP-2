// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   10/25/2022

#ifndef SDDS_LUXURYVAN_H
#define SDDS_LUXURYVAN_H
#include "Van.h"

namespace sdds {
   class Luxuryvan : public Van
   {
      std::string m_consumption{};

    public:
      Luxuryvan(std::istream& in);
      void display(std::ostream& out) const;
      std::string consumption() const;
   };
} // namespace sdds

#endif //! SDDS_LUXURYVAN_H
