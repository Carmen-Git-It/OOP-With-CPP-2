// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   10/25/2022

#include "Van.h"
#include "Utilities.h"

namespace sdds {
   // Default constructor
   Van::Van() {
      ; // Intentionally empty, variables initialized in class definition
   }

   // Reads data into member variables from a single line of an input stream
   Van::Van(std::istream& is) {
      std::string token{};
      // Check the vehicle type
      std::getline(is, token, ',');
      if (!(token[0] == 'v' || token[0] == 'V')) {
         throw("Error; invalid type!");
      }

      // Get the vehicle maker
      std::getline(is, token, ',');
      token   = trim(token);
      m_maker = token;

      // Get the vehicle type
      std::getline(is, token, ',');
      token = trim(token);
      if (token[0] == 'p') {
         m_type = Pickup;
      }
      else if (token[0] == 'm') {
         m_type = Minibus;
      }
      else if (token[0] == 'c') {
         m_type = Camper;
      }
      else {
         throw("Invalid record: invalid vehicle type!");
      }

      // Get the vehicle purpose
      std::getline(is, token, ',');
      token = trim(token);
      if (token[0] == 'd') {
         m_purpose = Delivery;
      }
      else if (token[0] == 'p') {
         m_purpose = Passenger;
      }
      else if (token[0] == 'c') {
         m_purpose = Camping;
      }
      else {
         throw("Invalid record: invalid vehicle purpose!");
      }

      // Get vehicle condition
      std::getline(is, token, ',');
      token = trim(token);
      if (token.find_first_not_of(' ') == std::string::npos) {
         m_condition = New;
      }
      else if (token[0] == 'n') {
         m_condition = New;
      }
      else if (token[0] == 'u') {
         m_condition = Used;
      }
      else if (token[0] == 'b') {
         m_condition = Broken;
      }
      else {
         throw("Invalid record: invalid vehicle condition!");
      }

      // Get vehicle topspeed
      std::getline(is, token, ',');
      token      = trim(token);
      m_topSpeed = std::stod(token);
   }

   // Return the condition of the vehicle
   std::string Van::condition() const {
      return (m_condition == New ? "new"
                                 : (m_condition == Used ? "used" : "broken"));
   }

   // Return the type of van
   std::string Van::type() const {
      return (m_type == Pickup ? "pickup"
                               : (m_type == Minibus ? "mini-bus" : "camper"));
   }

   // Return the purpose of the van
   std::string Van::usage() const {
      return (m_purpose == Delivery
                  ? "delivery"
                  : (m_purpose == Passenger ? "passenger" : "camping"));
   }

   // Returns the top speed of the car
   double Van::topSpeed() const { return m_topSpeed; }

   // Outputs a formatted representation of the Van data to the output stream
   void Van::display(std::ostream& out) const {
      out << "| ";
      out.width(8);
      out << std::right << m_maker << " | ";
      out.width(12);
      out << std::left
          << (m_type == Pickup ? "pickup"
                               : (m_type == Minibus ? "mini-bus" : "camper"))
          << " | ";
      out.width(12);
      out << std::left
          << (m_purpose == Delivery
                  ? "delivery"
                  : (m_purpose == Passenger ? "passenger" : "camping"))
          << " | ";
      out.width(6);
      out << std::left
          << (m_condition == New ? "new"
                                 : (m_condition == Used ? "used" : "broken"))
          << " | ";
      out.precision(2);
      out.width(6);
      out << std::fixed << m_topSpeed << " |";
   }
} // namespace sdds
