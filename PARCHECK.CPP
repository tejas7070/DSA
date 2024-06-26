/*
     Q] Parenthesis Checker
*/

   #include<iostream.h>
   #include<conio.h>
   #include<stdio.h>
   #include<string.h>

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

   void main()
   {
       char infix[50];
       int i, flag=1;

	clrscr();

      cout<<"\n\n Enter an infix expression : ";
	 gets(infix);

      for(i=0 ; i<strlen(infix); i++)
      {
	  if(infix[i] == '(' || infix[i]=='[' || infix[i]=='{')
	  {
	       PUSH(infix[i]);
	  }
	  else
	  {
	      if(infix[i] == ')')
	      {
		  if(POP() != '(')
		  {
		      flag = 2;
		      break;
		  }
	      }
	      if(infix[i] == ']')
	      {
		  if(POP() != '[')
		  {
		      flag = 2;
		      break;
		  }
	      }
	      if(infix[i] == '}')
	      {
		  if(POP() != '{')
		  {
		      flag = 2;
		      break;
		  }
	      }
	  }
      }

      if(flag == 1 && top==-1)
      {
	  cout<<"\n\n VALID INFIX EXPRESSION ";
      }
      else
      {
	  cout<<"\n\n INVALID INFIX EXPRESSION ";
      }

	getch();
   }

