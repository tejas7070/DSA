/*
      DOUBLY ENDED QUEUE
*/

   #include<iostream.h>
   #include<conio.h>
   #include<process.h>

      int x[5], size=5, f=-1, r=-1;

     void INSERT_LEFT()
     {
	 if((f==0 && r==size-1) || (f == r+1))
	 {
	      cout<<"\n\n DQ OVERFLOW!";
		return;
	 }

	 if(f == -1)
	 {
	     f = r = 0;
	 }
	 else if(f == 0)
	 {
	     f = size-1;
	 }
	 else
	 {
	     f--;
	 }

	     cout<<"\n\n Enter a num : ";
		cin>>x[f];
     }

     void INSERT_RIGHT()
     {
	 if((f==0 && r==size-1) || (f == r+1))
	 {
	      cout<<"\n\n DQ OVERFLOW!";
		return;
	 }

	 if(r == -1)
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

     void DISPLAY()
     {
	  int i;

	 if(f == -1)
	 {
	      cout<<"\n\n DQ IS EMPTY ";
	 }
	 else
	 {
	       cout<<"\n\n DQ : ";

	     if(f <= r)
	     {
		 for(i=f ; i<=r ; i++)
		 {
		     cout<<"  "<<x[i];
		 }
	     }
	     else
	     {
		 for(i=f ; i<size ; i++)
		 {
		     cout<<"  "<<x[i];
		 }

		 for(i=0; i<=r ; i++)
		 {
		     cout<<"  "<<x[i];
		 }
	     }
	 }
     }

     void DELETE_LEFT()
     {
	  if(f == -1)
	  {
	       cout<<"\n\n DQ IS EMPTY ";
	  }
	  else if(f == r)
	  {
	      x[f] = 0;
	      f = r = -1;
	  }
	  else
	  {
	       x[f] = 0;
	       f++;
	  }
	  if(f == size)
	  {
	     f = 0;
	  }
     }

     void DELETE_RIGHT()
     {
	  if(r == -1)
	  {
	       cout<<"\n\n DQ IS EMPTY ";
	  }
	  else if(f == r)
	  {
	      x[r] = 0;
	      f = r = -1;
	  }
	  else
	  {
	      x[r] = 0;
	      r--;

		if(r == -1)
		{
		    r = size-1;
		}
	  }
     }

   int menu()
   {
	int choice;

	clrscr();

      cout<<"\n\n 1] INSERT_LEFT ";
      cout<<"\n 2] INSERT_RIGHT ";
      cout<<"\n 3] DELETE_LEFT ";
      cout<<"\n 4] DELETE_RIGHT ";
      cout<<"\n 5] DISPLAY ";
      cout<<"\n 6] EXIT ";

      cout<<"\n ENTER YOUR CHOICE : ";
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
		   INSERT_LEFT();
		   DISPLAY();
		   break;
	    case 2:
		   INSERT_RIGHT();
		   DISPLAY();
		   break;
	    case 3:
		   DELETE_LEFT();
		   DISPLAY();
		   break;
	    case 4:
		   DELETE_RIGHT();
		   DISPLAY();
		   break;
	    case 5:
		   DISPLAY();
		   break;
	    case 6:
		   cout<<"\n\n EXIT ";
		      getch();
		      exit(0);
	    default:
		    cout<<"\n\n INVALID INPUT ";
	}
	   getch();
     }while(ch != 6);
   }


