//poj2676_dfs 391ms
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

const int maxn=10;

int T;
int ch[maxn][maxn];

bool row[maxn][maxn]; //row[i][k] 判断第i行是否有k
bool col[maxn][maxn]; //判断第i列是否有k
bool grid[maxn][maxn]; //判断第i个9宫格是否有k
bool flag=0;

int ans[maxn][maxn]; //记录答案
static int k=0;
void dfs(int x,int y)
{    k++;
    if(flag) return;
    if(x==9&&y==0){ //直接精确判断最后一格，不要用judge判断，若每次用judge判断时间浪费太多
        flag=1;
        memcpy(ans,ch,sizeof(ch)); //dfs记录路径答案最好直接拷贝数组，慎用原数组，因为若题目要求搜所以情况且过程用贪心时原数组最终会随着dfs的结束而清零
        return;
    }
    if(ch[x][y]==0){ //空格
        int k=x/3*3+y/3; //第k个9宫格
        for(int i=1;i<=9;i++){
            if(row[x][i]||col[y][i]||grid[k][i]) continue;
            ch[x][y]=i; //放置
            row[x][i]=col[y][i]=grid[k][i]=1;
            if(y+1<9) dfs(x,y+1);
            else dfs(x+1,0);
            ch[x][y]=0; //还原
            row[x][i]=col[y][i]=grid[k][i]=0;
        }
    }
    else{ //非空格
        if(y+1<9) dfs(x,y+1);
        else dfs(x+1,0);
    }
}

int main()
{
    cin>>T;
    while(T--){
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(grid,0,sizeof(grid));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                scanf("%1d",&ch[i][j]);
                row[i][ch[i][j]]=1;
                col[j][ch[i][j]]=1;
                grid[i/3*3+j/3][ch[i][j]]=1;
            }
        }
        flag=0;
        dfs(0,0);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                printf("%d",ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
