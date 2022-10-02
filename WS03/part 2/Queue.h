// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   09/27/2022

#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H
#include "Dictionary.h"
#include <iostream> // For the size_t type
namespace sdds {

template <typename T, std::size_t CAPACITY> class Queue
{
   const static T m_default; // Placeholder empty item, returned when asked
                             // for a non-existent item
   T m_items[CAPACITY]{};    // Holds the array of items in the queue.
   std::size_t m_numItems{};

 public:
   Queue() {}
   virtual ~Queue() {}
   // Adds new item to queue, returns true if
   // successful, false otherwise
   virtual bool push(const T& item) {
      bool isSuccess = false;
      if (m_numItems < CAPACITY) {
         m_items[m_numItems] = item;
         m_numItems++;
         isSuccess = true;
      }
      return isSuccess;
   }
   // Removes item from queue, creates a temporary copy, returns said
   // copy
   T pop() {
      T temp;
      if (m_numItems > 0) {
         temp = m_items[0];
         for (std::size_t i = 0; i < m_numItems; i++) {
            m_items[i] = m_items[i + 1];
         }
      }
      else {
         temp = m_default;
      }
      m_numItems--;
      return temp;
   }
   // Returns the number of elements in the queue
   size_t size() const { return m_numItems; };
   // Formatted output to provided ostream
   std::ostream& display(std::ostream& os = std::cout) const {
      os << "----------------------\n"
         << "| Dictionary Content |\n"
         << "----------------------\n";
      for (std::size_t i = 0; i < m_numItems; i++) {
         os << m_items[i] << std::endl;
      }
      os << "----------------------\n";
      return os;
   };
   // Returns either a copy of the index
   // requested, or a placeholder item
   T operator[](size_t index) const {
      T temp;
      if (index >= m_numItems) {
         temp = m_default;
      }
      else {
         temp = m_items[index];
      }
      return temp;
   };
};

template <typename T, std::size_t CAPACITY>
const T Queue<T, CAPACITY>::m_default = T{};
template <>
inline const Dictionary Queue<Dictionary, 100u>::m_default =
    Dictionary{"Empty Term", "Empty Substitute"};

} // namespace sdds
#endif // SDDS_QUEUE_H
