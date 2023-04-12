/**************************************************************************/
/* admin.h -    Header file for module admin                             */
/* Copyright:   2022                                                     */
/* License:     UTCN                                                     */
/* Author:      Mihu Denis & Sandu Andrei                                */
/* Version:     12.01.2022                                               */
/* Updates:     Request at updates@utcn.ro                               */
/**************************************************************************/

#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include <stdio.h>
#include <string.h>

#include "customer.h"
#include "struct.h"

void create()
{
	int i=0;
	FILE *fp,*fpq;
	fp=fopen("stock.txt","w");
	printf("Enter the number of records\n");
	scanf("%d",&nr_records);
	fpq=fopen("nr_records.txt","w");
	fprintf(fpq,"%d",nr_records);
	fclose(fpq);
	while(i<nr_records)
	{
		printf("Enter the product code\n");
		scanf("%d",&it.product_number);
		printf("Enter the name\n");
		scanf("%s",&it.product_name);
		printf("Enter the quantity\n");
		scanf("%d",&it.quantity);
		printf("Enter the price\n");
		scanf("%d",&it.price);
		i++;
		fprintf(fp,"%d\t%s\t%d\t%d\t",it.product_number,it.product_name,it.quantity,it.price);
	}
	fclose(fp);
	printf("\n ==Records have been created!==\n");

}

void delete()
{   FILE *fp,*fptr,*fpk;
	int x,found=0,xk=0,p;
	fp=fopen("stock.txt","r");
	fptr=fopen("temp1.txt","w");
	fpk=fopen("temp2.txt","w");
	printf("Enter the product number to be deleted\n");
	scanf("%d",&x);
	p=nr_records;
	while(xk!=p)
	{
		xk++;
		fscanf(fp,"%d",&it.product_number);
		if(it.product_number==x)
		{
			found=1;
			fscanf(fp,"%s",it.product_name);
			fscanf(fp,"%d",&it.quantity);
			fscanf(fp,"%d",&it.price);
			nr_records--;
			printf("Product has been successfully deleted\n");
		}
		else
		{
			fscanf(fp,"%s",it.product_name);
			fscanf(fp,"%d",&it.quantity);
			fscanf(fp,"%d",&it.price);
			fprintf(fptr,"%d\t%s\t%d\t%d\t",it.product_number,it.product_name,it.quantity,it.price);
		}
	}
	    fprintf(fpk,"%d",nr_records);
	    fclose(fpk);
		fclose(fptr);
		fclose(fp);
		if(found==0)
            printf("\n Product not found\n");
		remove("nr_records.txt");
		rename("temp2.txt","nr_records.txt");
		remove("stock.txt");
		rename("temp1.txt","stock.txt");
	}

	void displaya()
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

#endif // ADMIN_H_INCLUDED
