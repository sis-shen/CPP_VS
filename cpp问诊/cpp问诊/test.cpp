#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int base = 233;

int mol1 = 19260817;
int mol2 = 19660813;

int hash1(const string& str)
{
	int ans = 0;
	for (auto e : str)
	{
		ans = ans * base + e;
		ans %= mol1;
	}
	return ans;
}

int hash2(const string& str)
{
	int ans = 0;
	for (auto e : str)
	{
		ans = ans * base + e;
		ans %= mol2;
	}
	return ans;
}

struct hash_value
{
	int v1;
	int v2;

	bool operator<(const hash_value& hv2) const
	{
		if (v1 != hv2.v1)
		{
			return v1 < hv2.v1;
		}
		else
		{
			return v2 < hv2.v2;
		}
	}

	bool operator==(const hash_value& hv2) const
	{
		return v1 == hv2.v1 and v2 == hv2.v2;
	}
};

bool comp(const hash_value& hv1, const hash_value& hv2)
{
	return hv1 < hv2;
}

int main()
{
	vector<hash_value> arr;
	int n = 0;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;

		arr[i].v1 = hash1(tmp);
		arr[i].v2 = hash2(tmp);
	}

	sort(arr.begin(), arr.end(), comp);

	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i - 1] == arr[i])
		{
			n--;
		}
	}

	cout << n;
	return 0;
}