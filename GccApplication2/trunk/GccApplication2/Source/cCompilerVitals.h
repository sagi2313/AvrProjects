/* 
* cCompilerVitals.h
*
* Created: 1/24/2014 10:35:40
* Author: Sagi
*/


#ifndef __CCOMPILERVITALS_H__
#define __CCOMPILERVITALS_H__
/* the Following declarations are needed for any AVR c++ compilation */
void * operator new(size_t size)
{
	return malloc(size);
}

void operator delete(void * ptr)
{
	
	free(ptr);
	ptr=NULL;
}
void * operator new[](size_t size)
{
	return malloc(size);
}

void operator delete[](void * ptr)
{
	free(ptr);
}

__extension__ typedef int __guard __attribute__((mode (__DI__)));

extern "C" int __cxa_guard_acquire(__guard *);
extern "C" void __cxa_guard_release (__guard *);
extern "C" void __cxa_guard_abort (__guard *);
extern "C" void __cxa_pure_virtual(void);
void __cxa_pure_virtual(void) {};
/* ------------------------------------------------------------------------------------------------------*/

//class cCompilerVitals
//{
////variables
//public:
//protected:
//private:
//
////functions
//public:
	//cCompilerVitals();
	//~cCompilerVitals();
//protected:
//private:
	//cCompilerVitals( const cCompilerVitals &c );
	//cCompilerVitals& operator=( const cCompilerVitals &c );
//
//}; //cCompilerVitals

#endif //__CCOMPILERVITALS_H__
