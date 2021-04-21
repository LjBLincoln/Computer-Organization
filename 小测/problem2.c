#include<malloc.h>
#include<stdio.h>
struct stack{
		int size;
		int topIndex;
		int * stackArray;
};


struct stack * init_stack(int size){
	struct stack * stk = (struct stack*)malloc(sizeof(struct stack*));
	if(!stk){
		return NULL;
	}
	stk->size = size;
	stk->topIndex = 0;
	stk->stackArray = (int*)malloc(sizeof(int) * size);
	if(!(stk->stackArray )){
		return NULL;
	}
	return stk;
};


void push(int x, struct stack * stk){
	if(stk->topIndex == stk->size -1 ){
		//full stack
		int * stackArray = (int *)realloc(stk->stackArray,stk->size *2);//这里应该填rellaoc
		if(!stackArray){
			return ;
		}
		stk->stackArray = stackArray;
		stk->size = stk->size * 2;
	}
	stk->topIndex  = stk->topIndex +1;
	stk->stackArray[stk->topIndex] = x;
}

int pop(struct stack * stk){
	if(stk->topIndex <0){
		return 0;
	}
	int x = stk->stackArray[stk->topIndex];
	stk->stackArray[stk->topIndex] = 0;
	stk->topIndex -=1;
	return x;
}
	
int main(){
	struct stack * stk = init_stack(1);
	printf("stk->size,stk->topIndex  %d %d\n" , stk->size,stk->topIndex );
	push(2,stk);
	printf("stk->size,stk->topIndex  %d %d\n" , stk->size,stk->topIndex );
	push(3,stk);
	printf("stk->size,stk->topIndex  %d %d\n" , stk->size,stk->topIndex );
	int i = 		pop(stk);
	printf("stk->size,stk->topIndex  %d %d\n" , stk->size,stk->topIndex );
	return 0;
} 
