
#include "vector"
using namespace std;

void delete11 ( vector < int > & v ) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] % 11 == 0) {
            v.erase(v.begin() + i);
            i--;
        }
    }
}

void insertMany ( vector < int > &v , int a , int b ) {
    for (int i = 0; i < a; i++) {
        int middle {};
        if (v.size() % 2 == 0) {
            middle = v.size() / 2;
        }
        else {
            middle = v.size() / 2 + 1;
        }
        v.insert(v.begin() + middle, b);
    }
}

int* allocateAndSet(int a, int b) {
    if (a >= b) {
        return nullptr;
    }

    const int size = b - a+1;
    int *arr= new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = a+i;
    }

    return arr;
}

void deallocate(int* &arr) {
    delete[] arr;
    arr = nullptr;
}


int *reallocate(int *arr, int N, int n) {
    int size = N - n;
    int *newArr = new int[size];
    int index = 0;

    for (int i = n; i < N; i++) {
        newArr[index] = arr[i];
        index++;
    }

    delete[] arr;

    return newArr;
}

int **transposed(int **arr, int n, int m) {
    int **newArr = new int*[m];
    for (int i = 0; i < m; i++) {
        newArr[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            newArr[j][i] = arr[i][j];
        }
    }
    return newArr;
}
void deallocateMatrix(int**& matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}
