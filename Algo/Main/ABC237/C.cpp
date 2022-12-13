#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int cnt1 = 0, cnt2 = 0;
	bool notA = false;
	for (auto c : s)if (c != 'a')notA = true;
	if (!notA) { cout << "Yes\n" << endl; return 0; }

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a')cnt1++;
		else break;
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == 'a')cnt2++;
		else break;
	}

	if (cnt1 <= cnt2) {
		for (int i = 0; i < cnt2 - cnt1; i++)s.pop_back();
	}
	else {
		cout << "No\n";
		return 0;
	}

	string rev = s;
	reverse(rev.begin(), rev.end());
	if (s == rev)cout << "Yes\n";
	else cout << "No\n";
}