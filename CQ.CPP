/*
    CIRCULAR QUEUE (FIFO)
*/

   #include<iostream.h>
   #include<conio.h>
   #include<process.h>

      int x[5], size=5, f=-1 , r=-1;

     void PUSH()
     {
	 if((f==0 && r==size-1) || (f == r+1))
	 {
	     cout<<"\n\n CQ OVERFLOW ";
		return;
	 }
	 if(f == -1)
	 {
	     f = 0;
	 }
	 if(r == size-1)
	 {
	     r = -1;
	 }

		r++;

	  cout<<"\n\n Enter a num : ";
	     cin>>x[r];
     }

     void DISP()
     {
	     int i;

	 if(f == -1)
	 {
	      cout<<"\n\n CQ IS EMPTY ";
	 }
	 else
	 {
	       cout<<"\n\n CQ : ";

	     if(f <= r)
	     {
		 for(i=f ; i<=r; i++)
		 {
		     cout<<"  "<<x[i];
		 }
	     }
	     else
	     {
		for(i=f; i<size ; i++)
		{
		   cout<<"  "<<x[i];
		}

		for(i=0 ; i<=r; i++)
		{
		    cout<<"  "<<x[i];
		}
	     }
	 }
     }

     void POP()
     {
	  if(f == -1)
	  {
	      cout<<"\n\n CQ IS EMPTY ";
	  }
	  else
	  {
	       x[f] = 0;
	       f++;
	  }
	  if(f == r+1)
	  {
	      f = r = -1;
	  }
	  if(f == size)
	  {
	      f = 0;
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

