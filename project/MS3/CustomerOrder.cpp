// Name: Carmen Whitton
// Seneca Student ID: 102710217
// Seneca email: cwihtton@myseneca.ca
// Date of completion: 11/29/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "CustomerOrder.h"
#include "Utilities.h"
#include <iomanip>

namespace sdds {
   // Initialize class variable
   std::size_t CustomerOrder::m_widthField{ 1 };

   // Dynamically resizes the array of pointers to items, and adds a new item
   // given by the string passed in to item.
   void CustomerOrder::addItem(std::string item) {
      // Create temp array and pop items over
      Item** temp = new Item * [m_cntItem + 1] {};
      for (std::size_t i = 0; i < m_cntItem; i++) {
         temp[i] = m_lstItem[i];
      }
      // Create new item at end of array, delete old array, point member array to temp array
      temp[m_cntItem] = new Item(item);
      delete[] m_lstItem;
      m_lstItem = temp;
      m_cntItem++;
   }

   // Default constructor
   CustomerOrder::CustomerOrder() {
      ; // Do nothing-- values initialized in class declaration.
   }

   // Accepts a string describing a CustomerOrder
   CustomerOrder::CustomerOrder(const std::string data) {
      Utilities ut{};
      ut.setDelimiter('|');
      std::size_t nextPos{};
      std::string temp{};
      bool more{ false };
      m_name = ut.extractToken(data, nextPos, more);
      m_product = ut.extractToken(data, nextPos, more);
      // Add the items
      do {
         temp = ut.extractToken(data, nextPos, more);
         if (temp.length() > 0) {
            addItem(temp);
         }
      } while (more);
      m_widthField = ut.getFieldWidth() > m_widthField ? ut.getFieldWidth() : m_widthField;
   }

   // Disallow copy-construction, throws an error.
   CustomerOrder::CustomerOrder(const CustomerOrder&) {
      throw("Error: CustomerOrder can not be constructed via copy!");
   }

   // Move constructor
   CustomerOrder::CustomerOrder(CustomerOrder&& order) noexcept {
      *this = std::move(order);
   }

   // Move assignment operator
   CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order) noexcept {
      if (this != &order) {
         // Shift items over first, cut order's access
         delete[] m_lstItem;
         m_lstItem = order.m_lstItem;
         m_cntItem = order.m_cntItem;
         order.m_lstItem = nullptr;
         order.m_cntItem = 0;
         // Then the other member variables
         m_name = order.m_name;
         m_product = order.m_product;
      }
      return *this;
   }

   // Destructor
   CustomerOrder::~CustomerOrder() {
      for (std::size_t i = 0; i < m_cntItem; i++) {
         delete m_lstItem[i];
      }
      delete[] m_lstItem;
   }

   // Returns true if every item in the order has been filled
   bool CustomerOrder::isOrderFilled() const {
      bool filled{ true };
      for (std::size_t i = 0; i < m_cntItem; i++) {
         if (!m_lstItem[i]->m_isFilled) {
            filled = false;
         }
      }
      return filled;
   }

   // Returns true if the items specified by itemName are all filled, 
   // or if there is no instance of the item.
   bool CustomerOrder::isItemFilled(const std::string& itemName) const {
      bool filled = true;
      for (std::size_t i = 0; i < m_cntItem; i++) {
         if (m_lstItem[i]->m_itemName.compare(itemName) == 0 && !m_lstItem[i]->m_isFilled) {
            filled = false;
         }
      }
      return filled;
   }

   // Fills an item designated by the given station
   void CustomerOrder::fillItem(Station& station, std::ostream& os) {
      bool filled = false;
      for (std::size_t i = 0; i < m_cntItem && !filled; i++) {
         if (station.getQuantity() > 0 && m_lstItem[i]->m_itemName.compare(station.getItemName()) == 0) {
            m_lstItem[i]->m_isFilled = true;
            station.updateQuantity();
            m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
            filled = true;
            os << "Filled " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << std::endl;
         }
      }
      if (!filled) {
         os << "Unable to fill " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << std::endl;
      }
   }

   // Displays formatted data stored by the CustomerOrder
   void  CustomerOrder::display(std::ostream& os) const {
      os << m_name << " - " << m_product << std::endl;
      for (std::size_t i = 0; i < m_cntItem; i++) {
         os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] " <<
            std::setw(m_widthField) << std::setfill(' ') << m_lstItem[i]->m_itemName << " - " <<
            (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
      }
   }
}