#include <iostream>
using namespace std;

int non_repeating(int arr[], int size) {
    int soln = 0;

    for(int i = 0; i < size; i++) {
        soln ^= arr[i];
    }

    return soln;
}

int main() {
    int arr[] = { 3, 4, 1, 3, 1, 7, 2, 2, 4 };
    int n = non_repeating(arr, 9);
    cout << "Non repeating no. : " << n << endl;
    return 0;
}
