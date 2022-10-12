// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   10/11/2022

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <string>

namespace sdds {
   constexpr size_t SIZE = 6;

   class SpellChecker
   {
      std::string m_badWords[SIZE]{};
      std::string m_goodWords[SIZE]{};
      int m_replaced[SIZE]{};

    public:
      SpellChecker();
      SpellChecker(const char* filename);
      void operator()(std::string& text);
      void showStatistics(std::ostream& os) const;
   };
} // namespace sdds

#endif //! SDDS_SPELLCHECKER_H
