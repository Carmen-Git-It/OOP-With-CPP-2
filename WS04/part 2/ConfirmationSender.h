// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   10/03/2022

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"
namespace sdds {
class ConfirmationSender
{
   const Reservation** m_reservations{};
   size_t m_count{};

 public:
   ~ConfirmationSender();
   ConfirmationSender();
   ConfirmationSender(const ConfirmationSender& cs);
   ConfirmationSender(ConfirmationSender&& cs);
   ConfirmationSender& operator=(const ConfirmationSender& cs);
   ConfirmationSender& operator=(ConfirmationSender&& cs);
   ConfirmationSender& operator+=(const Reservation& res);
   ConfirmationSender& operator-=(const Reservation& res);
   friend std::ostream& operator<<(std::ostream& os,
                                   const ConfirmationSender& cs);
};
} // namespace sdds

#endif //! SDDS_CONFIRMATIONSENDER_H
