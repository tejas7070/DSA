/*
       TOWER OF HANOI
*/

     #include<iostream.h>
     #include<conio.h>

	 void move(int , char , char , char);

     void main()
     {
	 int n;

	 clrscr();

	 cout<<"\n\n Enter no discs : ";
	     cin>>n;

	 move(n , 'A' , 'B' , 'C');

	 getch();
     }

	  void move(int n , char src , char aux, char dest)
	  {
	      if(n >= 1)
	      {
		  move(n-1, src , dest , aux);
		  cout<<"\n\n move "<<src<<" => "<<dest;
		  move(n-1 , aux , src , dest);
	      }
	  }

/*
    n=3
	x move(3, A, B, C)
	  x move(2, A, C, B)
	    x move(1, A, B, C)
	      x move(0, A, C, B)
   A to C
	    x move(0, B,A,C)
   A to B
	   x move(1, C, A, B)
	     x move(0, C, B, A)
   C to B
	  x  move(0, A, C, B)
   A to C
	  x move(2, B,A,C)
	    x move(1, B,C,A)
	      x move(0, B,A,C)
   B to A
	     move(0, C, B,A)
   B to C
	   x move(1, A,B,C)
	    x move(0, A, C, B)
   A to C
	   move(0, B,A,C)
-----------------------------------------------------------------------------
   n=2
      x	move(2, A, B, C)
	x  move(1, A, C, B)
	  x  move(0, A, B , C)
    A => B
	  move(0, C, A, B)
    A => C
	  move(1, B, A, C)
	   x move(0, B, C, A)
    B => C
	  move(0, A, B , C)
-----------------------------------------------------------------------------
   n=1
	  move(1, A, B, C);
	   x move(0, A, C, B)
    A => C
	     move(0, B, A, C)
*/











/*
 n=3
       x move(3 , A, B , C)
	  x move(2 , A, C, B)
	    x move(1, A, B , C)
	       x move(0, A, C, B)
    Print A -> C
	       x move(0, B, A, C);
    Print A -> B
		x move(1, C,A,B);
		    xmove(0, C,B,A)
    Print C -> B
    Print A -> C
		 x move(2, B, A, C)
		   x move(1, B, C, A);
		      x move(0, B, A, C)
    Print B -> A
		      xmove(0, C, B , A)
    Print B -> C
		      x move(1, A, B , C);
			x move(0, A, C, B)
    Print A -> C
		      x move(0, B, A, C);
*/








/*
    n=2
	  x move(2 , A, B ,C)
	     x  move(1, A, C, B)
		 x move(0, A, B , C)
      Print A to B
	       move(0, C, A, B);
      Print A to C
	   move(1, B, A, C);
	    x move(0, B, C, A)
      Print B to C
	    move(0, A, B, C)
*/

/*
      n=2
	 x move(2 , A, B , C)
	    xmove(1, A, C, B)
	      x	move(0, A, B , C)

      print A to B

	    x move(0 , C, A, B)

      print A to C

	      xmove(1, B, A, C);
		 x move(0, B,C,A)

      print B to C

	       xmove(0, A, B , C)

-----------------------------------------------
    n=1
	 move(1, A , B , C)
	   move(0, A, C , B)
   print A to C
	   move(0, B , A , C)
*/

