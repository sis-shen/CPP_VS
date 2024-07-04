//#include <iostream>
//#include <vector>
//#include <string>
//#include <sstream>
//#include <functional>
//#include <algorithm>
//using namespace std;
//
//#define N 10
//
//class Tree
//{
//public:
//    Tree(int n = N)
//    {
//        child_matrix.resize(N);
//        vt.resize(n);
//    }
//
//    void mkchildmatrix()
//    {
//        for (int i = 0; i < vt.size(); i++)
//        {
//            if (vt[i] != -1)
//            {
//                child_matrix[vt[i]].push_back(i);
//            }
//        }
//    }
//
//    int LongestPath()
//    {
//        for (int i = 0; i < vt.size(); i++)
//        {
//            path.push_back(i);
//            if (vt[i] != -1) _dfs(vt[i]);
//            for (auto j : child_matrix[i])
//            {
//                _dfs(j);
//            }
//            path.pop_back();
//        }
//
//        return retpath.size();
//    }
//
//public:
//    vector<int>path;
//    vector<int> retpath;
//    void _dfs(int j)
//    {
//        //走到重复字符
//        if (str[path.back()] == str[j])
//        {
//            if (path.size() > retpath.size())
//            {
//                retpath = path;
//            }
//            return;
//        }
//
//        //走到头
//        if (path.back() == vt[j] && child_matrix[j].size() == 0)
//        {
//            if (str[path.back()] != str[j])
//            {
//                path.push_back(j);
//                if (path.size() > retpath.size())
//                {
//                    retpath = path;
//                }
//                path.pop_back();
//                return;
//            }
//            else
//            {
//                if (path.size() > retpath.size())
//                {
//                    retpath = path;
//                }
//            
//                return;
//            }
//                
//
//        }
//
//        //没走到头
//        int back = path.back();
//        path.push_back(j);
//
//        if (vt[j] != -1 &&  back != vt[j]) _dfs(vt[j]);
//
//        for (auto child : child_matrix[j])
//        {
//            if(back != child)
//                _dfs(child);
//        }
//
//        path.pop_back();
//
//    }
//public:
//    vector<int> vt;
//    vector<vector<int>> child_matrix;
//    string str;
//};
//
//int main()
//{
//    int n = 0;
//    cin >> n;
//    Tree tree(n);
//    for (int i = 0; i < n; i++)
//    {
//        cin >> tree.vt[i];
//    }
//
//    cin >> tree.str;
//    tree.mkchildmatrix();
//    cout << tree.LongestPath();
//
//    return 0;
//}
//
////4 -1 0 0 0 aabc