// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   10/25/2022

#include "Car.h"
#include "Utilities.h"

namespace sdds {
   // Default constructor
   Car::Car() {
      ; // Intentionally empty, variables initialized in class definition
   }

   // Reads data into member variables from a single line of an input stream
   Car::Car(std::istream& is) {
      std::string token{};
      // Check the vehicle type
      std::getline(is, token, ',');
      if (!(token[0] == 'c' || token[0] == 'C')) {
         throw("Error; invalid type!");
      }

      // Get the vehicle maker
      std::getline(is, token, ',');
      token   = trim(token);
      m_maker = token;

      // Get vehicle condition
      std::getline(is, token, ',');
      token = trim(token);
      if (token[0] == 'n') {
         m_condition = New;
      }
      else if (token[0] == 'u') {
         m_condition = Used;
      }
      else if (token[0] == 'b') {
         m_condition = Broken;
      }

      // Get vehicle topspeed
      std::getline(is, token, ',');
      token      = trim(token);
      m_topSpeed = std::stod(token);
   }

   // Return the condition of the vehicle
   std::string Car::condition() const {
      return (m_condition == New ? "new"
                                 : (m_condition == Used ? "used" : "broken"));
   }

   // Returns the top speed of the car
   double Car::topSpeed() const { return m_topSpeed; }

   // Outputs a formatted representation of the Car data to the output stream
   void Car::display(std::ostream& out) const {
      out << "| ";
      out.width(10);
      out << m_maker << " | ";
      out.width(6);
      out << (m_condition == New ? "new"
                                 : (m_condition == Used ? "used" : "broken"))
          << " | ";
      out.precision(2);
      out.width(6);
      out << std::fixed << m_topSpeed << " |";
   }
} // namespace sdds
