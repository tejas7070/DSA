
   #include<iostream.h>
   #include<conio.h>
   #include<stdio.h>
   #include<string.h>

   void main()
   {
     char str1[20], str2[20];

       clrscr();

     cout<<"\n\n Enter a string : ";
	 gets(str1);

     cout<<"\n\n Enter a string : ";
	 gets(str2);

       strcat(str1, str2);

     cout<<"\n\n str1 = "<<str1;
     cout<<"\n\n str2 = "<<str2;

       getch();
   }

