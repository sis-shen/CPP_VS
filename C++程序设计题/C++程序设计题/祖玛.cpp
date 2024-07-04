#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
class GameState
{
public:
	GameState(string _board,string str) :ret(0),hash(256,0),board(_board)
	{
		for (auto e : str)hash[e]++;
	}

	int cnt()
	{
		return _dfs(0,board.size()-1);
	}

	int _dfs(int left, int right)
	{
		int ch = board[left], n = 0;
		int l = left, r = right;
		while (board[l] == ch)
		{
			n++;
			l++;
		}
		while (board[r] == ch)
		{
			n++;
			r--;
			if (l == r)//到中间
			{
				if (n + hash[ch] < 3 ) return -1;
				else
				{
					hash[ch] -= (3 - n);
					return 3 - n;
				}
				
			}
		}

		//没到中间

		int lll = _dfs(l, r);
		if (lll == -1) return -1;

		if (n + hash[ch] < 3) return -1;
		else
		{
			hash[ch] -= (3 - n);
			return lll + 3 - n;
		}
		
	}

	int ret;

public:
	vector<int> hash;
	string board;
};

int main()
{

	
	string str1, str2;
	cin >> str1, str2;

	GameState g(str1, str2);

	cout << g.cnt();

	return 0;
}