# include<vector>
#include <iostream>

#include <ext\pool_allocator.h>
using namespace std;



int main(){
    vector<int, __gnu_cxx::__pool_alloc<int> > a = {0, 1, 2};
    cout<< a[1]<< endl;
    cout<< "size of a ="<< sizeof(a)<< endl;

    enum{money = 8};
    cout<< sizeof(money)<< endl;

    union obj{
    obj *link;
    char a;
    };
    obj simple;
    simple.a = 'a';
    cout << simple.a << endl;
    cout<< "size of union = "<< sizeof(simple)<< endl;
    int *p =nullptr;
    cout<< "size of pointer ="<< sizeof(p)<< endl;



return 0;
}
