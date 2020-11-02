/*
	invoice.c
	Foundation Programming project 1. A program to 
	display a personalised invoice for a painting service
	Jake Russell	
	October 2015
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	/* for strlen() */
#define MAX 20

void getName(char name[]);
float getHeight(void);
float getLen(void);
char getPaint(void);
char getUnder(void);
float getTime(void);


int main(void)
{
		/* declare variables */
	char name[MAX];
	char paint, under;
	int count;
	int pound = 0x9c;
	float height, len1, len2, area, time, paintCost, underCost, labCost, total, vat;
	
		/* take customer's name */
	getName(name);

		/* get room dimensions */
	height = getHeight();
	len1 = getLen();
	len2 = getLen();
	
		/* calculate the total area to be painted */
	area = (2 * (height * len1)) + (2 * (height * len2)) + (len1 * len2);
	printf("The total area to be painted is %.2f m^2.\n", area);
		
		/* enter the type of paint to be used */
	paint = getPaint();
	
		/* calculate the total cost of the paint required */ 
	switch(paint)
	{
		case'L':
		case'l':
			paintCost = area * 1.95;
			printf("The paint cost is: %c %.2f\n", pound, paintCost);
			break;
		case'S':
		case's':
			paintCost = area * 1.2;
			printf("The paint cost is: %c %.2f\n", pound, paintCost);
			break;
		case'E':
		case'e':
			paintCost = area * 0.65;
			printf("The paint cost is: %c %.2f\n", pound, paintCost);
			break;
		default:
			printf("Unknown paint type, try again.\n");
			exit(0);
			break;
	}
	
		/* ask if an undercoat is needed */
	under = getUnder();
	
		/* if an undercoat is needed, then calculate its cost */
	switch(under)
	{
		case'y':
		case'Y':
			underCost = area * 0.5;
			printf("The undercoat cost is: %c %.2f\n", pound, underCost);
			break;
		case'n':
		case'N':
			underCost = 0;
			printf("Customer will not be charged for undercoating.\n");
			break;
		default:
			printf("Invalid input, try again. \n");
			exit(0);
			break;
	}
	
		/* enter the amount of time the job will take */
	time = getTime();
	
		/* calculate the labor costs with a minimum charge of £120 */
	if(time <= 8)	   /* £120 / £15 = 8, so any job less than 8 hours will calculate a charge lower than £120 */
	{
		labCost = 120;
	}
	else if(time > 8)
	{
		labCost = time * 15;
	}
	printf("The labour cost is: %c%.2f", pound, labCost);
	
		/* calculate the VAT and the total cost of job */
	vat = (labCost + paintCost + underCost) * 0.2;
	total = labCost + paintCost + underCost + vat;
	
		/* allows the user to see all the entered data before generating the invoice */
	printf("\nPress enter to generate the invoice.");
	getchar();
	
		/* clear screen */
	system("cls");
	
		/* display invoice */
	printf("|---------------------------------------------|\n");
	printf("|                   Invoice                   |\n");
	printf("|---------------------------------------------|\n");
	printf("|     Customer name:       %s", name); 
	
		/* adds spaces to ensure the invoice outline is even, 
		calculated using the number of characters in the string */                  
	for(count = 18 - strlen(name); count >= 0; count--)
	{
		printf(" ");
	}
	printf("|\n");
	printf("|     Area of room:        %.2f m^2         |\n", area); 
	printf("|     Paint type:          %c                  |\n", paint);
	printf("|     Undercoat?           %c                  |\n", under);
	printf("|     Hours for job:       %.0f                 |\n", time);
	printf("|---------------------------------------------|\n");
	printf("|                    Price                    |\n");
	printf("|     Materials:           %c%.2f            |\n", pound, paintCost + underCost);
	printf("|     Labour:              %c%.2f            |\n", pound, labCost);
	printf("|     VAT:                 %c%.2f             |\n", pound, vat);
	printf("|                                             |\n");
	printf("|     Total:               %c%.2f            |\n", pound, total);
	printf("|---------------------------------------------|\n");
	
	return 0;	 
}

void getName(char name[])
{
	printf("Enter the customer's name: \n");
	scanf("%19[^\n]", name);
	fflush(stdin);
}

float getHeight(void)
{
	float height;
	
	printf("\nEnter the dimensions of the room in meters: \n");
	
		/* if statement to make sure the entered value is within the specified boundaries */
	printf("Height (minimum 2m, maximum 6m): \n");
	scanf("%f", &height);
	fflush(stdin);
	
	if(height < 2 || height > 6)
	{
		printf("Invalid value, try again\n");
		exit(0);
	}
	return height;
}

float getLen(void)
{
	float len;
	
		/* if statement to ensure entered value is within the boundaries */
	printf("Length of wall (minimum 1m, maximum 25m): \n");
	scanf("%f", &len);
	fflush(stdin);
	
	if(len < 1 || len > 25)
	{
		printf("Invalid value, try again\n");
		exit(0);
	}
	return len;
}

char getPaint(void)
{
	char paint;
	
	printf("\nWhat type of paint will be used? (L = luxury, S = standard, E = economy): \n");
	scanf("%c", &paint);
	fflush(stdin);
	return paint;
}

char getUnder(void)
{
	char under;
	
	printf("\nWill an undercoat be required? (Y/N): \n");
	scanf("%c", &under);
	fflush(stdin);
	return under;
}

float getTime(void)
{
	float time;
	
	printf("\nEnter the number of hours required for the job: \n");
	scanf("%f", &time);
	fflush(stdin);
	return time;
}

