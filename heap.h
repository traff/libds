#ifndef __HEAP_H__
#define __HEAP_H__

#include "vector.h"

#define PARENT(i) (i-1)/2
#define LEFT(i) 2*i+1
#define RIGHT(i) 2*i+2

/* heapcmpfunc is the template for the comparison function used by all heap
   functions. It takes as arguments the heap itself and two integers i and j
   which represent indices of two items in the heap. If the value at i is 
   "greater" than the value at j, this function should return an integer > 0.
   If the value at i is "less" than the value at j, the function should return
   an integer < 0. If the values at i and j are equal, this function should 
   return 0 */
typedef int (*heapcmpfunc)(vector*, int, int);

typedef struct {
	vector * vec;
	heapcmpfunc cmpfunc;
} heap;

heap * create_heap(heapcmpfunc cmpfunc);
void destroy_heap(heap * hp);

/* maintain the heap property starting at index i */
void heapify(heap * hp, int i);
/* build the heap */
void build_heap(heap * hp);
/* removes the first element from the heap and then adjusts to maintain the 
   heap property */
void heap_remove(heap * hp);
/* inserts the value into the heap such that the heap property is maintained */
void heap_insert(heap * hp, void * val, int size);

#endif /* __HEAP_H__ */
