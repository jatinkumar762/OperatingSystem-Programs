#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>

int total,i,n;
float avg;

class sjf
{
 int t,bt[12],wt[12];
 char p[12][6],tp[6];
 public:
 sjf()
 {
  wt[0]=0;
  total=0;
  avg=0;
 }
 void input(int n);
 void apply();
 void display();
};

 void sjf::input(int n)
 {
  for(i=0;i<n;i++)
  {
   cout<<"Enter process "<<i+1<<" name :";
   cin>>p[i];
   cout<<"Enter process time :";
   cin>>bt[i];
  }
 }

 void sjf::apply()
 {
  for(int i=0;i<n-1;i++)
   for(int j=i+1;j<n;j++)
    if(bt[i]>bt[j])
    {
     t=bt[j];
     bt[j]=bt[i];
     bt[i]=t;
     strcpy(tp,p[j]);
     strcpy(p[j],p[i]);
     strcpy(p[i],tp);
    }
  for(i=1;i<n;i++)
  {
   wt[i]=wt[i-1]+bt[i-1];
   total=total+wt[i];
  }
  avg=(float)total/n;
 }

 void sjf::display()
 {
  cout<<"P_name\tP_time\tW_time\n";
  for(i=0;i<n;i++)
  cout<<p[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\n";
 }

int main()
{
 sjf sjf;
 //clrscr();
 cout<<"Enter no. of processes :";
 cin>>n;
 sjf.input(n);
 sjf.apply();
 sjf.display();
 cout<<"total waiting time :"<<total<<"\n";
 cout<<"Average waiting Time :"<<avg;
 getch();
 return 0;
}
