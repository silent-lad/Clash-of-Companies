#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std ;
int c;
class MNC 
{  
	public:
    long long moneym ;
    MNC()
    {
        moneym=6000000 ;
    }
};


class bank { 
	public:
    long long moneyb ;
     bank()
    {
        moneyb=15000000 ;
    }
    
           };

class loan { public:
    int cycle,cstart,cend ;
    long double intrest,amount ;
    long double pay;
               loan()
    
    {
        cycle=0; intrest=0; cstart=-1 ; cend=-1 ; amount=0; pay=0;
    }
        void inloan()
    {
        cout<<"\nEnter no. of cycles:" ;
        cin>>cycle ;
        cout<<"\nEnter amount:" ;
        cin>>amount ;
        cout<<"\nEnter intrest %: " ;
        cin>>intrest ;
        cstart=((c/4)*4)+3 ;
        cend=cstart+1+cycle ;
        pay=(amount/cycle)+(amount*intrest/100)/cycle ;
    }

           };

class asset { public:
    int ownerid,start ;
    double sp,cp,profit,bp;
    
    asset()
    {
        ownerid=-1 ;
        sp=0; cp=0 ; profit=0 ; bp=0 ; start=100;
    }

    void inasset()
    {   cout<<"\nEnter profit:" ;
        cin>>profit;
        cout<<"\nEnter price bought:";
        cin>>cp;
        cout<<"\nEnter selling price:" ;
        cin>>sp ;
        start=c;
        
    }
    

};


int main()
{  
    MNC mnc[11] ;
    bank b[7] ; loan l[11][7]; asset a[32] ;
    for(c=0;c<50;c++)
    {  cout<<"\n\nSubcycle : "<<c+1<<"\n" ;
       if((c<4)||((c>=8)&&(c<12))||((c>=16)&&(c<20))||((c>=24)&&(c<28))||((c>=32)&&(c<36))||((c>=40)&&(c<44)))
       {
           for(int i=0;i<11;i++)
           {
               cout<<"\nMNC :"<<i+1<<" balance: "<<mnc[i].moneym<<"\nLoan taken? y/n " ;
               char c1;
               cin>>c1;
               if((c1=='y')||(c1=='y'))
               {
                   cout<<"\nEnter bank no:" ;
                   int x;
                   cin>>x;
                   x=x-1;
                   if(c>l[i][x].cend)
                   { 
                   l[i][x].inloan() ;
                   b[x].moneyb=b[x].moneyb-l[i][x].amount ;
                   mnc[i].moneym=mnc[i].moneym+l[i][x].amount ;
                   }
                   else
                    {cout<<"\nloan not repaid\n" ; 
                   

                    }
				}
               for(int j=0;j<7;j++)
               {          
                   
                   if((c>=(l[i][j].cstart))&&(c<(l[i][j].cend-1)))
                       
                       {b[j].moneyb=b[j].moneyb+l[i][j].pay ;} 


                    if((c>=(l[i][j].cstart))&&(c<(l[i][j].cend-1)))
                        mnc[i].moneym=mnc[i].moneym-l[i][j].pay ;
                        cout<<"\nbank "<<j+1<<" balance: "<<b[j].moneyb ;
               }
           
                cout<<"\nMNC :"<<i+1<<" \nWant to sell asset ?y/n" ;
                char c2;
                cin>>c2 ;
                if((c2=='y')||(c2=='Y'))
                 {

                 	cout<<"\nEnter id of asset to be sold: " ;
                 	int f,y1;
                 	cin>>f;
                 	f--;
                 	if((a[f].ownerid-1)<0) {cout<<"\nAsset unsold" ; }
                 	
                    else
                    {	y1=a[f].ownerid-1 ;
                 	mnc[y1].moneym=mnc[y1].moneym+a[f].sp ;
                 	a[f].ownerid=-1 ;
                 	cout<<"\nAsset :"<<f+1<<" Sold" ;
                 }
                 }
                cout<<"\nMNC :"<<i+1<<" \nWant to sell share ?y/n" ;
                char c3;
                cin>>c3;
                if((c3=='y')||(c3=='Y'))
                 {
					 int md,bank_id;
					 cout<<"\nEnter the amount of share sold: ";
					 cin>>md;
					 cout<<"\nEnter Bank number: ";
					 cin>>bank_id;
					 
					
					 
					 
					 mnc[i].moneym=mnc[i].moneym+md;
					 b[bank_id-1].moneyb=b[bank_id-1].moneyb-md;
				 }




			}
                  
           for(int d=0;d<32;d++)
           {
               if((c>=a[d].start)&&(a[d].ownerid>=0)) { mnc[a[d].ownerid-1].moneym=mnc[a[d].ownerid-1].moneym+a[d].profit ;}
               
                
               
           }
          if((c+1)%4==0)
          { cout<<"\n\nAfter end of subcycle :"<<c+1 ;
            for(int i=0;i<11;i++)
            {
               cout<<"\nMNC :"<<i+1<<" Balance: "<<mnc[i].moneym ;
            }
            for(int j=0;j<7;j++)
            {
              cout<<"\nBank :"<<j+1<<" Balance: "<<b[j].moneyb ;
            }
            

          } 

       }
      else
      
       {
           for(int i=0;i<11;i++)
           {   cout<<"\nMNC "<<i+1<<" balance:"<<mnc[i].moneym ;
               
               cout<<"\nWant to buy asset?y/n";
               char ch;
               cin>>ch;
                if((ch=='y')||(ch=='Y'))
                {
                    cout<<"\nEnter assest id :" ;
                    int q ;
                    cin>>q ;
                    q--;
                    a[q].inasset() ;
                    a[q].ownerid=i+1 ;

                    mnc[a[q].ownerid-1].moneym=mnc[a[q].ownerid-1].moneym-a[q].bp-a[q].cp ;
                    
                    
                    
           
                }
               for(int j=0;j<7;j++)
               {          
                   
                   if((c>=(l[i][j].cstart))&&(c<(l[i][j].cend-1)))
                       
                       {b[j].moneyb=b[j].moneyb+l[i][j].pay ;} 


                    if((c>=(l[i][j].cstart))&&(c<(l[i][j].cend-1)))
                        mnc[i].moneym=mnc[i].moneym-l[i][j].pay ;
                        cout<<"\nbank "<<j+1<<" balance: "<<b[j].moneyb ;
               }
               

               
           

           }
           for(int d=0;d<32;d++)
           {
               if((c>=a[d].start)&&(a[d].ownerid>=0)) { mnc[a[d].ownerid-1].moneym=mnc[a[d].ownerid-1].moneym+a[d].profit ;}
           
       
      
           }
    
     
       }
    
    }
}


