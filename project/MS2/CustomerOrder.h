// Name: Carmen Whitton
// Seneca Student ID: 102710217
// Seneca email: cwihtton@myseneca.ca
// Date of completion: 11/11/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include "Station.h"
#include <string>
#include <iostream>

namespace sdds {
   class CustomerOrder {
      struct Item
      {
         std::string m_itemName{};
         std::size_t m_serialNumber{ 0 };
         bool m_isFilled{ false };

         Item(const std::string& src) : m_itemName(src) {};
      };
      std::string m_name{};  // Customer name
      std::string m_product{}; // Product name
      std::size_t m_cntItem{};  // Number of items in the customer's order
      Item** m_lstItem{};  // Dynamic array of Items, each Item is dynamically allocated.
      static size_t m_widthField;
      void addItem(std::string);
   public:
      CustomerOrder();
      CustomerOrder(const std::string);
      CustomerOrder(const CustomerOrder&);
      CustomerOrder& operator=(const CustomerOrder&) = delete;
      CustomerOrder(CustomerOrder&&) noexcept;
      CustomerOrder& operator=(CustomerOrder&&) noexcept;
      ~CustomerOrder();
      bool isOrderFilled() const;
      bool isItemFilled(const std::string& itemName) const;
      void fillItem(Station& station, std::ostream& os);
      void display(std::ostream& os) const;
   };
}

#endif //!SDDS_CUSOMERORDER_H