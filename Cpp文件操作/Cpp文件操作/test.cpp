#include <iostream>
#include <fstream>

using namespace std;

//int main()
//{
//	fstream f;
//	f.open("file.txt", ios::out);//以out模式打开file.txt
//	string str = "This is a sentence";//在内存中准备一段字符串
//	f << str;//将字符串从内存写入文件
//	f.close();//关闭文件流
//
//	//f对象可以复用
//	f.open("file.txt", ios::in);//以in模式打开file.txt
//	string content;//声明变量
//	f >> content;//从文件流读取数据写入变量(内存)
//	cout << content;//打印出来看一眼
//	f.close();
//
//	return 0;
//}



//int main()
//{
//	fstream f;
//	f.open("nofile", ios::in);
//
//
//	return 0;
//}

//int main()
//{
//	fstream f;
//	string s1 = "123456789";
//	string s2 = "1234";
//	string tmp;
//
//	f.open("f1.txt", ios::out);
//	f << s1;
//	f.close();
//
//	f.open("f1.txt", ios::out);
//
//	
//
//	f.open("f1.txt", ios::out);
//	f << s2;
//	f.close();
//
//	return 0;
//}

//int main()
//{
//	fstream f;
//	f.open("ff.txt", ios::out);
//	f << "LongWord";//准备一个有内容的原文件
//	f.close();
//
//	f.open("ff.txt", ios::in | ios::out);
//	f << "1234";//写入1234
//	f.close();
//	//最后ff.txt的内容为"1234Word",不完全覆盖
//	return 0;
//}

//
//int main()
//{
//	fstream f;
//
//	f.open("file.txt",ios::out);
//	f << "111";//准备一个内容为111的文件
//	f.close();
//	f.open("file.txt", ios::app);
//	f << "222";//111后面追加222
//	f.close();
//	//文件内容为111222
//	return 0;
//}

//int main()
//{
//	fstream f;
//	f.open("f1.txt", ios::trunc | ios::out);
//	f.close();
//"
//	return 0;
//}

int main()
{
	fstream f;
	f.open("ff.txt", ios::binary);
	f << 123 ;
	f.close();
	return 0;
}