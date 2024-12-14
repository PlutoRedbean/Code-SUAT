#include <iostream>
#include "Matrix.h"

using namespace std;

Matrix::Matrix( void ) 
{
    // cout << "Please input matrix numbers";
}

Matrix::Matrix( size_t n, size_t m )
{
    N = n;
    M = m;
    array = new double *[n];
    for (int i = 0; i < n; i++) {
        array[i] = new double [m];
        // for (int j = 0; j < m; j++) {
        //     cin >> array[i][j];
        // }
    }
}

Matrix::Matrix( const Matrix& a ) 
{
    N = a.N;
    M = a.M;
    array = new double *[N];
    for (int i = 0; i < N; i++) {
        array[i] = new double [M];
        // for (int j = 0; j < M; j++) {
        //     cin >> array[i][j];
        // }
    }
}

Matrix::~Matrix() 
{
    for (int i = 0; i < N; i++) {
        delete array[i];
    }
    delete []array;
}

void Matrix::Transpose()
{
    Matrix output(this->M, this->N);
    for (int i = 0; i < this->M; i++) {
        for (int j = 0; j < this->N; j++) {
            output.array[i][j] = this->array[j][i];
        }
    }
    // cout << output;
    for (int i = 0; i < this->N; i++) {
        delete this->array[i];
    }
    delete []this->array;
    
    this->N = output.N;
    this->M = output.M;
    this->array = new double *[this->N];
    for (int i = 0; i < this->N; i++) {
        array[i] = new double [this->M];
    }

    for (int i = 0; i < this->N; i++) {
        for (int j = 0; j < this->M; j++) {
            // cout << i << " " << j << "\n";
            this->array[i][j] = output.array[i][j];
        }
    }
}

Matrix Matrix::Add(const Matrix& b)
{
    Matrix output(this->N, this->M);
    if(this->N != b.N || this->M != b.M) {
        // cout << "返回原矩阵:\n";
        // for (int i = 0; i < this->N; i++) {
        //     for (int j = 0; j < this->M; j++) {
        //         output.array[i][j] = 0;
        //     }
        // }
        for (int i = 0; i < output.N; i++) {
            delete output.array[i];
        }
        delete []output.array;
        output.N = 1;
        output.M = 1;
        output.array = new double *[output.N];
        for (int i = 0; i < output.N; i++) {
            output.array[i] = new double [output.M];
        }
        output.array[0][0] = 0;
    } else if (this->N == b.N && this->M == b.M) {
        // cout << "返回加法矩阵\n";
        for (int i = 0; i < this->N; i++) {
            for (int j = 0; j < this->M; j++) {
                output.array[i][j] = this->array[i][j] + b.array[i][j];
            }
        }
    }
    return output;
}

Matrix Matrix::Multiply(const Matrix& b)
{
    Matrix output(this->N, b.M);
    if(this->N != b.M || this->M != b.N) {
        // cout << "返回原矩阵:\n";
        // for (int i = 0; i < this->N; i++) {
        //     for (int j = 0; j < this->M; j++) {
        //         output.array[i][j] = 0;
        //     }
        // }
        for (int i = 0; i < output.N; i++) { 
            delete output.array[i];
        }
        delete []output.array;
        output.N = 1;
        output.M = 1;
        output.array = new double *[output.N];
        for (int i = 0; i < output.N; i++) {
            output.array[i] = new double [output.M];
        }
        output.array[0][0] = 0;
    } else if (this->N == b.M && this->M == b.N) {
        // cout << "返回乘法矩阵:\n";
        for (int i = 0; i < this->N; i++) {
            for (int j = 0; j < b.M; j++) {
                output.array[i][j] = 0.0;
                for (int j1 = 0; j1 < this->M; j1++) {
                    // cout << this->array[i][j1] << " " << b.array[j1][i] << endl;
                    // cout << i << " " << j << endl;
                    output.array[i][j] += this->array[i][j1] * b.array[j1][j];
                }
            }
        } 
    }
    return output;
}

ostream& operator<<(ostream& os, const Matrix& a)
{
    for (int i = 0; i < a.N; i++) {
        for (int j = 0; j < a.M; j++) {
            os << a.array[i][j] << " ";
        }
        cout << endl;
    }
    return os;
}

istream& operator>>(istream& os, Matrix& a)
{
    cout << "Please input matrix numbers\n";
    for (int i = 0; i < a.N; i++) {
        for (int j = 0; j < a.M; j++) {
            os >> a.array[i][j];
        }
    }
    return os;
}
/*稍微有点屎山，小屎不算屎，算屎丘吧*/