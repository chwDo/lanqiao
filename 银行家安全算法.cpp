#include <iostream>
#include <string>
using namespace std;
/* int Available[3] = {3,3,2};  //������Դ���� 
 int Max[5][3] = { { 7, 5, 3 }, { 3, 2, 2 }, { 9, 0, 2 }, { 2, 2, 2 }, {4,3,3} };//���������� 
 int ALLocation[5][3] = { {0,1,0}, {2,0,0}, {3,0,2}, {2,1,1}, {0,0,2} };//������� 
 int Need[5][3] = { {7,4,3}, {1,2,2}, {6,0,0}, {0,1,1}, {4,3,1} };//������� 
 bool  Finsh[5] = { false, false, false, false,false };  //������*/
 int Available[100];//������Դ���� 
 int Max[100][100]; //���������� 
 int ALLocation[100][100];//������� 
 int Need[100][100];//������� 
 bool  Finsh[100];
  int m;      //���̸��� 
  int n;      //��Դ������ 
 int  F[100],c=0;
 bool test(int k){
    for(int i=0;i<n;i++)
	 {
	 if(Need[k][i]> Available[i])
	 {
       return false;
	 }
 }
     cout<<"P"<<k<<"�õ�������Դ:"<<endl;
     for(int i=0;i<n;i++)
     {
	  Available[i]-=Need[k][i];    //������Դ  
	  cout<<Need[k][i]<<"  ";    
	  Need[k][i]=0;  //�������ı� 
	  
	  ALLocation[k][i]+=Need[k][i];  //�õ���Դ 
	  
	  Available[i]=Available[i]+Max[k][i]; //�ͷ���Դ 
	 }
	 cout<<endl;   
	 Finsh[k]=true; //��ɱ�־ 
	 F[c++]=k;
	 return true;
 }


bool safe(){
      for(int i=0;i<m;i++)
        if(Finsh[i]==false)  //�ж��Ƿ������ 
         {
           if(test(i)==true)  //�Է��� 
		      i=-1;            //������� ��ͷѭ��       
		 }
	  for(int i=0;i<m;i++)
	   if(Finsh[i]==false)   //�����������ж��Ƿ�ȫ����� ���в���ɵ� �򷵻��ް�ȫ���� 
	     return false;  
	
	return true;
} 
void input(){
	cout<<"������̸���"<<endl;	
	  cin>>m;
	cout<<"������Դ������"<<endl;
	  cin>>n;
	cout<<"�����뵱ǰ������Դ"<<n<<"��"<<endl;
	for(int i=0;i<n;i++)
	 {
	     cin>>Available[i];
	 }
	 cout<<"�������������"<<m<<"*"<<n<<endl;
	 for(int i=0;i<m;i++)
	 {   
	    for(int j=0;j<n;j++)
	      cin>>Max[i][j];
	 }
	 cout<<"�������ѷ������  "<<m<<"*"<<n<<endl;
	 for(int i=0;i<m;i++)
	 {    Finsh[i]=false;          //�������ʼ�� 
	    for(int j=0;j<n;j++){
	      cin>>ALLocation[i][j];
	      Need[i][j]=Max[i][j]-ALLocation[i][j];  //��������ʼ�� 
	   }
	 }
	 
}
int main(){
	input();
   if(safe()){
   	cout<<"���ڰ�ȫ����"<<endl;
   for(int i=0;i<c;i++)
   cout<<F[i]<<"  ";
     }
    else 
	{
		cout<<"�����ڰ�ȫ����"<<endl;
	}
   return 0;
}
