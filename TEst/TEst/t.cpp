#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    string str;
    int right = line.size() - 1;
    int left = right - 1;
    while (left >= 0)
    {
        cout << str << endl;
        while (left >= 0 && line[left] != ' ')left--;
        str += line.substr(left+1, right - left);
        str += ' ';
        right = --left;
    }
    str.pop_back();
    cout << str;
}