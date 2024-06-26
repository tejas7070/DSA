/*
    Expression Tree in C++
*/

   #include<iostream.h>
   #include<conio.h>
   #include<stdio.h>
   #include<string.h>
   #include<ctype.h>

   struct node
   {
	char ch;
	struct node *left;
	struct node *right;

   }*root=NULL;

   struct node *stk[30];
   int top=-1;

   void PUSH(struct node *n)
   {
       top++;
       stk[top] = n;
   }

   struct node* POP()
   {
       if(top != -1)
       {
	   return stk[top--];
       }
   }

       void INORDER(struct node *);
       void PREORDER(struct node *);
       void POSTORDER(struct node *);
                
   void main()
   {
      char post[50];
      int i;
      struct node *newnode;

       clrscr();

     cout<<"\n\n Enter postfix expression : ";
	 gets(post);

      for(i=0; i<strlen(post); i++)
      {
	  newnode = new node;
	  newnode->ch = post[i];
	  newnode->left = NULL;
	  newnode->right = NULL;

	  if(isalpha(post[i]))
	  {
	       PUSH(newnode);
	  }
	  else
	  {
	      newnode->right = POP();
	      newnode->left = POP();

		PUSH(newnode);
	  }
      }

	     root = POP();

	  cout<<"\n\n INORDER : ";
	    INORDER(root);

	  cout<<"\n\n PREORDER : ";
	    PREORDER(root);

	  cout<<"\n\n POSTORDER : ";
	    POSTORDER(root);

       getch();
   }

    void INORDER(struct node *root)
    {
	if(root != NULL)
	{
	    INORDER(root->left);
	    cout<<"  "<<root->ch;
	    INORDER(root->right);
	}
    }

    void PREORDER(struct node *root)
    {
	if(root != NULL)
	{
	    cout<<"  "<<root->ch;
	    PREORDER(root->left);
	    PREORDER(root->right);
	}
    }

    void POSTORDER(struct node *root)
    {
	if(root != NULL)
	{
	    POSTORDER(root->left);
	    POSTORDER(root->right);
	    cout<<"  "<<root->ch;
	}
    }

