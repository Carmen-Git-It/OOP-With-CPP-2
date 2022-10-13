// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   10/12/2022

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <string>

namespace sdds {
   class Movie
   {
      std::string m_title{};
      size_t m_year{};
      std::string m_description{};

    public:
      Movie();
      Movie(const std::string& strMovie);
      const std::string& title() const;
      template <typename T> void fixSpelling(T& spellChecker) {
         spellChecker(m_description);
         spellChecker(m_title);
      }
   };
} // namespace sdds

#endif //! SDDS_MOVIE_H
