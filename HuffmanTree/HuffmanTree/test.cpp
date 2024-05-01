#define  _CRT_SECURE_NO_WARNINGS 1

#include "hefman.h"






class HefmanTreeSystem
{
public:

	//void Run()
	//{
	//	char ch;
	//	while (true)
	//	{
	//		menu();
	//		cin >> ch;
	//		switch (ch)
	//		{
	//		case 'I': Init(); break;
	//		case 'E': Encode(); break;
	//		case 'D': Decode(); break;
	//		case 'P': PrintCode(); break;
	//		case 'T': TreePrint(); break;
	//		default:
	//			cout << "输入非法，请重新输入" << endl << endl;
	//			break;
	//		}
	//	}
	//}

	void TestHefmanTree()
	{
		string str = "abcdef";
		vector<char> ch(str.begin(), str.end());
		vector<int> weigh({ 9,8,7,6,5,4 });
		sup::HefmanTree<char> tmp(ch, weigh);
		sup::HefmanTree<char>ht = tmp;

		ht.print_tree();
		cout << endl;
		ht.print_code_list();

		ht.remake_tree();
		ht.print_tree();
		cout << endl;
		ht.print_code_list();
	}

	void TestInit()
	{
		cout << "TestInit()" << endl;

		Init();

		g_ht.print_code_list();
	}

	void TestReadFile()
	{
		sup::HefmanTree<char> ht;
		ht.read_file("hfmTree.txt");
		ht.print_code_list();
	}

	void TestEncode()
	{
		g_ht.read_file("hfmTree.txt");
		Encode();
	}

	void Init()
	{
		int n = 0;
		cout << "请输入数据量n: " << endl;
		cin >> n;
		vector<int> weighs(n);
		vector<char> str(n);

		cout << "请输入" << n << "个字符(用#表示空格)" << endl;
		for (int i = 0; i < n; i++)
		{
			char ch = 0;
			cin >> ch;
			str[i] = ch;
		}

		cout << "请输入" << n << "个权重" << endl;
		for (int i = 0; i < n; i++)
		{
			int w = 0;
			cin >> w;
			weighs[i] = w;
		}

		sup::HefmanTree<char> ht(str, weighs);
		g_ht = ht;
		ht.whrite_file("hfmTree.txt");

	}

	void Encode()
	{
		fstream f;
		f.open("ToBeTran.txt", ios::in);
		string line;
		string code;
		while (getline(f, line))
		{
			for (auto ch : line)
			{
				if (ch != ' ')
					code += g_ht.get_index(ch);
				else
					code += g_ht.get_index('#');
			}
		}

		f.close();

		f.open("CodeFile.txt", ios::out);
		f << code;
		f.close();
	}


	void menu()
	{
		cout << "=============================";
		cout << "         请输入指令            ";
		cout << "    I.初始化  E.编码  D.译码     ";
		cout << "    P.打印代码  T.打印赫夫曼树     ";
		cout << "=============================";
	}
private:
	sup::HefmanTree<char> g_ht;
};


int main()
{
	HefmanTreeSystem hfsys;
	hfsys.TestReadFile();
	hfsys.TestEncode();
	return 0;
}