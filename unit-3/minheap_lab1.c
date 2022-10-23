

#include <stdio.h>
#include <stdlib.h>

typedef struct MinHeap MinHeap;
struct MinHeap {
    int* arr;
    int size;  //size of the heap
};


MinHeap* init_minheap(int size) {
    MinHeap* minheap = (MinHeap*)calloc(1, sizeof(MinHeap));
    minheap->size = size;
    minheap->arr = (int*)calloc(size, sizeof(int));
    return minheap;
}

void create_minheap(MinHeap *heap) 
{
	int c,p,key;
	
	for(int i=heap->size/2-1;i>=0;i--)
	{
		p=i;
		c=2*p+1;
		key=heap->arr[p];
		
		while(c<heap->size)
		{
			if(c+1 < heap->size)
			{
				if(heap->arr[c+1]<heap->arr[c])
					c=c+1;
			}
			if(key > heap->arr[c])
			{
				heap->arr[p]=heap->arr[c];
				p=c;
				c=2*p+1;
			}
			else
				break;
		}
		heap->arr[p]=key;
	}

}




void print_minheap(MinHeap* heap) 
{
    // IMPLEMENT HERE
    for(int i = 0;i  < heap->size;i++)
    {
        printf("%d ",heap->arr[i]);
    }


}

void free_minheap(MinHeap* heap) {
    if (!heap)
        return;
    free(heap->arr);
    free(heap);
}

int main() {

    int capacity; 
    scanf("%d", &capacity);
    MinHeap* heap = init_minheap(capacity); //number of elements 
    int i=0;
    while(i < capacity){
        scanf("%d", &heap->arr[i++]);

    }
    create_minheap(heap);
    print_minheap(heap);
    free_minheap(heap);
    return 0;
}