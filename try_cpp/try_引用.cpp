
#include <iostream>
using namespace std;
float temp; //定义全局变量temp
float fn1(float r); //声明函数fn1
float &fn2(float r); //声明函数fn2
float fn1(float r) //定义函数fn1，它以返回值的方法返回函数值
{
	temp = (float)(r*r*3.14);
	return temp;
}
float &fn2(float r) //定义函数fn2，它以引用方式返回函数值
{
	temp = (float)(r*r*3.14);
	return temp;
}
int main() //主函数
{

	float a = fn1(10.0); //第1种情况，系统生成要返回值的副本（即临时变量）
	//float &b = fn1(10.0); //第2种情况，可能会出错（不同 C++系统有不同规定）
						  //不能从被调函数中返回一个临时变量或局部变量的引用
	float c = fn2(10.0); //第3种情况，系统不生成返回值的副本
						 //可以从被调函数中返回一个全局变量的引用
	float &d = fn2(10.0); //第4种情况，系统不生成返回值的副本
						  //可以从被调函数中返回一个全局变量的引用
	cout << a << endl;
	cout << c << endl;
	cout << d << endl;
	cout << "test the &" <<endl;

	int a1 = 101;
	int &s = a1;
	cout << "the s-& is "<< s << endl;
	s = 1;
	cout << "the changed s-& is "<< s << endl;



	return 0;
}
