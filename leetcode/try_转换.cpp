#include<iostream>

using namespace std;

int main(){
    int arr[5] = {0, 1 ,2, 3, 4};

    arr[3]= 128;
    cout<< arr[3] <<endl;

    ((short*)arr)[6]= 2;//arr被重新解释成2bytes的short型，此时，之前赋值128的地方变为arr[7]

    cout<< arr[3] << endl;//输出的值为2的9次幂加上128
    //arr被重新解释成2bytes的short型，此时，之前赋值128的地方变为arr[7]

    cout<< arr[0] << endl;//输出的值为2的9次幂加上128
    cout<< arr[4] <<endl;



return 0;
}
