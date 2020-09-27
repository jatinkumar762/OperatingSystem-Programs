#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int isIdent(char ch);
int isOper(char ch);
int isDel(char ch);
void removeDuplicate();

char op[8]={'+','-','*','/','=','<','>','%'}; 
char del[9]={'}','{',';','(',')','[',']',',','#'}; 
char *key[]={"int","void","main","char","float","FILE"};

int idi=0,idj=0,j,opi=0,opj=0,liti=0,deli=0;
int uniqIdenti=0,uniqOpi=0,uniqDeli=0,keyi=0,consi=0;

char uniqIdent[20][20],uniqOp[20][20],uniqDel[20],keyword[20][20];
char ident[20][20],literal[20][30],lit[30],oper[20][20],delem[20],constant[20][20];

void lexAnalysis(char *str)
{
	int i=0,l;
	while(str[i]!='\0')
	{
		if(isIdent(str[i]))  // Check For Identifier
		{
			while(isIdent(str[i]))
			{
				ident[idi][idj++]=str[i++];
			}
			ident[idi][idj]='\0';
			idi++,idj=0;
		}
		else
	 if(str[i]=='"')         //for literals 
      { 
         l=0;
         lit[l++]=str[i]; 
         for(j=i+1;str[j]!='"';j++) 
         { 
            lit[l++]=str[j]; 
         } 
         lit[l++]=str[j];
		 lit[l]='\0'; 
         strcpy(literal[liti++],lit); 
         i=j+1; 
         
      } 
	  else
	  if(isOper(str[i]))    //Check For Operator
	  {
			while(isOper(str[i]))
			{
			  oper[opi][opj++]=str[i++]; 
			}
	    	oper[opi][opj]='\0';
	    	opi++,opj=0;
			
	  }
		else
		if(isDel(str[i]))     //Check For Delimeter
		{
		    while(isDel(str[i])) 
            { 
              delem[deli++]=str[i++]; 
            } 
			delem[deli]='\0';	
		}
		else
		{
			i++;
		}		
	}
}

int isIdent(char ch)  //Check for Identifier
{
    if(isalpha(ch)||ch=='_'||isdigit(ch)||ch=='.')
	return 1;
	else
	return 0;	
}

int isOper(char ch)   //Check for Operator
{
   int f=0,i;
   for(i=0;i<8&&!f;i++) 
   { 
    if(ch==op[i]) 
    f=1; 
   } 
   return f; 	
}

int isDel(char ch)    //Check for Delimeter
{
   int f=0,i; 
   for(i=0;i<9&&!f;i++) 
   { 
    if(ch==del[i]) 
     f=1; 
   } 
   return f; 	
}

int isKey(char *str)  //check for keyword
{
   int i,f=0; 
   for(i=0;i<6;i++) 
   { 
      if(!strcmp(key[i],str)) 
      f=1; 
   } 
  return f; 
	
}

void removeDuplicate()
{
	int i,j,flag=1;
    for(i=0;i<deli;i++)    //removing duplicate delemeters 
    {
        flag=1;
		for(j=0;j<uniqDeli;j++)
		{
			if(delem[i]==uniqDel[j])
			{
				flag=0; break;
			}
		}	
    	if(flag)
    	uniqDel[uniqDeli++]=delem[i];	
    }
    uniqDel[uniqDeli]='\0';
	
	for(i=0;i<idi;i++)    //removing duplicate identifiers 
    {
        flag=1;
		for(j=0;j<uniqIdenti;j++)
		{
			if(!strcmp(ident[i],uniqIdent[j]))
			{
				flag=0; break;
			}
		}	
    	if(flag)
    	strcpy(uniqIdent[uniqIdenti++],ident[i]);	
    }
    
	
	for(i=0;i<opi;i++)    //removing duplicate operator 
    {
        flag=1;
		for(j=0;j<uniqOpi;j++)
		{
			if(!strcmp(oper[i],uniqOp[j]))
			{
				flag=0; break;
			}
		}	
    	if(flag)
    	strcpy(uniqOp[uniqOpi++],oper[i]);	
    }
 
}

void final()
{
    int i=0;
    idi=0;
    
    for(i=0;i<uniqIdenti;i++)
    {
      if(isKey(uniqIdent[i]))   //Identify Keyword
	  strcpy(keyword[keyi++],uniqIdent[i]);
	  else
	  if(isdigit(uniqIdent[i][0]))    //identifying constants 
      strcpy(constant[consi++],uniqIdent[i]);
      else 
      strcpy(ident[idi++],uniqIdent[i]);   //Identifier
    }	
}

void outputs()   //Printing the Outputs
{
	
int i;
     printf("\n\tDelemeter are : \n"); 
     for(i=0;i<uniqDeli;i++) 
     printf("\t%c\n",uniqDel[i]); 

     printf("\n\tOperators are : \n"); 
     for(i=0;i<uniqOpi;i++) 
     { 
      printf("\t"); 
      puts(uniqOp[i]); 
     } 

     printf("\n\tIdentifiers are : \n"); 
     for(i=0;i<idi;i++) 
     { 
          printf("\t"); 
          puts(ident[i]); 
     } 

       printf("\n\tKeywords are : \n"); 
       for(i=0;i<keyi;i++) 
       { 
           printf("\t"); 
           puts(keyword[i]); 
       } 

        printf("\n\tConstants are :\n"); 
       for(i=0;i<consi;i++) 
       { 
 			 printf("\t"); 
 			 puts(constant[i]); 
       } 

	  printf("\n\tLiterals are :\n"); 
	  for(i=0;i<liti;i++) 
	  { 
  	     printf("\t"); 
   		 puts(literal[i]); 
 	  } 
}
int main()
{
   char filename[15];
   FILE *file;
   char line [ 128 ];
   printf("Enter The File Name :\n");
   scanf("%s",&filename);
   file = fopen ( filename, "r" );
    if ( file != NULL )
   {
       /* or other suitable maximum line size */
      while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
      {
       lexAnalysis(line);
      }
      fclose( file );
      removeDuplicate(); 
      final(); 
      outputs();
   }
   else
   {
      perror( filename ); /* If file doesn't exist */
   }	
	
}
