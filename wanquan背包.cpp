#include<iostream>
#include<algorithm>
#include<iomanip> 
using namespace std;
 int f[100][100];
 int X[10]={0};
 int weight[10]={0,5,2,3,4,0,0,0,0,0};
 int value[10]={0,5,6,7,8,0,0,0,0,0};

int main()
{   
	int N=4,M;
	cout<<"输入背包容量\n";
	cin>>M;//背包容量

	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++)
		{
			if (weight[i]<=j)
			{
				f[i][j]=max(f[i-1][j],f[i][j-weight[i]]+value[i]);
			}
			else
				f[i][j]=f[i-1][j];
		}
	
	cout<<"最大价值是 ： "<<f[N][M]<<endl;
		for (int i=1; i<=N; i++){	
		for (int j=1; j<=M; j++)
		{
			cout<<setw(3)<<f[i][j]<<"  ";
		}
		cout<<endl;
	}	
	while(N>0&&M>0){
		
		if(f[N][M]!=f[N][M-weight[N]]+value[N])
		{
			N--;
		}
		else
		{   
			X[N]++;
			M-=weight[N];
		}
	}
    for(int i=1;i<5;i++){
    	cout<<X[i]<<" ";
	}
}
