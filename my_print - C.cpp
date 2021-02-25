#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int my_printf(const char *fmt, ...);
int my_puts(char const s[1]) {
    for (int i = 0;s[i] != '\0'; i++){
	    if (putchar(s[i]) == '\0') {return 0;}
    }
    return 0;
    }

int main()
{
    
    int param1 = 0xABCD;
    double param2 = 312.12;
    char param3 = 'K';
    char * param4 = "Test string";
    int d = my_printf("All parameters are as follows %X %lf %c %s\n", param1, param2, param3, param4);
   	my_printf("Total characters %d\n",d);
   	my_printf("Hello World");
    return 0;
}


int my_printf(const char* fmt, ...)
{
    va_list valist;
    
    int i = 0;
	int noc = 0; // No. of Characters
	int a = 123;
    int count=0;// no. of parameter
    int stackdown = 0;
    if((void*)&fmt > (void*)&a){stackdown = 1;}
	if(stackdown == 1)
	{   
		int e = 0;
		while(1){
		    if(*(fmt+e) == '%'){
		        e++;
				count++;	
			}
			if(*(fmt+e) == '\0'){break;
			}
			e++;
		}
		va_start(valist, count); //initializes the list with recieved arguments
		
		while(1){
            if(*(fmt+i) == '%' ){
	        	i++;
	        	if(*(fmt+i) == 'X'){
				    i++;
				    char str[16];
				    itoa(va_arg(valist,int),str,16);
					my_puts(str);
					noc = noc + strlen(str);
					}
	        	if(*(fmt+i) == 'c'){
					i++;
					noc++;
					putchar((char)(va_arg(valist,int)));
				    }
	        	if(*(fmt+i) == 'l'){
				    i++;
					if(*(fmt+i) == 'f'){
					    i++;
					    char buf[16];
					    gcvt (va_arg(valist,double), 15, buf);
					    my_puts(buf);
					    noc = noc + strlen(buf);
					    }
				    }
		        if(*(fmt+i) == 'd' or *(fmt+i) == 'i' ){
				    i++;
				    char str[16];
				    itoa(va_arg(valist,int),str,10);
					my_puts(str);
					noc = noc + strlen(str);	
				    }
		        if(*(fmt+i) == 's'){
		        	i++;
		        	char *ft = (char*)(va_arg(valist,int));
		        	int z = 0;
					while(1){
		        		putchar(*(ft+z));
		        		z++;
						noc++;
		        		if(*(ft+z)=='\0'){break;}
					    }
				    }
				if(*(fmt+i) == 'f'){
		        	i++;
					char buf[8];
					gcvt (va_arg(valist,double), 7, buf);
					my_puts(buf);
					noc = noc + strlen(buf);
					}
				}
		    else{
				putchar(*(fmt+i)); //prints the string other than format specifier
				i++;
				noc++;
			    }
	        
		if(*(fmt+i)=='\0'){break;}// exits when it reaches to end of string '\0'
		}
    }
	return noc;
} 


 


