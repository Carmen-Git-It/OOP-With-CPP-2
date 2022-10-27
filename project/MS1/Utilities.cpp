// Name: Carmen Whitton
// Seneca Student ID: 102710217
// Seneca email: cwihtton@myseneca.ca
// Date of completion: 10/26/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

namespace sdds {
   // Utility function to clear whitespace
   std::string& Utilities::trim(std::string& str) {
      bool trimmed = false;

      while (!trimmed) {
         trimmed = true;
         if (str.find(' ') == 0) {
            trimmed = false;
            str.erase(str.begin());
         }
         if (str.size() > 0 &&
            str.substr(str.size() - 1, 1).find(' ') != std::string::npos) {
            str.erase(str.end() - 1);
            trimmed = false;
         }
      }
      return str;
   }

   // initialize the default value of the delimiter
   char Utilities::m_delimiter{
       ','}; 

   // Static class function that returns the current delimiter
   char Utilities::getDelimiter() { return m_delimiter; }

   // Sets a new delimiter for all instances of Utilities
   void Utilities::setDelimiter(char newDelimiter) {
      m_delimiter = newDelimiter;
   }

   // Sets the width of the extracted token
   void Utilities::setFieldWidth(size_t newWidth) {
      m_widthField = newWidth;
   }

   // Gets the current fieldwidth
   size_t Utilities::getFieldWidth() const { return m_widthField; }

   // Extracts a token from a given string, returns a copy of the token trimmed of whitespace,
   // and returns the next position to check for a token by reference, and whether or not there
   // is another token by reference.
   std::string Utilities::extractToken(const std::string& str, size_t& next_pos,
                                       bool& more) {
      std::string token{};
      size_t right = str.find(m_delimiter, next_pos);
      if (right == next_pos) {
         more = false;
         throw("Invalid next position!");
      }
      if (right != std::string::npos) {
         token = str.substr(next_pos, right - next_pos);
         token = trim(token);
         more = true;
         if (m_widthField < right - next_pos) {
            m_widthField = right - next_pos;
         }
         next_pos = right + 1;
      }
      else {
         token = str.substr(next_pos);
         token = trim(token);
         more = false;
      }
      return token;
   }
} // namespace sdds
