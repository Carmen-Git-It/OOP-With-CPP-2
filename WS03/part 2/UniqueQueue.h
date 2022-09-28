// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   09/27/2022

#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H
#include "Queue.h"
namespace sdds {
template <typename T> class UniqueQueue : public Queue<T, 100u>
{
 public:
   virtual ~UniqueQueue() {}
   virtual bool push(const T& item) {
      bool unique    = true;
      bool isSuccess = false;
      for (std::size_t i = 0; i < Queue<T, 100u>::size(); i++) {
         if (item == Queue<T, 100u>::operator[](i)) {
            unique = false;
         }
      }
      if (unique) {
         isSuccess = Queue<T, 100u>::push(item);
      }
      return isSuccess;
   };
};
} // namespace sdds
#endif //! SDDS_UNIQUEQUEUE_H
