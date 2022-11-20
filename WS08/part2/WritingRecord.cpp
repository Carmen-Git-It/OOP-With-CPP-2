// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   11/18/2022

#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> temp{};
		for (size_t i = 0; i < emp.size(); i++) {
			bool matched = false;
			for (size_t j = 0; j < sal.size() && !matched; j++) {
				if (emp[i].id == sal[j].id) {
					matched = true;
					EmployeeWage* e = new EmployeeWage(emp[i].name, sal[j].salary);
					try {
						e->rangeValidator();
						if (!temp.validSin(emp[i].id)) {
							throw(std::string("***Employees SIN is not valid"));
						}
						temp += e;
					}
					catch (const char* err) {
						delete e;
						throw(std::string(err));
					}
					catch (const std::string& msg) {
						delete e;
						throw(msg);
					}
				}
			}
		}
		return temp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		for (size_t i = 0; i < emp.size(); i++) {
			bool matched = false;
			for (size_t j = 0; j < sal.size() && !matched; j++) {
				if (emp[i].id == sal[j].id) {
					matched = true;
					std::unique_ptr<EmployeeWage> e(new EmployeeWage(emp[i].name, sal[j].salary));
					try {
						e->rangeValidator();
						if (!activeEmp.validSin(emp[i].id)) {
							throw(std::string("***Employees SIN is not valid"));
						}
						activeEmp += e;
					}
					catch (const char* err) {
						throw(std::string(err));
					}
					catch (const std::string& msg) {
						throw(msg);
					}
				}
			}
		}

		return activeEmp;
	}
}