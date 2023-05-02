#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;

 double Atof(string s) {
        double num = 0;
        int sign = 1;
        int check = 1;
        int expsign = 1;
        double decimal = 1.0;
        long exp = 0;
        int dotcheck =1;

        
        
        for(int i=0;i<s.length();i++)
        {
            
            if(check)
            {
                while(i<s.length() && s[i] == ' ') i++;


                if(s[i] == '-') 
                { 
                    sign = -1;
                    i++;
                }
                else if (s[i] == '+') 
                {
                    sign = 1;
                    i++;
                }
                check = 0;

            }

            if( s[i] - '0' >= 0 &&  s[i] - '0' <= 9 )
                num = num*10.0 + double(s[i] - '0'); 
            
            else if(s[i] == '.' && dotcheck )
			{
				i++;
				while(i<s.length() && ( s[i] - '0' >= 0 &&  s[i] - '0' <= 9 ))
				{
					decimal = decimal*10.0;
					num = num*10.0 + double(s[i] - '0');
					i++;
					
			    }
			    i--;
			    dotcheck = 0;
		    }
            
//            else if(s[i] == 'e' || s[i] == 'E' )
//            {
//            	i++;
//            	
//                if(s[i] == '-') 
//                { 
//                    expsign = -1;
//                    i++;
//                }
//                else if (s[i] == '+') 
//                {
//                    expsign = 1;
//                    i++;
//                }
//                
//                while(i<s.length() && ( s[i] - '0' >= 0 &&  s[i] - '0' <= 9 ))
//                {
//                	
//				    exp = exp*10 + int(s[i] - '0');
//				    i++;
//                }
//                exp = exp*expsign;
//                break;
//                
//                
//			}
            
            else if(s[i] == ' ') break;
            
            else {
			       break;
				   //cout<<"Invalid Input"<<endl;
				   //return 0; 
			
		         }
        }
//        while(exp > 0)
//        {
//        	num = num * 10;
//        	exp--;
//		}
//		
//		while(exp < 0)
//        {
//        	num = num * 0.1;
//        	exp++;
//		}

        return sign*(num/decimal);
        
    }

int main(){
	string s;
	getline(cin,s);
	cout<<setprecision(10)<<Atof(s);
}
    