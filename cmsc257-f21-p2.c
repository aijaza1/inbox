////////////////////////////////////////////////////////////////////////
//
// File          : cmsc257-f21-p2.c
// Description   : This is a part of the starter code for CMSC 257 
//	               Plese see the course page for more details	
//
// Author        : Azeem Aijaz
// Last Modified : 11/6/21
//

//Add program description, author name, last edit date as in the project1
////Do not modify anything below this line

#include <stdio.h>
#include <stdlib.h>
#include "p2-support.h"

int main(){
	struct Mailbox* ib;
	ib = (struct Mailbox*) malloc(sizeof(struct Mailbox));
	initialize(ib);
	display_inbox_menu(ib);
	free (ib);
	return 0;
}

