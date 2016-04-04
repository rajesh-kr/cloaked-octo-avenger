#include <iostream>
using namespace std;
const int M = 5;
const int N = 6;

void set_zero(int arr[M][N]) {
    bool row[M];
    bool col[N];
    int i, j;
    // initially set all values to false
    for(i = 0; i < M; i++) {
        row[i] = false;
    }
    for(i = 0; i < N; i++) {
        col[i] = false;
    }

    // traverse the 2-d array to find the location of zero
    for(i = 0; i < M; i++) {
        for(j = 0; j < N; j++) {
            if(arr[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    // set corresponding rows to zero
    for(i = 0; i < M; i++) {
        if(row[i]) {
            for(j = 0; j < N; j++) {
                arr[i][j] = 0;
            }
        }
    }

    // set corresponding cols to zero
    for(i = 0; i < N; i++) {
        if(col[i]) {
            for(j = 0; j < M; j++) {
                arr[j][i] = 0;
            }
        }
    }
}

int main() {
    int arr[M][N] = {
                        {1, 2, 3, 0, 5, 0},
                        {3, 0, 2, 1, 4, 1},
                        {3, 1, 5, 1, 2, 3},
                        {2, 5, 0, 2, 9, 2},
                        {1, 2, 8, 0, 3, 1}
                    };

    set_zero(arr);
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
