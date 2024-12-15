#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Employee
{
public:
	using ptr = shared_ptr<Employee>;
	virtual double getSalary() = 0;
};

class FixedSalaryEmployee: public Employee
{
public:
	FixedSalaryEmployee(double salary = 0, double factor = 1.0)
		:_fixed_salary(salary)
		,_factor(factor)
	{}

	double getSalary()
	{
		return _fixed_salary * _factor;
	}
private:
	double _fixed_salary;
	double _factor;
};

class CommissionEmployee : public Employee
{
public:
	CommissionEmployee(double salary = 0, double factor = 1.0)
		:_commission(salary)
		, _factor(factor)
	{}

	double getSalary()
	{
		return _commission * _factor;
	}
private:
	double _commission;
	double _factor;
};

class MultiEmployee : public Employee
{
public:
	MultiEmployee(double salary = 0, double commission = 0, double factor = 1.0)
		:_fixed_salary(salary)
		, _commission(commission)
		,_factor(factor)
	{}

	double getSalary()
	{
		return _fixed_salary * _factor + _commission;
	}
private:
	double _fixed_salary;
	double _commission;
	double _factor;
};

int main()
{
	vector<Employee::ptr> emps;
	for (int i = 0; i < 1; ++i)
	{
		Employee::ptr ptr(new FixedSalaryEmployee(2000));
		emps.push_back(ptr);
		Employee::ptr ptr2(new CommissionEmployee(4000));
		emps.push_back(ptr2);
		Employee::ptr ptr3(new MultiEmployee(1000, 1000, 1.1));
		emps.push_back(ptr3);
	}
	for (auto ptr : emps)
	{
		cout << ptr->getSalary()<<endl;
	}
	return 0;
}