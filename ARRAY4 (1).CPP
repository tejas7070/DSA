/*
     Linear Search
*/

   #include<iostream.h>
   #include<conio.h>

   void main()
   {
      int size, x[30], i, num, pos=0;

       clrscr();

     cout<<"\n\n Enter size : ";
	cin>>size;

     cout<<"\n\n Enter nums : \n";
	for(i=0 ;i<size ; i++)
	{
	    cin>>x[i];
	}

     cout<<"\n\n Enter num to be searched : ";
	cin>>num;

      for(i=0 ; i<size ; i++)
      {
	  if(num == x[i])
	  {
	      pos = i+1;
	      break;
	  }
      }

      if(pos == 0)
      {
	  cout<<"\n\n NUM NOT FOUND ";
      }
      else
      {
	  cout<<"\n\n pos =  "<<pos;
      }

       getch();
   }













