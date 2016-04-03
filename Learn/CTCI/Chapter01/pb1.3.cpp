#include <iostream>
#include <string>
using namespace std;

bool is_permutation(string s1, string s2) {
    if(s1.length() != s2.length()) {
        return false;
    }

    int temp[256];
    for(int i = 0; i < 256; i++) {
        temp[i] = 0;
    }

    for(int i = 0; i < s1.length(); i++) {
        if(temp[s1[i]] == 0) {
            temp[s1[i]] = 1;
        }
        else {
            temp[s1[i]]++;
        }
    }

    for(int i = 0; i < s2.length(); i++) {
        if(temp[s2[i]] == 0) {
            return false;
        }
        else {
            temp[s2[i]]--;
        }
    }

    for(int i = 0; i < 256; i++) {
        if(temp[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string s1 = "rajesh";
    string s2 = "jsaehr";
    if(is_permutation(s1, s2)) {
        cout << "s1 and s2 are permutation of each other" << endl;
    }
    else {
        cout << "s1 and s2 are not permutation of each other" << endl;
    }

    string t1 = "rajesh";
    string t2 = "kumar";
    if(is_permutation(t1, t2)) {
        cout << "t1 and t2 are permutation of each other" << endl;
    }
    else {
        cout << "t1 and t2 are not permutation of each other" << endl;
    }

    string u1 = "rajesh";
    string u2 = "kumarj";
    if(is_permutation(u1, u2)) {
        cout << "u1 and u2 are permutation of each other" << endl;
    }
    else {
        cout << "u1 and u2 are not permutation of each other" << endl;
    }

    return 0;
}
