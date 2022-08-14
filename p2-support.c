#include "p2-support.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int counter = 10;
////////////////////////////////////////////////////////////////////////
//
// File          	: p2support.c
// Description    : This is a set of general-purpose utility functions 
//  		    we use for the 257 project 
  		    
void  		    
initialize (struct Mailbox *ib)
{
//allocate memory for 2000 emails
ib->emails = malloc (sizeof (struct Email) * MAILBOX_SIZE);
ib->size = 0;
           
create_email ("asonmez@mail.com", user_email, "Welcome to your inbox.","Welcome to your inbox, just wanted to say hi. Here's hoping you get all your code done.", 11,20,2020, ib);

create_email ("mmartinez@mail.com", user_email, "Padding out your inbox.", "Yet another email just to pad out your inbox, have fun!", 11,30,2020, ib);

create_email ("dboyle@mail.com", user_email, "3rd email!", "Alright, time for another email for your inbox. Not going too lie, it's a bit of a pain coming up with stuff for these strings. Anyways, have fun with your code!", 12,2,2020, ib);

create_email ("cbluer@mail.com", user_email, "4th email!", "Content of fourth email. More coding, more fun!", 12,8,2020, ib);

create_email ("cboyle@mail.com", user_email, "5th email!", "Content of fifth email. Coding is fun-tastic!", 12,18,2020, ib);

create_email ("sblack@mail.com", user_email, "6th email!", "Content of fifth email. Coding is fun-tastic!", 1,1,2021, ib);

create_email ("sblack@mail.com", user_email, "7th email!", "Body of sixth email. Coding is fun-tastic!", 1,5,2021, ib);

create_email ("sblack@mail.com", user_email, "8th email!", "Body of eighth email. Coding isfun-tastic!", 2,15,2021, ib);                                                            

create_email ("sblack@mail.com", user_email, "9th email!", "Body of ninth email. Coding is fun-tastic!", 2,25,2021, ib);                                                                                                                   
create_email ("dboyle@mail.com", user_email, "Last email!", "Body of tentth email. Coding is fun-tastic!", 3,15,2021, ib);
}


void create_email(char send[50], char rece[50], char sub[200], char bod[2000], int m, int d, int y, struct Mailbox *ib){
 		static int id = 0;

		ib->emails[ib->size].id = id;
		strcpy(ib->emails[ib->size].sender, send); 
		strcpy(ib->emails[ib->size].receiver, rece);
		strcpy(ib->emails[ib->size].subject, sub);
		strcpy(ib->emails[ib->size].body, bod);
		ib->emails[ib->size].s.month = m;
		ib->emails[ib->size].s.day = d;
		ib->emails[ib->size].s.year = y;
		ib->size++;
		id++;
}
void display_inbox_menu(struct Mailbox *ib){
	int choice = 0;
	do{
	printf("\n");
	printf("*************** aijaza INBOX	***************\n");
	printf("***************	Total Inbox: %04d ***************\n", ib->size);
	printf("\n1. Show Inbox\n");
	printf("2. Show Email by ID\n");
	printf("3. Sort inbox by Sender\n");
	printf("4. Sort Inbox by ID\n");
	printf("5. Search Inbox by Keyword\n");
	printf("6. Delete\n");
	printf("7. Exit Inbox\n");
	printf("\n");
	scanf("%d", &choice);
	printf("\n");
	int id, id2;
	char word[10];
	switch(choice){
	case 1: show_inbox(ib); 
	break;
	case 2: printf("Enter the ID of the email you want to read: \n");
		scanf("%d", &id); 
		printf("\n");
		email_id(ib, id);
	break;
	case 3:	sort_sender(ib);
	break;
	case 4: sort_id(ib);
	break;
	case 5:	printf("Enter the keyword you are searching for: \n");
		scanf("%s", word);
		printf("\n");
		search_keyword(ib, word);
	break;
	case 6: printf("Enter the ID of the e-mail you want to delete: \n");
		scanf("%d", &id2);
		delete_id(ib, id2);
	break;

	}
}while(choice != 7);
if(choice == 7){
free(ib->emails);
free(ib);
printf("Exiting e-mail client - Good Bye !");
exit(0);
}
}

