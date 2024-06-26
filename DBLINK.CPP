
   #include<iostream.h>
   #include<conio.h>
   #include<process.h>

   struct node
   {
	int num;
	node *prev;
	node *next;

   }*start=NULL;

       void CREATE();
       void DISP();
       void INSERT_BEGIN();
       void INSERT_BEFORE();
       void INSERT_AFTER();
       void DELETE_BEGIN();
       void DELETE_GIVEN();
       void INSERT_END();
       void DELETE_END();

      int menu()
      {
	  int choice;

	  clrscr();

	  cout<<"\n\n 1] CREATE DB Linked List ";
	  cout<<"\n 2] DISPLAY LL ";
	  cout<<"\n 3] INSERT_BEGIN ";
	  cout<<"\n 4] INSERT_BEFORE ";
	  cout<<"\n 5] INSERT_AFTER ";
	  cout<<"\n 6] DELETE_BEGIN ";
	  cout<<"\n 7] DELETE_GIVEN ";
	  cout<<"\n 8] INSERT_END ";
	  cout<<"\n 9] DELETE_END ";
	  cout<<"\n 10] EXIT  ";

	  cout<<"\n\n ENTER YOUR CHOICE : ";
	     cin>>choice;

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
		      DELETE_BEGIN();
		      DISP();
		      break;
	      case 7:
		      DELETE_GIVEN();
		      DISP();
		      break;
	      case 8:
		      INSERT_END();
		      DISP();
		      break;
	      case 9:
		      DELETE_END();
		      DISP();
		      break;
	      case 10:
		      cout<<"\n\n EXIT ";
			getch();
			exit(0);
	      default:
		      cout<<"\n\n INVALID INPUT ";
	  }
	  getch();
      }while(ch != 10);
   }

       void CREATE()
       {
	    struct node *newnode, *temp;
	    newnode = new node;

	      cout<<"\n\n Enter a num : ";
		cin>>newnode->num;

		newnode->next = NULL;

	     if(start == NULL)
	     {
		  newnode->prev = NULL;
		  start = newnode;
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
	       cout<<"\n\n NO LINKED LIST ";
	   }
	   else
	   {
		    temp = start;

		while(temp != NULL)
		{
		     cout<<"\n\n "<<temp->num;

			temp = temp->next;
		}
	   }
       }

       void INSERT_BEGIN()
       {
	   struct node *newnode;
	   newnode = new node;

	   cout<<"\n\n Enter a num : ";
	     cin>>newnode->num;

	     newnode->prev = NULL;
	     newnode->next = start;
	     start->prev = newnode;
	     start = newnode;
       }

       void INSERT_BEFORE()
       {
	   int tnum;
	   struct node *newnode, *temp;

	    cout<<"\n\n Enter target number : ";
		 cin>>tnum;

	    if(start->num == tnum)
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
		  cout<<"\n\n TARGET NUMBER NOT FOUND ";
	      }
	      else
	      {
		      newnode = new node;

		   cout<<"\n\n Enter a number : ";
		     cin>>newnode->num;

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

	    cout<<"\n\n Enter target number : ";
		 cin>>tnum;

	       temp = start;

	     while(temp!=NULL && temp->num != tnum)
	     {
		 temp = temp->next;
	     }

	     if(temp == NULL)
	     {
		 cout<<"\n\n TARGET NUMBER NOT FOUND ";
	     }
	     else
	     {
		   newnode = new node;

		 cout<<"\n\n Enter a num : ";
		   cin>>newnode->num;

		   newnode->prev = temp;
		   newnode->next = temp->next;
		   temp->next->prev = newnode;
		   temp->next = newnode;
	     }
       }

       void DELETE_BEGIN()
       {
	    struct node *temp;
	    temp = start->next;
	    delete start;
	    start = temp;
       }

       void DELETE_GIVEN()
       {
	   int tnum;
	   struct node *temp;

	   cout<<"\n\n Enter num to be deleted : ";
	      cin>>tnum;

	    if(tnum == start->num)
	    {
		DELETE_BEGIN();
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
		     cout<<"\n\n NUM NOT FOUND ";
		 }
		 else
		 {
		      temp->prev->next = temp->next;
		      temp->next->prev = temp->prev;
			delete temp;
		 }
	    }
       }

       void INSERT_END()
       {
	   struct node *temp, *newnode;

	   temp = start;

	   while(temp->next != NULL)
	   {
		temp = temp->next;
	   }

	      newnode = new node;

	      cout<<"\n\n Enter a num : ";
		cin>>newnode->num;

		newnode->prev = temp;
		newnode->next = NULL;
		temp->next = newnode;
       }

       void DELETE_END()
       {
	   struct node *temp;

	   if(start->next == NULL)
	   {
		delete start;
		start = NULL;
	   }
	   else
	   {
	       temp = start;

	       while(temp->next->next != NULL)
	       {
		   temp = temp->next;
	       }

		   delete temp->next;
		   temp->next = NULL;
	   }
       }

