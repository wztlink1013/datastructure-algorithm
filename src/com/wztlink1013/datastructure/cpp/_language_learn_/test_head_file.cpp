#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main(){
	double num=sqrt(3.0);
	for (int i = 0; i < 6; i++){
		cout <<"当精度为"<<i<<"时："<<setprecision(i)<<num<<endl;//设置不同的精度
	}
	cout << "当前cout精度为：" <<cout.precision() << endl;
    cout << "当前域宽：" <<cout.width() << endl;
    cout << "=================================="
        << "\n";
	cout <<setw(7)<<num << endl; //默认是右对齐
	cout << "当前填充字符：" << endl;
	cout<<setfill('*') <<setw(10)<<num << endl; //setfill()函数可以直接插入流中
	return 0;
}
