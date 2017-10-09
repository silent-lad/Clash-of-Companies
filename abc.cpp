#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std ;
int c;

class MNC {  public:
    float moneym ;
    MNC()
    {
        moneym=10000 ;
    }
    
} ;


class bank { public:
    float moneyb ;
     bank()
    {
        moneyb=10000 ;
    }
    
           };

class loan { public:
    int cycle,cstart,cend ;
    float intrest,amount ;
    float pay;
               loan()
    
    {
        cycle=0; intrest=0; cstart=-1 ; cend=-1 ; amount=0; pay=0;
    }
        void inloan()
    {
        cout<<"\nenter no. of cycles:" ;
        cin>>cycle ;
        cout<<"\nenter amount:" ;
        cin>>amount ;
        cout<<"\nenter intrest %;" ;
        cin>>intrest ;
        cstart=c+1 ;
        cend=c+1+cycle ;
        pay=(amount+(amount*intrest/100))/cycle  ;
    }

           };

class asset { public:
    int ownerid,start ;
    float sp,cp,profit,bp;
    
    asset()
    {
        ownerid=0 ;
        sp=0; cp=0 ; profit=0 ; bp=0 ; start=100;
    }

    void inasset()
    {   cout<<"\nenter ownerid" ;
        cout<<"\nenter profit:" ;
        cin>>profit;
        cout<<"\nenter price bought:";
        cin>>cp;
        cout<<"\nenter selling price:" ;
        cin>>sp ;
        start=c+1;
        
    }


};


int main()
{  
    MNC mnc[1] ;
    bank b[1] ; loan l[1][1]; asset a[10] ;
    for(c=0;c<2;c++)
    {  cout<<"\nsubcycle"<<c+1 ;
       if((c<=4)||((c>=8)&&(c<=12))||((c>=16)&&(c<=20)))
       {
           for(int i=0;i<1;i++)
           {
               cout<<"\nMNC"<<i+1<<"\n"<<"balance:"<<mnc[i].moneym<<"\nloan taken? y/n" ;
               char c;
               cin>>c;
               if((c=='y')||(c=='y'))
               {
                   cout<<"\n enter bank no." ;
                   int x;
                   cin>>x;
                   x=x-1;
                   l[i][x].inloan() ;
                   b[x].moneyb=b[x].moneyb-l[i][x].amount ;
                   
               }
               for(int j=0;j<1;j++)
               {          cout<<"\nbank"<<j+1<<"balance:"<<b[j].moneyb ;
                   
                          if((c>=(l[i][j].cstart))&&(c<=(l[i][j].cend)))
                      
                          b[j].moneyb=b[j].moneyb+l[i][j].pay ; mnc[i].moneym=mnc[i].moneym-l[i][j].pay ;
                      
               }
               
           }
           for(int d=0;d<10;d++)
           {
               if(c>=a[d].start) { mnc[a[d].ownerid-1].moneym=mnc[a[d].ownerid-1].moneym+a[d].profit ;}
               
               
               
           }
           

       }
      else
       {
           for(int i=0;i<1;i++)
           {   cout<<"\nMNC"<<i+1<<"\nbalance:"<<mnc[i].moneym ;
               
               cout<<"\nwant to buy asset?y/n";
               char ch;
               cin>>ch;
                if((ch=='y')||(ch=='Y'))
                {
                    cout<<"\nenter assest id" ;
                    int q ;
                    cin>>q ;
                    q--;
                    a[q].inasset() ;
                    mnc[a[q].ownerid-1].moneym=mnc[a[q].ownerid-1].moneym-a[q].bp-a[q].cp ;
                    
                    
                    
           
                }
               for(int j=0;j<1;j++)
               {          cout<<"\nbank"<<j+1<<"balance:"<<b[j].moneyb ;
                   
                   if((c>=(l[i][j].cstart))&&(c<=(l[i][j].cend)))
                       
                       b[j].moneyb=b[j].moneyb+l[i][j].pay ; mnc[i].moneym=mnc[i].moneym-l[i][j].pay ;
                   
               }
               

               
           }
           for(int d=0;d<10;d++)
           {
               if(c>=a[d].start) { mnc[a[d].ownerid-1].moneym=mnc[a[d].ownerid-1].moneym+a[d].profit ;}
           
       
      
           }
    
     
       }
    
    }
}
