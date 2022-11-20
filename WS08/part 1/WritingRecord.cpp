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
					}
					catch (...) {
						delete e;
					}
					try {
						temp.validSin(emp[i].id);
						temp += e;
					}
					catch (...) {
						throw(std::string("ERROR: *** Employees salaray range is not valid"));
					}
				}
			}
		}
		return temp;
	}
}