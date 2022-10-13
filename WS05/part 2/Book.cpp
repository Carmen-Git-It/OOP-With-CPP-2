// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   10/11/2022

#include "Book.h"
#include <iostream>

namespace sdds {
   // Local function used to trim whitespace from both ends of a string
   std::string& Book::trim(std::string& str) {
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
   Book::Book() {
      ; // Intentionally left empty, initialization is done in the class
        // definition
   }

   // Parses an input string describing a book into a Book object
   Book::Book(const std::string& strBook) {
      std::string token{};
      size_t left{};
      size_t right{strBook.find(",")};
      m_author      = strBook.substr(left, right);
      m_author      = trim(m_author); // Trim the whitespace on both sides
      left          = right;
      right         = strBook.find(",", left + 1);
      m_title       = strBook.substr(left + 1, right - left - 1);
      m_title       = trim(m_title);
      left          = right;
      right         = strBook.find(",", left + 1);
      m_country     = strBook.substr(left + 1, right - left - 1);
      m_country     = trim(m_country);
      left          = right;
      right         = strBook.find(",", left + 1);
      token         = strBook.substr(left + 1, right - left - 1);
      m_price       = std::stod(token);
      left          = right;
      right         = strBook.find(",", left + 1);
      token         = strBook.substr(left + 1, right - left - 1);
      m_year        = std::stoi(token);
      left          = right;
      right         = strBook.find('\n', left + 1);
      m_description = strBook.substr(left + 1, right - left - 1);
      m_description = trim(m_description);
   }

   // Getter for the title of the book
   const std::string& Book::title() const { return m_title; }

   // Getter for the country of origin the book
   const std::string& Book::country() const { return m_country; }

   // Getter for the year the book was published
   const size_t& Book::year() const { return m_year; }

   // Mutable getter for the price of the book
   double& Book::price() { return m_price; }

   // Friend function insertion operator overload for an ostream, inserts the
   // formatted data contained within the book to the ostream
   std::ostream& operator<<(std::ostream& os, const Book& book) {
      os.width(20);
      os << book.m_author << " | ";
      os.width(22);
      os << book.m_title << " | ";
      os.width(5);
      os << book.m_country << " | ";
      os.width(4);
      os << book.m_year << " | ";
      os.width(6);
      os.precision(2);
      os << std::fixed << book.m_price << " | " << book.m_description
         << std::endl;

      return os;
   }

} // namespace sdds
