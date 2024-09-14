#include <iostream>
#include <string>

using namespace std;

class Course
{
public:
	Course(const string& name,int credit = 0,int id = -1,double score = 0)
		:_name(name), _credit(credit), _id(id), _score(score)
	{}

	void Set(const string& name, int credit = 0, int id = -1, double score = 0)
	{
		_name = name;
		_credit = credit;
		_id = id;
		_score = score;
	}
	void Info()
	{
		printf("课程名:%s ,课程号:%d ,学分:%d ,分数:%lf\n", _name.c_str(), _credit, _id, _score);
	}

	void ShowName()
	{
		cout << "课程名:" << _name << endl;
	}

	void ShowCredit()
	{
		cout << "学分：" << _credit << endl;
	}

	void ShowID()
	{
		cout << "课程ID" << _id << endl;
	}

	void ShowScore()
	{
		cout << "分数" << _score << endl;
	}

private:
	string _name;
	int _credit;//学分
	int _id;//课程号
	double _score;//分数
};



int main()
{
	Course CPP("C++程序设计", 3, 1, 99.8);
	CPP.ShowName();
	CPP.Info();
	CPP.Set("C++面向对象", 6, 11, 250);
	CPP.Info();
	return 0;
}