#include <iostream>
#include <cstddef>
#include "Array.h"

using namespace std;

double** arrayMultiply(double **a, int n, int m, double **b, int l, int k)
{
    if (m == l) {
        double **output = new double *[n];
        for (int i = 0; i < n; i++) {
            output[i] = new double[k];
            for (int j = 0; j < k; j++) {
                output[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                for (int p = 0; p < m; p++) {
                    output[i][j] += a[i][p] * b[p][j]; 
                }
            }
            
        }
        
        return output;
    } else {
        return NULL;
    }
}

double** arrayAdd(double **a, int n, int m, double **b, int l, int k) 
{
    if (n == l && m == k) {
        double **output = new double *[n];
        for (int i = 0; i < n; i++) {
            output[i] = new double[k];
            for (int j = 0; j < k; j++) {
                output[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                output[i][j] += a[i][j] + b[i][j];
            }
        }
        return output;
    } else {
        return NULL;
    }
}

double** arrayTranspose(double **a, int n, int m) 
{
    double **output = new double *[m];
    for (int i = 0; i < m; i++) {
        output[i] = new double[n];
        for (int j = 0; j < n; j++) {
            output[i][j] = a[j][i];
        }
    }
    return output;
}