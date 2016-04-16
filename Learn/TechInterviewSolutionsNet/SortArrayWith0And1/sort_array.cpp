#include <iostream>
using namespace std;

void swap(int arr[], int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void sort_array(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while(start <= end) {
        while(arr[start] == 0) {
            start++;
        }
        while(arr[end] == 1) {
            end--;
        }

        if(start <= end) {
            swap(arr, start, end);
        }
    }
}

int main() {
    int arr[] = {1, 0, 0, 0, 1, 1, 0, 1, 0, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    sort_array(arr, size);
    for(int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
