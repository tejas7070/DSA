/*
     Q]  Find longest word(s) in a given string

	 str = "This is my book"

	 Longest words => This, book
	 Length = 4
*/

   #include<iostream.h>
   #include<conio.h>
   #include<stdio.h>
   #include<string.h>

   void main()
   {
      char str[30], word[30], longest[30]="";
      int i, j, max=0;


       clrscr();

     cout<<"\n\n Enter a string : ";
	gets(str);

     for(i=0 ; i<strlen(str) ; i++)
     {
	  j=0 ;

	  while(str[i]!=' ' && str[i]!='\0')
	  {
	      word[j] = str[i];
		i++; j++;
	  }

	     word[j] = '\0';

	   if(max <= strlen(word))
	   {
	       max = strlen(word);

	       strcat(longest, word);
	       strcat(longest, " , ");
	   }
     }

       cout<<"\n\n Longets word(s) = "<<longest;
       cout<<"\n\n Length = "<<max;

       getch();
   }

