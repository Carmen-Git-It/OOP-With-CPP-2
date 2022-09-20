// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   09/19/2022 (Happy birthday to me!)

#include "TennisLog.h"
#include <cstring>
#include <fstream>
#include <iostream>

namespace sdds {

/*** Tennis Match ***/

TennisMatch::operator bool() const {
   return m_matchId != 0 && m_tournamentId.length() != 0;
}

std::ostream& operator<<(std::ostream& os, const TennisMatch& match) {
   if (!match) {
      os << "Empty Match";
   }
   else {
      os.fill('.');
      os.width(20);
      os << std::right << "Tourney ID : ";
      os.width(30);
      os << std::left << match.m_tournamentId << std::endl;
      os.width(20);
      os << std::right << "Match ID : ";
      os.width(30);
      os << std::left << match.m_matchId << std::endl;
      os.width(20);
      os << std::right << "Tourney : ";
      os.width(30);
      os << std::left << match.m_tournamentName << std::endl;
      os.width(20);
      os << std::right << "Winner : ";
      os.width(30);
      os << std::left << match.m_winner << std::endl;
      os.width(20);
      os << std::right << "Loser : ";
      os.width(30);
      os << std::left << match.m_loser << std::endl;
   }

   return os;
}

/*** Tennis Log ***/

TennisLog::TennisLog() {
   m_matches = nullptr;
   // Empty constructor, all values are initialized to safe empty values;
}

// Delete class resources to avoid memory leaks
TennisLog::~TennisLog() { delete[] m_matches; }

// Copy constructor
TennisLog::TennisLog(const TennisLog& log) { *this = log; }

// Move constructor
TennisLog::TennisLog(const TennisLog&& log) { *this = std::move(log); }

// Copy assignment operator
TennisLog& TennisLog::operator=(const TennisLog& log) {
   if (this != &log) {
      delete[] m_matches;
      m_numMatches = log.m_numMatches;
      m_matches    = new TennisMatch[m_numMatches];
      for (size_t i = 0; i < m_numMatches; i++) {
         m_matches[i] = log.m_matches[i];
      }
   }
   return *this;
}

// Move assignment
TennisLog& TennisLog::operator=(TennisLog&& log) {
   if (this != &log) {
      m_numMatches = log.m_numMatches;
      delete[] m_matches;
      m_matches     = log.m_matches;
      log.m_matches = nullptr;
   }
   return *this;
}

// Accepts a .csv file as a source of initial match data
TennisLog::TennisLog(const char* filename) {
   std::string buffer; // buffer for file reading
   std::ifstream file(filename);

   size_t numMatches{0};
   if (file.is_open()) {
      std::getline(file, buffer); // Takes the header out so it isn't counted
      // Get the number of matches
      while (file) {
         std::getline(file, buffer);
         numMatches++;
      }
      // Account for extra read at the end
      numMatches--;
      // allocate memory for the matches
      m_matches = new TennisMatch[numMatches];
      // clear the flags and rewind the file
      file.clear();
      file.seekg(0);
      // clear the header
      std::getline(file, buffer);
      // start the second loop through
      while (file) {
         std::getline(file, buffer, ',');
         // double check the read worked properly
         if (file) {
            // Grab each value individually
            m_matches[m_numMatches].m_tournamentId = buffer;
            std::getline(file, buffer, ',');
            m_matches[m_numMatches].m_tournamentName = buffer;
            std::getline(file, buffer, ',');
            m_matches[m_numMatches].m_matchId = std::stoul(buffer);
            std::getline(file, buffer, ',');
            m_matches[m_numMatches].m_winner = buffer;
            std::getline(file, buffer);
            m_matches[m_numMatches].m_loser = buffer;
            m_numMatches++;
         }
      }
      // Make sure to close the file to prevent a memory leak
      file.close();
   }
   else {
      std::cerr << "Error: Could not open file: " << filename << std::endl;
   }
}

// Takes a reference to a match and adds it to the list
// of matches stored in the TennisLog array
void TennisLog::addMatch(const TennisMatch& match) {
   // Create a new buffer one element larger
   TennisMatch* tempMatches = new TennisMatch[m_numMatches + 1];
   // Copy each match over one at a time
   for (size_t i = 0; i < m_numMatches; i++) {
      tempMatches[i] = m_matches[i];
   }

   // Delete the array of old values and copy the address of the new memory
   delete[] m_matches;
   m_matches = tempMatches;
   // Insert new match
   m_matches[m_numMatches] = match;
   // Increment match count
   m_numMatches++;
}

// Searches the list of matches for the name given
// Returns the match if the name is found
// Returns an empty match if the name is not found
TennisLog TennisLog::findMatches(const char* playerName) {
   TennisLog log;
   for (size_t i = 0; i < m_numMatches; i++) {
      if (strcmp(playerName, m_matches[i].m_winner.c_str()) == 0 ||
          strcmp(playerName, m_matches[i].m_loser.c_str()) == 0) {
         log.addMatch(m_matches[i]);
      }
   }
   return log;
}

const TennisMatch TennisLog::operator[](size_t index) const {
   TennisMatch match;
   if (index < m_numMatches) {
      match = m_matches[index];
   }
   return match;
}

TennisLog::operator size_t() const { return m_numMatches; }

} // namespace sdds
