#ifndef XYZ_H
#define XYZ_H
#pragma once

#ifdef PLATFORM_WINDOWS
    #ifdef XYZLIBRARY_EXPORTS
        #define XYZAPI __declspec(dllexport)
    #else
        #define XYZAPI __declspec(dllimport)
    #endif
#else
    #define XYZAPI
#endif

#ifdef __cplusplus
    #define EXTERN_C extern "C"
#else
    #define EXTERN_C
#endif




#ifdef __cplusplus
class IXyz
{
public:
    virtual int Foo(int n)=0;
    virtual void Release()=0;
};

typedef IXyz* XYZ_HANDLE;

#else
typedef void* XYZ_HANDLE;
#endif



EXTERN_C XYZAPI int (xyz_foo)(XYZ_HANDLE handle,int n);
EXTERN_C XYZAPI void (xyz_release)(XYZ_HANDLE* handle);

#endif

