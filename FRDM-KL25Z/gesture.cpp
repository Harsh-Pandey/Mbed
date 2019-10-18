#include<mbed.h>
#include<MMA8451Q.h>
BusOut led(LED1, LED2, LED3);
Serial pc(USBTX, USBRX);
MMA8451Q acc(PTE25, PTE24, 0x1d<<1);
float x,y,z;
void ledSleep()
{
	led=0x7;
}
void getacc()
{
	x=acc.getAccX();
		y=acc.getAccY();
		z=acc.getAccZ();
}
int main()
{
	int count=0;
	while(1)
	{
		switch (count)
		{
			case 1:
				ledSleep();
				led=0x6;
				break;
			
			case 2:
				ledSleep();
				led=0x5;
				break;
			
			case 3:
				ledSleep();
				led=0x3;
				break;
			default:
				ledSleep();
				break;
		}
		getacc();
		
		if((abs(z)<0.5)&&(abs(y)>1.5))
		{
			count++;
			//pc.printf("Forward count:%d\n\r",count);
		//wait(0.2);
			if(count>3)
				count=1;
			pc.printf("Forward count:%d\n\r",count);
			wait(0.3);
		}
		else if((abs(z)>1.5)&&(abs(y)<1))
		{
			//pc.printf("Sideways count:%d\n\r",count);
			count--;
			if(count==0)
				count=3;
			pc.printf("Sideways count:%d\n\r",count);
			wait(0.3);
		}
		else
			ledSleep();
}
		}
