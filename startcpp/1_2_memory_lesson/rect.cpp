#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	ifstream ifs("input.txt");
	string s;
	vector<string> texts;
	while (getline(ifs, s)) { texts.push_back(s); }
	texts.push_back(string(texts[0].size(), ' '));
	
	int ly = 6, ry = texts.size() - 1, lx = 5, rx = 44; //[l, r]
	for (int i = ly; i <= ry; i++) {
		for (int j = lx; j <= rx; j++) {
			if (i == ly && j == lx) texts[i][j] = '+';
			else if (i == ly && j == rx) texts[i][j] = '+';
			else if (i == ry && j == lx) texts[i][j] = '+';
			else if (i == ry && j == rx) texts[i][j] = '+';
			else if (i == ly) texts[i][j] = '-';
			else if (i == ry) texts[i][j] = '-';
			else if (j == lx) texts[i][j] = '|';
			else if (j == rx) texts[i][j] = '|';
		}
	}

	ofstream ofs("output.txt");
	for (string s: texts) ofs << s << endl;
	return 0;
}