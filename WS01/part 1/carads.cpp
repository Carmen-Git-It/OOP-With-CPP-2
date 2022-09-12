// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   09/11/2022 (Happy birthday to me!)

#include "carads.h"
#include <cstring>

double g_discount = 0;
double g_taxrate = 0;

namespace sdds {
// Displays the arguments passed in in list form
void listArgs(int argc, char *argv[]) {
  std::cout << "Command Line:\n"
            << "--------------------------" << std::endl;
  for (int i = 0; i < argc; i++) {
    std::cout << "  " << i + 1 << ": " << argv[i] << std::endl;
  }
  std::cout << "--------------------------\n" << std::endl;
}

// Empty constructor, all values initialized to safe empty state
Cars::Cars() {}

void Cars::read(std::istream &is) {
  char discount = 'x';
  if (is) {
    is >> m_status;
    // Throw out comma
    is.ignore();
    is.get(m_brand, 11, ',');
    is.ignore();
    is.get(m_model, 16, ',');
    is.ignore();
    is >> m_year;
    is.ignore();
    is >> m_price;
    is.ignore();
    is >> discount;
    m_discounted = discount == 'Y' ? true : false;
    is.ignore();
  }
}

void Cars::display(bool reset) const {
  static int counter = 0;
  if (reset) {
    counter = 0;
  }
  counter++;
  // double discount = g_discount * m_price;
  double taxedPrice = m_price + m_price * g_taxrate;
  double discountPrice = taxedPrice - taxedPrice * g_discount;
  if (strlen(m_brand) > 0) {
    std::cout.width(2);
    std::cout << std::left << counter << ". ";
    std::cout.width(10);
    std::cout << std::left << m_brand << "| ";
    std::cout.width(15);
    std::cout << std::left << m_model << "| ";
    std::cout << m_year << " |";
    std::cout.width(12);
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::cout << std::right << taxedPrice << "|";
    std::cout.width(12);
    if (m_discounted) {
      std::cout << std::right << discountPrice << std::endl;
      // std::cout << std::right
      // << (m_price * (((double)1 + g_taxrate))) /
      // ((double)1 + g_discount)
      // << std::endl;
    } else {
      std::cout << std::endl;
    }
  } else {
    std::cout << counter << ". No Car";
  }
}

char Cars::getStatus() const { return m_status; }
} // namespace sdds
