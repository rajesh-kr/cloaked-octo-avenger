#include <iostream>
using namespace std;

int find_index(int arr[], int number, int start, int end) {
    // error check
    if(start > end) {
        return -1;
    }

    // check if mid is equal to given number
    int mid = (start + end) / 2;
    if(number == arr[mid]) {
        return mid;
    }

    // if first half is not rotated
    if(arr[start] < arr[mid]) {
        // if first half is sorted, and key is in range, we can do binary search
        if(number >= arr[start] && number < arr[mid]) {
            return find_index(arr, number, start, mid - 1);
        }
        //else, find in the second half
        return find_index(arr, number, mid + 1, end);
    }

    // first half is not sorted, means second half is
    // check the number in sorted half 
    if(number > arr[mid] && number <= arr[end]) {
        return find_index(arr, number, mid + 1, end);
    }
    return find_index(arr, number, start, mid - 1);
}

int main() {
    int arr[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int t = 6;

    int index = find_index(arr, t, 0, size - 1);

    if(index == -1) {
        cout << "Element not found" << endl;
    }
    else {
        cout << "Index of " << t << " is " << index << endl;
    }

    return 0;
}
