// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   09/11/2022 (Happy birthday to me!)

#include "tennislog.h"

namespace sdds {

/*** Tennis Match ***/

TennisMatch::operator bool() const { return false; }

std::ostream &operator<<(std::ostream &os, const TennisMatch &match) {
  if (!match) {
    os << "Empty Match";
  } else {
    os.fill('.');
    os.width(20);
    os << os.right << "Tourney ID : ";
    os.width(30);
    os << os.left << match.tournamentId << std::endl;
    os.width(20);
    os << os.right << "Match ID : ";
    os.width(30);
    os << os.left << match.matchId << std::endl;
    os.width(20);
    os << os.right << "Tourney : ";
    os.width(30);
    os << os.left << match.tournamentName << std::endl;
    os.width(20);
    os << os.right << "Winner : ";
    os.width(30);
    os << os.left << match.winner << std::endl;
    os.width(20);
    os << os.right << "Loser : ";
    os.width(30);
    os << os.left << match.loser << std::endl;
  }

  return os;
}

/*** Tennis Log ***/
TennisLog::TennisLog() {
  // Empty constructor, all values are initialized to safe empty values;
}

TennisLog::~TennisLog() { delete[] matches; }

TennisLog::TennisLog(const char *filename) {
  // TODO read file to create TennisLog instance
}

void addMatch(const TennisMatch &);
TennisLog findMatches(const char *playerName);
const TennisMatch &operator[](size_t) const;
operator size_t() const;

} // namespace sdds
