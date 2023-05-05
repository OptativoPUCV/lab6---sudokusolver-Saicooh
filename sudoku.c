#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct
{
  int sudo[9][9];
} Node;

Node *createNode()
{
  Node *n = (Node*) malloc(sizeof(Node));
  return n;
}

Node *copy(Node *n)
{
  Node *new =(Node*) malloc(sizeof(Node));
  *new = *n;
  return new;
}

Node *read_file(char* file_name)
{
  Node *n = createNode();
  FILE *file = fopen(file_name, "r");
  int i,j;
  
  for(i = 0 ; i < 9 ; i++)
  {
    for(j = 0 ; j < 9 ; j++)
    {
      if(!fscanf (file, "%d", &n ->sudo[i][j])) printf("failed to read data!");
    }
  }

  fclose(file);
  return n;
}

void print_node(Node* n)
{
  int i,j;
  
  for(i = 0 ; i < 9 ; i++)
  {
    for(j = 0 ; j < 9 ; j++)
    {
      printf("%d ", n -> sudo[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int repetidosFila(int fila, Node *n)
{
  int numFila[10] = {0}, columna;

  for(columna = 0 ; columna < 9 ; columna++)
  {
    if(n -> sudo[fila][columna] != 0)
    {
      if (numFila[n -> sudo[fila][columna]] == 1) return 0;
      else numFila[n -> sudo[fila][columna]] = 1;
    }
  }
  
  return 1;
}

int repetidosColumna(int columna, Node *n)
{
  int numColumna[10] = {0}, fila;

  for(fila = 0 ; fila < 9 ; fila++)
  {
    if(n -> sudo[fila][columna] != 0)
    {
      if (numColumna[n -> sudo[fila][columna]] == 1) return 0;
      else numColumna[n -> sudo[fila][columna]] = 1;
    }
  }
  
  return 1;
}

int repetidosSubMatriz(int subMatriz, Node *n)
{
  int aux[10] = {0}, p;
  
  for(p = 0 ; p < 9 ; p++)
  {
    int i = 3 * (subMatriz/3) + (p/3);
    int j = 3 * (subMatriz%3) + (p%3);
    
    if(n -> sudo[fila][columna] != 0)
    {
      if (aux[n -> sudo[i][j]] == 1) return 0;
      else aux[n -> sudo[i][j]] = 1;
    }
  }
  
  return 1;
}
int is_valid(Node *n)
{
  
  return 1;
}

List *get_adj_nodes(Node *n)
{
  List *list = createList();

  for(int i = 0 ; i < 9 ; i++)
  {
    for(int j = 0 ; j < 9 ; j++)
    {
      if (n -> sudo[i][j] == 0)
      {
        for(int nuevo = 1 ; nuevo < 10 ; nuevo++)
        {
          n -> sudo[i][j] = nuevo;
          
          if (is_valid(n)) 
          {
            Node *adjNode = copy(n);
            pushBack(list, adjNode);
          }
          
        }
        n -> sudo[i][j] = 0;
        return list;
      }
    }
  }
  
  return list;
}




int is_final(Node* n)
{
  for(int i = 0 ; i < 9 ; i++)
    for(int j = 0 ; j < 9 ; j++)
      if (n -> sudo[i][j] == 0) return 0;
  
  return 1;
}

Node *DFS(Node* initial, int* cont)
{
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/