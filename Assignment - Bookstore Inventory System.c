#include <stdio.h>
#include<string.h>
#include <ctype.h>
#include<conio.h>
#define TRUE 1
typedef struct
{
	int id;
	char title[80], author[80], pblshr[80];
	float price;
}book;
int choice, search_c, s_key;
book getInput(book data);
void writeInput(book data);
void deleteInput();
void displayInput();

book data;
char s_name[100], text;

FILE *fpt;

int main ()
{
	int flag = TRUE;

	printf("\t\t\t Bookstore Inventory System\n");
	printf("----------------------------------Main Menu------------------------------------\n");
	printf("\nNavigate through this application using the options provided.\n\n");
	printf("1 -------> :: Enter Book Data \t4 -------> :: Delete all records \n\n2 -------> :: Search for Books \t5 -------> :: Exit Inventory \n\n3 -------> :: Display all Books\n");
	printf("\n------------------------------------------------------------------------------\n\n");
	while (flag)
	{
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		
		if (choice ==2)
		{

		}		
		else if (choice == 3)
		{
			displayInput();
		}
		else if (choice ==4)
		{	
			deleteInput();
		}
		else if (choice == 5)
		{	
			break;
		}
		else if(choice == 1)
		{	
			fpt = fopen("records.txt", "ab");
			data = getInput(data);
			writeInput(data);
			fclose(fpt);
		}
	
			
	}
	getch();
	
}

book getInput (book data)
{
	printf("\nISBN: ");
	scanf("%d", &data.id);
	printf("Enter Book Title. : ");
	fflush(stdin);
	gets(data.title );
	printf("Enter Book Author : ");
	fflush(stdin);
	gets(data.author );
	printf("Enter Book Publisher : ");
	fflush(stdin);
	gets(data.pblshr );
	printf("Enter Book Price (RM): ");
	scanf("%f", &data.price);
	return(data);
}

void writeInput(book data)
{	
	fprintf(fpt,"\n %d\t    %-15s\t%-15s\t%-15s\tRM%.2f\n",data.id, data.title, data.author, data.pblshr, data.price);
	return;
}

void deleteInput()
{
	char yesno[10];
	printf("\nAll records will be deleted, are you sure? [y/n]: ");
	scanf("%s", yesno);
	if (strstr(yesno,"y"))
	{
		printf("\nRecords successfully deleted\n");
		fpt = fopen("records.txt", "w");
		fpt = NULL;
		fclose(fpt);
	}
	else if (strstr(yesno,"n"))
		printf("\nOkay\n!");
	else
		printf("\nInvalid User Input\n");
}

void displayInput()
{
	printf("------------------------------------------------------------------------------\n");
	printf(" ISBN No |      Title      |     Author     |    Publisher    |  Price\n");
	printf("------------------------------------------------------------------------------\n");
	fpt = fopen("records.txt", "r");
	if (fpt != NULL)
	{
		do 
		{
			text = fgetc(fpt); 
			printf("%c", text); 
		}while (text != EOF); 
		fclose(fpt);
	}
	else
		printf("\nNo records found!");
}


	
	
		
			
		
		
	
	
	
