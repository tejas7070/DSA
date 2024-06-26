/*
     Q] Transpose without using another matrix
*/

   #include<iostream.h>
   #include<conio.h>

   void main()
   {
      int A[3][3], i,j, temp;

       clrscr();

      cout<<"\n\n Enter 9 nums : \n";
	 for(i=0 ; i<3; i++)
	 {
	      for(j=0 ; j<3 ; j++)
	      {
		  cin>>A[i][j];
	      }
	 }

	 for(i=0 ; i<3; i++)
	 {
	      for(j=0 ; j<3 ; j++)
	      {
		  if(i < j)
		  {
		     temp = A[i][j];
		     A[i][j] = A[j][i];
		     A[j][i] = temp;
		  }
	      }
	 }

      cout<<"\n\n Matrix after transpose : \n";
	 for(i=0 ; i<3; i++)
	 {
	      for(j=0 ; j<3 ; j++)
	      {
		  cout<<"  "<<A[i][j];
	      }

		   cout<<"\n\n";
	 }

       getch();
   }

