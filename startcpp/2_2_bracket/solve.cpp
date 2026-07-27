#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int i;
	stack<int> stk;
	for (i = 0; i < n; i++) {
		int c;
		cin >> c;
		if (c == '(' || c == '[' || c == '{') { //40, 91, 123
			stk.push(c);
		}
		else {
			// 閉じカッコ - 開きカッコ のASCIIコードは1または2
			if (stk.empty() || (c - stk.top()) / 3 != 0) {
				cout << i + 1 << endl;
				return 0;
			}
			stk.pop();
		}
	}

	if (stk.empty()) cout << 0 << endl;
	else cout << n + 1 << endl;
	return 0;
}