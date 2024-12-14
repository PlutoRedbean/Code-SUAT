#include "Matrix.hpp"

Matrix::Matrix() 
{
    N = 1;
    M = 1;
    array = new double [0];
    array[0] = 0;
}

Matrix::Matrix( size_t n, size_t m )
{
    N = n;
    M = m;
    array = new double [n * m];
}

Matrix::Matrix(const Matrix& a) 
{
    N = a.N;
    M = a.M;
    array = new double [N * M];
    for (int i = 0; i < a.N; i++) {
        for (int j = 0; j < a.M; j++) {
            array[(i * a.M) + j] = a.array[(i * a.M) + j];
        }
    }
}

Matrix::~Matrix()
{
    delete []array;
}

Matrix & Matrix::operator=(const Matrix& a)
{
    if (this->N == a.N && this->M == a.M) {
        for (int i = 0; i < this->N; i++) {
            for (int j = 0; j < this->M; j++) {
                this->array[(i * this->M) + j] = a.array[(i * a.M) + j];    //[(i * this->M) + j] 横:(i*this->M)  纵:j
            }
        }
    } else {
        this->~Matrix();
        this->N = a.N;
        this->M = a.M;
        this->array = new double [a.N * a.M];
        for (int i = 0; i < this->N; i++) {
            for (int j = 0; j < this->M; j++) {
                this->array[(i * this->M) + j] = a.array[(i*a.M) + j];    //[(i * this->M) + j] 横:(i * this->M)  纵:j
            }
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& b)
{
    if (this->N == b.N && this->M == b.M) {
        Matrix result(N, M);
        for (int i = 0; i < this->N; i++) {
            for (int j = 0; j < this->M; j++) {
                result.array[(i * this->M) + j] = this->array[(i * this->M) + j] + b.array[(i * b.M) + j];
            }
        }
        return result;
    } else {
        return Matrix();
    }
}

Matrix Matrix::operator*(const Matrix& b)
{
    Matrix result(this->N, b.M);
    if (this->N != b.M || this->M != b.N) {
        return Matrix();
    }
    for (int i = 0; i < this->N; i++) {
        for (int j = 0; j < b.M; j++) {
            result.array[(i * this->M) + j] = 0.0;
            for (int j1 = 0; j1 < this->M; j1++) {
                result.array[(i * b.M) + j] += this->array[(i * this->M) + j1] * b.array[j + (j1 * b.M)];
            }
        }
    } 
    return result;
}

Matrix & Matrix::operator+=(const Matrix& b)
{
    if (this->N == b.N && this->M == b.M) {
        for (int i = 0; i < this->N; i++) {
            for (int j = 0; j < this->M; j++) {
               this->array[(i * this->M) + j] += b.array[(i * b.M) + j];
            }
        }
    }
    return *this;
}

Matrix & Matrix::operator*=(const Matrix& b)
{
    if (this->N == b.M && this->M == b.N) {
        Matrix result(this->N, b.M);
        for (int i = 0; i < this->N; i++) {
            for (int j = 0; j < b.M; j++) {
                result.array[(i * this->M) + j] = 0.0;
                for (int j1 = 0; j1 < this->M; j1++) {
                    result.array[(i * b.M) + j] += this->array[(i * this->M) + j1] * b.array[j + (j1 * b.M)];
                }
            }
        } 
    }
    
    return *this;
}

Matrix& Matrix::operator++()
{
    for (int i = 0; i < this->N; i++) {
        for (int j = 0; j < this->M; j++) {
            this->array[(i * this->M) + j] += 1;
        }
    }
    return *this;
}

Matrix Matrix::operator++(int)
{
    Matrix copier = *this;
    for (int i = 0; i < this->N; i++) {
        for (int j = 0; j < this->M; j++) {
            this->array[(i * this->M) + j] += 1;
        }
    }
    return copier;
}

bool Matrix::operator==(const Matrix& b)
{
    if (this->N == b.N && this->M == b.M) {
        int check = 0;
        for (int i = 0; i < this->N; i++) {
            for (int j = 0; j < this->M; j++) {
                if(this->array[(i * this->M) + j] == b.array[(i * this->M) + j]) {
                    check++;
                }
            }
        }
        return check == this->N * this->M;
    } else {
        return false;
    }
}

bool Matrix::operator!=(const Matrix& b)
{
    if (this->N == b.N && this->M == b.M) {
        int check = 0;
        for (int i = 0; i < this->N; i++) {
            for (int j = 0; j < this->M; j++) {
                if(this->array[(i * this->M) + j] == b.array[(i * this->M) + j]) {
                    check++;
                }
            }
        }
        return check != this->N * this->M;
    } else {
        return true;
    }
}

ostream& operator<<(ostream& os, const Matrix& a)
{
    for (int i = 0; i < a.N; i++) {
        for (int j = 0; j < a.M; j++) {
            os << a.array[(i * a.M) + j] << " ";
        }
        cout << endl;
    }
    return os;
}

istream& operator>>(istream& os, Matrix& a)
{
    cout << "请输入矩阵中的数字\n";
    for (int i = 0; i < a.N; i++) {
        for (int j = 0; j < a.M; j++) {
            os >> a.array[(i * a.M) + j];
        }
    }
    return os;
}