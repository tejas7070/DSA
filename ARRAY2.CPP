
   #include<iostream.h>
   #include<conio.h>

   void main()
   {
      int x[5], i, sum=0;

       clrscr();

     cout<<"\n\n Enter 5 nums : \n";
	for(i=0 ; i<5; i++)
	{
	    cin>>x[i];

	    sum = sum + x[i];
	}

      cout<<"\n\n sum = "<<sum;
      cout<<"\n\n Average = "<<sum/5;

       getch();
   }











