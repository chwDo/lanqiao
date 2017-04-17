//#include <iostream>
//#include <string>
//using namespace std;
//int str[20];
//int matrix[20][6];
//int sub(int begin,int end){
//	int sum = 0;
//	for (int i = begin; i <= end; i++){
//		sum = sum * 10 + str[i];
//	}
//	return sum;
//}
//
//int DP(int n,int k){
//	
//	if (k == 0){	
//		return sub(1,n);
//	}
//	if (n == k + 1){
//		int sum = 1;
//		for (int i = 1; i <= n; i++){
//			sum *= str[i];
//		}
//		return sum;
//	}
//
//	int max=0,temp;
//	for (int i = k; i < n ; i++){
//
//		temp = DP(i, k-1)*(sub(i+1, n));
//		max < temp ? max = temp : max;
//
//	}
//
//	return max;
//	
//}
//int main(){
//	string s;
//	cin >> s;
//	cout << s;
//	for (int i = 0; i < s.length(); i++){
//		str[i+1] = (int)s[i]-'0';
//	}
//	int K;
//	cin >> K;
//	cout << DP(s.length(), K);
//
//
//	 return 0;
//}