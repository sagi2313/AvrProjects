/*
 * GccApplication2.cpp
 *
 * Created: 1/22/2014 20:17:04
 *  Author: Sagi
 */ 


#include <avr/io.h>
#include <stdlib.h>

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

class cPoint
{
	public:
	int X,Y;
	cPoint();
	cPoint(int x, int y)
	{
		X=x;
		Y=y;
	}
};
class Rectangle
{
friend class cPoint;
public:
	Rectangle(int x1,int y1,int x2,int y2): ul(x1,y1), dr(x2,y2){};
	unsigned int area()
		{
			return((dr.X-ul.X) * (dr.Y-ul.Y));
		}			
private:	
	cPoint ul;
	cPoint dr;
};
class Circle {
	double radius;
	public:
	Circle(double r) : radius(r) { }
	double area() {return radius*radius*3.14159265;}
};

class Cylinder {
	Circle base;
	double height;
	public:
	Cylinder(double r, double h) : base (r), height(h) {}
	double volume() {return base.area() * height;}
};
volatile static float f;
volatile static int a;
volatile long* p;
union lf
{
 float f;
long p;	
}lf1;
int main(void)
{

    Rectangle R(1,1,13,14);
	Cylinder C(4,6);
	f=C.volume();
	a=R.area();
	a=2;
	p=(long *)&f;
	lf1.f=0.0;
	for(a=0;a<1000;a++)
	{
		lf1.p++;
	}
	f=(float)a;
	f+=0.5;
	f+=0.25;
	while(1)
    {
     
	
    }
	return(0);
}