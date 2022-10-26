// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   10/25/2022

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include "Vehicle.h"
namespace sdds {
   Vehicle* createInstance(std::istream& in);
   std::string& trim(std::string&);
} // namespace sdds
#endif //! SDDS_UTILITIES_H
