#include <bits/stdc++.h>
using namespace std;
int main() {
	ifstream fin("try");
	string s;
	string res;
	while (fin >> s) {
		if (s.back() == '+') {
			s.pop_back();
			s.pop_back();
			s.erase(0, 1);
			res += s;
		}
		else if (s.length() > 0 && s[0] == '"') {
			s.pop_back();
			s.erase(0, 1);
			res += s;
		}
	}
	cout << res << endl;
}