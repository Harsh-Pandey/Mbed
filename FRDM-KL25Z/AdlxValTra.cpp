#include "mbed.h"
#include "nRF24L01P.h"
#include "MMA8451Q.h"
#define MMA8451Q_I2C_ADDRESS (0x1d<<1)
MMA8451Q acc(PTE25, PTE24,MMA8451Q_I2C_ADDRESS);
Serial pc(USBTX, USBRX);
nRF24L01P my_nRF24L01P(PTD6,PTE3,PTE2,PTB8,PTB9,PTD0);
DigitalOut RedLED(LED1);
int main()
{
	//transmission
	float xaxis,yaxis, zaxis;
	char count[3];
	//char h[6]="hello";
	char TxDataCnt;
	char temp;
	my_nRF24L01P.powerUp();
	my_nRF24L01P.setRfFrequency(2400);
	pc.printf("nRF24L01P+ frequency : %d MHz\r\n",my_nRF24L01P.getRfFrequency());
	pc.printf("nRF24L01P+ Output power : %d dBm\r\n",my_nRF24L01P.getRfOutputPower());
	pc.printf("nRF24L01P+ data rate : %d kbps\r\n",my_nRF24L01P.getAirDataRate());
	pc.printf("nRF24L01P+ Tx address : 0x%010llX()\r\n",my_nRF24L01P.getTxAddress());
	pc.printf("nRF24L01P+ Rx address : 0x%010llX\r\n",my_nRF24L01P.getRxAddress());
	pc.printf("Simple Transmitter(0-9 Counter )\r\n");
	TxDataCnt=3;
	my_nRF24L01P.setTransferSize(TxDataCnt);
	my_nRF24L01P.enable();
	while(1)
		{
		xaxis=acc.getAccX();
			yaxis=acc.getAccY();
			zaxis=acc.getAccZ();
		count[0]=(xaxis+1)*127;
			count[1]=(yaxis+1)*127;
			count[2]=(zaxis+1)*127; 
			xaxis=(xaxis+1)*127;
			yaxis=(yaxis+1)*127;
			zaxis=(zaxis+1)*127;
		
			if(xaxis<120||xaxis>129| |yaxis<125||yaxis>135||zaxis<245||zaxis>255){
		temp=my_nRF24L01P.write(NRF24L01P_PIPE_P0, count, TxDataCnt);
		pc.printf("Sending X=%d Y=%d Z=%d\r\n",count[0],count[1],count[2]);
		RedLED=! RedLED;
		//count[0]++;
		wait(1);}
			else
				continue;
	}
}

