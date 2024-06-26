
      #include<stdio.h>
      #include<stdlib.h>
      #include<conio.h>

       struct node
       {
	    int num;
	    struct node *prev;
	    struct node *next;

       }*start = NULL;

	  void CREATE();
	  void DISP();
	  void INSERT_BEGIN();
	  void INSERT_BEFORE();
	  void INSERT_AFTER();
	  void INSERT_END();
	  void DELETE_BEGIN();
	  void DELETE_GIVEN();

       int menu()
       {
	   int choice;

	   clrscr();

	   printf("\n 1] Create a DB LInked List ");
	   printf("\n 2] Display DB LInked List ");
	   printf("\n 3] INSERT_BEGIN ");
	   printf("\n 4] INSERT_BEFORE ");
	   printf("\n 5] INSERT_AFTER ");
	   printf("\n 6] INSERT_END ");
	   printf("\n 7] DELETE_BEGIN ");
	   printf("\n 8] DELETE_GIVEN ");

	   printf("\n 9] EXIT ");

	   printf("\n\n Enter your choice : ");
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
			INSERT_BEGIN();
			DISP();
			break;
	       case 4:
			INSERT_BEFORE();
			DISP();
			break;
	       case 5:
			INSERT_AFTER();
			DISP();
			break;
	       case 6:
			INSERT_END();
			DISP();
			break;
	       case 7:
			DELETE_BEGIN();
			DISP();
			break;
	       case 8:
			DELETE_GIVEN();
			DISP();
			break;
	       case 9:
			printf("\n\n EXIT ");
			   getch();
			   exit(0);
	       default:
			printf("\n\n INVALID INPUT ");
	    }
		getch();
	}while(ch != 9);
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

	void INSERT_BEGIN()
	{
	    struct node *newnode;
	    newnode = malloc(sizeof(struct node));

	      printf("\n\n Enter a num : ");
	      scanf("%d", &newnode->num);

	      newnode->prev = NULL;
	      newnode->next = start;
	      start->prev = newnode;
	      start = newnode;
	}

	void INSERT_BEFORE()
	{
	       int tnum;
	      struct node *newnode, *temp;

	     printf("\n\n Enter target num : ");
	       scanf("%d", &tnum);

	    if(tnum == start->num)
	    {
		 INSERT_BEGIN();
	    }
	    else
	    {
		 temp = start->next;

		 while(temp!=NULL && temp->num != tnum)
		 {
		    temp = temp->next;
		 }

		 if(temp == NULL)
		 {
		    printf("\n\n Target num not found ");
		 }
		 else
		 {
		    newnode = malloc(sizeof(struct node));

		      printf("\n\n Enter a num : ");
			scanf("%d", &newnode->num);

			newnode->prev = temp->prev;
			newnode->next = temp;
			temp->prev->next = newnode;
			temp->prev = newnode;
		 }
	    }
	}

	void INSERT_AFTER()
	{
	       int tnum;
	      struct node *newnode, *temp;

	     printf("\n\n Enter target num : ");
	       scanf("%d", &tnum);

	      temp = start;

	     while(temp!=NULL && temp->num != tnum)
	     {
		 temp = temp->next;
	     }

	     if(temp == NULL)
	     {
		printf("\n\n Target num not found ");
	     }
	     else
	     {
		 newnode = malloc(sizeof(struct node));

		   printf("\n\n Enter a num : ");
		     scanf("%d", &newnode->num);

		     newnode->prev = temp;
		     newnode->next = temp->next;
		     temp->next->prev = newnode;
		     temp->next = newnode;
	     }
	}

	void INSERT_END()
	{
	    struct node *newnode , *temp;

	       temp = start;

	       while(temp->next != NULL)
	       {
		    temp = temp->next;
	       }

	     newnode = malloc(sizeof(struct node));

		printf("\n\n Enter a num : ");
		  scanf("%d", &newnode->num);

		  newnode->prev = temp;
		  newnode->next = NULL;
		  temp->next = newnode;
	}

	void DELETE_BEGIN()
	{
	     struct node *temp;
	     temp = start->next;
	     free(start);
	     start = temp;
	     start->prev = NULL;
	}

	void DELETE_GIVEN()
	{
	     int tnum;
	     struct node *temp;

	     printf("\n\n Enter num to be deleted : ");
	       scanf("%d", &tnum);

	     if(tnum == start->num)
	     {
		 DELETE_BEGIN();
	     }
	     else
	     {
		  temp = start->next;

		  while(temp!= NULL && temp->num != tnum)
		  {
		      temp = temp->next;
		  }

		  if(temp == NULL)
		  {
		       printf("\n\n NUM NOT FOUND ");
		  }
		  else
		  {
		     temp->prev->next = temp->next;
		     temp->next->prev = temp->prev;
			  free(temp);
		  }
	     }
	}
