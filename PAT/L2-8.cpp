#include <iostream>
#include <set>
#include<string>
#include<vector>
#include<cstdio>
#include<map>
#include<algorithm>
#include <string>
#include <iterator>  
using namespace std;
set<string>  s_at;
map<string, int> m;
set<string> s_care;
int main() {
	int N;
	cin >> N;
	string s;
	while (N--) {
		cin >> s;
		s_at.insert(s);
	}
	cin >> N;
	int n;
	double sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> s;
		cin >> n;
		sum += n;
		s_care.insert(s);
		m.insert(make_pair(s,n));
	}
	sum /= N;
	set<string> diffen;
	set_difference(
		s_care.begin(), s_care.end(),
		s_at.begin(),s_at.end(),
		insert_iterator<set<string>>(diffen, diffen.begin()));
	s_care.clear();
	for (string i : diffen) {
		if (m[i] > sum) {
			s_care.insert(i);
		}
	}
	if (!s_care.empty()){
		for (string i : s_care) {
			cout << i << endl;
		}
	}
	else cout << "Bing Mei You";
	return 0;
}
