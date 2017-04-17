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

bool row[maxn][maxn]; //row[i][k] �жϵ�i���Ƿ���k
bool col[maxn][maxn]; //�жϵ�i���Ƿ���k
bool grid[maxn][maxn]; //�жϵ�i��9�����Ƿ���k
bool flag=0;

int ans[maxn][maxn]; //��¼��
static int k=0;
void dfs(int x,int y)
{    k++;
    if(flag) return;
    if(x==9&&y==0){ //ֱ�Ӿ�ȷ�ж����һ�񣬲�Ҫ��judge�жϣ���ÿ����judge�ж�ʱ���˷�̫��
        flag=1;
        memcpy(ans,ch,sizeof(ch)); //dfs��¼·�������ֱ�ӿ������飬����ԭ���飬��Ϊ����ĿҪ������������ҹ�����̰��ʱԭ�������ջ�����dfs�Ľ���������
        return;
    }
    if(ch[x][y]==0){ //�ո�
        int k=x/3*3+y/3; //��k��9����
        for(int i=1;i<=9;i++){
            if(row[x][i]||col[y][i]||grid[k][i]) continue;
            ch[x][y]=i; //����
            row[x][i]=col[y][i]=grid[k][i]=1;
            if(y+1<9) dfs(x,y+1);
            else dfs(x+1,0);
            ch[x][y]=0; //��ԭ
            row[x][i]=col[y][i]=grid[k][i]=0;
        }
    }
    else{ //�ǿո�
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
