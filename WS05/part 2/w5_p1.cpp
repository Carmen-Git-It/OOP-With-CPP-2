// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel

#include "Book.h"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace sdds;

enum AppErrors {
   CannotOpenFile   = 1, // An input file cannot be opened
   BadArgumentCount = 2, // The application didn't receive anough parameters
};

// ws books.txt
int main(int argc, char** argv) {
   std::cout << "Command Line:\n";
   std::cout << "--------------------------\n";
   for (int i = 0; i < argc; i++)
      std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
   std::cout << "--------------------------\n\n";

   // get the books
   sdds::Book library[7];
   if (argc == 2) {
      std::ifstream file(argv[1]);
      if (file) {
         size_t index{}; // Tracks the number of library indices filled
         while (file && index < 7) {
            std::string temp{};
            std::getline(file, temp, '\n');
            // If the line isn't a comment
            if (temp[0] != '#') {
               library[index++] = Book(temp);
            }
         }
      }
      else {
         std::cerr << "Error: Could not open file: " << argv[1] << std::endl;
         exit(AppErrors::CannotOpenFile);
      }
   }
   else {
      std::cerr << "ERROR: Incorrect number of arguments.\n";
      exit(AppErrors::BadArgumentCount);
   }

   double usdToCadRate = 1.3;
   double gbpToCadRate = 1.5;

   // Lambda
   auto fix = [=](Book& book) {
      if (!book.country().compare("US")) {
         book.price() *= usdToCadRate;
      }
      else if (!book.country().compare("UK") && book.year() >= 1990 &&
               book.year() <= 1999) {
         book.price() *= gbpToCadRate;
      }
   };

   std::cout << "-----------------------------------------\n";
   std::cout << "The library content\n";
   std::cout << "-----------------------------------------\n";
   for (Book& b : library) {
      std::cout << b << std::endl;
   }

   std::cout << "-----------------------------------------\n\n";
   for (Book& b : library) {
      fix(b);
   }

   std::cout << "-----------------------------------------\n";
   std::cout << "The library content (updated prices)\n";
   std::cout << "-----------------------------------------\n";
   for (Book& b : library) {
      std::cout << b << std::endl;
   }

   std::cout << "-----------------------------------------\n";

   return 0;
}
