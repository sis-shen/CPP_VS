#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    x *= 2;
    vector<int> arr(n);
    int left = 0, right = 0;
    int sum = 0;
    n--;
    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    while (left < n)
    {
        while (right < n && sum < x)
        {
            sum += right;
            right++;
        }
        ret = max(ret, right - left);
        sum -= arr[left];
        left++;
    }
    ret = max(ret, right - left);

    cout << ret << endl;


    return 0;
}