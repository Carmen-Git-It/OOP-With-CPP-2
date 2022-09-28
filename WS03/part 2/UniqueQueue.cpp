// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   09/27/2022

#include "UniqueQueue.h"
#include <cmath>
namespace sdds {
template <> bool UniqueQueue<double>::push(const double& item) {
   bool unique    = true;
   bool isSuccess = false;
   for (std::size_t i = 0; i < Queue<double, 100u>::size(); i++) {
      if (std::fabs(item) <=
              std::fabs(Queue<double, 100u>::operator[](i)) + 0.005 &&
          std::fabs(item) >=
              std::fabs(Queue<double, 100u>::operator[](i)) - 0.005) {
         unique = false;
      }
   }
   if (unique) {
      isSuccess = Queue<double, 100u>::push(item);
   }
   return isSuccess;
}
} // namespace sdds
