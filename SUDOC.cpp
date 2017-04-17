#include <iostream>
#include <set>
#include <cstdio>
#include <cstring>
using namespace std;
struct T{
	int x ;
	int y ;
	int w ;
	T(int x, int y,int w){
		this->x = x;
		this->y = y;
		this->w = w;
	}
	bool operator < (const T&t)const{
		
			if ( w > t.w) return true ;
			else if (w == t.w)
			{
				if (x < t.x)  return true;
				else if (x==t.x)  return y < t.y;
					else   return false;
				
			}
			else  return false;

	}
};
int m[9][9];
bool De_m[9][9][9]; 
multiset<T> n;
int check = 0;
void Recording(int x, int y, int value,bool c){
	for (int i = 0; i<9; i++){
		De_m[i][y][value - 1] = c;
		De_m[x][i][value - 1] = c;
	}
	int xx = x / 3 * 3;
	int yy = y / 3 * 3;
	for (int i = xx; i<xx + 3; i++){
		for (int j = yy; j<yy + 3; j++){
			De_m[i][j][value - 1] = c;
		}
	}
}
void init(){
	char mt[9][9];
	for (int i = 0; i<9; i++)
	for (int j = 0; j<9; j++){
	//	scanf("%1d", &m[i][j]);
		cin >> mt[i][j];
		m[i][j] = mt[i][j] - '0';
		if (m[i][j] != 0){
			Recording(i, j, m[i][j],true);
			check++;
		}
	}
	//进行可选择值初始化
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			int sum = 0;
			for (int k = 0; k < 9; k++){
				sum += De_m[i][j][k];
			}
			n.insert(T(i, j, sum));
		}
	}
}

void output()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << m[i][j];
			//if (j % 3 == 2)
			//{
			//	cout << "   ";
			//}
		}
		cout << endl;
		//if (i % 3 == 2)
		//{
		//	cout << endl;
		//}
	}
}
static int cc = 0;
void DFS(multiset <T>::iterator it){
	if (check > 80) return;

		if (m[it->x][it->y] == 0){
			for (int i = 0; i < 9; i++){
				if ( (!De_m[it->x][it->y][i])){
					
					m[it->x][it->y] = i+1;
					Recording(it->x, it->y, i + 1,true);
                    check++;
					 
					 DFS(++it);
					it--;   //回退时将指针回溯

					if (check > 80) return ;

					 m[it->x][it->y] = 0;
					 Recording(it->x, it->y, i + 1, false);
					 check--;
				}
			}
		}
		else
		{
			DFS(++it);
			it--; //回退时将指针回溯
		}
}
int main(){
	multiset <T>::iterator it;
	int k;
	cin >> k;
	while (k--)
	{

		init();
	    it = n.begin();
		DFS(it);

		output();
		
		//for each (int i in De_m)
		//{ 
		//	i = 0;
		//}
		check = 0;
		n.clear();
		memset(De_m, 0, sizeof(De_m));
	}
	//set <T>::iterator it;
	//for (set <T>::iterator it = n.begin(); it != n.end(); it++){
	//	cout << it->x << " " << it->y << " " << it->w << endl;
	//}
	
}