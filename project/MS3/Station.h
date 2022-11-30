// Name: Carmen Whitton
// Seneca Student ID: 102710217
// Seneca email: cwihtton@myseneca.ca
// Date of completion: 11/29/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <string>

namespace sdds {
   class Station
   {
      int m_id;
      std::string m_itemName;
      std::string m_description;
      size_t m_serial;
      size_t m_itemQuantity;
      static size_t m_widthField;
      static size_t id_generator;
   public:
      Station(const std::string& rec);
      const std::string& getItemName() const;
      size_t getNextSerialNumber();
      size_t getQuantity() const;
      void updateQuantity();
      void display(std::ostream& os, bool full) const;
   };
} // namespace sdds

#endif // !SDDS_STATION_H
