#include<iostream>
using namespace std;
int Tree[999];
int flag=1;
void FindPostTree(int begin,int length){
	int root=Tree[begin];
	
	if(length==0||flag==0) return ;
      	int i=0;
		for(;i<length;i++){
			if(Tree[begin+i]>=root){
				
			   	for(int j=i;j<length;j++){
			   		
			   		if(Tree[begin+j]<root){
			   			flag=0;
			   			return ;
			   		}
	              
			   	}
			   	
			   	break;
			   	
			}
			
      }
      		FindPostTree(begin+1,i-(begin+1));
			FindPostTree(i,length-i);
}


int main(){
	int N;
    cin>>N;
	 for(int i=0;i<N;i++){
	 	cin>>Tree[i];
	 }
	 FindPostTree(0,N);
	
	cout<<flag;
	
	
	
	return 0;
} 
