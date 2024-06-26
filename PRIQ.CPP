/*
    PRIORITY QUEUE WITH LINKED LIST (FIFO)
*/

   #include<iostream.h>
   #include<conio.h>
   #include<process.h>

     struct node
     {
	  int num;
	  int pri;
	  struct node *next;
     };

	struct node *f = NULL;
	struct node *r = NULL;

      void PUSH()
      {
	   struct node *newnode, *temp;

	    newnode = new node;

	    cout<<"\n\n Enter a num : ";
	     cin>>newnode->num;

	    cout<<"\n\n Enter priority : ";
	     cin>>newnode->pri;

	     newnode->next = NULL;

	   if(f == NULL)
	   {
	       f = r = newnode;
	   }
	   else if(newnode->pri < f->pri)
	   {
	       newnode->next = f;
	       f = newnode;
	   }
	   else
	   {
		temp = f;

	      while(temp->next!=NULL && temp->next->pri<=newnode->pri)
	      {
		    temp = temp->next;
	      }

	      if(temp->next != NULL)
	      {
		  newnode->next = temp->next;
		  temp->next = newnode;
	      }
	      else
	      {
		  r->next = newnode;
		  r = newnode;
	      }
	   }
      }

      void DISP()
      {
	   struct node *temp;

	  if(f == NULL)
	  {
	       cout<<"\n\n PRIQ IS EMPTY ";
	  }
	  else
	  {
	       temp = f;

	     while(temp != NULL)
	     {
		 cout<<"\n\n "<<temp->num<<"["<<temp->pri<<"]";

		    temp = temp->next;
	     }
	  }
      }

      void POP()
      {
	   struct node *temp;

	  if(f == NULL)
	  {
	       cout<<"\n\n PRIQ IS EMPTY ";
	  }
	  else
	  {
	       temp = f->next;
		delete f;
		f = temp;
	  }
	  if(f == NULL)
	  {
	     r = NULL;
	  }
      }

     int menu()
     {
	  int choice;

	  clrscr();

	cout<<"\n\n 1] PUSH ";
	cout<<"\n 2] DISP ";
	cout<<"\n 3] POP ";
	cout<<"\n 4] EXIT ";

	cout<<"\n\n  Enter your choice : ";
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
		   PUSH();
		   DISP();
		   break;
	   case 2:
		   DISP();
		   break;
	   case 3:
		   POP();
		   DISP();
		   break;
	   case 4:
		   cout<<"\n\n EXIT ";
		     getch();
		     exit(0);
	   default:
		   cout<<"\n\n INVALID INPUT ";
	}
	   getch();
     }while(ch != 4);
   }


