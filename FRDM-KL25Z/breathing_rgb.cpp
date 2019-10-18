#include"mbed.h"

PwmOut ledr (PTB18);
PwmOut ledg (PTB19);
PwmOut ledb (PTD1);
float i;
main()
 {
   ledr.period_ms(3);
   ledg.period_ms(3);
   ledb.period_ms(3);
     
     while(1)
       {
        for(i=1;i>0;i=i-0.1)   //led violet goes up
           { 
            ledg=1;
            ledr.write(i);
            ledb.write(i);
            wait(0.1);
           }
         for(i=0;i<1;i=i+0.1)   //led violet goes down
           {
             ledg=1;
             
             ledr.write(i);
             ledb.write(i);
             wait(0.1);
           }
         for(i=1;i>0;i=i-0.1)   //led blue goes up
           {
            ledr=1;
            ledg=1;
             ledb.write(i);
             wait(0.1);
           }
         
           
          for(i=0;i<1;i=i+0.1)   //led blue goes down
           {
             ledr=1;
             ledg=1;
             ledb.write(i);
             wait(0.1);
               
             }
          for(i=1;i>0;i=i-0.1)   //led green goes up
           {
             ledr=1;
             ledb=1;
             ledg.write(i);
             wait(0.1);
           }
         for(i=0;i<1;i=i+0.1)   //led green goes down
           {
             ledr=1;
             ledb=1;
             ledg.write(i);
             wait(0.1); 
           }
          for(i=1;i>0;i=i-0.1)   //led yellow goes up
           {
             
             ledb=1;
             ledr.write(i);
             ledg.write(i);
             wait(0.1);
           }
         for(i=0;i<1;i=i+0.1)   //led yellow goes down
           {
             ledb=1;
             ledr.write(i);
             ledg.write(i);
             wait(0.1); 
           }
         for(i=1;i>0;i=i-0.1)   //led red goes up
           { 
           ledg=1;
           ledb=1;
            ledr.write(i);
            wait(0.1);
           }
         for(i=0;i<1;i=i+0.1)   //led red goes down
           {
             ledg=1;
             ledb=1;
             ledr.write(i);
             wait(0.1);
           }
           
           
        
           
         
         
           
         }
         
}
