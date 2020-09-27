#include<stdio.h>
#include<conio.h>
#include<string.h>
struct Process
{
	char name[10];
	int arrT;
	int burT;
	int rem;
	int finishT;
	int waitT;
	int turnA;
	int count;
};
typedef struct Process Process;

int n,tSlice,tTotal,totWt=0,totTa=0;
Process *p;
char ganttChartN[10][10];
int ganttChartT[10];

int checkProcess(int);
void printGanttChart();

int main()
{
	Process tmp;
	int i,j,k;
	printf("\nEnter the number of process :");
	scanf("%d",&n);	
	printf("\nEnter the time slice of the CPU :");
	scanf("%d",&tSlice);
	
	p=(Process*)malloc(sizeof(Process)*n);
	/*
	ganttChartN=(char**)malloc(sizeof(char*)*n);
	for(i=0;i<n;i++)
	ganttChartN[i]=(char*)malloc(sizeof(char)*10);
	
	ganttChartT=(int*)malloc(sizeof(int)*n);
	*/
	for(i=0;i<n;i++)
	{
		printf("\nProcess-%d Details :\n",i+1);
		printf("Enter the Name :");
		scanf("%s",&p[i].name);
		printf("Enter the Arrival Time :");
		scanf("%d",&p[i].arrT);
		printf("Enter the Burst Time :");
		scanf("%d",&p[i].burT);	
		
		p[i].rem=p[i].burT;
		p[i].finishT=0;
		p[i].waitT=0;
		p[i].turnA=0;
		p[i].count=1;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].arrT>p[j+1].arrT)
			{
				tmp=p[j];
				p[j]=p[j+1];
				p[j+1]=tmp;
			}		
		}
	}
    
    i=0,k=0;
    tTotal=p[0].arrT;
    
    while(checkProcess(n)==1)
    {
    	if(p[i].rem!=0)
    	{
    			if(p[i].rem-tSlice>=0)
    			{
    	   			p[i].rem=(p[i].rem-tSlice);	
    	   			
    	   			if(p[i].count==1)
    	   			{
                        p[i].waitT+=(tTotal-p[i].arrT);
                    }
                    else
                    {
                        p[i].waitT+=(tTotal-p[i].finishT);	
                    }
                    tTotal+=tSlice;
                    
                    p[i].finishT=tTotal;    
                    p[i].turnA=(tTotal-p[i].arrT);    
				    p[i].count++;  
					
					strcpy(ganttChartN[k],p[i].name);
					ganttChartT[k++]=p[i].finishT; 
    			}
    			else 
    			{
    	            if(p[i].count==1)
    	   			{
                        p[i].waitT+=(tTotal-p[i].arrT);
                    }
                    else
                    {
                        p[i].waitT+=(tTotal-p[i].finishT);	
                    }			
    				tTotal+=p[i].rem;
    				
    			    p[i].finishT=tTotal;    
                    p[i].turnA=(tTotal-p[i].arrT);    
				    p[i].count++; 
				   	p[i].rem=0;
				   	
				   	strcpy(ganttChartN[k],p[i].name);
					ganttChartT[k++]=p[i].finishT;
    			}
       }
       i++;
       if(i==n)
       i=0;
    }
    
    for(i=0;i<n;i++)
    {
      	totWt+=p[i].waitT;
      	totTa+=p[i].turnA;
    }
    
    printf("\nTotal Time :%d",tTotal);
    
    for(i=0;i<n;i++)
    {
    	printf("\n\n");
    	printf("** Process %s Details **",p[i].name);
    	printf("\nTurn Around Time : %d",p[i].turnA);
    	printf("\nWaiting Time   : %d",p[i].waitT);
    }
    
    printf("\n\n");
    printf("\nAverage Waiting Time :%f",(float)totWt/n);
    printf("\nAverage Turn Around Time :%f",(float)totTa/n);
    
    printf("\n\n\t***Gantt Chart***\n\n");
    for(i=0;i<k;i++)
    printf("|   %s   ",ganttChartN[i]);
    printf("|\n");
    
    printf("%d",p[0].arrT);
    for(i=0;i<k;i++)
    printf("        %d",ganttChartT[i]);
	return 0;
}

int checkProcess(int s)
{
	int i;
	for(i=0;i<s;i++)
	{
		if(p[i].rem!=0)
		return 1;
	}
	return 0;
}


