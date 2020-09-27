#include<stdio.h>
#include<conio.h>

int main()
{
	int *Frag,*Files,*Block,nFile,nFrag,nBlock,i,j;
	int *FFile,*FBlock;
	int tmp,lowest;
	
	//Take Input of Block Size Information
	printf("\nEnter the Number of Blocks:");
	scanf("%d",&nBlock);
	
	Block=(int*)malloc(sizeof(int)*nBlock);
    FBlock=(int*)malloc(sizeof(int)*nBlock);  //File Index
    
	for(i=1;i<=nBlock;i++)
	{
	  printf("Block-%d Size :",i);
	  scanf("%d",&Block[i]);
    }
     
    //Take Input Of File Information
	printf("\nEnter the Number of File:");
	scanf("%d",&nFile);
	
	nFrag=nFile;
	Frag=(int*)malloc(sizeof(int)*nFrag);  //Contains the Fragmentation Value
	Files=(int*)malloc(sizeof(int)*nFile); //Contains the File size
	FFile=(int*)malloc(sizeof(int)*nFile); //Contains the Block Number
	 
	for(i=1;i<=nFile;i++)
	{
		FFile[i]=-1;
	}
	
	for(i=1;i<=nFile;i++)
	{
	  printf("File-%d Size :",i);
	  scanf("%d",&Files[i]);
    }
	
	for(i=1;i<=nFile;i++)
	{
		lowest=9999;
		for(j=1;j<=nBlock;j++)
		{
	        if(FBlock[j]!=1)
			{
			   tmp=Block[j]-Files[i];
			   if(tmp>=0)
			   {
			   	  if(lowest>tmp)
			   	  {
			   	  	FFile[i]=j;
			   	  	Frag[i]=tmp;
			   	  	lowest=tmp;
			      }
			   }				
			}		
		}
		
		if(FFile[i]!=-1)
		FBlock[FFile[i]]=1;
	}
	
	printf("\n\t\t****BestFit Memory Management****\n");
	printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
	for(i=1;i<=nFile;i++)
	{
	   if(FFile[i]!=-1)  //Check File is assigned a block
	   printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,Files[i],FFile[i],Block[FFile[i]],Frag[i]);
	   else
	   printf("\n%d\t\t%d\t\t%s\t\t%s\t\t%s",i,Files[i],NULL,NULL,NULL);
	}
	
	return 0;
}
