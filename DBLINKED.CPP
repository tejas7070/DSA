/*
       Doubly Linked List


	*start
	1000            2000            3000            4000
    NULL 10  2000   1000 20 3000    2000 30  4000   3000 40  NULL
*/

   #include<stdio.h>
   #include<conio.h>
   #include<process.h>

   struct node
   {
       int num;
       struct node *prev;
       struct node *next;

   }*start=NULL;

      void CREATE();
      void DISP();

     int menu()
     {
	  int choice;

	  clrscr();

	printf("\n\n 1] CREATE A DB LINKED LIST ");
	printf("\n 2] DISPLAY LINKED LIST ");
	printf("\n 3] EXIT ");

	printf("\n ENTER YOUR CHOICE : ");
	    scanf("%d", &choice);

	    return choice;
     }

   void main()
   {
       int ch;

       clrscr();

     do
     {
	  ch = menu();

	switch(ch)
	{
	    case 1:
		     CREATE();
		     DISP();
		     break;
	    case 2:
		     DISP();
		     break;
	    case 3:
		     printf("\n\n EXIT ");
			getch();
			exit(0);
	    default:
		     printf("\n\n INVALID INPUT ");
	}
	    getch();
     }while(ch != 3);
   }


      void CREATE()
      {
	  struct node *newnode, *temp;
	  newnode = malloc(sizeof(struct node));

	      printf("\n\n Enter a num : ");
	       scanf("%d", &newnode->num);

		newnode->next = NULL;

	     if(start == NULL)
	     {
		 start = newnode;
		 start->prev = NULL;
	     }
	     else
	     {
		  temp = start;

		 while(temp->next != NULL)
		 {
		     temp = temp->next;
		 }
		     temp->next = newnode;
		     newnode->prev = temp;
	     }
      }

      void DISP()
      {
	   struct node *temp;

	   if(start == NULL)
	   {
	       printf("\n\n NO LINKED LIST ");
	   }
	   else
	   {
		    temp = start;

		 while(temp != NULL)
		 {
		     printf("\n\n %d ", temp->num);

			 temp = temp->next;
		 }
	   }
      }

/*
       *temp
       *start
	1000            2000              3000
    NULL 10 2000    1000 20 3000      2000 30 NULL
*/



