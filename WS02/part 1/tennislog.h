// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   09/11/2022 (Happy birthday to me!)

#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H

#include <iostream>
#include <string>

namespace sdds {

struct TennisMatch {
  std::string tournamentId{};
  std::string tournamentName{};
  std::string winner{};
  std::string loser{};
  unsigned int matchId{};
  operator bool() const;
};

std::ostream &operator<<(std::ostream &, const TennisMatch &);

class TennisLog {
  TennisMatch *matches{};

public:
  TennisLog();
  ~TennisLog();
  TennisLog(const char *filename);
  void addMatch(const TennisMatch &);
  TennisLog findMatches(const char *playerName);
  const TennisMatch &operator[](size_t) const;
  operator size_t() const;
};

} // namespace sdds
#endif // SDDS_TENNISLOG_H
