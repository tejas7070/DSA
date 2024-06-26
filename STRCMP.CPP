/*
      ASCII

      A=65   a=97
      B=66   b=98
      C=67   c=99
*/

   #include<iostream.h>
   #include<conio.h>
   #include<stdio.h>
   #include<string.h>

   void main()
   {
     char str1[20], str2[20];
      int i;

       clrscr();

     cout<<"\n\n Enter a string : ";
	 gets(str1);

     cout<<"\n\n Enter a string : ";
	 gets(str2);

       i = strcmpi(str1, str2);

       cout<<"\n\n i = "<<i;

     if(i == 0)
     {
	 cout<<"\n\n SAME STRING ";
     }
     else
     {
	 cout<<"\n\n NOT SAME STRING ";
     }

       getch();
   }

