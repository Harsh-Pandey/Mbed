#include "mbed.h"
#include "USBMouse.h"
#include "TSISensor.h"
#include "MMA8451Q.h"
Serial pc(USBTX,USBRX);
USBMouse mouse;
TSISensor tsi;
MMA8451Q acc(PTE25,PTE24,0X1d<<1);
main()
{
    float click=0;
    float x=0;
    float y=0;
    char choice;
    pc.printf("\n");
    pc.printf("Enter the variable for sensitivity:\n\r");
            while(1)
            {
                 if(pc.readable())
                     {
                         
                      
                 choice=pc.getc();
                switch(choice)
                   {
                       case 'S':
                       {
                        x=-5*acc.getAccY();
                       y=5*acc.getAccX();
                       mouse.move(x,y);
                       click=tsi.readPercentage();
                       if(click>0&&click<=0.4)
                        {  
                       mouse.press(MOUSE_RIGHT);
                          }
                       else if(click>0.6)
                        {
                        mouse.press(MOUSE_LEFT);
                          }
                       else
                         {
                       mouse.release(MOUSE_LEFT);
                       mouse.release(MOUSE_RIGHT);
                        }
                        wait(0.001);
                        }
                        break;
                        
                        case 'M':
                        { 
                        x=-12*acc.getAccY();
                        y=12*acc.getAccX();
                        mouse.move(x,y);
                        click=tsi.readPercentage();
                        if(click>0&&click<=0.4)
                         {  
                        mouse.press(MOUSE_RIGHT);
                            }
                        else if(click>0.6)
                        {
                         mouse.press(MOUSE_LEFT);
                            }
                          else
                         {
                         mouse.release(MOUSE_LEFT);
                          mouse.release(MOUSE_RIGHT);
                            }
                         wait(0.001);
                         }
                         break;
                         
                         case 'F':
                        { x=-20*acc.getAccY();
                         y=20*acc.getAccX();
                         mouse.move(x,y);
                         click=tsi.readPercentage();
                         if(click>0&&click<=0.4)
                           {  
                         mouse.press(MOUSE_RIGHT);
                           }
                         else if(click>0.6)
                          {
                          mouse.press(MOUSE_LEFT);
                          }
                          else
                           {
                          mouse.release(MOUSE_LEFT);
                           mouse.release(MOUSE_RIGHT);
                            }
                          wait(0.001);
                        }  
                          break;
                          
                         default:
                         {
				x=-5*acc.getAccY();
                       		y=5*acc.getAccX();
                       		mouse.move(x,y);
                       		click=tsi.readPercentage();
                       		if(click>0&&click<=0.4)
                        		{  
                       				mouse.press(MOUSE_RIGHT);
                         		 }		
                       		else if(click>0.6)
                        	{
                        			mouse.press(MOUSE_LEFT);
                          	}
                       		else
                         		{
                       				mouse.release(MOUSE_LEFT);
                      				 mouse.release(MOUSE_RIGHT);
                        		}
                        	wait(0.001);
                        }
                        
                        break;
                        
                       
                        }  
                          
                         
                   }         
                        
                            
           }               
}                        

