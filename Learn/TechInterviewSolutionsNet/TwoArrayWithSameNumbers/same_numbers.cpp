#include <iostream>
#include <map>
using namespace std;

bool same_arr(int arr1[], int size1, int arr2[], int size2) {
    if(size1 != size2) {
        return false;
    }

    map<int, int> m;
    for(int i = 0; i < size1; i++) {
        m[arr1[i]]++;
    }

    for(int i = 0; i < size2; i++) {
        if(m[arr2[i]] == 0) {
            return false;
        }
        m[arr2[i]]--;
    }

    for(int i = 0; i < size1; i++) {
        if(m[arr1[i]] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int arr1[] = {4, 3, 5, 2, 7, 6, 1, 9, 8};
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    if(same_arr(arr1, 9, arr2, 9)) {
        cout << "Both array are same" << endl;
    }
    else {
        cout << "Both array are different" << endl;
    }
}
