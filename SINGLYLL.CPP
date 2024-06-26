/*
      SINGLE LINKED LIST
*/

   #include<iostream.h>
   #include<conio.h>
   #include<process.h>

      void CREATE();
      void DISP();
      void INSERT_BEGIN();
      void INSERT_BEFORE();
      void INSERT_AFTER();
      void INSERT_END();
      void DELETE_BEGIN();
      void DELETE_END();

     struct node
     {
	 int num;
	 node *next;

     }*start=NULL;

     int menu()
     {
	    int choice;

	   clrscr();

	 cout<<"\n\n 1] CREATE A LINKED LIST ";
	 cout<<"\n 2] DISPLAY LINKED LIST ";
	 cout<<"\n 3] INSERT_BEGIN ";
	 cout<<"\n 4] INSERT_BEFORE ";
	 cout<<"\n 5] INSERT_AFTER ";
	 cout<<"\n 6] INSERT_END ";
	 cout<<"\n 7] DELETE_BEGIN ";
	 cout<<"\n 8] DELETE_END ";
	 cout<<"\n 9] EXIT ";

	  cout<<"\n\n Enter your choice : ";
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
		       INSERT_END();
		       DISP();
		       break;
	      case 7:
		       DELETE_BEGIN();
		       DISP();
		       break;
	      case 8:
		       DELETE_END();
		       DISP();
		       break;
	      case 9:
		       cout<<"\n\n EXIT ";
			  getch();
			  exit(0);
	      default:
		      cout<<"\n\n INVALID INPUT ";
	  }
	     getch();
      }while(ch != 9);
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

		   temp= temp->next;
	      }
	  }
     }

      void INSERT_BEGIN()
      {
	  struct node *newnode;
	  newnode = new node;

	    cout<<"\n\n Enter a num : ";
	       cin>>newnode->num;

	       newnode->next = start;
	       start = newnode;
      }

      void INSERT_BEFORE()
      {
	  int tnum;
	  struct node *newnode, *temp;

	   cout<<"\n\n Enter target number : ";
	      cin>>tnum;

	   if(tnum == start->num)
	   {
	       INSERT_BEGIN();
	   }
	   else
	   {
		    temp = start;

	       while(temp->next != NULL && temp->next->num != tnum)
	       {
		     temp = temp->next;
	       }

	       if(temp->next == NULL)
	       {
		   cout<<"\n\n TARGET NUMBER NOT FOUND ";
	       }
	       else
	       {
		     newnode = new node;

		   cout<<"\n\n Enter a num : ";
		      cin>>newnode->num;

		    newnode->next = temp->next;
		    temp->next = newnode;
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

	    while(temp != NULL && temp->num != tnum)
	    {
		temp = temp->next;
	    }

	    if(temp == NULL)
	    {
		cout<<"\n\n TARGET NUM NOT FOUND ";
	    }
	    else
	    {
		  newnode = new node;

		cout<<"\n\n Enter a num : ";
		   cin>>newnode->num;

		newnode->next = temp->next;
		  temp->next = newnode;
	    }
      }

      void INSERT_END()
      {
	   struct node *newnode, *temp;

	      temp = start;

	    while(temp->next != NULL)
	    {
		 temp = temp->next;
	    }

	      newnode = new node;

	      cout<<"\n\n Enter a num : ";
		 cin>>newnode->num;

	      newnode->next = NULL;
	      temp->next = newnode;
      }

      void DELETE_BEGIN()
      {
	   struct node *temp;

	   temp = start->next;
	     delete start;
	     start = temp;
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


