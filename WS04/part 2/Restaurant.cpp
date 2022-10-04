// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   10/03/2022

#include "Restaurant.h"

namespace sdds {
// Deallocates the reservation pointer array
void Restaurant::deallocate() {
   for (size_t i = 0; i < m_count; i++) {
      delete m_reservations[i];
   }
   delete[] m_reservations;
}

// Destructor
Restaurant::~Restaurant() { deallocate(); }

// Parameterized constructor
Restaurant::Restaurant(const Reservation* reservations[], size_t count) {
   // Allocate memory for the array of pointers
   m_reservations = new Reservation*[count];
   for (size_t i = 0; i < count; i++) {
      // allocate memory for the individual pointer
      m_reservations[i]  = new Reservation;
      *m_reservations[i] = *reservations[i];
   }
   m_count = count;
}

// Copy constructor
Restaurant::Restaurant(const Restaurant& restaurant) { *this = restaurant; }

// Move constructor
Restaurant::Restaurant(Restaurant&& restaurant) {
   *this = std::move(restaurant);
}

// Copy assignment operator
Restaurant& Restaurant::operator=(const Restaurant& restaurant) {
   if (this != &restaurant) {
      deallocate();
      m_reservations = new Reservation*[restaurant.m_count];
      for (size_t i = 0; i < restaurant.m_count; i++) {
         m_reservations[i]  = new Reservation;
         *m_reservations[i] = *restaurant.m_reservations[i];
      }
      m_count = restaurant.m_count;
   }
   return *this;
}

// Move assignment operator
Restaurant& Restaurant::operator=(Restaurant&& restaurant) {
   if (this != &restaurant) {
      deallocate();
      m_count                   = restaurant.m_count;
      m_reservations            = restaurant.m_reservations;
      restaurant.m_reservations = nullptr;
   }
   return *this;
}

// Returns the size of the array of reservation pointers.
size_t Restaurant::size() const { return m_count; }

// Displays formatted output describing the member variable data to the passed
// output stream
std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant) {
   static unsigned called = 0;
   called++;
   os << "--------------------------\nFancy Restaurant " << called
      << "\n--------------------------\n";
   if (restaurant.m_count > 0) {
      for (size_t i = 0; i < restaurant.m_count; i++) {
         os << *restaurant.m_reservations[i] << "\n";
      }
   }
   else {
      os << "This restaurant is empty!";
   }

   os << "--------------------------\n";

   return os;
}

} // namespace sdds
