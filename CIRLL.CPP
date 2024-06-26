
   #include<iostream.h>
   #include<conio.h>
   #include<process.h>

    struct node
    {
	int num;
	struct node *next;
    };

       struct node *start=NULL;

       void CREATE();
       void DISP();
       void INSERT_BEGIN();
       void INSERT_BEFORE();
       void INSERT_AFTER();
       void INSERT_END();
       void DELETE_BEGIN();
       void DELETE_END();

      int menu()
      {
	  int choice;

	  clrscr();

	  cout<<"\n\n 1] Create a Circular LL ";
	  cout<<"\n 2] DISPLAY LL";
	  cout<<"\n 3] INSERT_BEGIN";
	  cout<<"\n 4] INSERT_BEFORE";
	  cout<<"\n 5] INSERT_AFTER";
	  cout<<"\n 6] INSERT_END";
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

	   if(start == NULL)
	   {
	      start = newnode;
	      newnode->next = start;
	   }
	   else
	   {
		 temp = start;

	       while(temp->next != start)
	       {
		    temp = temp->next;
	       }

		   temp->next = newnode;
		   newnode->next = start;
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

	       do
	       {
		   cout<<"\n\n "<<temp->num;

		      temp = temp->next;

	       }while(temp != start);

	   }
      }

      void INSERT_BEGIN()
      {
	   struct node *newnode, *temp;
	   newnode = new node;

	     cout<<"\n\n Enter a num : ";
		cin>>newnode->num;

	     newnode->next = start;

		temp = start;

	     while(temp->next != start)
	     {
		 temp = temp->next;
	     }

		temp->next = newnode;
		start = newnode;
      }

      void INSERT_BEFORE()
      {
	   int tnum;
	   struct node *newnode, *temp;

	     cout<<"\n\n Enter target num : ";
		cin>>tnum;

	     if(tnum == start->num)
	     {
		 INSERT_BEGIN();
	     }
	     else
	     {
		  temp = start;

		 while(temp->next!=start && temp->next->num != tnum)
		 {
		      temp = temp->next;
		 }

	       if(temp->next == start)
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
      }

      void INSERT_AFTER()
      {
	   int tnum;
	   struct node *newnode, *temp;

	     cout<<"\n\n Enter target num : ";
		cin>>tnum;

	       temp = start;

	    while(temp->num != tnum && temp->next != start)
	    {
		temp = temp->next;
	    }

	     if(temp->num != tnum && temp->next == start)
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

	     while(temp->next != start)
	     {
		 temp = temp->next;
	     }

		newnode = new node;

		cout<<"\n\n Enter a num : ";
		   cin>>newnode->num;

		 newnode->next = temp->next;
		 temp->next = newnode;
      }

      void DELETE_BEGIN()
      {
	   struct node *temp, *temp2;

	   if(start->next == start)
	   {
		delete start;
		start = NULL;
	   }
	   else
	   {
		temp2 = start->next;

		  temp = start;

	       while(temp->next != start)
	       {
		   temp = temp->next;
	       }

		 temp->next = temp2;
		   delete start;
		   start = temp2;
	   }
      }

      void DELETE_END()
      {
	  struct node *temp;

	  if(start->next == start)
	  {
	      delete start;
	      start = NULL;
	  }
	  else
	  {
		 temp = start;

	      while(temp->next->next != start)
	      {
		  temp = temp->next;
	      }

		   delete temp->next;
		   temp->next = start;
	  }
      }
