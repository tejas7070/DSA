/*
     Q] String Palindrome
*/

   #include<iostream.h>
   #include<conio.h>
   #include<stdio.h>
   #include<string.h>

   void main()
   {
      char str[20];
      int i,j, len, flag=1;

       clrscr();

     cout<<"\n\n Enter a string : ";
	  gets(str);

	len = strlen(str);

    for(i=0,j=len-1 ; i<len/2 ; i++,j--)
    {
	  if(str[i] != str[j])
	  {
	       flag = 2;
	       break;
	  }
    }

    if(flag == 1)
    {
	cout<<"\n\n Palindrome ";
    }
    else
    {
	cout<<"\n\n NOT Palindrome ";
    }

       getch();
   }




