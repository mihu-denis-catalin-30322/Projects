/**************************************************************************/
/* struct.h -    Header file for module struct                           */
/* Copyright:   2022                                                     */
/* License:     UTCN                                                     */
/* Author:      Mihu Denis & Sandu Andrei                                */
/* Version:     12.01.2022                                               */
/* Updates:     Request at updates@utcn.ro                               */
/**************************************************************************/

#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#include<stdio.h>
#include<string.h>

struct item
{
	int product_number;
	char product_name[10];
	int quantity;
	int price;
}it;
struct customer
{
	int product_number;
	char product_name[10];
	int quantity;
	int price;
	int amount;
}cst[100];
struct tempor
{
	int product_number;
	char product_name[10];
	int quantity;
	int price;
	int amount;
}cst_t[100];

#endif // STRUCT_H_INCLUDED
