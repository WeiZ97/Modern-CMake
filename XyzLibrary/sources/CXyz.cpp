#include "CXyz.h"
#include <stdio.h>

class CXyz :public IXyz{
    int id;
    int field;
    int Foo(int n);
    void Release();
public:
    CXyz(int id):id(id),field(id/2){};
};

int CXyz::Foo(int n){
    return n*n*n;
}

void CXyz::Release(){
    printf("instance:%d newfield:%d release\n",this->id,this->field);
}

XYZAPI XYZ_HANDLE GetCXyz(int id){
    return new CXyz(id);
}

