#include "led.h"
#include "delay.h"
#include "dac.h"
#include "math.h"
int main(void)
{
   Dac1_Init();
   double S,C,X,SCX,x;
   u8 t;
	x=1.8165;
	while(1)
	{
   S=pow(x,0.6666);
   C=sqrt(3.3-pow(x,2));
   X=sin(31.41592*x);
   SCX=(S+0.9*C*X)*900;
   Dac1_Set_Vol(SCX+1100); //DACÊä³öº¯Êý
   if(t==0)
      x=x-0.001;
   else
      x=x+0.001;
   if(x<=0)t=1;
   if(x==1.8165)
      {
         t=0;
         delay_ms(10000);
      }
  }
}

