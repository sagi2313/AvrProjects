/*
 * GccApplication1.cpp
 *
 * Created: 1/15/2014 18:54:43
 *  Author: Sagi
 */ 


#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include "visobjects.h"
template <class T>
class mypair {
	T values [2];
	public:
	mypair (T first, T second)
	{
		values[0]=first; values[1]=second;
	}
};
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
	
typedef struct 
{
int x;
int y;

}sPoint;	
class sagicls
{
int height;
int width;

public:
    
	enum LedStates
	{
	LedOff,
	LedOn,
	LedBlink	
	};
	LedStates ThisLed;
	sagicls(int,int);
	bool SetName(char *s);
	void SetValues(int,int);
	int GetArea();
	bool GetCenter(sPoint *p);
	int ID;
	sagicls () {n++;ID=n;name=NULL;};
	~sagicls() {height=200;initialized=false;n--;
				if(name!=NULL)delete name;
				};
	
protected:

private:
char *name;
static int n;
bool initialized=false;
sPoint CenterPoint(void);
};

int sagicls::n=0;
bool sagicls::SetName(char *s)
{
	int i=strlen(s);
	if(i>0)
	{
		name=(char*) new char[i];// char;
		*name=*s;
		return(true);
	}
	return(false);
}
sagicls::sagicls(int w,int h )
{
	width=w;
	height=h;
	initialized=true;
	n++;
}
int sagicls::GetArea(void)
{
	if(initialized==false)return(NULL);
	return(width * height);
}
sPoint sagicls::CenterPoint(void)
{
	
	sPoint p;
	p.x=((width * 3)/2);
	p.y=((height * 3)/2);
	return(p);
}

bool sagicls::GetCenter(sPoint *p)
{	
	if(initialized==true)
	{
		*p=CenterPoint();
	}
	return(initialized);
}
void sagicls::SetValues (int x, int y) {
	width = x;
	height = y;
	initialized=true;
}
int main(void)
{
	int a=0;
	ColorCls col,col2;
	col.SetColor(0x4561);
	col.SetColor(0xffff);
	col.SetColor(0x001F);
	col2.SetColor(33,55,67);
	col2.SetColor(255,255,255);
	col2.SetColor(255,0,255);
	sagicls sagi;
	sagicls *b = new sagicls;
	const sagicls c(10,10);
	sPoint p;
	a=sagi.GetArea();
	sagi.GetCenter(&p);
	sagi.SetValues(4,8);
    a=sagi.GetArea();
	sagi.GetCenter(&p);
	sagi.ThisLed=sagi.LedOn;
	sagi.ThisLed=sagi.LedBlink;
	sagi.ThisLed=sagicls::LedOn;
	sagi.SetName("Alekos2313");
	b= new sagicls;
	delete &c;
	//a=c->GetCenter(&p);
	a=b->GetArea();
	a=b->ID;
	while(1)
    {
        
		//TODO:: Please write your application code 
    }
}