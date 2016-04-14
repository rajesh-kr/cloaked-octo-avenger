#include <iostream>
#include <map>
#include <string>
using namespace std;

void print_merged(string arr1[], int size1, string arr2[], int size2) {
    map<string, int> m;

    for(int i = 0; i < size1; i++) {
        m[arr1[i]] = 1;
    }

    for(int i = 0; i < size2; i++) {
        m[arr2[i]] = 1;
    }

    for(map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << endl;
    }
}

int main() {
    string arr1[] = {"are", "you", "there"};
    string arr2[] = {"how", "are", "you"};

    print_merged(arr1, 3, arr2, 3);

    return 0;
}
