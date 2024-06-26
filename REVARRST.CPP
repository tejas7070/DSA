/*
    HOMEWORK
    Q] Reverse a string using stack

	 str = "Computer"
	 str = "retupmoC"
---------------------------------------------------
     Q] Reverse an array using stack
*/

   #include<iostream.h>
   #include<conio.h>

     int stk[30], top=-1;

    void PUSH(int n)
    {
	 top++;
	 stk[top] = n;
    }

    int POP()
    {
	if(top != -1)
	{
	    return stk[top--];
	}
    }

   void main()
   {
       int size, x[30], i;

	clrscr();

      cout<<"\n\n Enter size : ";
	 cin>>size;

      cout<<"\n\n Enter nums : \n";
	 for(i=0 ; i<size ; i++)
	 {
	     cin>>x[i];
	 }

	 for(i=0 ; i<size ; i++)
	 {
	     PUSH(x[i]);
	 }

	 for(i=0 ; i<size ; i++)
	 {
	     x[i] = POP();
	 }

	cout<<"\n\n List after reverse : \n";
	   for(i=0 ; i<size ; i++)
	   {
	       cout<<"  "<<x[i];
	   }

	getch();
   }








