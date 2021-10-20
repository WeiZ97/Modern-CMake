#include <stdlib.h>
#include <stdio.h>

#include "XyzLibrary.h"

int main(){
    
    XYZ_HANDLE sxyz=GetSXyz(23);
    printf("%d\n",sxyz->Foo(3));
    

    XYZ_HANDLE cxyz=GetCXyz(114514);
    printf("%d\n",cxyz->Foo(3));

    

    xyz_release(&sxyz);
    xyz_release(&cxyz);

    system("pause");
    return 0;
}