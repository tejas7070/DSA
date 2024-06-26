/*
     INFIX TO POSTFIX
*/

   #include<iostream.h>
   #include<conio.h>
   #include<stdio.h>
   #include<string.h>
   #include<ctype.h>

   char stk[30];
   int top=-1;

   void PUSH(char ch)
   {
	 top++;
	stk[top] = ch;
   }

   char POP()
   {
       if(top != -1)
       {
	   return stk[top--];
       }
   }

   int getpri(char op)
   {
	if(op == '*' || op=='%' || op=='/')
	{
	     return 1;
	}
	else if(op=='+' || op=='-')
	{
	     return 0;
	}
	else
	{
	     return -1;
	}
   }

   void main()
   {
      char infix[50], postfix[50];
	int i, j=0;

	clrscr();

      cout<<"\n\n Enter infix expression : ";
	  gets(infix);

      for(i=0 ; i<strlen(infix); i++)
      {
	  if(infix[i] == '(')
	  {
	       PUSH(infix[i]);
	  }
	  else if(isalpha(infix[i]))
	  {
	     postfix[j] = infix[i];
		j++;
	  }
	  else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*'
				       || infix[i]=='/' || infix[i]=='%')
	  {
		while(top!=-1 && getpri(stk[top]) >= getpri(infix[i]))
		{
		    postfix[j] = POP();
		       j++;
		}

		     PUSH(infix[i]);
	  }
	  else if(infix[i] == ')')
	  {
	      while(top!=-1 && stk[top]!='(')
	      {
		   postfix[j] = POP();
		     j++;
	      }

		   POP();
	  }
      }

	   while(top!=-1)
	   {
	       postfix[j] = POP();
		  j++;
	   }

		postfix[j] = '\0';

	   cout<<"\n\n Postfix = "<<postfix;

	getch();
   }
