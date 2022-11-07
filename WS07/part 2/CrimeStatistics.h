// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   11/06/2022

#ifndef SDDS_CRIMESTATISTICS_H
#define SDDS_CRIMESTATISTICS_H
#include <string>
#include <vector>
#include <list>

namespace sdds {

   struct Crime {
      std::string province{};
      std::string district{};
      std::string crime{};
      unsigned numCases{};
      unsigned year{};
      unsigned m_resolved{};
   };

   class CrimeStatistics {
      std::vector<Crime> m_crimes;
   public:
      CrimeStatistics(const char* filename);
      void display(std::ostream& out) const;
      void sort(const char*);
      bool inCollection(const char*) const;
      std::list<Crime> getListForProvince(const char*) const;
      void cleanList();
   };

   std::ostream& operator<<(std::ostream& out, const Crime& crime);

}


#endif //!SDDS_CRIMESTATISTICS_H