// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   10/12/2022

#include "Movie.h"

namespace sdds {

   // I would love to pop this into a utility class but there's no option to in
   // this workshop
   std::string& trim(std::string& str) {
      bool trimmed = false;

      while (!trimmed) {
         trimmed = true;
         if (str.find(' ') == 0) {
            trimmed = false;
            str.erase(str.begin());
         }
         if (str.substr(str.size() - 1, 1).find(' ') != std::string::npos) {
            str.erase(str.end() - 1);
            trimmed = false;
         }
      }
      return str;
   }

   // Default constructor
   Movie::Movie() {
      ; // Intentionally empty
   }

   // Parses a string that contains information about a movie, into a movie
   // object
   Movie::Movie(const std::string& strMovie) {
      std::string token{};
      size_t left{};
      size_t right  = strMovie.find(",");
      m_title       = strMovie.substr(left, right);
      m_title       = trim(m_title);
      left          = right;
      right         = strMovie.find(",", left + 1);
      token         = strMovie.substr(left + 1, right - left - 1);
      m_year        = std::stoi(token);
      left          = right;
      right         = strMovie.find('\n', left + 1);
      m_description = strMovie.substr(left + 1, right - left - 1);
      m_description = trim(m_description);
   }

   // Returns a constant reference to the title of the movie
   const std::string& Movie::title() const { return m_title; }

} // namespace sdds
