#include <iostream>
#include <string>
using namespace std;

const int N = 4;
const string dictionary[] = {"GIT", "TEST", "RAJESH", "COMPANY", "MAPS"};
char boggle[N][N] = {
                        {'S', 'H', 'I', 'Y'},
                        {'E', 'T', 'N', 'G'},
                        {'J', 'A', 'P', 'S'},
                        {'R', 'M', 'O', 'C'}
                    };
int n = sizeof(dictionary) / sizeof(dictionary[0]);

bool isWord(string str) {
    // simple now
    // iterate over all the words of dictionary
    for(int i = 0; i < n; i++) {
        if(str.compare(dictionary[i]) == 0) {
            return true;
        }
    }
    return false;
}

void findWordsUtil(int i, int j, bool visited[N][N], string& str) {
    // mark the current node visited, and append to string
    visited[i][j] = true;
    str = str + boggle[i][j];

    // check if this word exist in dictionary
    if(isWord(str)) {
        cout << str << endl;
    }

    // now, find for every adjacent letter
    for(int row = i-1; row <= i+1 && row < N; row++) {
        for(int col = j-1; col <= j+1 && col < N; col++) {
            if(row >= 0 && col >= 0 && visited[row][col] == false) {
                findWordsUtil(row, col, visited, str);
            }
        }
    }

    visited[i][j] = false;
    str.erase(str.length() - 1);
}

void findWords() {
    // creating a visited array to keep track of which nodes are already processed
    bool visited[N][N];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }

    // to store the string upto current position
    string str = "";

    // now use dfs to find word from every position in boggle matrix
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            findWordsUtil(i, j, visited, str);
        }
    }
}

int main() {
    cout << "Boggle :" << endl;
    findWords();

    return 0;
}
