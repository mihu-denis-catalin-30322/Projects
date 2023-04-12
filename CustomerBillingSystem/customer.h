/**************************************************************************/
/* customer.h -    Header file for module customer                       */
/* Copyright:   2022                                                     */
/* License:     UTCN                                                     */
/* Author:      Mihu Denis & Sandu Andrei                                */
/* Version:     12.01.2022                                               */
/* Updates:     Request at updates@utcn.ro                               */
/**************************************************************************/

#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include <stdio.h>
#include <string.h>

#include "admin.h"
#include "struct.h"

int nr_records;
int k=0;
int ti=0;

void buy()
{
int no,a,cont=0,k,l=0,bi=0,ln=0;
l3 : printf("Enter product number\n");
scanf("%d",&no);
FILE *fp,*fptr;
fp=fopen("stock.txt","r");
fptr=fopen("temp.txt","w");
while(!(feof(fp)))
{
	l++;
fscanf(fp,"%d",&it.product_number);
fscanf(fp,"%s",it.product_name);
fscanf(fp,"%d",&it.quantity);
fscanf(fp,"%d",&it.price);
if(it.product_number==no)
{
	ln++;
	if(ln==2)//Daca un articol este introdus de doua ori, este luat numai o data(Verifica daca produsul a mai fost bagat anterior).
	break;
	printf("Enter the quantity\n");
	scanf("%d",&a);
	if(a<=it.quantity)//verificam daca cantitatea introdusa nu depaseste stocul
	{
		cst[ti].product_number=it.product_number;
		strcpy(cst[ti].product_name,it.product_name);
		cst[ti].quantity=a;
		cst[ti].price=it.price;
		it.quantity=it.quantity-a;
		ti++;
	}
	else
	printf("Out of stock\n");
	bi++;
}
else
{
	cont++;
    fprintf(fptr,"%d\t",it.product_number);
    fprintf(fptr,"%s\t",it.product_name);
    fprintf(fptr,"%d\t",it.quantity);
    fprintf(fptr,"%d\t",it.price);
	continue;
}
fprintf(fptr,"%d\t",it.product_number);
fprintf(fptr,"%s\t",it.product_name);
fprintf(fptr,"%d\t",it.quantity);
fprintf(fptr,"%d\t",it.price);
}
if(l==cont)
printf("error\nChoose properly\n");
fclose(fptr);
fclose(fp);
remove("stock.txt");
rename("temp.txt","stock.txt");//actualizam stocul din display
ln=0;
printf("Do you want to shop for another product?\nPress 1 for yes\n");
scanf("%d",&k);
if(k==1)
goto l3;
}

void invoice()
{
	int j,o;
	float total=0;
	printf("\n\n******************************INVOICE******************************************\n");
	printf("================================================================================\n");
	printf("product number\t| product name\t| price\t| quantity\t| amount\t|\n");
	printf("================================================================================\n");
	for(o=0;o<ti;o++)
	{
		cst[o].amount=0;
		cst[o].amount=(cst[o].quantity)*(cst[o].price);
		total=total+cst[o].amount;
	}
	for(j=0;j<ti;j++)
	{
		printf("%6d\t       |%9s   \t  | %3d\t|%3d\t        |   %3d\n",cst[j].product_number,cst[j].product_name,cst[j].price,cst[j].quantity,cst[j].amount);
	}
	printf("\nAmount to pay is %.2f USD",total);
	printf("\nThank you for shopping, come again!\n");
}

void display()
{
	int zk=0;
    FILE *fp;
	fp=fopen("stock.txt","r");
	printf("================================================================================\n");
	printf("\t|product number\t|product name\t|quantity\t|price\t|\n");
	printf("=================================================================================\n");
	while(zk!=nr_records)
	{
		zk++;
		fscanf(fp,"%d",&it.product_number);
		if(it.product_number==0)
		{
		printf("Product number cannot be zero\n");
		break;
		}
		fscanf(fp,"%s",it.product_name);
		fscanf(fp,"%d",&it.quantity);
		fscanf(fp,"%d",&it.price);
		printf("\n\t  %14d|\t%8s|\t%8d|\t%d|\n",it.product_number,it.product_name,it.quantity,it.price);
	}
	fclose(fp);
}

void mdisplay()
{
	int o;
	printf("================================================================================\n");
	printf("product number\t|product name\t|quantity\t|price\t\n");
	printf("================================================================================\n");
	for(o=0;o<ti;o++)
	{
		printf("%14d\t|%12s\t|%6d\t|%6d\n",cst[o].product_number,cst[o].product_name,cst[o].quantity,cst[o].price);
	}
}

void mdelete()
{
	int i,j,f,g=0,aj=0,ag=0;
	FILE *fw,*fq;
	printf("Enter the product number to be deleted\n");
	scanf("%d",&f);
	for(i=0;i < ti;i++)
	{
	  if(cst[i].product_number==f)
	  {aj=cst[i].quantity;
	  printf("\nProduct deleted successfully\n");}
	  continue;
	  cst_t[g].product_number=cst[i].product_number;
	  strcpy(cst_t[g].product_name,cst[i].product_name);
	  cst_t[g].quantity=cst[i].quantity;
	  cst_t[g].price=cst[i].price;
	  g++;
	}
	for(j=0;j<g;j++)
	{
	 cst[j].product_number=cst_t[j].product_number;
 	 strcpy(cst[j].product_name,cst_t[j].product_name);
	  cst[j].quantity=cst_t[j].quantity;
	  cst[j].price=cst_t[j].price;
	}
	ti=g;
	printf("\n%d",aj);
	fq=fopen("stock.txt","r");
	fw=fopen("temp4.txt","w");
	for(j=0;j<nr_records;j++)
	{
		    fscanf(fq,"%d",&it.product_number);
		    fscanf(fq,"%s",it.product_name);
			fscanf(fq,"%d",&it.quantity);
			fscanf(fq,"%d",&it.price);
			if(it.product_number==f)
			{ag=aj+it.quantity;
			fprintf(fw,"%d\t%s\t%d\t%d\t",it.product_number,it.product_name,ag,it.price);}
            else
			fprintf(fw,"%d\t%s\t%d\t%d\t",it.product_number,it.product_name,it.quantity,it.price);

	}
	fclose(fq);
    fclose(fw);
    remove("stock.txt");
    rename("temp4.txt","stock.txt");
}


#endif // CUSTOMER_H_INCLUDED
