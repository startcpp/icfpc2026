#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

int main() {
    int i, j;
    ifstream ifs("input.txt");
    string s;
    vector<string> texts;
    while (ifs >> s) { texts.push_back(s); }

    s = "@";
    for (string text: texts) {
        s += "`" + text + "`s";
    }
    s += "H";

    vector<vector<char>> board(13, vector<char>(s.length() + 2, ' '));
    board[0][0] = '+'; board[0][1] = '-'; board[0][2] = '+';
    board[1][0] = '|'; board[1][1] = 'I'; board[1][2] = '|';
    board[2][0] = '+'; board[2][1] = '-'; board[2][2] = '+';
    board[3][0] = 'v';
    board[4][0] = 'v';
    board[5][0] = '+';
    rep(i, s.length()) board[5][1 + i] = '-';
    board[5][1 + s.length()] = '+';
    
    board[6][0] = '|';
    rep(i, s.length()) board[6][1 + i] = s[i];
    board[6][1 + s.length()] = '|';

    board[7][0] = '+';
    rep(i, s.length()) board[7][1 + i] = '-';
    board[7][1 + s.length()] = '+';
    
    board[8][0] = 'v';
    board[9][0] = 'v';
    
    board[10][0] = '+'; board[10][1] = '-'; board[10][2] = '+';
    board[11][0] = '|'; board[11][1] = 'O'; board[11][2] = '|';
    board[12][0] = '+'; board[12][1] = '-'; board[12][2] = '+';

    rep(i, 13) {
        rep(j, s.length() + 2) {
            cout << board[i][j];
        }
        cout << endl;
    }
    return 0;
}