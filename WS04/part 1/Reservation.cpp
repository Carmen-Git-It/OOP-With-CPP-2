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

// Parameterized constructor accepts a line of data from the data
// file representing a reservation formatted as such:
// ID:NAME,EMAIL,PARTY_SIZE,DAY,HOUR
// Stores the data in the member variables.
Reservation::Reservation(const std::string& res) {
   std::string temp = res; // Make a mutable copy to use .empty()

   // first trim literally all whitespace from the string
   size_t index = temp.find(" ");
   while (index != std::string::npos) {
      temp.erase(index, 1);
      index = temp.find(" ");
   }

   // Copy the ID from the file into a local variable
   index = temp.find(":");
   strcpy(m_id, temp.substr(0, index).c_str());
   m_name = temp.substr(index + 1, temp.find(",") - (index + 1));
   temp   = temp.substr(temp.find(",") + 1);
   std::cout << "temp: " << temp << std::endl;

   m_email      = temp.substr(0, temp.find(","));
   temp         = temp.substr(temp.find(",") + 1);
   m_guestCount = std::stoi(temp.substr(0, temp.find(",")));
   temp         = temp.substr(temp.find(",") + 1);
   m_day        = (std::stoi(temp.substr(0, temp.find(","))));
   temp         = temp.substr(temp.find(",") + 1);
   m_hour       = (unsigned char)std::stoi(temp);
}

// A setter for the day and hour member variables
void Reservation::update(int day, int time) {
   m_day  = day;
   m_hour = time;
}

std::ostream& operator<<(std::ostream& os, const Reservation& res) {
   os.width(10);
   os << std::right << res.m_id << ": ";
   os.width(20);
   os << std::right << res.m_name << " <";
   os.width(20);
   os << std::left << res.m_email << "> ";

   if (res.m_hour >= 6 && res.m_hour <= 9) {
      os << "Breakfast ";
   }
   else if (res.m_hour >= 11 && res.m_hour <= 15) {
      os << "Lunch ";
   }
   else if (res.m_hour >= 17 && res.m_hour <= 21) {
      os << "Dinner ";
   }
   else {
      os << "Drinks ";
   }
   os << "on day " << (int)res.m_day << " @ " << (int)res.m_hour << ":00 for #"
      << res.m_guestCount
      << (res.m_guestCount == 1 ? " person.\n" : " people.\n");
   return os;
}
} // namespace sdds
