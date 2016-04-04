#include <iostream>
#include <string>
using namespace std;

bool isSubstring(string s1, string s2) {
    // TODO
    return true;
}

bool isRotation(string s1, string s2) {
    int l1 = s1.length();
    int l2 = s2.length();

    if(l1 == l2 && l1 > 0) {
        string s1s1 = s1 + s1;
        return isSubstring(s1s1, s2);
    }

    return false;
}

int main() {
    string s1 = "waterbottle";
    string s2 = "erbottlewat";

    if(isRotation(s1, s2)) {
        cout << "TRUE" << endl;
    }
    else {
        cout << "FALSE" << endl;
    }

    return 0;
}
