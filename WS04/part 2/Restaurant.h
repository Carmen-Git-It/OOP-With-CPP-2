// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   10/03/2022

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include "Reservation.h"
namespace sdds {
class Restaurant
{
   size_t m_count;
   Reservation** m_reservations;
   void deallocate();

 public:
   ~Restaurant();
   Restaurant(const Reservation* reservations[], size_t count);
   Restaurant(const Restaurant& restaurant);
   Restaurant(Restaurant&& restaurant);
   Restaurant& operator=(const Restaurant& restaurant);
   Restaurant& operator=(Restaurant&& restaurant);
   size_t size() const;
   friend std::ostream& operator<<(std::ostream&, const Restaurant& restaurant);
};

} // namespace sdds

#endif // !SDDS_RESTAURANT_H
