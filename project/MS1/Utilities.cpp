// Name: Carmen Whitton
// Seneca Student ID: 102710217
// Seneca email: cwihtton@myseneca.ca
// Date of completion: 10/26/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

namespace sdds {
   char Utilities::m_delimiter{
       ','}; // initialize the default value of the delimiter

   // Static class function that returns the current delimiter
   char Utilities::getDelimiter() { return m_delimiter; }

   // Sets a new delimiter for all instances of Utilities
   void Utilities::setDelimiter(char newDelimiter) {
      m_delimiter = newDelimiter;
   }

   // Sets the width of the extracted token
   void Utilities::setFieldWidth(size_t newWidth) { m_widthField = newWidth; }

   // Gets the current fieldwidth
   size_t Utilities::getFieldWidth() const { return m_widthField; }

   // Extracts a token from a given string
   std::string Utilities::extractToken(const std::string& str, size_t& next_pos,
                                       bool& more) {
      size_t right = str.find(m_delimiter);
   }
} // namespace sdds
