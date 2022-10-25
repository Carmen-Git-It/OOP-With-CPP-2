// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   10/11/2022

#include "SpellChecker.h"
#include <fstream>

namespace sdds {
   // Default constructor
   SpellChecker::SpellChecker() {
      ; // Intentionally empty
   }
   // Loads the good and bad words from a given file
   SpellChecker::SpellChecker(const char* filename) {
      if (filename != nullptr) {

         std::ifstream file(filename);
         if (file) {
            size_t index{};
            while (file && index < SIZE) {
               size_t left{};
               size_t right{};
               std::string temp;
               std::getline(file, temp, '\n');
               right              = temp.find(' ');
               m_badWords[index]  = temp.substr(left, right);
               left               = temp.find_first_not_of(' ', right + 1);
               m_goodWords[index] = temp.substr(left);
               index++;
            }
         }
         else {
            throw("Bad file name!");
         }
      }
      else {
         throw("Bad file name!");
      }
   }

   // Functor function that accepts a string, and replaces incorrect text with
   // correct text
   void SpellChecker::operator()(std::string& text) {
      for (size_t i = 0; i < SIZE; i++) {
         size_t index = text.find(m_badWords[i]);
         while (index != std::string::npos) {
            text.replace(index, m_badWords[i].length(), m_goodWords[i]);
            m_replaced[i]++;
            index = text.find(m_badWords[i]);
         }
      }
   }

   // Displays the number of times each word has been replaced
   void SpellChecker::showStatistics(std::ostream& os) const {
      os << "Spellchecker Statistics" << std::endl;
      for (size_t i = 0; i < SIZE; i++) {
         os.width(15);
         os << std::right << m_badWords[i] << ": " << m_replaced[i]
            << " replacements" << std::endl;
      }
   }

} // namespace sdds
