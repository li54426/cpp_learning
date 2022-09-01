
#include <iostream>
using namespace std;

int main() //主函数
{
    //测试引用
	cout << "test the &" <<endl;

	const int a1 = 101;
	const int &s = a1;
	cout << "the ref s is "<< s << endl;
	//s = 1;
	cout << "the changed s-& is "<< s << endl;

	const int &i = 41;
	cout<< "the i is" <<i << endl;





	return 0;
}
