/*
 * GccApplication2.cpp
 *
 * Created: 1/22/2014 20:17:04
 *  Author: Sagi
 */ 


#include <avr/io.h>
#include <stdio.h>
volatile unsigned long lng=0;

int main(void)
{
char p=11;
    while(1)
    {
        lng++;
		if(p + lng)
		{
		p++;
		printf("%ld",lng);
		}
		//TODO:: Please write your application code 
    }
}