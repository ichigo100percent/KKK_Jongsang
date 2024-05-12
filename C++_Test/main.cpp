#include "Salary.h"
#include <vector>
using namespace Js;

int main()
{
	vector<Employee*> employees;
	Employee* e1 = new SalaryHourly("권상우", ePositionType::사원, 200);
	Employee* e2 = new SalaryHourly("조인성", ePositionType::사원, 220);
	Employee* e3 = new SalaryMonthly("김우성", ePositionType::대리, 3);
	Employee* e4 = new SalaryMonthly("강동원", ePositionType::대리, 5);
	Employee* e5 = new SalaryAnnualy("황정민", ePositionType::과장, 3);
	Employee* e6 = new SalaryMonthly("박종훈", ePositionType::과장, 15);
	Employee* e7 = new SalaryMonthly("최민식", ePositionType::부장, 20);
	Employee* e8 = new SalaryAnnualy("정찬영", ePositionType::부장, 3);
	Employee* e9 = new SalaryHourly("안성기", ePositionType::이사, 50);
	Employee* e10 = new SalaryAnnualy("송강호", ePositionType::이사, 4);

	for (Employee* emp : { e1, e2, e3, e4, e5, e6, e7, e8, e9, e10 }) 
	{
		employees.push_back(emp);
	}

	for (size_t i = 0; i < employees.size(); i++)
	{

		cout << employees[i]->GetName() << " ";
		cout << employees[i]->GetPostion() << " ";
		cout << employees[i]->GetSalary() << endl;
	}


	return 0;
}