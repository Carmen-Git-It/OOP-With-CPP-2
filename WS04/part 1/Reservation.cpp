// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   10/02/2022

#include "Reservation.h"
#include <cstring>

namespace sdds {
// Default constructor
Reservation::Reservation() {
   ; // intentionally empty
}

Reservation::Reservation(const std::string& res) {
   std::string temp = res; // Make a mutable copy to use .empty()

   // first trim literally all whitespace from the string
   size_t index = temp.find(" ");
   while (index >= 0) {
      temp.erase(index);
   }
   // Copy the ID from the file into a local variable
   index = temp.find(":");
   strcpy(m_id, temp.substr(0, index).c_str());
   m_name       = temp.substr(index + 1, temp.find(",") - (index + 1));
   temp         = temp.substr(temp.find(",") + 1);
   m_email      = temp.substr(temp.find(","));
   temp         = temp.substr(temp.find(",") + 1);
   m_guestCount = std::stoi(temp.substr(0, temp.find(",")));
   temp         = temp.substr(temp.find(",") + 1);
   m_day        = std::stoi(temp.substr(0, temp.find(",")));
   temp         = temp.substr(temp.find(",") + 1);
   m_hour       = std::stoi(temp);
}
} // namespace sdds
