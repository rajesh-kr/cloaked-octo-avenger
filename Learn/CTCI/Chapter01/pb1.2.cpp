#include <iostream>
#include <cstring>
using namespace std;

void reverse(char* str) {
    int j = strlen(str) - 1;
    int i = 0;
    while(i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char t[] = "rajesh";
    char u[] = "kumar";
    cout << t << endl;
    cout << u << endl;
    reverse(t);
    reverse(u);
    cout << t << endl;
    cout << u << endl;

    return 0;
}
