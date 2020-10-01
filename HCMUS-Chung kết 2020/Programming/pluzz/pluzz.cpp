#include <bits/stdc++.h>

using namespace std;
int val(char x) {
	x=toupper(x);
	if (x=='A') return 10;
	if (x=='B') return 11;
	if (x=='C') return 12;
	if (x=='D') return 13;
	if (x=='E') return 14;
	if (x=='F') return 15;
	return x-'0';
}
int main() {
	ifstream f1("a");
	ifstream f2("b");
	int n=33;
	while (n--) {
		string s,t; f1>>s; f2>>t;
		int val0;
		if (s.length()==4)
			val0=val(s[2])*16+val(s[3]),
		else val0=val(s[2]);
		int val1;
		if (t.length()==4)
			val1=val(t[2])*16+val(t[3]);
		else val1=val(t[2]);
		cout<<char(val0+val1);
	}
}