   #include<stdio.h>
   #include<conio.h>
   #include<process.h>

       struct node
       {
	   int num;
	   struct node *next;
       };

	 struct node *F = NULL;
	 struct node *R = NULL;

       void PUSH()
       {
	    struct node *newnode;
	    newnode = malloc(sizeof(struct node));

	      printf("\n\n Enter a num : ");
	       scanf("%d", &newnode->num);

		 newnode->next = NULL;

	     if(F == NULL)
	     {
		 F = R = newnode;
	     }
	     else
	     {
		 R->next = newnode;
		 R = newnode;
	     }
       }

       void DISP()
       {
	   struct node *temp;

	   if(F == NULL)
	   {
	       printf("\n\n QUEUE IS EMPTY ");
	   }
	   else
	   {
		    temp = F;

		while(temp != NULL)
		{
		     printf("\n\n %d ", temp->num);

			temp = temp->next;
		}
	   }
       }

       void PEEK()
       {
	   if(F == NULL)
	   {
	       printf("\n\n QUEUE IS EMPTY ");
	   }
	   else
	   {
	       printf("\n\n PEEK = %d ", f->num);
	   }
       }

       void POP()
       {
	    struct node *temp;

	   if(F == NULL)
	   {
	       printf("\n\n QUEUE IS EMPTY ");
	   }
	   else
	   {
		temp = F->next;
		  free(F);
		  F = temp;
	   }
	   if(F == NULL)
	   {
		R = NULL;
	   }
       }

    int menu()
    {
	 int choice;

	 clrscr();

	printf("\n\n 1] PUSH ");
	printf("\n 2] DISP ");
	printf("\n 3] PEEK ");
	printf("\n 4] POP ");
	printf("\n 5] EXIT ");

	printf("\n\n Enter your choice : ");
	    scanf("%d", &choice);

	    return choice;
    }

   void main()
   {
      int ch;

       clrscr();

       do
       {
	   ch = menu();

	   switch(ch)
	   {
	      case 1:
		      PUSH();
		      DISP();
		      break;
	      case 2:
		      DISP();
		      break;
	      case 3:
		      PEEK();
		      break;
	      case 4:
		      POP();
		      DISP();
		      break;
	      case 5:
		      printf("\n\n EXIT ");
			getch();
			exit(0);
	      default:
		      printf("\n\n INVALID INPUT ");
	   }
	      getch();
       }while(ch != 5);
   }
