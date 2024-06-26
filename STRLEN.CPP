
   #include<iostream.h>
   #include<conio.h>
   #include<stdio.h>
   #include<string.h>

   void main()
   {
     char str1[20];
      int i;

       clrscr();

     cout<<"\n\n Enter a string : ";
	 gets(str1);

	i = strlen(str1);

     cout<<"\n\n Length = "<<i;

       getch();
   }

