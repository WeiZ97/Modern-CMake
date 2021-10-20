#include "SXyz.h"
#include <stdio.h>

class SXyz :public IXyz{
    int id;
    int Foo(int n);
    void Release();
public:
    SXyz(int id):id(id){};
};

int SXyz::Foo(int n){
    return n*n;
}

void SXyz::Release(){
    printf("instance:%d release\n",this->id);
}

XYZAPI XYZ_HANDLE GetSXyz(int id){
    return new SXyz(id);
}


