#include <map>
#include <string>
#include <iostream>
using namespace std;

bool unique_string(string s) {
    map<char, int> temp;

    for(int i = 0; i < s.length(); i++) {
        if(temp[s[i]] != 0) {
            return false;
        }
        else {
            temp[s[i]]++;
        }
    }

    return true;
}

int main() {
    string s1 = "array";
    string s2 = "uniqestrg";

    cout << s1 << " : " << unique_string(s1) << endl;
    cout << s2 << " : " << unique_string(s2) << endl;

    return 0;
}
