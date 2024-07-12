#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

    string compressString(string& S) {
        if (S.size() <= 1) return S;
        string* pret = new string;
        string& ret = (*pret);
        int left = 0, right = 1;
        for (int right = 1; right < S.size(); ++right)
        {
            if (right < S.size() && S[right] == S[left])
            {
                continue;
            }
            ret.push_back(S[left]);
            ret = ret + to_string(right - left);
            left = right;
            if (ret.size() >= S.size()) return S;
        }

        ret.push_back(S[left]);
        ret = ret + to_string(right - left);

        if (S.size() > ret.size())
        {
            return ret;
        }
        else
        {
            return S;
        }
    }
};


int main()
{
    Solution sl;
    string s = "aabcccccaa";
    sl.compressString(s);
    return 0;
}