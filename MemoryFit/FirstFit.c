#include<stdio.h>  
#include<conio.h>

int main()
{
	int *Frag,*Files,*Block,nFile,nFrag,nBlock,i,j;
	int *FFile,*FBlock;  
	//FFile -File Has Assigned a Block or not
	//FBlock -Block is Assigned to a File or not
	int tmp;
	//Take Input of Block Size Information
	printf("\nEnter the Number of Blocks:");
	scanf("%d",&nBlock);
	Block=(int*)malloc(sizeof(int)*nBlock);
    FBlock=(int*)malloc(sizeof(int)*nBlock);
	for(i=1;i<=nBlock;i++)
	{
	  printf("\nBlock-%d Size :",i);
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
	  printf("\nFile-%d Size :",i);
	  scanf("%d",&Files[i]);
    }
	
	for(i=1;i<=nFile;i++)
	{
		for(j=1;j<=nBlock;j++)
		{
	        if(FBlock[j]!=1)
			{
			   tmp=Block[j]-Files[i];
			   if(tmp>=0)
			   {
			   	  FBlock[j]=1;
			   	  FFile[i]=j;
			   	  Frag[i]=tmp;
			   	  break;
			   }				
			}		
		}
	}
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
