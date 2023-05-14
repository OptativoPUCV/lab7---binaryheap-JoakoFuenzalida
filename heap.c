#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq -> size == 0)
  {
    return NULL;
  }
  
    return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  
  int posicion = pq->size;
  heapElem aux;
  int posPadre = (posicion - 1)/2; 
  
  if(pq -> size == pq -> capac)
  {
    pq->capac = pq->capac * 2+1;
    pq->heapArray = realloc(pq->heapArray, pq->capac);
  }

  if(pq->size == 0)
  {
    pq->heapArray[0].data = data;
    pq->heapArray[0].priority = priority;
    pq->size++;
    return;
  }
  
  pq->heapArray[pq->size].data = data;
  pq->heapArray[pq->size].priority = priority;
  pq->size++;

  while(pq->heapArray[posicion].priority > pq->heapArray[posPadre].priority)
  {
    if(pq->heapArray[posicion].priority > pq->heapArray[posPadre].priority)
    {
      aux = pq->heapArray[posicion];
      pq->heapArray[posicion] = pq->heapArray[posPadre];
      pq->heapArray[posPadre] = aux;
      posicion = posPadre;
      posPadre = (posicion-1)/2;
    }
      
  }

}


void heap_pop(Heap* pq){
   if(pq -> size == 0)
  {
    return;
  }
  heapElem aux;
  int posicion = 0;
  int menorHijo = 1;
  int mayorHijo =2;

  pq->heapArray[0] = pq->heapArray[pq->size-1];
  pq->size--;

  while(menorHijo < pq->size)
  {
   int nodo = menorHijo; 

    if(menorHijo < pq->size && pq->heapArray[mayorHijo].priority > pq->heapArray[menorHijo].priority)
    {
      nodo = mayorHijo;
    }

    if(pq->heapArray[posicion].priority > pq -> heapArray[nodo].priority)
    {
      break;
    }
     aux = pq->heapArray[posicion];
    pq->heapArray[posicion] = pq->heapArray[nodo];
    pq->heapArray[nodo] = aux;

    posicion = nodo;

    menorHijo = menorHijo * 2 +1;
    mayorHijo = mayorHijo *2 +1;
    
      
  }


  
  
  
}



Heap* createHeap(){
  Heap *m = malloc(3 *sizeof(Heap));
  m -> heapArray = malloc(3 *sizeof(Heap));
  m-> size = 0;
  m -> capac = 3;
   return m;
}
