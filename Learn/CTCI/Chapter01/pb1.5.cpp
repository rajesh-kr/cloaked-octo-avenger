#include <iostream>
#include <string>
using namespace std;

string compress_string(string s) {
    int i = 0;
    string soln = "";

    // iterate over the complete string
    while(i < s.length()) {
        // use k to store the length of current character
        int k = 1;
        char c = s[i];
        i++;

        // check if next character is equal to present
        while(s[i] == c) {
            i++;
            k++;
        }

        // add the compressed part
        soln = soln + c + to_string(k);

        // check if length of compressed is greater than original
        if(soln.length() > s.length()) {
            return s;
        }
    }

    // check if length of compressed is greater than original
    if(soln.length() > s.length()) {
        return s;
    }

    return soln;
}

int main() {
    string s = "aabcccccaaa";
    cout << "Before compression : " << s << endl;
    cout << "After compression : " << compress_string(s) << endl;

    return 0;
}
