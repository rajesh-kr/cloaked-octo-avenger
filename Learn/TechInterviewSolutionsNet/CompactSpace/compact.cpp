#include <iostream>
#include <string>
using namespace std;

string compact_string(string s) {
    string c;
    int i = 0;
    while(i < s.length()) {
        if(s[i] == ' ') {
            while(s[i] == ' ') {
                i++;
            }
            if(i != s.length()) {
                c += ' ';
            }
        }
        else {
            c += s[i];
            i++;
        }
    }

    return c;
}

int main() {
    string s = "My name   is        rajesh   ";
    string c = compact_string(s);
    cout << c << "." << endl;
    return 0;
}
