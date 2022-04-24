//
//  main.cpp
//  DemoTest
//
//  Created by 李敬琪 on 2017/3/25.
//  Copyright © 2017年 ls. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
template<class T> class mat
{
public:
    mat()  // 默认构造
    {
        setDim(1, 1);
    }

    mat(unsigned row, unsigned cow) // 指定行列构造
    {
        setDim(row, cow);
    }

    mat(vector<T>&r)  // 由vector作为行向量构造矩阵
    {
        setDim(r.size(), 1);
        elem[0] = r;
    }

    ~mat()
    {
        for (unsigned i = 0; i < elem.size(); i++)
        {
            elem[i].clear();
            elem[i].shrink_to_fit();
        }
        elem.clear();
        elem.shrink_to_fit();
    }

    void setDim(unsigned row,unsigned cow)
    {
        elem.resize(row);
        for (unsigned i = 0; i < row; i++)
        {
            elem[i].resize(cow);
        }
    }

    const vector<double>& operator[](unsigned row) const
    {
        return elem[row];
    }

    vector<double>& operator[](unsigned row)
    {
        return elem[row];
    }

    unsigned getRow() const   // 行数
    {
        return elem.size();
    }

    unsigned getCow() const  // 列数
    {
        return getRow() ? elem[0].size() : 0;
    }

    mat<T> getRowMat(unsigned r)  const // 取第r行向量
    {
        mat<T> R(1, getCow());
        for (unsigned i = 0; i < getCow(); i++)
        {
            R[0][i]=elem[r - 1][i];
        }
        return R;
    }

    mat<T> getCowMat(unsigned c)  const // 取第c列向量
    {
        mat<T> C(getRow(), 1);
        for (unsigned i = 0; i < getRow(); i++)
        {
            C[i][0]=elem[i][c - 1];
        }
        return C;
    }

    void   showMatrix() {
        for (unsigned i = 0; i < elem.size(); i++)
        {
            for (unsigned j = 0; j < elem[i].size(); j++)
            {
                cout << elem[i][j] << " ";
            }
            cout << endl;
        }

    }

    friend mat<T>  operator+(const mat<T>&A, const mat< T>&B)     // 矩阵加法
    {
        mat<T> C(A.getRow(),A.getCow());
        
        for (unsigned i = 0; i < C.getRow(); i++)
        {
            for (unsigned j = 0; j < C.getCow(); j++)
            {
                C[i][j]=A[i][j] + B[i][j];
            }
        }
        return C;
    }

    friend mat<T>  operator-(const mat<T>&A, const mat< T>&B)     // 矩阵减法
    {
        mat<T> C(A.getRow(), A.getCow());
        
        for (unsigned i = 0; i <C.getRow(); i++)
        {
            for (unsigned j = 0; j < C.getCow(); j++)
            {
                C[i][j] = A[i][j] - B[i][j];
            }
        }
        return C;
    }

    friend mat<T>  operator*(const mat<T>&A, const mat< T>&B)   // 矩阵乘法
    {
        unsigned i, j, k;
        mat<T> C(A.getRow(), B.getCow());
        for (i = 0; i <A.getRow(); i++)
        {
            for (j = 0; j < B.getCow(); j++)
            {
                for (k = 0; k < A.getCow(); k++)
                {
                    C[i][j]+=A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }

    friend mat<T>  operator*(const T& e,const mat<T>&A)     // 矩阵数乘
    {
        mat<T> C(A.getRow(), A.getCow());
        
        for (unsigned i = 0; i < C.getRow(); i++)
        {
            for (unsigned j = 0; j < C.getCow(); j++)
            {
                C[i][j] = A[i][j]*e;
            }
        }
        return C;
    }

    friend mat<T>  operator/(const mat<T>&A,const T& e)     // 矩阵除以一个数
    {
        mat<T> C(A.getRow(), A.getCow());
        
        for (unsigned i = 0; i < C.getRow(); i++)
        {
            for (unsigned j = 0; j < C.getCow(); j++)
            {
                C[i][j]= A[i][j]/e;
            }
        }
        return C;
    }

    bool isSquare() const  // 判断是否为方阵
    {
        return getRow() == getCow();
    }

private:
    vector<vector <T>> elem;
};


int main(int argc, const char * argv[]) {
    mat<double> A(4,4),B(4,4);

    cout << "为矩阵A赋值" << endl;

    for ( unsigned i = 0; i < A.getRow(); i++)
    {
        for ( unsigned j = 0; j<A.getCow() ;j++) {
            A[i][j] = i+j;
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "为矩阵B赋值" << endl;

    for (unsigned i = 0; i < B.getRow();i++)
    {
        for (unsigned j = 0; j < B.getCow();j++)
        {
            B[i][j] = i+j;
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;

    mat<double> C(4,4);
    C = A*B;
    C.showMatrix();

}
