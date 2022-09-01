
#include <iostream>
using namespace std;

int main() //主函数
{
    int a= 10;
    int b = 20;
    const int *p = &a;
    cout<< "the pointer is " << p <<endl;

    //p是可以改变的
    p = &b;
    cout << "the changed pointer is" << p << endl;

    //*p不可以改变, 但是可以通过其他方法修改*p ,例如修改b
    //*p = 30;

    b = 30;
    cout << "the changed *p is" << *p << endl;

    //指针不能修改.
    int *const q =  &a;
    //q = &b;
    *q = 30;
    cout << "the changed pointer q value is" << *q ;




	return 0;
}
