// Name: Carmen Whitton
// Seneca Student ID: 102710217
// Seneca email: cwihtton@myseneca.ca
// Date of completion: 11/29/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <string>

namespace sdds {
   class Utilities
   {
      std::size_t m_widthField{1};
      static char m_delimiter;
      std::string& trim(std::string& str);

    public:
      void setFieldWidth(size_t newWidth);
      size_t getFieldWidth() const;
      std::string extractToken(const std::string& str, size_t& next_pos,
                               bool& more);
      static void setDelimiter(char newDelimiter);
      static char getDelimiter();
   };
} // namespace sdds

#endif //! SDDS_UTILITIES_H
