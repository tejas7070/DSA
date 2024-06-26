
   #include<iostream.h>
   #include<conio.h>
   #include<process.h>

   struct node    // self-referential structure
   {
       int num;
       struct node *left;
       struct node *right;
   };

      struct node* INSERT(struct node* , int);
	void INORDER(struct node *);
	void PREORDER(struct node *);
	void POSTORDER(struct node *);

	void COUNT_ALL(struct node *);
	void COUNT_LEAF(struct node *);
	void COUNT_BRANCH(struct node *);

      struct node* FIND_MIN(struct node *);
      struct node* FIND_MAX(struct node *);

      struct node* DELETE(struct node *, int);

      int menu()
      {
	   int choice;

	   clrscr();

	 cout<<"\n\n 1] INSERT A NODE ";
	 cout<<"\n 2] INORDER TRAVERSAL ";
	 cout<<"\n 3] PREORDER TRAVERSAL ";
	 cout<<"\n 4] POSTORDER TRAVERSAL ";
	 cout<<"\n 5] COUNT_ALL NODES";
	 cout<<"\n 6] COUNT_LEAF NODES ";
	 cout<<"\n 7] COUNT_BRANCH NODES ";
	 cout<<"\n 8] FIND_MIN ";
	 cout<<"\n 9] FIND_MAX";
	 cout<<"\n 10] DELETE A NODE";
	 cout<<"\n 11] EXIT ";

	 cout<<"\n\n Enter your choice : ";
	     cin>>choice;

	     return choice;
      }

    int count = 0;

   void main()
   {
       int ch, n;
       struct node *root=NULL;
       struct node *temp;

       clrscr();

      do
      {
	  ch = menu();

	  switch(ch)
	  {
	      case 1:
		      cout<<"\n\n Enter a num : ";
			 cin>>n;

		    root = INSERT(root, n);
			break;
	     case 2:
		      cout<<"\n\n INORDER : ";
			 INORDER(root);
			  break;
	     case 3:
		      cout<<"\n\n PREORDER : ";
			 PREORDER(root);
			  break;
	     case 4:
		      cout<<"\n\n POSTORDER : ";
			 POSTORDER(root);
			  break;
	     case 5:
			   count=0;
			   COUNT_ALL(root);
			   cout<<"\n\n count = "<<count;
			    break;
	     case 6:
			   count=0;
			   COUNT_LEAF(root);
			   cout<<"\n\n count = "<<count;
			    break;
	     case 7:
			   count=0;
			   COUNT_BRANCH(root);
			   cout<<"\n\n count = "<<count;
			    break;
	     case 8:
			 temp = FIND_MIN(root);
			 cout<<"\n\n MIN = "<<temp->num;
			    break;
	     case 9:
			 temp = FIND_MAX(root);
			 cout<<"\n\n MAX = "<<temp->num;
			    break;
	     case 10:
		      cout<<"\n\n Enter a num : ";
			 cin>>n;

		    root = DELETE(root, n);
			break;
	     case 11:
		       cout<<"\n\n EXIT ";
			  getch();
			  exit(0);
	     default:
		     cout<<"\n\n INVALID INPUT ";
	  }
	    getch();
      }while(ch != 11);
   }

      struct node* INSERT(struct node *root , int n)
      {
	  struct node *newnode;

	  if(root == NULL)
	  {
	      newnode = new node;
	      newnode->num = n;
	      newnode->left = NULL;
	      newnode->right = NULL;
	      root = newnode;
	  }
	  else if(n <= root->num)
	  {
	     root->left = INSERT(root->left , n);
	  }
	  else
	  {
	     root->right = INSERT(root->right , n);
	  }

	    return root;
      }

      void INORDER(struct node *root)
      {
	  if(root != NULL)
	  {
	      INORDER(root->left);
	      cout<<"  "<<root->num;
	      INORDER(root->right);
	  }
      }

      void PREORDER(struct node *root)
      {
	  if(root != NULL)
	  {
	      cout<<"  "<<root->num;
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
	      cout<<"  "<<root->num;
	  }
      }

      void COUNT_ALL(struct node *root)
      {
	  if(root != NULL)
	  {
	       count++;

	      COUNT_ALL(root->left);
	      COUNT_ALL(root->right);
	  }
      }

      void COUNT_LEAF(struct node *root)
      {
	  if(root != NULL)
	  {
	      if(root->left == NULL && root->right == NULL)
	       count++;

	      COUNT_LEAF(root->left);
	      COUNT_LEAF(root->right);
	  }
      }

      void COUNT_BRANCH(struct node *root)
      {
	  if(root != NULL)
	  {
	      if(root->left != NULL || root->right != NULL)
	       count++;

	      COUNT_BRANCH(root->left);
	      COUNT_BRANCH(root->right);
	  }
      }

      struct node* FIND_MIN(struct node *root)
      {
	   if(root->left == NULL)
	   {
	       return root;
	   }
	   else
	   {
	       FIND_MIN(root->left);
	   }
      }

      struct node* FIND_MAX(struct node *root)
      {
	   if(root->right == NULL)
	   {
	       return root;
	   }
	   else
	   {
	       FIND_MAX(root->right);
	   }
      }

      struct node* DELETE(struct node *root, int n)
      {
	   struct node *temp;

	   if(root == NULL)
	   {
	       cout<<"\n\n NUM NOT FOUND ";
	   }
	   else if(n < root->num)
	   {
	       root->left = DELETE(root->left , n);
	   }
	   else if(n > root->num)
	   {
	      root->right = DELETE(root->right, n);
	   }
	   else
	   {
		if(root->left == NULL)
		{
		     temp = root->right;
		     delete root;
		     root = temp;
		}
		else if(root->right == NULL)
		{
		     temp = root->left;
		     delete root;
		     root = temp;
		}
		else
		{
		     temp = FIND_MAX(root->left);
		     root->num = temp->num;
		     root->left = DELETE(root->left, temp->num);
		}
	   }

	     return root;
      }

