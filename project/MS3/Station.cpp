// Name: Carmen Whitton
// Seneca Student ID: 102710217
// Seneca email: cwihtton@myseneca.ca
// Date of completion: 11/29/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Station.h"
#include "Utilities.h"
#include <iostream>

namespace sdds {
   // Set initial value of id_generator to 0
   size_t Station::id_generator{ 0 };

   // Set the widthField to the same default as used in Utilities
   size_t Station::m_widthField{ 1 };

   // Single argument constructor, accepts a single line string representation of a record
   // that it then tokenizes and stores in local variables.
   Station::Station(const std::string& rec) {
      m_id = ++id_generator;
      Utilities ut{};
      size_t next_pos{};
      bool more{ false };
      m_itemName = ut.extractToken(rec, next_pos, more);
      m_serial = std::stoi(ut.extractToken(rec, next_pos, more));
      m_itemQuantity = std::stoi(ut.extractToken(rec, next_pos, more));
      m_widthField = m_widthField > ut.getFieldWidth() ? m_widthField : ut.getFieldWidth();
      m_description = ut.extractToken(rec, next_pos, more);
   }

   // Returns the name of the item managed by this station
   const std::string& Station::getItemName() const {
      return m_itemName;
   }

   // Returns the next serial number, increments the serial number
   size_t Station::getNextSerialNumber() {
      return m_serial++;
   }

   // Returns the quantity of items remaining at the station
   size_t Station::getQuantity() const {
      return m_itemQuantity;
   }

   // Decrements item quantity by 1
   void Station::updateQuantity() {
      m_itemQuantity--;
   }

   // Displays formatted output to a given output stream
   void Station::display(std::ostream& os, bool full) const {
      os.width(3);
      os.fill('0');
      os << m_id << " | ";
      os.width(m_widthField);
      os.fill(' ');
      os << m_itemName << " | ";
      os.width(6);
      os.fill('0');
      os << m_serial << " |";
      os.fill(' ');
      if (full) {
         os << " ";
         os.width(4);
         os << m_itemQuantity << " | " << m_description;
      }
      os << std::endl;
   }
}
