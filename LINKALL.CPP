
   #include<iostream.h>
   #include<conio.h>
   #include<process.h>

   struct node
   {
       int num;
       struct node *next;

   }*start=NULL;

      void CREATE();
      void DISP();
      void INSERT_BEGIN();
      void INSERT_END();
      void INSERT_BEFORE();
      void INSERT_AFTER();
      void DELETE_BEGIN();
      void DELETE_GIVEN();
      void DELETE_END();
      void SEARCH();
      void SORT();
      void REVERSE();

   int menu()
   {
	int choice;

	clrscr();

       cout<<"\n\n 1] CREATE A LINKED LIST ";
       cout<<"\n 2] DISPLAY A LINKED LIST ";
       cout<<"\n 3] INSERT_BEGIN ";
       cout<<"\n 4] INSERT_END ";
       cout<<"\n 5] INSERT_BEFORE ";
       cout<<"\n 6] INSERT_AFTER ";
       cout<<"\n 7] DELETE_BEGIN";
       cout<<"\n 8] DELETE_GIVEN";
       cout<<"\n 9] DELETE_END";
       cout<<"\n 10] SEARCH an element ";
       cout<<"\n 11] SORT LIST ";
       cout<<"\n 12] REVERSE A LIST ";
       cout<<"\n 13] EXIT ";

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
		       INSERT_END();
		       DISP();
		       break;
	      case 5:
		       INSERT_BEFORE();
		       DISP();
		       break;
	      case 6:
		       INSERT_AFTER();
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
		       DELETE_END();
		       DISP();
		       break;
	      case 10:
		       SEARCH();
		       break;
	      case 11:
		       SORT();
		       DISP();
		       break;
	      case 12:
		       REVERSE();
		       DISP();
		       break;
	      case 13:
			cout<<"\n\n EXIT ";
			  getch();
			  exit(0);
	      default:
			 cout<<"\n\n INVALID INPUT ";
	  }
	     getch();
     }while(ch != 13);
   }

	 void REVERSE()
	 {
	     struct node *prev , *temp, *temp2;
		 prev = NULL;
		 temp = start;

		 while(temp != NULL)
		 {
		     temp2 = temp->next;
		     temp->next = prev;
		     prev = temp;
		     temp = temp2;
		 }
		     start = prev;
	 }

     void SORT()
     {
	   struct node *p1, *p2;
	     int temp;

	   for(p1=start ; p1!=NULL ; p1=p1->next)
	   {
		 for(p2=p1->next ; p2!=NULL ; p2=p2->next)
		 {
		      if(p1->num > p2->num)
		      {
			  temp = p1->num;
			  p1->num = p2->num;
			  p2->num = temp;
		      }
		 }
	   }
     }

     void CREATE()
     {
	 struct node *newnode , *temp;
	 newnode = new node;

	 cout<<"\n\n  Enter a num : ";
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
		    temp= temp->next;
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

	    newnode->next = start;
	    start = newnode;
     }

     void INSERT_BEFORE()
     {
	 int tnum;
	 struct node *temp, *newnode;

	  cout<<"\n\n Enter target num : ";
	     cin>>tnum;

	  if(tnum == start->num)
	  {
	      INSERT_BEGIN();
	  }
	  else
	  {
		  temp = start;

	       while(temp->next!=NULL && temp->next->num != tnum)
	       {
		     temp = temp->next;
	       }

		 if(temp->next == NULL)
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
	 struct node *temp, *newnode;

	  cout<<"\n\n Enter target num : ";
	     cin>>tnum;

	      temp = start;

	   while(temp != NULL  && temp->num != tnum)
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
	 struct node *newnode , *temp;

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

     void DELETE_GIVEN()
     {
	 int tnum;
	 struct node *temp, *temp2;

	   cout<<"\n\n Enter num to be deleted : ";
	       cin>>tnum;

	  if(tnum == start->num)
	  {
	      DELETE_BEGIN();
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
		   cout<<"\n\n NUM NOT FOUND ";
	       }
	       else
	       {
		     temp2 = temp->next->next;
		       delete temp->next;
		       temp->next = temp2;
	       }
	  }
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

     void SEARCH()
     {
	  int num;
	  struct node *temp;
	  int pos=1;

	 cout<<"\n\n Enter num to be searched : ";
	     cin>>num;

	       temp = start;

	   while(temp != NULL && temp->num != num)
	   {
	       temp = temp->next;
		 pos++;
	   }

	   if(temp == NULL)
	   {
	       cout<<"\n\n NUM NOT FOUND ";
	   }
	   else
	   {
		cout<<"\n\n NUM FOUND ";
		cout<<"\n pos = "<<pos;
	   }
     }

