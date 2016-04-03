#include <iostream>
#include <cstring>
using namespace std;

void increase_string(char* s, int i, int n) {
    for(int j = n-3; j >= i; j--) {
        s[j+2] = s[j];
    }
}

void replace_space(char* s, int n) {
    for(int i = 0; i < n; i++) {
        if(s[i] == ' ') {
            n += 2;
            increase_string(s, i+1, n);
            s[i++] = '%';
            s[i++] = '2';
            s[i] = '0';
        }
    }
}

int main() {
    char s1[] = "Mr John Smith          ";
    int n = 13;
    replace_space(s1, n);
    cout << s1 << "." << endl;
    return 0;
}
