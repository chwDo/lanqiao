#include <iostream>
#include <string>
using namespace std;
/* int Available[3] = {3,3,2};  //可用资源矩阵 
 int Max[5][3] = { { 7, 5, 3 }, { 3, 2, 2 }, { 9, 0, 2 }, { 2, 2, 2 }, {4,3,3} };//最大需求矩阵 
 int ALLocation[5][3] = { {0,1,0}, {2,0,0}, {3,0,2}, {2,1,1}, {0,0,2} };//分配矩阵 
 int Need[5][3] = { {7,4,3}, {1,2,2}, {6,0,0}, {0,1,1}, {4,3,1} };//需求矩阵 
 bool  Finsh[5] = { false, false, false, false,false };  //检测矩阵*/
 int Available[100];//可用资源矩阵 
 int Max[100][100]; //最大需求矩阵 
 int ALLocation[100][100];//分配矩阵 
 int Need[100][100];//需求矩阵 
 bool  Finsh[100];
  int m;      //进程个数 
  int n;      //资源种类数 
 int  F[100],c=0;
 bool test(int k){
    for(int i=0;i<n;i++)
	 {
	 if(Need[k][i]> Available[i])
	 {
       return false;
	 }
 }
     cout<<"P"<<k<<"得到分配资源:"<<endl;
     for(int i=0;i<n;i++)
     {
	  Available[i]-=Need[k][i];    //分配资源  
	  cout<<Need[k][i]<<"  ";    
	  Need[k][i]=0;  //需求矩阵改变 
	  
	  ALLocation[k][i]+=Need[k][i];  //得到资源 
	  
	  Available[i]=Available[i]+Max[k][i]; //释放资源 
	 }
	 cout<<endl;   
	 Finsh[k]=true; //完成标志 
	 F[c++]=k;
	 return true;
 }


bool safe(){
      for(int i=0;i<m;i++)
        if(Finsh[i]==false)  //判断是否已完成 
         {
           if(test(i)==true)  //试分配 
		      i=-1;            //分配完成 从头循环       
		 }
	  for(int i=0;i<m;i++)
	   if(Finsh[i]==false)   //经过遍历后判断是否全部完成 若有不完成的 则返回无安全序列 
	     return false;  
	
	return true;
} 
void input(){
	cout<<"输入进程个数"<<endl;	
	  cin>>m;
	cout<<"输入资源种类数"<<endl;
	  cin>>n;
	cout<<"请输入当前可用资源"<<n<<"个"<<endl;
	for(int i=0;i<n;i++)
	 {
	     cin>>Available[i];
	 }
	 cout<<"请输入需求矩阵"<<m<<"*"<<n<<endl;
	 for(int i=0;i<m;i++)
	 {   
	    for(int j=0;j<n;j++)
	      cin>>Max[i][j];
	 }
	 cout<<"请输入已分配矩阵  "<<m<<"*"<<n<<endl;
	 for(int i=0;i<m;i++)
	 {    Finsh[i]=false;          //检测矩阵初始化 
	    for(int j=0;j<n;j++){
	      cin>>ALLocation[i][j];
	      Need[i][j]=Max[i][j]-ALLocation[i][j];  //需求矩阵初始化 
	   }
	 }
	 
}
int main(){
	input();
   if(safe()){
   	cout<<"存在安全序列"<<endl;
   for(int i=0;i<c;i++)
   cout<<F[i]<<"  ";
     }
    else 
	{
		cout<<"不存在安全序列"<<endl;
	}
   return 0;
}