void show_inbox(struct Mailbox *ib){
	printf("ID   SENDER--------------   MM/DD/YYYY   SUBJECT--------\n");
	printf("--   --------------------   --/--/----   ---------------\n");
	int k;
	for(k = 0; k < ib->size; k++){
	printf("%02d - %-20s - %02d/%02d/%d - %-15s\n", ib->emails[k].id, ib->emails[k].sender, ib->emails[k].s.month, ib->emails[k].s.day, ib->emails[k].s.year, ib->emails[k].subject);
	}

}

void email_id(struct Mailbox *ib, int id){
		printf("%s - %s\n", ib->emails[id].sender, ib->emails[id].subject);
		printf("Email recieved on: %02d/%02d/%d\n\n", ib->emails[id].s.month, ib->emails[id].s.day, ib->emails[id].s.year);
		printf("%s\n\n", ib->emails[id].body);
		
}

void sort_sender(struct Mailbox *ib){

	int i, j;
	char sender[50];
	char subject[200];
	char body[2000];
	int id;
	int day;
	int month;
	int year;

	for(i = 0; i < counter; i++)
		for(j = i+1; j < counter; j++){
		if(strcmp(ib->emails[i].sender, ib->emails[j].sender) >0){
			strcpy(sender, ib->emails[i].sender);
			strcpy(ib->emails[i].sender, ib->emails[j].sender);
			strcpy(ib->emails[j].sender, sender);

			strcpy(subject, ib->emails[i].subject);
			strcpy(ib->emails[i].subject, ib->emails[j].subject);
			strcpy(ib->emails[j].subject, subject);

			strcpy(body, ib->emails[i].body);
			strcpy(ib->emails[i].body, ib->emails[j].body);
			strcpy(ib->emails[j].body, body);

			id = ib->emails[i].id;
			ib->emails[i].id = ib->emails[j].id;
			ib->emails[j].id = id;

			day = ib->emails[i].s.day;
			ib->emails[i].s.day = ib->emails[j].s.day;
			ib->emails[i].s.day = day;

			month = ib->emails[i].s.month;
			ib->emails[i].s.month = ib->emails[j].s.month;
			ib->emails[j].s.month = month;

			year = ib->emails[i].s.year;
			ib->emails[i].s.year = ib->emails[j].s.year;
			ib->emails[j].s.year = year;
			}
	}

}

int compare(const void *x, const void *y){
	struct Email *one = (struct Email *)x;
	struct Email *two = (struct Email *)y;
	return one->id - two->id;
}
void sort_id(struct Mailbox *ib){
	qsort(ib->emails, ib->size, sizeof(struct Email), compare);
}

void search_keyword(struct Mailbox *ib, char word[]){
	int v;
	printf("ID   SENDER------------   MM/DD/YYYY   SUBJECT--------\n");
	printf("--   ------------------   --/--/----   ---------------\n");
	for(v = 0; v < ib->size; v++){
		if(strstr(ib->emails[v].sender, word) || strstr(ib->emails[v].subject, word) ||  strstr(ib->emails[v].body, word)){
			
			printf("%02d - %-20s - %02d/%02d/%d - %-15s\n", ib->emails[v].id, ib->emails[v].sender, ib->emails[v].s.month, ib->emails[v].s.day, ib->emails[v].s.year, ib->emails[v].subject);
		}
}
}

void delete_id(struct Mailbox *ib, int id){
	int d, f;
	
	if(id >= ib->size){
	printf("No email found with ID");
	exit(0);
	}
	else{
	for(d = 0; d < ib->size; d++){
		if(id == ib->emails[d].id){
			for(f = d; f < ib->size-1; f++){
			ib->emails[f] = ib->emails[f+1];
			}
			printf("Email with ID = %d is deleted\n", id);
		}

	}
	ib->size--;
	counter--;	
	}
}
