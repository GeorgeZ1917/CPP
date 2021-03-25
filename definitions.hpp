#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#if __has_include ( <numbers> )
#include <numbers>
#endif

#define PI 3.141592653589
template <typename TReturn, typename T1, typename T2> TReturn& larger ( T1& A, T2& B );
template <typename T> T function ( T A, T B );
template <> float function <float> ( float a, float b );
template <> int* function <int*> ( int* a, int* b );
int staticFunction ();
int modifyByReference ( int &referenceOfVariable );
long long int factorial ( int n );

#endif
