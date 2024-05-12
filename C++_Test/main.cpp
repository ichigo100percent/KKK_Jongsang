#include "Salary.h"
#include <vector>
using namespace Js;

int main()
{
	vector<Employee*> employees;
	Employee* e1 = new SalaryHourly("�ǻ��", ePositionType::���, 200);
	Employee* e2 = new SalaryHourly("���μ�", ePositionType::���, 220);
	Employee* e3 = new SalaryMonthly("��켺", ePositionType::�븮, 3);
	Employee* e4 = new SalaryMonthly("������", ePositionType::�븮, 5);
	Employee* e5 = new SalaryAnnualy("Ȳ����", ePositionType::����, 3);
	Employee* e6 = new SalaryMonthly("������", ePositionType::����, 15);
	Employee* e7 = new SalaryMonthly("�ֹν�", ePositionType::����, 20);
	Employee* e8 = new SalaryAnnualy("������", ePositionType::����, 3);
	Employee* e9 = new SalaryHourly("�ȼ���", ePositionType::�̻�, 50);
	Employee* e10 = new SalaryAnnualy("�۰�ȣ", ePositionType::�̻�, 4);

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