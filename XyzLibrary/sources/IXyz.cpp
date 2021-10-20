#include "IXyz.h"
#include <stdlib.h>

XYZAPI int xyz_foo(XYZ_HANDLE handle,int n){
    int nReslult=-1;
    if(handle!=nullptr){
        nReslult =handle->Foo(n);
    }
    return nReslult;
}

XYZAPI void xyz_release(XYZ_HANDLE* handle){
    (*handle)->Release();
    delete (*handle);
    (*handle)=NULL;
    return;
}