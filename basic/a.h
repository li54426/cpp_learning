#include<iostream>

template<class T>
class mystack{
private:
    int top;
    T *base;
    int len;

public:
    mystack(int len);
    void creat();
    void del();
    #void push();
    T push(T value);
    T pop()
};

extern int i ;

//i++
int fun1(int i);

