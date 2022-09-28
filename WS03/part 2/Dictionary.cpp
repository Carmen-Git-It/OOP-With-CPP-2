// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   09/27/2022

#include "Dictionary.h"
#include <iostream>
namespace sdds {
Dictionary::Dictionary() {}
std::ostream& operator<<(std::ostream& os, const Dictionary& dic) {
   os.width(20);
   os << std::right << dic.m_term;
   os << ": " << dic.m_definition;

   return os;
}

bool Dictionary::operator==(const Dictionary& dic) const {
   return m_term.compare(dic.m_term) == 0 &&
          m_definition.compare(dic.m_definition) == 0;
}

} // namespace sdds
