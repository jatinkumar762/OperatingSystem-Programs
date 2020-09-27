#include<stdio.h>
#include<string.h>

char pName[20][15],c[20];
int bTime[20],aTime[20],tot_Pro,Twt,Ttt,Wt[10];
float Awt,Att;

//DISPLAYING THE GANTT CHART
void Gantt_chart()
{
    int i;
    printf("\n\n\t\t\tGANTT CHART\n");
    printf("\n-----------------------------------------------------------\n");
    for(i=1;i<=tot_Pro;i++)
        printf("|\t%s\t",pName[i]);
    printf("|\t\n");   
    printf("\n-----------------------------------------------------------\n");
    printf("\n");
    for(i=1;i<=tot_Pro;i++)
        printf("%d\t\t%d|",Wt[i],(Wt[i]+bTime[i]));
    printf("\n-----------------------------------------------------------\n");
    printf("\n");
 }
 
 
//CALCULATING AVERAGE WAITING TIME AND AVERAGE TURN AROUND TIME
void Calculate()
{
    int i,T;  //T strt from Intial Time & goes to End
    //For the 1st process
    Wt[1]=aTime[1],T=aTime[1];
    for(i=2;i<=tot_Pro;i++)
    {
    	T+=bTime[i-1];
    	if( (T-aTime[i])>=0 )
    	{
    	   Wt[i]=T;	
    	}
    	else
     	{
    		T=(aTime[i]);
    		Wt[i]=T;
    	}
    }
    for(i=1;i<=tot_Pro;i++)
    {
        Twt=Twt+(Wt[i]-aTime[i]);
        Ttt=Ttt+((Wt[i]+bTime[i])-aTime[i]);
    }
    Att=(float)Ttt/tot_Pro;
    Awt=(float)Twt/tot_Pro;
    printf("\n\n Average Turn around time=%3.2f ms ",Att);
    printf("\n\n AverageWaiting Time=%3.2f ms",Awt);
    
}
int main()
{
	int i,j,tmp;
	
	//---------Take Input--------------//
	printf("Enter the Total No of Process :");
	scanf("%d",&tot_Pro);
	for(i=1;i<=tot_Pro;i++)
	{
	   printf("\nEnter the Name of the Process:");
	   scanf("%s",pName[i]);	
	   printf("\nEnter the Burst time for the Process %s :",pName[i]);
	   scanf("%d",&bTime[i]);	
	   printf("\nEnter the Arrival time for the Process %s :",pName[i]);
	   scanf("%d",&aTime[i]);
	}
	
	//--------Short Process According to Arrival Time---------//
	for(i=1;i<=tot_Pro-1;i++)
	{
		for(j=i+1;j<=tot_Pro;j++)
		{
			if(aTime[i]>aTime[j])
			{
			   	tmp=bTime[i];
			   	bTime[i]=bTime[j];
			   	bTime[j]=tmp;
			   	
			   	tmp=aTime[i];
			   	aTime[i]=aTime[j];
			   	aTime[j]=tmp;
				
				strcpy(c,pName[i]);
				strcpy(pName[i],pName[j]);
				strcpy(pName[j],c);
			}
		}
	}

	Calculate();
    Gantt_chart();
	return 0;
}
