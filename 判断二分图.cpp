#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;
int par[5]={0,1,2,3,4};
int main()
{
	int a[5][5];
	for(int i=0;i<5;i++)
     for(int j=0;j<5;j++){
     	cin>>a[i][j];
     	if(j>i&&a[i][j]!=0){    	
	     	 if(par[i]==i&&par[j]==j){     //没有加入集合的点  
	     	 	par[i]=-1;
	     	 	par[j]=-2;
	     	 }
	     	 else if(par[i]!=i&&par[j]==j) //i加入过入集合的点 
                  if(par[i]==-1) par[j]=-2;
                    else par[j]=-1;
	     	 }
	     	 else if(par[i]==i&&par[j]!=j){  //j加入过集合的点 
	     	 	  if(par[j]==-1) par[i]=-2;
                    else par[i]=-1;
	     	 }
	    }
			   
		  for(int i=0;i<5;i++)
	       for(int j=0;j<5;j++){
	       		if(j>i&&a[i][j]!=0){
				      if(par[i]==par[j]){
				      	 cout<<"no";
				      	 return 0;
				      } 
				   } 
     	}
    cout<<"yeas";
  return 0;
}

