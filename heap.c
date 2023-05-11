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

}


void heap_pop(Heap* pq){
  int posicion = pq->size;
  heapElemen aux;
  int posPadre = (posicion - 1)/2; 
  if(pq -> size == pq -> capac)
  {
    pq->heapArray = realloc(pq->heapArray, pq->capac+2+1)
  }

  if(pq->size == 0)
  {
    pq->heapArray[0].data = data;
    pq->heapArray[0].priority = priority;
    pq->size++;
  }
  
  pq->heapArray[pq->size].data = data;
  pq->heapArray[pq->size].priority = priority;
}



Heap* createHeap(){
  Heap *m = malloc(3 *sizeof(Heap));
  m -> heapArray = malloc(3 *sizeof(Heap));
  m-> size = 0;
  m -> capac = 3;
   return m;
}
