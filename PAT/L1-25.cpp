#include<iostream> 
#include<cstdio>
#include<string>
using namespace std;
int main() {
	string str1, str2;
	cin >> str1;
	cin.get();
	getline(cin, str2);

	bool flag1 = 1, flag2 = 1;
	int len1 = str1.length(), len2 = str2.length();

	if (len1<1 || len1>4) {
		flag1 = 0;
	}
	else {
		for (char i : str1) {
			if (i<'0' || i>'9') {
				flag1 = 0;
				break;
			}
		}
	}
	if (len2<1 || len2>4) {
		flag2 = 0;
	}
	else {
		for (char i : str2) {
			if (i<'0' || i>'9') {
				flag2 = 0;
				break;
			}
		}
	}
	int s1 = 0;
	if (flag1) {
		
		for (char i : str1) {
			s1 = s1 * 10 + (int(i) - int('0'));
		}

		if (s1<1 || s1>1000)
		{
			flag1 = 0;
		}
	}
	int s2 = 0;
	if (flag2) {
		
		for (char i : str2) {
			s2 = s2 * 10 + (int(i) - int('0'));
		}
		if (s2<1 || s2>1000)
		{
			flag2 = 0;
		}
	}
	if (flag1 == 1 && flag2 == 1)
	{
		printf("%d + %d = %d\n", s1, s2, s1 + s2);
	}
	else if (flag1 == 1 && flag2 == 0)
	{
		printf("%d + ? = ?\n", s1);
	}
	else if (flag1 == 0 && flag2 == 1)
	{
		printf("? + %d = ?\n", s2);
	}
	else
	{
		printf("? + ? = ?\n");
	}




	return 0;
}

