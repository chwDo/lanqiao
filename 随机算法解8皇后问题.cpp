//#include <iostream>
//#include <iomanip>
////#include <cstdlib>
//#include <cmath>
//#include <ctime>
//#include <cstring>
//#include <windows.h>
//using namespace std;
//
//const int n = 8;  //�ʺ���
//
//int c[n + 1];
//
//void init()
//{
//	for (int k = 1; k <= n; k++) c[k] = 0;
//}
//
//void show()
//{
//	for (int i = 1; i <= n; i++)
//	{
//		cout << "c[" << setw(2) << i << "]=" << setw(2) << c[i] << "  ";
//		if (i % 5 == 0) cout << endl;
//	}
//	cout << endl;
//}
//
//void display()
//{
//	for (int i = 1; i <= n; i++)
//	{
//		cout << "  ";
//		for (int j = 1; j <= n; j++)
//		{
//			if (j == c[i])cout << "��";
//			else cout << "��";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//
//long start, finish;  //��¼���ݿ�ʼ�ͽ�����ʱ�� 
//
//void killTime(string algorithm)
//{
//	finish = clock();
//	cout << algorithm << " �㷨���� " << n << " �ʺ����⻨�� " << finish - start << "�����룩" << endl << endl;
//	//show();
//	display();
//	exit(0);
//}
//
//bool isValid(int k)
//{
//	for (int i = 1; i<k; i++)
//	{
//		if (c[k] == c[i] || abs(c[k] - c[i]) == k - i) return false;  //�жϻʺ�����Ƿ�Ϸ�
//	}
//	return true;
//}
//
//void queens(int k)
//{
//	for (int column = 1; column <= n; column++)
//	{
//		c[k] = column;
//		if (isValid(k))
//		{
//			if (k == n) killTime("queens"); //    if(k==n) killTime(__FUNCTION__);
//			else queens(k + 1);
//		}
//	}
//}
//
//void randomQueens(int k)
//{
//	for (int column = 1; column <= n; column++)
//	{
//		c[k] = rand() % n + 1;
//		if (isValid(k))
//		{
//			if (k == n) killTime(__FUNCTION__);
//			else randomQueens(k + 1);
//		}
//	}
//}
//
//int v[n + 1] = { 0 };
//
//void queensLV(int k)//�������n���ʺ����˹ά��˹�㷨
//{
//	int count = 0;
//	memset(v, 0, sizeof(v));
//	for (int column = 1; column <= n; column++)
//	{
//		c[k] = column;
//		if (isValid(k)) v[++count] = column;
//	}
//	if (count == 0) queensLV(1);       //�������λ�ò����ڱ�ʾ����ʧ��  ��Ҫ��������� 
//	for (int i = 1; i <= count; i++)
//	{
//		c[k] = v[rand() % count + 1];  //�ӺϷ�λ�������ѡ��һ��λ��,����˳ɹ��ĸ���  ��ʦ��������һ�����Ե�COUNTΪ0��ʱ�򣨿���λ�����ڣ�c[k]�õ���v[1]��ֵ����һ�еĿ���ֵ�ĵ�һ����ѡ�����Գ��ֲ��Ϸ����
//		if (k == n) killTime(__FUNCTION__);
//		 else queensLV(k + 1);
//	}
//}
//
//int main()
//{
//	//srand(time(0));
//	srand((unsigned)time(NULL));   
//	init();
//	start = clock();
//	//queens(1);
//	//randomQueens(1);
//	queensLV(1);
//
//	return 0;
//}
//
#include<iostream> 
#include<cstdio>
#include<cstring>
using namespace std;
int main() {
	string str1, str2;
	cin >> str1;
	cin.get();
	getline(cin, str2);
	cout << str1 << "   " << str2;

	bool flag1 = 1, flag2 = 1;
	int len1 = str1.length(), len2 = str2.length();

	if (len1<1 || len1>4) {
		flag1 = 0;
	}
	else {
		for (char i : str1) {
			if (i<'0' || i>'9') {
				flag1 = 0;
			}
		}
	}
	if (len2<1 || len2>4) {
		flag2 = 0;
	}
	else {
		for (char i : str1) {
			if (i<'0' || i>'9') {
				flag2 = 0;
			}
		}
	}

	if (flag1) {
		int s1 = 0;
		for (char i : str1) {
			s1 = s1 * 10 + int(i);
		}

		if (s1<1 || s1>1000)
		{
			flag1 = 0;
		}
	}
	if (flag2) {
		int s2 = 0;
		for (char i : str1) {
			s2 = s2 * 10 + int(i);
		}
		if (s2<1 || s2>1000)
		{
			flag2 = 0;
		}
	}

	if (flag1 == 1 && flag2 == 1)
	{
		printf("%d + %d = %d\n", sum1, sum2, sum1 + sum2);
	}
	else if (flag1 == 1 && flag2 == 0)
	{
		printf("%d + ? = ?\n", sum1);
	}
	else if (flag1 == 0 && flag2 == 1)
	{
		printf("? + %d = ?\n", sum2);
	}
	else
	{
		printf("? + ? = ?\n");
	}




	return 0;
}