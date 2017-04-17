#include<iostream>
#include <fstream>
#include <string>
using namespace std;
struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	char  elem;
};
TreeNode* BinaryTreeFromOrdings(char* pre,char* in,int length){
 TreeNode* node=new TreeNode;
   if(length==0){
   	return NULL;
   }
	node->elem=pre[0];
	int rootIndex=0;
  for(;rootIndex<length;rootIndex++){
  	if(in[rootIndex]==node->elem)
  	break;
  }
  //left
  node->left=BinaryTreeFromOrdings(pre+1,in,rootIndex);
  //right
  node->right=BinaryTreeFromOrdings(pre+rootIndex+1,in+rootIndex+1,length-(rootIndex+1));
  cout<<node->elem<<" ";
  delete(node);
  
  return NULL;
}

int main(){
	char* pre="GDAFEMHZ";
	char* in="ADEFGHMZ";
	BinaryTreeFromOrdings(pre,in,8);
	return 0;
} 
