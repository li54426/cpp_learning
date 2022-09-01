#include"a.h"

using namespace a;

mystack :: mystack(int len){
    this -> len = len;
    this -> base = malloc(len * sizeof(T));
    this -> top = 0;

}

T mystack ::pop(){
    if(this ->top > -1)
        return *(this->base + this ->top);

    else
        return T();

}
int mystack::push(T value){
    if(this -> top < this ->len ){
        this ->top--;
        return
    }


}
