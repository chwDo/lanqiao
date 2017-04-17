#include<iostream>
#include<algorithm> 
using namespace std;
int main(){
long long a[31][31]={0};
long long b;

for(int i=1;i<=29;i++){
	for(int j=1;j<=i;j++){
		cin>>b;
		a[i][j]=b*(1<<29)+a[i-1][j-1]/2+a[i-1][j]/2;
		
	}
	
}	
for(int i=1;i<=30;i++){
	a[30][i]=a[29][i-1]/2+a[29][i]/2;

}	
	sort(a[30],a[30]+31);
	cout<<a[30][30]<<endl;
	
	
}
