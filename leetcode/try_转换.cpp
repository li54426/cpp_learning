#include<iostream>

using namespace std;

int main(){
    int arr[5] = {0, 1 ,2, 3, 4};

    arr[3]= 128;
    cout<< arr[3] <<endl;

    ((short*)arr)[6]= 2;//arr�����½��ͳ�2bytes��short�ͣ���ʱ��֮ǰ��ֵ128�ĵط���Ϊarr[7]

    cout<< arr[3] << endl;//�����ֵΪ2��9���ݼ���128
    //arr�����½��ͳ�2bytes��short�ͣ���ʱ��֮ǰ��ֵ128�ĵط���Ϊarr[7]

    cout<< arr[0] << endl;//�����ֵΪ2��9���ݼ���128
    cout<< arr[4] <<endl;



return 0;
}
