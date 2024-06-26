/*
     STACK WITH ARRAYS (LIFO)
*/

   #include<iostream.h>
   #include<conio.h>
   #include<process.h>

      int x[30], top=-1;

      void PUSH()
      {
	     top++;

	  cout<<"\n\n Enter a num : ";
	     cin>>x[top];
      }

      void DISP()
      {
	  if(top == -1)
	  {
	      cout<<"\n\n STACK IS EMPTY ";
	  }
	  else
	  {
	      for(int i=top ; i>=0; i--)
	      {
		   cout<<"\n\n "<<x[i];
	      }
	  }
      }

      void PEEK()
      {
	  if(top == -1)
	  {
	      cout<<"\n\n STACK IS EMPTY ";
	  }
	  else
	  {
	      cout<<"\n\n PEEK = "<<x[top];
	  }
      }

      void POP()
      {
	  if(top == -1)
	  {
	      cout<<"\n\n STACK IS EMPTY ";
	  }
	  else
	  {
		 x[top] = 0;
		 top--;
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

