//
//  main.cpp
//  Intervals_Project1_B
//
//  Created by ARYAN  PILLAI on 2018-10-21.
//  Copyright © 2018 ARYAN  PILLAI. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include<stdio.h>

void interval_calculator();
void interval_calculator()
{
    std::string operation;
    
    double ii[2];// here ii stands for immediate interval
    double test[2];// here test is used to do the functions on ii making the code easier to understand
    //test[0]=NULL;
    //test[1]=NULL;
    double iflag=0;
    double mflag=0;
    double msi[2];//here msi stands for memory stored interval;
    double scalar=0;
    double owi[2]; // here owi stands for operation with interval
    
    do{
        std::cout<<"input :> ";
        std::cin>> operation;
        
        if(operation=="exit")
        {
            break;
        }
        
        else if (operation=="enter")
        {
            std::cin>>ii[0];
            std::cin>>ii[1];
            
            if(ii[0]<=ii[1])
            {std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
                test[0]=ii[0];
                test[1]=ii[1];
                iflag=1;
            }
            else
            {  std::cout<<"Error: invalid interval as "<<ii[0]<<" > "<<ii[1]<<std::endl;
                if(iflag==0)
                std::cout<<"--"<<::std::endl;
                else{
                   ii[0]=test[0];
                    ii[1]=test[1];
                    std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
                }
            }
        }
            
        else if (operation=="negate")
        {
            if(iflag==0)
                std::cout<<"--"<<::std::endl;
            else{
            test[0]=-ii[1];
                test[1]=-ii[0];
                ii[0]=test[0];
                ii[1]=test[1];
                std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;}
            
        }
        
        else if(operation=="invert")
        {
            if(iflag==0)
            {
                std::cout<<"--"<<std::endl;
            }
            else if((ii[0]<0 and ii[1]<0) || (ii[0]>0 and ii[1]>0))
            {
                test[0]=1/ii[1];
                test[1]=1/ii[0];
                ii[0]=test[0];
                ii[1]=test[1];
                std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
            else{
                std::cout<<"Error: division by zero"<<std::endl;
                std::cout<<"--"<<std::endl;
                iflag=0;
            }
        }
        else if(operation=="ms")
        {
            
            if (iflag==0)
                std::cout<<"--"<<std::endl;
            else
            {msi[0]=ii[0];
                msi[1]=ii[1];
                mflag=1;
                std::cout<<"["<<msi[0]<<", "<<msi[1]<<"]"<<std::endl;}
        }
        else if(operation=="mr")
        {
            if(iflag==0)
                std::cout<<"--"<<std::endl;
            
            else if(mflag==0 and iflag!=0)
                std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            else
            {
                ii[0]=msi[0];
                ii[1]=msi[1];
                mflag=1; iflag=1;
                std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
        }
        else if(operation=="mc")
        {
            if(iflag==0)
                std::cout<<"--"<<std::endl;
            else
            {
                msi[0]=0;
                msi[1]=0;
                mflag=0;
                std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
        }
        else if(operation=="m+")
        {
            if(iflag==0)
                std::cout<<"--"<<std::endl;
            
            else
            {
                test[0]=ii[0]+msi[0];
                test[1]=ii[1]+msi[1];
                msi[0]=test[0];
                msi[1]=test[1];
                std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
        }
        else if(operation=="m-")
        {
            if(iflag==0 or mflag==0)
                std::cout<<"--"<<std::endl;
            
            else
            {
                test[0]=msi[0]-ii[0];
                test[1]=msi[1]-ii[1];
                if(test[0]<test[1])
                {msi[0]=test[0];
                    msi[1]=test[1];}
                else{
                    msi[0]=test[1];
                    msi[1]=test[0];
                }
                std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
        }
        else if(operation=="scalar_add")
        {
            
            std::cin>>scalar;
            if(iflag==0 )
                std::cout<<"--"<<std::endl;
            
            else
            {
               ii[0]=ii[0]+scalar;
               ii[1]=ii[1]+scalar;
                std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
            }
        else if(operation=="scalar_subtract")
        {
            
            std::cin>>scalar;
            if(iflag==0 )
                std::cout<<"--"<<std::endl;
            
            else
            {
                ii[0]=ii[0]-scalar;
                ii[1]=ii[1]-scalar;
                std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
            }
        else if(operation=="scalar_multiply")
        {
            
            std::cin>>scalar;
            if(iflag==0 )
                std::cout<<"--"<<std::endl;
            else{
          if(scalar>=0)
            {
                ii[0]=ii[0]*scalar;
                ii[1]=ii[1]*scalar;
                std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
            else if(scalar<0)
            {
                test[0]=ii[0]*scalar;
                test[1]=ii[1]*scalar;
                ii[0]=test[1];
                ii[1]=test[0];
                std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
            }}
        
        else if (operation=="scalar_divide")
        {
            
            std::cin>>scalar;
            if(iflag==0 )
                std::cout<<"--"<<std::endl;
            else if(scalar!=0){
            
                test[0]=ii[0]/scalar;
                test[1]=ii[1]/scalar;
                if(test[0]<test[1])
                {
                    ii[0]=test[0];
                    ii[1]=test[1];
                }
                else{
                    ii[1]=test[0];
                    ii[0]=test[1];
                }
                std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
            else
            {
                std::cout<<"Error: division by zero"<<std::endl;
                std::cout<<"--"<<std::endl;
                iflag=0;
            }
            }
        else if(operation=="scalar_divided_by")
        {
            std::cin>>scalar;
            if(iflag==0)
                std::cout<<"--"<<std::endl;
            
            else{
            if((ii[0]<0 and ii[1]<0) or (ii[0]>0 and ii[1]>0))
               {
                   test[0]=scalar/(ii[0]);
                   test[1]=scalar/(ii[1]);
                   if(test[0]<test[1])
                   {ii[0]=test[0];
                       ii[1]=test[1];}
                   else{
                       ii[0]=test[1];
                       ii[1]=test[0];
                   }
                   std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
               }
            else{
                std::cout<<"Error: division by zero"<<std::endl;
                 std::cout<<"--"<<std::endl;
                iflag=0;
            }
            }}
        
        else if(operation=="interval_add")
        {
            std::cin>>owi[0]
                    >>owi[1];
            
            if((owi[0]>owi[1]))
            {
                std::cout<<"Error: invalid interval as "<<owi[0]<<" > "<<owi[1]<<std::endl;
                
                if(iflag==0)
                    std::cout<<"--"<<std::endl;
                else
                    std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
            else if(iflag==0 )
                std::cout<<"--"<<std::endl;
            else
            {
                    ii[0]=ii[0]+owi[0];
                    ii[1]=ii[1]+owi[1];
                    std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
        }
        else if(operation=="interval_subtract")
        {
            std::cin>>owi[0]
            >>owi[1];
            
            if((owi[0]>owi[1]))
            {
                std::cout<<"Error: invalid interval as "<<owi[0]<<" > "<<owi[1]<<std::endl;
                
                if(iflag==0)
                    std::cout<<"--"<<std::endl;
                else
                    std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
            else if(iflag==0 )
                std::cout<<"--"<<std::endl;
            else
            {
                ii[0]=ii[0]-owi[1];
                ii[1]=ii[1]-owi[0];
                std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
        }
    
        else if(operation=="interval_multiply")
        {
            std::cin>>owi[0]
            >>owi[1];
            
            if((owi[0]>owi[1]))
            {
                std::cout<<"Error: invalid interval as "<<owi[0]<<" > "<<owi[1]<<std::endl;
                
                if(iflag==0)
                    std::cout<<"--"<<std::endl;
                else
                    std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
            else if(iflag==0 )
                std::cout<<"--"<<std::endl;
            else
            {
               
                double a=std::min({ii[0]*owi[0],ii[1]*owi[0], ii[1]*owi[0],ii[1]*owi[1]});
               
                double c=std::max({ii[0]*owi[0],ii[1]*owi[0], ii[1]*owi[0],ii[1]*owi[1]});
                
                ii[0]=a;
                ii[1]=c;
                std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
        }
        else if (operation=="interval_divide")
        {
            std::cin>>owi[0]
                >>owi[1];
            
            if((owi[0]>owi[1]))
            {
                std::cout<<"Error: invalid interval as "<<owi[0]<<" > "<<owi[1]<<std::endl;
                
                if(iflag==0)
                    std::cout<<"--"<<std::endl;
                else
                    std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
            else if(iflag==0 )
                std::cout<<"--"<<std::endl;
            else if((owi[0]<0 and owi[1]<0) or (owi[0]>0 and owi[1]>0))
            {
                
                double a=std::min({(ii[0]/owi[0]),(ii[1]/owi[0]),(ii[1]/owi[0]),(ii[1]/owi[1])});
                double c=std::max({(ii[0]/owi[0]),(ii[1]/owi[0]),(ii[1]/owi[0]),(ii[1]/owi[1])});

                ii[0]=a;
                ii[1]=c;
                std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
            else{
                std::cout<<"Error: division by zero"<<std::endl;
                std::cout<<"--"<<std::endl;
                iflag=0;
                owi[0]=0;
                owi[0]=0;
            }
        }
        else if(operation=="integers")
        {
            if(iflag==0)
                std::cout<<"--"<<std::endl;
            
            else if(ii[1]-ii[0]>=1)
            {
            double a=std::ceil(ii[0]);
            double b=std::floor(ii[1]);
            std::cout<<a;
            ++a;
            while(a<=b)
            {
                std::cout<<", "<<a++;
            }
            std::cout<<std::endl;
             std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
            else{
                 std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
        }
        else if(operation=="intersect")
        {
            std::cin>>owi[0]
            >>owi[1];
            
            if((owi[0]>owi[1]))
            {
                std::cout<<"Error: invalid interval as "<<owi[0]<<" > "<<owi[1]<<std::endl;
                
                if(iflag==0)
                    std::cout<<"--"<<std::endl;
                else
                    std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
            else if(iflag==0 )
                std::cout<<"--"<<std::endl;
            
            else
            {
                if(owi[0]>ii[1] or owi[1]<ii[0])
                {
                    iflag=0;
                    std::cout<<"--"<<std::endl;
                }
                else if(owi[0]<ii[0] and owi[1]>ii[1])
                    std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
                else if(owi[0]>=ii[0] and owi[1]<=ii[1])
                {
                    ii[1]=owi[1];
                    ii[0]=owi[0];
                    std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
                }
                else if(owi[0]<=ii[0] and owi[1]<=ii[1])
                {
                    ii[1]=owi[1];
                    std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
                }
                else if(owi[0]>=ii[0] and owi[1]>=ii[1])
                {
                    ii[0]=owi[0];
                    std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
                }
                
            }
        }
        else if(operation=="cartesian_integers")
        {
            std::cin>>owi[0]
            >>owi[1];
            
            if((owi[0]>owi[1]))
            {
                std::cout<<"Error: invalid interval as "<<owi[0]<<" > "<<owi[1]<<std::endl;
                
                if(iflag==0)
                    std::cout<<"--"<<std::endl;
                else
                    std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
            }
            else if(iflag==0 )
                std::cout<<"--"<<std::endl;
            else
            {
                if((ii[1]-ii[0]>=1) and (owi[1]-owi[0]>=1))
                {
                    //double a=std::ceil(ii[0]);
                    double b=std::floor(ii[1]);
                    //double c=std::ceil(owi[0]);
                    double d=std::floor(owi[1]);
        
                    for(double a=std::ceil(ii[0]);a<=b;a++)
                    {
                        for(double c=std::ceil(owi[0]);c<=d;c++)
                        {
                            if(a==b and c==d)
                                break;
                            std::cout<<"("<<a<<","<<c<<")"<<", ";
                            
                        }
                    }
                    std::cout<<"("<<b<<","<<d<<")";
                    std::cout<<std::endl;
                    std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;
                }
                else{
                    std::cout<<"["<<ii[0]<<", "<<ii[1]<<"]"<<std::endl;//cartesian_integers 4.5 6.3 enter 2.99 4.99
                }
            }
            
        }
        else{
            std::cout<<"Error: illegal command"<<std::endl;
        }
    }while(operation!="exit");
    std::cout<<"Bye bye: Terminating interval calculator program."<<std::endl;
    
    

}
int main() {
    interval_calculator();
    return 0;
}

