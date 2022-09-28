// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   09/25/2022

#include "Queue.h"

namespace sdds {
template <>
const Dictionary Queue<Dictionary, 100u>::m_default =
    Dictionary{"Empty Term", "Empty Substitute"};
}
