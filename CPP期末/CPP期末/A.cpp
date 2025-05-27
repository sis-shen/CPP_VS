#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    vector<vector<int>> mat;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        mat.resize(rows, vector<int>(cols, 0));
    }
    
    Matrix(const Matrix& m) :mat(m.mat), rows(m.rows), cols(m.cols) {}
    
    Matrix(const vector<vector<int>>& mat_):mat(mat_)
    {
        rows =mat_.size();
        cols = mat_[0].size();
    }

    void setMatrix() {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                cin >> mat[i][j];
    }

    void printMatrix() const {
        for (const auto& row : mat) {
            for (int elem : row)
                cout << elem << " ";
            cout << endl;
        }
    }


    Matrix operator*(const Matrix& n) const
    {
        int r = rows;
        int c = n.cols;
        if (cols != n.rows)
        {
            throw invalid_argument("非法计算");
        }
        vector<vector<int>> ret(vector<vector<int>>(r, vector<int>(c, 0)));

        for (int i = 0; i < r;++i)
        {
            for (int j = 0; j < c; ++j)
            {
                for (int k = 0; k < c;++k)
                {
                    ret[i][j] += mat[i][k] * n.mat[k][j];
                }
            }
        }
        return Matrix(ret);
    }
};

// 请把下面的所有代码复制到你的开发环境中，按照上面的要求填充所需要的代码，然后提交代码进行测试。（注意：main函数中的内容是不能修改的，违者0分）

// 下面的main函数代码【不能修改；一旦改动，本题0分】。
int main() {
    int rowsA, colsA, rowsB, colsB;
    cin >> rowsA >> colsA;
    Matrix A(rowsA, colsA);
    A.setMatrix();


    cin >> rowsB >> colsB;
    Matrix B(rowsB, colsB);
    B.setMatrix();

    try {
        cout << "Result of A * B:" << endl;
        Matrix result = A * B;
        result.printMatrix();
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    return 0;
}