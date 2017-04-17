#include <iostream>
#include <set>
#include<string>
#include<vector>
#include<cstdio>
#include<map>
#include<algorithm>
#include <string>
#include <iterator>
#include<functional>
using namespace std;
struct people
{
	int count;
	double income;
	int Index;
	people() {
		count = 0;
		income = 0;
	}
	bool operator < (const people&T)const {
		if (T.income > income) return true;
		else if (T.income==T.income && T.count > count) return true;
		else if (T.income == T.income && T.count == T.count &&T.Index < Index) return true;

		return false;

	}
	friend ostream & operator <<(ostream &cout,people&T) {
		cout << T.Index << " " << T.income << " " << T.count << endl;
		return cout;
	}
};
vector<people> p;
int main(){
	int N;
	cin >> N;
	p.resize(N);
	int n;
	int num,value;
	for (int i = 0; i < N; i++) {
		cin >> n;
		while (n--){
			cin >> num;
			cin >> value;
			p[i].income -=value/100.0;
			p[num-1].income += value/100.0;
			p[num - 1].count++;
			p[i].Index = i+1;
		}
	}
	multiset<people> s;
	copy(p.begin(), p.end(), s.begin());
	for (multiset<people>::iterator it = s.begin(); it != s.end();it++) {
		cout << it->Index<<" "<<it->income<<endl;
	}
	return 0;
}
