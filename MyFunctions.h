#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct customer{
	char CustomerName[40];
	char MovieName[20];
	int seatno;
	char time[10];
	int id;
	char status[10];
};
//Patterns
void DelayAdmin(){
system("cls");
printf("\n\n\n\n");
int i,j;
char message[32]="Welcome To Admin Panel";
int count=0;
for(i=0;i<240;i++){
	for(j=0;j<10000000;j++){
	}
	if(i>45&&count<22)
		printf("%c",message[count++]);

	else printf("*");
}
}
void DelayWelcome(){
	char msg[14]="Enter Records";  //20
	int i,count=0,j;
	for(i=0;i<120;i++){
		for(j=0;j<10000000;j++){
		}
		if(i>50&&count<14)printf("%c",msg[count++]);
		else printf("*");
	}
}
void ViewMovies(){
	system("cls");
	printf("\nGRAB A SEAT NOW!!!!\n");
	printf("\n\n");
	int count=0,i,j;
	char msg1[18]="Today's Show List";
	char msg2[40]="1.MS Dhoni\n2.Kabali\n3.Batman\n4.Bahubali";
		for(i=0;i<18;i++){
		if(count<18)printf("%c",msg1[count++]);
   	} 
	     printf("\n");
	count=0;
		for(i=0;i<39;i++){
		for(j=0;j<10000000;j++){
		}
		if(count<39)printf("%c",msg2[count++]);
	}
}
void BookMeASeat(struct customer c){
	int response=1;
	int timechoice;
	int movchoice;
	FILE *fpwrite;
	fpwrite=fopen("Customer1.DAT","ab+");
	char moviename[20];
	char movietiming[20];
	while(response){
	ViewMovies();
	printf("\nEnter Your Choice\n");
	scanf("%d",&movchoice);
	printf("Enter your choice of timing\n");
	printf("1.9Am-12Am\n2.5Pm-8Pm\n3.9Pm-12\n");
	scanf("%d",&timechoice);
	if(movchoice==1)strcpy(c.MovieName,"MS Dhoni");
	else if (movchoice==2)strcpy(c.MovieName,"Kabali");
	else if(movchoice==3) strcpy(c.MovieName,"Batman");
	else strcpy(c.MovieName,"Bahubali");
	if(timechoice==1)strcpy(c.time,"9Am-12");
	else if(timechoice==2)strcpy(c.time,"5Pm-8Pm");
	else strcpy(c.time,"9Pm-12");
	printf("Enter Seat No.\n");
	scanf("%d",&c.seatno);
	printf("Enter Your Name: ");
	
	scanf("%s",c.CustomerName);
	c.id=c.seatno;
	strcpy(c.status,"Booked");
	fwrite(&c,sizeof(c),1,fpwrite);
	system("cls");
	printf("Your Seat has been Booked !!!\n");
	fclose(fpwrite);
	printf("Your Booking Details\n");
	printf(" Name: %s\n Movie Name: %s\n Time: %s\n Timing: %d\n Id: %d\n",c.CustomerName,c.MovieName,c.time,c.seatno,c.id);
	printf("Status: %s",c.status);
	printf("\nWant To Book More!!!\nThen Enter 1 else 0!!!");
	scanf("%d",&response);
	}
}
void BookingCancelation(struct customer cob){
	system("cls");
	FILE *fp,*fpwrite;
	int flag=0;
	fp=fopen("Customer1.DAT","rb+");
	fpwrite=fopen("Customer1.DAT","ab+");
	int id,finalchoice=0;
	printf("Movie Cancelation\n");
	printf("Please Enter Your Id: ");
	scanf("%d",&id);
	while(fread(&cob,sizeof(cob),1,fp)==1){
		if(cob.id==id){
			printf("Your Booking Details\n");
			printf(" Name: %s\n Movie Name: %s\n Time: %s\n Timing: %d\n Id: %d\n\n",cob.CustomerName,cob.MovieName,cob.time,cob.seatno,cob.id);
			printf("Enter 1 to Cancel :");
			scanf("%d",&finalchoice);
			if(finalchoice==1){
			printf("Booking Cancelled\n");
			strcpy(cob.status,"Cancelled");
			printf("Status: %s",cob.status);
			}
			flag=1;
		}
	}
	if(flag==0)printf("Sorry Your Details Cant Be Found");	
}
	void ViewAll(struct customer c){
	FILE *fpread;
	DelayAdmin();
	char username[40],password[100];
	printf("Enter Username: ");
	scanf("%s",&username);
	printf("Enter Password: ");
	scanf("%s",&password);
	if(strcmp(username,"Admin")==0&&strcmp(password,"administrator")==0){
		system("cls");
		printf("\t\t\t\t\t\t\tWELCOME ADMIN\nRecords In Our Database\n");
		printf("--------------------------------------------\n");
	    fpread=fopen("Customer1.DAT","rb+");
	    while(fread(&c,sizeof(c),1,fpread)==1){
		printf(" Name: %s\n Movie Name: %s\n Time: %s\n Seat No: %d\n Id: %d\n",c.CustomerName,c.MovieName,c.time,c.seatno,c.id);
		printf("--------------------------------------------\n");
	}
	fclose(fpread);
	}else printf("Wrong username or Password");
}
