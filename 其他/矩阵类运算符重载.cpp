#include <iostream>
#include <stdlib.h>
using namespace std;
class Matrix{
	private:
		int row, col;
		int mt[100][100];
	public:
		bool isNull(){
			return row == 0 ? true : false;
		}
		void disp();
		Matrix(int row, int col){
			this -> row = row;
			this -> col = col;
			cout << "请输入该矩阵元素:" << endl;
			input();
		}
		Matrix(){

		}
		void input(){
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					cin >> mt[i][j];
				}
			}

		}
		Matrix operator+(const Matrix& m){
			Matrix result;
			if(this->row != m.row || this->col != m.col){
				cout << "program terminated!"<< endl;
				return result;
			}
			for (int i = 0; i < m.row; ++i)
			{
				for (int j = 0; j < m.col; ++j)
				{
					result.mt[i][j] = this->mt[i][j] + m.mt[i][j];
				}
			}
			result.row = m.row;
			result.col = m.col;
			return result;
		}
		void operator=(const Matrix& m){
			for (int i = 0; i < m.row; ++i)
			{
				for (int j = 0; j <m.col; ++j)
				{
					this->mt[i][j] = m.mt[i][j];
				}
			}
			this->row = m.row;
			this->col = m.col;
		}
		~Matrix(){
		}

};
void Matrix::disp()
{
	for(int i=0;i<row;i++)
	{
		cout<<'\t';
		for(int j=0;j<col;j++)
			// cout<<*(m+i*col+j)<<'\t';
			cout<<mt[i][j]<< '\t';
		cout<<endl;
	}
}
int main()
{
	int row_a,col_a,row_b,col_b;
	cout<<"请输入am矩阵的行数和列数:"<<endl;
	cin >> row_a >> col_a;
	Matrix am(row_a,col_a);
	cout<<"请输入bm矩阵的行数和列数:"<<endl;
	cin>>row_b>>col_b;
	Matrix bm(row_b,col_b),cm;
	cout<<"am:"<<endl;
	am.disp();
	cout<<"bm:"<<endl;
	bm.disp();
	cm=am+bm;
	if(cm.isNull()){
		return 0;
	}
	cout<<"cm=am+bm:"<<endl;
	cm.disp();
	am=bm;
	cout<<"am=bm:"<<endl;
	am.disp();
	return 0;
}