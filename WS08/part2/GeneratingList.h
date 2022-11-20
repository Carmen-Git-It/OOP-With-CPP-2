// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   11/18/2022

#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>
#include <cstring>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool validSin(const std::string& sin) const {
			int sum{};
			sum += std::stoi(sin.substr(sin.size() - 1, 1));
			// Iterate from the end of the number to the beginning, doubling every other number
			for (int i = sin.size() - 2; i >= 0; i--) {
				int val = std::stoi(sin.substr(i, 1)) * 2;
				// Add the two digits together if the multiplication exceeded 10
				if (val >= 10) {
					val = (val % 10) + ((val - (val % 10)) / 10);
				}
				sum += val;

				// iterate again to skip every other element
				if (i - 1 >= 0) {
					i--;
					sum += std::stoi(sin.substr(i, 1));
				}
			}

			// TODO: DELETE THIS
			if (sum % 10 != 0) {
				std::cout << "INVALID SIN: " << sin;
			}

			return sum % 10 == 0;
		}

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator+=(T* obj) {
			list.push_back(std::move(*obj));
			delete obj;
		}
		
		void operator+=(std::unique_ptr<T>& obj) {
			list.push_back(std::move(*obj));
		}

		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
