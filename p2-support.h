////////////////////////////////////////////////////////////////////////
//
// File           : p2support.h
// Description    : Headers of general-purpose utility functions 
//					          we use for the 257 project #2.
// Author	  : Azeem Aijaz
// Date		  : 11/6/21
// Notes					:
////////////////////////////////////////////////////////////////////////
// Add comments for each function below in the following format
///////////////////////////////////////////////////////////////////////

#define MAILBOX_SIZE 2000
#define ADRESS_SIZE 50
#define SUBJECT_SIZE 200
#define BODY_SIZE 2000
#define NAME_SIZE 20
//CHANGE the email below to your vcu email
#define user_email "aijaza@mail.com"
//add other define Macros as needed
#ifndef CMSC257_P2SUPPORT_INCLUDED
#define CMSC257_P2SUPPORT_INCLUDED
#endif 
struct Email
{	 char sender[ADRESS_SIZE];
        char receiver[ADRESS_SIZE];
	char subject[SUBJECT_SIZE];
	char body[BODY_SIZE];
	struct sent_date{
		int month;
		int day;
		int year;		
}s;
	int id;
//add other struct members as needed
//consider adding a nested struct here
};
        		  
struct Mailbox
{
int size;
struct Email *emails; 
//add other struct members as needed
};
        		                   
/////////////////////////////////////////////////////////////////////////////////////
// This is a sample comment for the initialize function	
// You should include a similar comment for each function declared within the .h file
//
// Function     : initialize
// Description  : Initializes the database for CMSC257 project #2 by manually entering
// the records using create_email function
// Inputs       : struct Mailbox* - pointer to the database    
// Outputs      : void
void initialize (struct Mailbox *ib);
//add other function declarations as needed


// Function     : create_email
// Description  : places the data from the main to make 10 different emails
// Inputs       : struct Mailbox* - pointer to the database, char send - the sender data, char reci - receiver data, char sub - subject data, char body - body data, int m - month data, int d = day data, int y = year data    
// Outputs      : void
void create_email(char send[50], char reci[50], char sub[200], char bod[2000], int m, int d, int y, struct Mailbox *ib);


// Function     : display_inbox_menu
// Description  : display the inbox menu
// Inputs       : struct Mailbox* - pointer to the database   
// Outputs      : void
void display_inbox_menu(struct Mailbox *ib);


// Function     : show_inbox
// Description  : display all the mailbox data
// Inputs       : struct Mailbox* - pointer to the database   
// Outputs      : void
void show_inbox(struct Mailbox *ib);


// Function     : email_id
// Description  : given an email id, print the email with sender, subject, date, and body
// Inputs       : struct Mailbox* - pointer to the database, int id - id specified to show // Outputs      : void
void email_id(struct Mailbox *ib, int id);


// Function     : sort_sender
// Description  : sort the emails by senders email address lexicographically
// Inputs       : struct Mailbox* - pointer to the database   
// Outputs      : void
void sort_sender(struct Mailbox *ib);


// Function     : comapre
// Description  : compares two id's
// Inputs       : const void *x - pointer to first id, const void *y - pointer to second id   
// Outputs      : int
int compare(const void *x, const void *y);


// Function     : sort_id
// Description  : sort the emails by id
// Inputs       : struct Mailbox* - pointer to the database   
// Outputs      : void
void sort_id(struct Mailbox *ib);


// Function     : search_keyword
// Description  : search emails in inbox given string and displays all emails with the keyword within sender, subject, or body fields
// Inputs       : struct Mailbox* - pointer to the database, char word - word to search for   
// Outputs      : void
void search_keyword(struct Mailbox *ib, char word[]);


// Function     : delete_id
// Description  : delete an email given the id
// Inputs       : struct Mailbox* - pointer to the database, int id - id to be deleted   
// Outputs      : void
void delete_id(struct Mailbox *ib, int id);
