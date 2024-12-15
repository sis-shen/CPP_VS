#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>
using namespace std;


class BaseItem
{
public:
	BaseItem(const string& name)
		:_name(name)
	{}

	string GetName()
	{
		return _name;
	}

protected:
	string _name;
};


class Student:public BaseItem
{
public:
	Student(const string& name)
		:BaseItem(name)
	{}

	using ptr = shared_ptr<Student>;

	bool AddCourse(const string& name,double score = 0)
	{
		if (_hash.count(name))
		{
			cout << "添加失败！ ";
			cout << _name << "已存在课程" << name<<endl;
			return false;
		}

		cout << _name << "成功添加课程" << name<<endl;
		_hash[name] = score;
	}

	bool SetCoureScore(const string& name, double score)
	{
		if (!_hash.count(name))
		{
			cout <<_name<<"的" << name << "课程不存在,修改失败" << endl;
			return false;
		}

		cout << _name << "成功修改课程" << name << "分数为" << score;
		_hash[name] = score;
		return true;
	}

	double GetAvg()
	{
		double sum = 0;
		for (auto p : _hash)
		{
			sum += p.second;
		}
		return sum / _hash.size();
	}
	
	double GetScore(const string& name)
	{
		return _hash[name];
	}

private:
	unordered_map<string, int> _hash;
};

class Course:public BaseItem
{
public:
	Course(const string& name)
		:BaseItem(name)
	{}
	using ptr = shared_ptr<Course>;

	double GetAvg()
	{
		double sum = 0;
		for (auto ps : _hash)
		{
			sum += (ps.second)->GetScore(_name);
		}
		return sum / _hash.size();
	}

	bool AddStudent(shared_ptr<Student> pStu)
	{
		string name = pStu->GetName();
		if (_hash.count(name))return false;

		_hash[name] = pStu;
		return true;
	}
private:
	unordered_map<string, shared_ptr<Student>> _hash;
};

class Student_Course_System
{
private:
	typedef Student_Course_System Self;
public:
	using ptr = shared_ptr<Self>;

	void InitForTest()
	{
		cout << "==========自动初始化！！！======" << endl;
		_AddCourse("高等数学A1");
		_AddCourse("高等数学A2");
		_AddCourse("大学物理B");
		_AddCourse("C++程序设计");

		_AddStudent("勇哥");
		_AddStudent("老八");
		_AddStudent("铁蛋");
		_AddStudent("铁柱");

		_StuAddCourse("勇哥", "大学物理B", 100);

		cout << "========================" << endl;
	}


	void _AddStudent(const string& name)
	{
		if (_stus.count(name))
		{
			cout << "添加学生失败，重名学生已存在:" << name << endl;
			return;
		}
		Student::ptr stu = make_shared<Student>(name);
		_stus[name] = stu;
		cout << "添加学生成功：" << name << endl;
	}

	void _AddCourse(const string& name)
	{
		if (_cors.count(name))
		{
			cout << "添加失败，课程已存在：" << name <<endl;
			return;
		}
		Course::ptr course = make_shared<Course>(name);
		_cors[name] = course;
		cout << "添加课程成功: " << name <<endl;
	}
	void _StuAddCourse(const string& stu, const string& course,double score = 0)
	{
		if (!_stus.count(stu))
		{
			cout << "学生不存在！ :" << stu <<endl;
			return;
		}
		if (!_cors.count(course))
		{
			cout << "课程不存在！ ：" << course << endl;
			return;
		}

		_stus[stu]->AddCourse(course, score);
		_cors[course]->AddStudent(_stus[stu]);

		cout << stu << " 添加课程<" << course << ">成功。成绩:" << score << endl;
	}
public:
	void PrintStuAvg(const string& stu)
	{
		if (!_stus.count(stu))
		{
			cout << stu << "不存在！\n";
			return;
		}
		cout << stu<<"的平均成绩是" << (_stus[stu]->GetAvg()) << endl;
	}

	void PrintCourseAvg(const string& course)
	{
		cout << course << "的平均成绩是" << (_cors[course]->GetAvg()) << endl;
	}

	static ptr GetInstance()//实现单例模式
	{
		static ptr pSCS = shared_ptr<Self>(new Self);
		return pSCS;
	}
private:
	Student_Course_System() = default;
	Student_Course_System(const Self&) = delete;
	Self operator=(const Self&) = delete;

	unordered_map<string, shared_ptr<Student>> _stus;
	unordered_map<string, shared_ptr<Course>> _cors;
};

void _TestAdd1(const string& stu,const string& cor,double score)
{
	Student_Course_System::ptr system = Student_Course_System::GetInstance();
	cout << "即将添加 <" << stu << "> <" << cor << "> <" << score <<">" << endl;
	system->_StuAddCourse(stu, cor, score);
	cout << endl;

}

void Test1()
{
	cout << "接下来测试学生添加课程功能" << endl;
	_TestAdd1("勇哥", "高等数学A1", 20);
	_TestAdd1("勇哥", "高等数学A2", 14.5);

	_TestAdd1("老八", "C++程序设计", 200);
	_TestAdd1("老八", "大学物理B", 60);
	_TestAdd1("老八", "高等数学A2", 87.5);

	_TestAdd1("不存在的人", "大学物理B", 10);
	_TestAdd1("勇哥", "不存在的课程", 10);
}

void Test2()
{
	cout << endl;
	cout << "接下来查询勇哥的平均分！" << endl;

	Student_Course_System::ptr system = Student_Course_System::GetInstance();
	system->PrintStuAvg("勇哥");
	cout << endl;
}

void Test3()
{
	cout << endl;
	cout << "接下来查询大学物理B的平均分！" << endl;

	Student_Course_System::ptr system = Student_Course_System::GetInstance();
	system->PrintCourseAvg("大学物理B");
	cout << endl;
}

void Test4()
{
	cout << endl;
	cout << "接下来是动态测试！";

	Student_Course_System::ptr system = Student_Course_System::GetInstance();
	system->_AddCourse("动态课程");

	system->_StuAddCourse("勇哥", "动态课程", 100);
	system->_StuAddCourse("老八", "动态课程", 0);
	cout << "现在查询课程平均分!!" << endl;
	system->PrintCourseAvg("动态课程");

	cout << "即将添加更多学生！！！" << endl;
	getchar();
	system->_StuAddCourse("铁蛋", "动态课程", 80);
	system->_StuAddCourse("铁柱", "动态课程", 70);
	getchar();
	cout << "现在查询课程平均分!!" << endl;
	system->PrintCourseAvg("动态课程");
	getchar();
	
	cout << endl;
	system->_AddStudent("动态人机");
	system->_StuAddCourse("动态人机", "高等数学A1", 100);
	system->_StuAddCourse("动态人机", "高等数学A2", 10);

	cout << "现在查询学生平均分!!" << endl;
	system->PrintStuAvg("动态人机");

	cout << "即将添加更多成绩！！！" << endl;
	getchar();
	system->_StuAddCourse("动态人机", "大学物理B", 50);
	system->_StuAddCourse("动态人机", "动态课程", 30);
	getchar();
	cout << "现在查询学生平均分!!" << endl;
	system->PrintStuAvg("动态课程");

}

int main()
{
	Student_Course_System::ptr system = Student_Course_System::GetInstance();

	system->InitForTest();

	getchar();

	Test1();

	getchar();
	Test2();

	getchar();

	Test3();
	getchar();

	Test4();
	getchar();

	return 0;
}