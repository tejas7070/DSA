/*
    Q]
	str = "i love java"

	str = "i evol avaj"
*/

   #include<iostream.h>
   #include<conio.h>
   #include<stdio.h>
   #include<string.h>

   void main()
   {
      char str[30], word[30];
      int i, j;

       clrscr();

    cout<<"\n\n Enter a string : ";
       gets(str);

     for(i=0 ; i<strlen(str); i++)
     {
	     j=0;

	  while(str[i] != ' ')
	  {
	      word[j] = str[i];
		 i++; j++;
	  }

	    word[j] = '\0';
	    cout<<strrev(word)<<" ";
     }

       getch();
   }









