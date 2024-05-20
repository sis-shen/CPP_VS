#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//int main()
//{
//	fstream f;
//	f.open("this,txt",ios::in);///打开当前文件夹的文件
//	f.open("../father.txt",ios::in);//打开父级文件夹的文件
//	f.open("./dir/child.txt",ios::in);//打开子级文件夹的文件(dir是文件夹名称)
//	
//	string str;
//	
//	getline(f,str);
//	cout<<str<<endl;
//	f.close();
//	
//	string s;
//	
//	getline(f,s);
//	cout<<str;
//	f.close();
//	
//	return 0;
//}

int main()
{
	fstream f;
	//f.open("ff.txt",ios::out);
	f.open("ff.txt", ios::binary | ios::out);
	f << "test" << endl;
	f.close();
	
	f.open("ff.txt", ios::binary | ios::in);
	char ch;
	while ((ch = f.get()) != EOF)
	{
		if (ch == '\r')
			cout << "\\r";
		else if (ch == '\n')
			cout << "\\n";
		else
			cout << ch;
	}
	return 0;
}
