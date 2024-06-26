/*
     STACK WITH Linked List (LIFO)
*/

   #include<iostream.h>
   #include<conio.h>
   #include<process.h>

    struct node
    {
	int num;
	node *prev;

    }*top=NULL;

      void PUSH()
      {
	   node *newnode = new node;

	    cout<<"\n\n Enter a num : ";
	      cin>>newnode->num;

	     newnode->prev = top;
	      top = newnode;
      }

      void DISP()
      {
	   if(top == NULL)
	   {
	       cout<<"\n\n STACK IS EMPTY ";
	   }
	   else
	   {
		 node *temp = top;

		 while(temp != NULL)
		 {
		      cout<<"\n\n "<<temp->num;
			temp = temp->prev;
		 }
	   }
      }

      void PEEK()
      {
	   if(top == NULL)
	   {
	       cout<<"\n\n STACK IS EMPTY ";
	   }
	   else
	   {
	       cout<<"\n\n PEEK = "<<top->num;
	   }
      }

      void POP()
      {
	   if(top == NULL)
	   {
	       cout<<"\n\n STACK IS EMPTY ";
	   }
	   else
	   {
		  node *temp = top->prev;
		    delete top;
		    top = temp;
	   }
      }

    int menu()
    {
	 int choice;

	 clrscr();

	 cout<<"\n\n 1] PUSH ";
	 cout<<"\n 2] DISP ";
	 cout<<"\n 3] PEEK ";
	 cout<<"\n 4] POP ";
	 cout<<"\n 5] EXIT ";

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
		       PUSH();
		       DISP();
		       break;
	       case 2:
		       DISP();
		       break;
	       case 3:
		       PEEK();
		       break;
	       case 4:
		       POP();
		       DISP();
		       break;
	       case 5:
		       cout<<"\n\n EXIT ";
			 getch();
			 exit(0);
	       default:
		       cout<<"\n\n INVALID INPUT ";
	   }
	   getch();
       }while(ch != 5);
   }

