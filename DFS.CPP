
       #include<iostream.h>
       #include<conio.h>

       int n, adj[10][10]={0} , visited[10]={0};

	 void DFS(int);

     void main()
     {
	 int e, v1, v2, node, i, j;

	  clrscr();

	  cout<<"\n\n Enter no of nodes : ";
	     cin>>n;

	  cout<<"\n\n Enter no of edges : ";
	     cin>>e;

	  cout<<"\n\n Enter edges : \n";
	    for(i=1 ; i<=e ; i++)
	    {
		  cin>>v1>>v2;

		adj[v1-1][v2-1] = adj[v2-1][v1-1] = 1;
	    }

	   cout<<"\n\n Enter starting node : ";
		 cin>>node;

		cout<<"\n\n DFS : ";
		   DFS(node-1);

	   getch();
     }

	 void DFS(int node)
	 {
		  int i;

		 cout<<"  "<<node+1;
		  visited[node] = 1;

	       for(i=0 ; i<n ; i++)
	       {
		  if(adj[node][i] == 1 && visited[i] == 0)
		  {
		       DFS(i);
		  }
	       }
	 }

