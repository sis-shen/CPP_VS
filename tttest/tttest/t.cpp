#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    unsigned int obj = 0x0000011f9cd40000;
    int id = (obj >> 13);
    cout << id;
    return 0;
}