// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   09/19/2022 (Happy birthday to me!)

#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H

#include <iostream>
#include <string>

namespace sdds {

// Empty state:
// matchId : 0
// tournamentId : empty string
struct TennisMatch {
   std::string m_tournamentId{};
   std::string m_tournamentName{};
   unsigned int m_matchId{};
   std::string m_winner{};
   std::string m_loser{};
   operator bool() const;
};

std::ostream& operator<<(std::ostream&, const TennisMatch&);

// Empty state:
// matches : nullptr
class TennisLog
{
   TennisMatch* m_matches{};
   size_t m_numMatches{};

 public:
   TennisLog();
   ~TennisLog();
   TennisLog(const TennisLog&);  // Copy constructor
   TennisLog(const TennisLog&&); // Move constructor
   TennisLog(const char* filename);
   void addMatch(const TennisMatch&);
   TennisLog findMatches(const char* playerName);
   const TennisMatch operator[](size_t) const;
   operator size_t() const;
   TennisLog& operator=(const TennisLog&); // Copy assignment
   TennisLog& operator=(TennisLog&&);      // Move assignment
};

} // namespace sdds
#endif // SDDS_TENNISLOG_H
