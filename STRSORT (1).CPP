/*
    Q] Program to sort a tring in asc order

	str = "monday";
	str = "admnoy"
*/

   #include<iostream.h>
   #include<conio.h>
   #include<stdio.h>
   #include<string.h>

   void main()
   {
      char str[30], temp;
	int i,j;

       clrscr();

     cout<<"\n\n Enter a string : ";
	  gets(str);

      for(i=0 ; i<strlen(str) ; i++)
      {
	  for(j=i+1 ; j<strlen(str); j++)
	  {
	      if(str[i] > str[j])
	      {
		  temp = str[i];
		  str[i] = str[j];
		  str[j] = temp;
	      }
	  }
      }

      cout<<"\n\n sorted string = "<<str;

       getch();
   }














