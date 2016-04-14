#include <iostream>
using namespace std;

void intersection(int a[], int size1, int b[], int size2) {
    int i = 0, j = 0;
    while(i < size1 && j < size2) {
        if(a[i] == b[j]) {
            cout << a[i] << " ";
            i++;
            j++;
        }
        else if(a[i] < b[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    cout << endl;
}

int main() {
    int a[] = { 1, 3, 4, 5, 7 };
    int b[] = { 2, 3, 5, 6 };

    intersection(a, 5, b, 4);
    return 0;
}
