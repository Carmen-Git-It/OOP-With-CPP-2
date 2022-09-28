// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   09/27/2022

#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H

#include <string>
namespace sdds {
class Dictionary
{
   std::string m_term{};
   std::string m_definition{};

 public:
   Dictionary();
   const std::string& getTerm() const { return m_term; }
   const std::string& getDefinition() const { return m_definition; }
   Dictionary(const std::string& term, const std::string& definition)
       : m_term{term}, m_definition{definition} {}
   friend std::ostream& operator<<(std::ostream& os, const Dictionary&);
   bool operator==(const Dictionary&) const;

   // TODO: Code the missing prototype functions and operators
   //       that the class needs in order to work with the Queue class.
   //       Implement them in the Dictionary.cpp file.
};
} // namespace sdds
#endif // SDDS_DICTIONARY_H
