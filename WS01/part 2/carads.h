// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   09/11/2022 (Happy birthday to me!)

#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H

#include <iostream>

extern double g_taxrate, g_discount;
namespace sdds {
void listArgs(int argc, char *argv[]);

class Cars {
  char *m_brand{};
  char m_model[16]{};
  int m_year{};
  double m_price{};
  char m_status{}; // N for new or U for used
  bool m_discounted{};

public:
  Cars();
  ~Cars();
  Cars(const Cars &);
  Cars &operator=(const Cars &);
  operator bool() const;
  // Data read in format:
  // <Order Tag>,<Car Brand>,<CarModel>,<Year>,<Price>,<Discount status>
  void read(std::istream &is);
  // If no brand is stored, prints nothing, otherwise displays car data.
  void display(bool reset) const;
  char getStatus() const;
};

std::istream &operator>>(std::istream &is, Cars &car);
void operator>>(const Cars &car1, Cars &car2);
} // namespace sdds

#endif // SDDS_CARADS_H
