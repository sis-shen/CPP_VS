#include <iostream>
#include <string>


struct Employee
{
	std::string name = "Unkown";
	int id = -1;
	double salary = 0.0;
};

int main()
{
	int raw = 10;
	const int& x = raw;
	//����Ǳ����������ͳ�ʼ��
	int y = x;//�������ڱ�����ʼ��,x �� y�ǲ�ͬ�Ķ���
	//���涼�����õ�����
	int& z = x;//�����ԣ���Ϊz�����ã���xָ����ͬ���Ķ��󣬵�Ȩ�޷Ŵ�
	int* n = &x;//ͬ�������ԣ�����Ȩ�޷Ŵ�
	const int& a = x;//��ء
	const int* m = &x;//��ء


	Employee e1;
	Employee e2 = { "Jongh", 1 , 1.0 };
	Employee e3 = { "Web" };
	return 0;
}