#include <iostream>
using namespace std;
const int n = 4;
// const int n = 5;

void rotate90(int img[n][n], int N) {
    int i, j, k, temp;
    for(i = 0, j = N; i < j; i++, j--) {
        for(k = i; k < j; k++) {
            temp = img[i][k];
            img[i][k] = img[N-k][i];
            img[N-k][i] = img[N-i][N-k];
            img[N-i][N-k] = img[k][N-i];
            img[k][N-i] = temp;
        }
    }
}

int main() {
    int img[n][n] = {
                        {1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 16}
                    };
/*
    int img[n][n] = {
                        {1, 2, 3, 4, 5},
                        {6, 7, 8, 9, 10},
                        {11, 12, 13, 14, 15},
                        {16, 17, 18, 19, 20},
                        {21, 22, 23, 24, 25}
                    };
*/

    rotate90(img, n-1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << img[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
