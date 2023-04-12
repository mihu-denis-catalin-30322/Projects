#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "admin.h"
#include "customer.h"
#include "struct.h"

int main()
{
	char ch,password[10],q[10]="admin";
	int s=0,y=0,i;
	FILE *fpe;
	fpe=fopen("nr_records.txt","r");
	fscanf(fpe,"%d",&nr_records);
	fclose(fpe);
	printf("\t======CUSTOMER BILLING SYSTEM======\n");
	printf("\t        \n");
	printf("\tMade by Denis & Andrei\n");
	q: printf("\n\n\t01. ADMINISTRATOR\n\t02. CUSTOMER\n\t03.EXIT\n");
	scanf("%d",&s);
	switch(s)
	{
	          case 1: printf("\tEnter password\n\t");
              for(i=0;i<5;i++)
              {
              ch = getch();
              password[i] = ch;
              ch = '*' ;
               printf("%c",ch);
              }
              password[i]='\0';
              if(strcmp(password,q))
              {
              printf("Wrong password try again");
              goto q;
             }
               else
               goto l3;
               l3: printf("\n\Access granted\n");
		       printf("\t01.CREATE\n\t02.DELETE\n\t03.DISPLAY\n\t04.MAIN MENU\n");
		        scanf("%d",&y);
		        switch(y)
		        {
        			case 1:create();
        			      goto q;
  			      case 2:delete();
  			             goto q;
                  case 3:display();
                         goto q;
                  case 4: goto q;
                  default : printf("error\n");
				  goto q;
        		}
		         break;
       case 2: printf("\t01.BUY\n\t02.INVOICE\n\t03.DISPLAY\n\t04.MY CART\n\t05.MAIN MENU\n\t06. DELETE ITEMS IN CART\n");
              scanf("%d",&y);
              switch(y)
		        {
        			case 1:buy();
        			      goto q;
  			      case 2:invoice();
  			             goto q;
                  case 3:display();
                         goto q;
                  case 4: mdisplay();
                  goto q;
                  case 5: goto q;
                  case 6: mdelete();
                  goto q;
                  default : printf("error\n");
				  goto q;
        		}
		         break;
      case 3: printf("Exiting...\n");
      break;
       default : printf("error\n");
       break;
	}
	return 0;
}
