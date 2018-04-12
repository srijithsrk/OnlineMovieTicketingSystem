#include<stdio.h>
#include <conio.h>
#include "MyFunctions.h"
void main()
{
	struct customer cob;
	int choice,response;
	DelayWelcome();
	printf("Welcome To Online Booking for Movies\n\n");
	printf("Enter:- \n1 For Movie Booking \n2 For Viewing Today's Show\n3 Booking Cancelation\n4 Admin Login\n");
	label:
	scanf("%d",&choice);
	switch(choice){
		case 1:BookMeASeat(cob);
		break;
		case 2:ViewMovies();
		printf("\nWant To Book A ShoW !?!\nEnter 1 To Book A Show!!! ");
		scanf("%d",&response);
		if(response==1)BookMeASeat(cob);
		break;
		case 3:BookingCancelation(cob);
		break;
		case 4:ViewAll(cob);
		break;
		default:printf("Invalid Response\n");
		goto label;
		break;
	}

}
