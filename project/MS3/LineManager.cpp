// Name: Carmen Whitton
// Seneca Student ID: 102710217
// Seneca email: cwihtton@myseneca.ca
// Date of completion: 11/29/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <fstream>
#include <algorithm>
#include "LineManager.h"

namespace sdds {
   // Parameterized Constructor, links all of the stations together according to the data
   // in the file and builds an activeLine based on the file requirements and the list of
   // available stations.
   LineManager::LineManager(const std::string& filename, const std::vector<Workstation*>& stations) {
      std::string line{};
      std::ifstream file(filename);
      std::size_t count{ 0 };
      if (file) {
         while (file) {
            // Read in the next line from the file
            std::getline(file, line);
            if (file) {
               // Resize the active line again to expand the number of entries
               m_activeLine.resize(count + 1);
               // Copy the workshops over one at a time as the lines are read in (inefficient, but no other loops allowed lol)
               std::copy_if(stations.begin(), stations.end(), m_activeLine.begin() + count, [&](Workstation* w) -> bool {
                  bool matched = false;
               // If the station found has a second station
               if (line.find('|') != std::string::npos && w->getItemName().compare(line.substr(0, line.find('|'))) == 0) {
                  // find the next station from the line
                  auto next = std::find_if(stations.begin(), stations.end(), [&](Workstation* m) -> bool {
                     return m->getItemName().compare(line.substr(line.find('|') + 1)) == 0;
                     });
                  // set the next station
                  w->setNextStation(*next);
                  matched = true;
               }
               else if (w->getItemName().compare(line) == 0) {
                  matched = true;
               }
                  return matched;
               });
            }
           
            // Track the count
            count++;
         }
         // Identify the first workstation
         auto first = std::find_if_not(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* w) -> bool {
            // Count the number of stations that have station w as the next station
            auto c = std::count_if(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* m) -> bool {
               return m->getNextStation() == w;
            });
            // return true if the number of stations referencing w is greater than 0
            return c > 0;
         });
         // Assign the first station
         m_firstStation = *first;

         // Update the number of customer orders
         m_cntCustomerOrder = g_pending.size();
      }
      else {
         throw("Error opening file!");
      }
   }

   // Reorder the stations in order of the assembly line
   void LineManager::reorderStations() {
      // Create a temporary vector
      std::vector<Workstation*> tempList{};
      // Start with the first node, work our way to the end (this is basically a linked list)
      Workstation* temp = m_firstStation;
      tempList.push_back(temp);
      while (temp->getNextStation()) {
         temp = temp->getNextStation();
         tempList.push_back(temp);
      }
      m_activeLine = tempList;
   }

   // Emulates a single step of operations in the assembly line
   bool LineManager::run(std::ostream& os) {
      bool done = false;
      static unsigned count{ 0 };
      count++;
      os << "Line Manager Iteration: " << count << std::endl;
      // If there are pending orders left
      if (g_pending.size() > 0) {
         // Move the next order off of pending and onto the first station
         *m_firstStation += std::move(g_pending.front());
         g_pending.pop_front();
      }
      
      // Fill and move items along for each active line
      for (Workstation* w : m_activeLine) {
         w->fill(os);
      }

      for (Workstation* w : m_activeLine) {
         w->attemptToMoveOrder();
      }

      /*for (auto it = m_activeLine.rbegin(); it != m_activeLine.rend(); it++) {
         (*it)->attemptToMoveOrder();
      }*/
      
      // If all of the customer orders are in one of the two finished piles, done is true
      if (m_cntCustomerOrder == g_completed.size() + g_incomplete.size()) {
         done = true;
      }

      return done;
   }

   // Display every active station in order
   void LineManager::display(std::ostream& os) const {
      for (Workstation* w : m_activeLine) {
         w->display(os);
      }
   }
}