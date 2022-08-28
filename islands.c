#include "pqueue.h"
// ENZO HOLZMANN GAIO EX02 2449013
//melhor caso==11/4*n^2 +-1 (ilhas de um asterisco)
//pior caso == 9*n^2+-1  (uma ilha so)
//O (n^2)

int inside (int i, int j, int n) {
  if ((i < 0) || (j < 0) || (i >= n) || (j >= n))
    return 0;
  return 1;    
}

void print_matrix (char M[][10], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%3c", M[i][j]);
    }
    printf("\n");
  }   
}

void conquer (char M[][10], int i, int j, int n, int nlabel) {
  Queue *q = create((n*n)+1); /*supondo pior caso*/
  enqueue (q, (point){i,j});
  M[i][j] = (char) nlabel+'0';
  while (!empty(q)) {
    point p = dequeue (q);
    /*Terminar*/
  if(inside(p.x+1,p.y+1,n) && M[p.x+1][p.y+1]=='*')
  {
    M[p.x+1][p.y+1]=(char) nlabel+'0';
    enqueue(q,(point){p.x+1,p.y+1});
  }
  if(inside(p.x,p.y+1,n) && M[p.x][p.y+1]=='*')
  {
    M[p.x][p.y+1]=(char) nlabel+'0';
    enqueue(q,(point){p.x,p.y+1});
  }
   if(inside(p.x+1,p.y,n) && M[p.x+1][p.y]=='*')
  {
    M[p.x+1][p.y]=(char) nlabel+'0';
    enqueue(q,(point){p.x+1,p.y});
  }
     if(inside(p.x+1,p.y-1,n) && M[p.x+1][p.y-1]=='*')
  {
    M[p.x+1][p.y-1]=(char) nlabel+'0';
    enqueue(q,(point){p.x+1,p.y-1});
  }
     if(inside(p.x-1,p.y-1,n) && M[p.x-1][p.y-1]=='*')
  {
    M[p.x-1][p.y-1]=(char) nlabel+'0';
    enqueue(q,(point){p.x-1,p.y-1});
  }
     if(inside(p.x-1,p.y,n) && M[p.x-1][p.y]=='*')
  {
    M[p.x-1][p.y]=(char) nlabel+'0';
    enqueue(q,(point){p.x-1,p.y});
  }
     if(inside(p.x,p.y-1,n) && M[p.x][p.y-1]=='*')
  {
    M[p.x][p.y-1]=(char) nlabel+'0';
    enqueue(q,(point){p.x,p.y-1});
  }
     if(inside(p.x-1,p.y+1,n) && M[p.x-1][p.y+1]=='*')
  {
    M[p.x-1][p.y+1]=(char) nlabel+'0';
    enqueue(q,(point){p.x-1,p.y+1});
  }

  }
  destroy (q); 
}

int count_islands (char M[][10], int n) {
  int i, j, sum = 0;	
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (M[i][j] == '*') 
      {
	      sum++;
        
        conquer (M, i, j, n, sum);     
      }	      
    }	     
  }
  return sum;
}

int main () {

  int n = 10;

  char M[][10] = 
    { {'*',' ','*',' ',' ',' ','*','*','*','*'}, 
      {' ',' ','*',' ','*',' ','*',' ',' ',' '},	    
      {'*','*','*','*',' ',' ','*',' ',' ',' '},
      {'*',' ',' ','*',' ',' ',' ',' ',' ',' '},
      {'*','*','*','*',' ',' ',' ','*','*','*'},
      {' ','*',' ','*',' ',' ','*','*','*','*'},
      {' ',' ',' ',' ',' ','*','*','*',' ',' '},
      {' ',' ',' ','*',' ',' ','*','*','*',' '},
      {'*',' ','*',' ','*',' ',' ','*',' ',' '},
      {'*','*','*','*',' ',' ',' ','*','*','*'} 
    } ;

  print_matrix (M, n);
  printf("Número de ilhas: %d\n", count_islands (M, n));

  print_matrix (M, n);

  return 0; 
}
