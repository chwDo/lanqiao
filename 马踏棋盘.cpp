#include<iostream>
#include<iomanip>
using namespace std;
int xx[] = { -2, -2, 2, 2, 1, 1, -1, -1 };
int yy[] = { -1, 1, 1, -1, 2, -2, 2, -2 };
int chess[8][8];
bool c = false;
void DFS(int x, int y, int step){
	if (step > 63){
		c = true; 
		return;
	}
	for (int i = 0; i<8; i++){

		if (x + xx[i]>7 || x + xx[i]<0 || y + yy[i]>7 || y + yy[i]<0 || chess[x + xx[i]][y + yy[i]] != 0)
			continue;
		chess[x + xx[i]][y + yy[i]] = step+1;
		DFS(x + xx[i], y + yy[i], step+1);
		if (c)
		{
			return;
		}

		chess[x + xx[i]][y + yy[i]] = 0;
		

	}

}
void output(){
	for (int i = 0; i<8; i++){
		for (int j = 0; j<8; j++){
			cout << setw(2)<<chess[i][j] << "  ";
		}
		cout << endl;
	}
}
int main(){

	int x, y;
	cin >> x>>y;
	chess[x][y] = 1;
	DFS(x, y, 1);
	output();

	return 0;

}
