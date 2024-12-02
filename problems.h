

#include <vector>
using namespace std;

void delete11(std::vector<int>& v) {
    v.erase(std::remove_if(v.begin(), v.end(), [](int x) { return x % 11 == 0; }), v.end());
}

void insertMany(std::vector<int>& v, int y, int x) {
    int middle = (v.size() % 2 == 0) ? v.size() / 2 : (v.size() / 2) + 1;
    v.insert(v.begin() + middle, y, x);
}
int* allocateAndSet(int a, int b) {
    if (a > b) {
        return nullptr;
    }
    int size = b - a + 1;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = a + i;
    }
    return arr;
}
void deallocate(int* arr) {
    delete[] arr;
    arr = nullptr;
}
int* reallocate(int* arr, int N, int n) {
    int newSize = N - n;
    int* newArr = new int[newSize];
    for (int i = 0; i < newSize; i++) {
        newArr[i] = arr[n + i];
    }
    delete[] arr;
    return newArr;
}
int** transposed(int** arr, int n, int m) {
    // Allocate memory for transposed matrix
    int** transposedArr = new int*[m];
    for (int i = 0; i < m; i++) {
        transposedArr[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            transposedArr[j][i] = arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return transposedArr;
}
