#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, l, r;
    string str;
    cin >> n >> l >> r >> str;

    int left = 0; int right = 0;
    vector<int> hash(256, 0);
    int cnt = 0, sumr = 0;
    while (right < n)
    {
        char ch = str[right++];
        if (hash[ch] == 0) cnt++;
        hash[ch]++;
        while (cnt > r)
        {
            char ch = str[left++];
            hash[ch]--;
            if (hash[ch] == 0)cnt--;
        }

        sumr += right - left;
    }
    left = 0;
    right = 0;
    cnt = 0;
    int suml = 0;
    hash = vector<int>(256, 0);
    while (right < n)
    {
        char ch = str[right++];
        if (hash[ch] == 0) cnt++;
        hash[ch]++;
        while (cnt > l - 1)
        {
            char ch = str[left++];
            hash[ch]--;
            if (hash[ch] == 0)cnt--;
        }

        suml += right - left;

    }

    cout << sumr - suml;

    return 0;
}