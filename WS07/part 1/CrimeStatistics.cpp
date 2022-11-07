// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   11/06/2022

#include "CrimeStatistics.h"
#include <fstream>
#include <iostream> // TODO: Remove after debug


namespace sdds {
   // Utility function to clear whitespace
   std::string& trim(std::string& str) {
      bool trimmed = false;

      while (!trimmed) {
         trimmed = true;
         if (str.find(' ') == 0) {
            trimmed = false;
            str.erase(str.begin());
         }
         if (str.size() > 0 &&
            str.substr(str.size() - 1, 1).find(' ') != std::string::npos) {
            str.erase(str.end() - 1);
            trimmed = false;
         }
      }
      return str;
   }

   // Custom constructor attempts to read Crime objects from the given file
   // and stores the objects in a vector
   CrimeStatistics::CrimeStatistics(const char* filename) {
      std::ifstream file(filename);

      if (file) {
         while (file) {
            // Temp variables
            Crime crime{};
            char buffer[26];
            std::string token{};
            // Get province
            file.get(buffer, 26);
            token = std::string(buffer);
            token = trim(token);
            crime.province = token;
            // Get district
            file.get(buffer, 26);
            token = std::string(buffer);
            token = trim(token);
            crime.district = token;
            // Get crime
            file.get(buffer, 26);
            token = std::string(buffer);
            token = trim(token);
            crime.crime = token;
            // Get year
            file.get(buffer, 6);
            crime.year = atoi(buffer);
            // Get cases
            file.get(buffer, 6);
            crime.numCases = atoi(buffer);
            // Get resolved
            file.get(buffer, 6);
            crime.numResolved = atoi(buffer);
            // Clear the line and push the crime into the vector
            std::getline(file, token);
            m_crimes.push_back(crime);
         }
      }
      else {
         throw("Error: Invalid file name!");
      }

   }

   void CrimeStatistics::display(std::ostream& out) const {
      for (auto it = m_crimes.cbegin(); it < m_crimes.cend(); it++) {
         out << *it << std::endl;
      }
   }

   std::ostream& operator<<(std::ostream& out, const Crime& crime) {
      out << "| ";
      out.width(21);
      out.fill(' ');
      out << crime.province << " |";
      out.width(15);
      out << crime.district << " |";
      out.width(20);
      out << crime.crime << " |";
      out.width(6);
      out << crime.year << " |";
      out.width(4);
      out << crime.numCases << " |";
      out.width(3);
      out << crime.numResolved << " |";
      return out;
   }
}