#include <iostream>


using namespace std;

class Complex
{
private:
    int r = 0;
    int i = 0;

public:
    Complex(int r_in, int i_in):r(r_in), i(i_in){}
    int get_r(){
        return this -> r;
    }
    int get_i(){
        return this -> i;
    }

    friend class Com;
};

class Com{

private:
    int num = 0;

public:
    Com(int a):num(a){}
    int getr(Complex c){
    return c.r;

}

};
int main() //主函数
{
    Complex a(1, 1);

    //cout << a.r; //'int Complex::r'is private

    Com b(10);

    cout << b.getr(a);

	return 0;
}
