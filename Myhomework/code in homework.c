// homework8
int array[N] = {…};
for (int i = 0; i < N; i++)
    if (array[i] != 0)
		array[i]++;
	li a0, N
	la a1, array
loop:
	lw a2, 0(a1)
	beqz a2, endif
	addi a2, a2, 1
	sw a2, 0(a1)
endif:
	addi a0, a0, -1
	addi a1, a1, 4
	bnez a0, loop


//homework7
intx [ 1 6 ] ;
int tid ;
#pragma omp parallel private (tid ) shared (x)
{
    tid = omp_get_thread_num( ) ;
    for (int i = 0; i <8; i ++) {
        if (tid == 0) x[i∗2+ tid ] = 1 ;
        if (tid == 1) x[i∗2+ tid ] = 2 ;
    }
} 





	// homework 6 .
1    m128i result = _mm_add_epi32(_mm_loadu_si128(( m128i *) (arr+4)	), vector	);//
2	_mm_storeu_si128(( m128i *) arr	, result	);
1	vector = _mm_mullo_epi32	( vector	,vector 	);
1	m128i fives = 	_mm_set1_epi32( 5	); //设置四个5
2	m128i mask = 	_mm_cmpeq_epi32( vecotr	, fives	);
3	m128i result = 	_mm_and_si128(vector , mask  );
4	_mm_storeu_si128( ( m128i *) arr	, result	);
5	vector = _mm_loadu_si128(  ( m128i *) (arr+4)  	);
6	mask = _mm_cmpeq_epi32( vecotr	, fives	);
7	result = 		_mm_and_si128(vector , mask  );
8	_mm_storeu_si128( ( m128i *) (arr+4)	, result	);
1	m128i vector_ones = _mm_set1_epi32( 1	);
2	m128i result = _mm_add_epi32(vector	, vector_ones	);
3	_mm_storeu_si128(( m128i *) arr	, result	);

static int product_naive(int n, int *a) {
    int product = 1;
    for (int i = 0; i < n; i++) { product *= a[i];
    }
    return product;
}
static int product_vectorized(int n, int *a) {
    int result[4];
    m128i prod_v =  _mm_set1_epi32( 1   );
    for (int i = 0; i < n	; i += 1 ) { // Vectorized loop
        prod_v = _mm_mullo_epi32( _mm_loadu_si128(( m128i *) (a+4*i)    ), prod_v  );
    }// 怎么并发让每个数都乘起来?
    mm_storeu_si128( result	, prod_V	);
    for (int i = 1	; i < 4		; i++) { 
        result[0] *= result[i]
        // Handle tail case result[0] *= 		;
    }
    return 	result[0];
}
	// Decrements element i of arr. n is a multiple of omp_get_num_threads()
	#pragma omp parallel
	{
	    int threadCount = omp_get_num_threads();//return the number of total hardware threads executing the code
    	int myThread = omp_get_thread_num();//return the number of the thread executing the code
    	for (int i = 0; i < n; i++) {
    	    if (i % threadCount == myThread) arr[i] -= 1;
    	}// n = 8, threaadcount = 2, mythread = 2  第一个 0%2   1%2  2%2  4%2
	}

2	double fast_product(double *arr, int n) {
3	double product = 1;
4	#pragma omp parallel for
5	for (int i = 0; i < n; i++) {
        #pragma omp critical
6	    product *= arr[i];
7	}
8	return product;
9	}

2	double fast_product(double *arr, int n) {
3	double product = 1;
4	#pragma omp for reduction(* : product )
5	for (int i = 0; i < n; i++) {
6	product *= arr[i]; // 先算完然后把他乘起来
7	}
8	return product;
9	}

Leaf: addi sp,sp,-8 # adjust stack for 2 items
	  sw s1, 4(sp)  # save s1 for use afterwards
      sw s0, 0(sp)  # save s0 for use afterwards

      add s0,a0,a1  # f = g + h
      add s1,a2,a3  # s1 = i + j
      sub a0,s0,s1  # return value (g + h) – (i + j)

      lw s0, 0(sp)  # restore register s0 for caller 
      lw s1, 4(sp)  # restore register s1 for caller
      addi sp,sp,8  # adjust stack to delete 2 items
      jr ra 	  # jump back to calling routine

fib: addi sp,sp,-8 # adjust stack for 2 items
	sw s1, 4(sp)  # save s1 for use afterwards
      sw s0, 0(sp)  # save s0 for use afterwards

      addi s0,x0,x0 # int a = 0;
      addi s1,x0,1  #int b = 1;
      addi t1,x0,1  # int c = a + b;
      sub a0,a0,1  # n--
Loop:
      ble s1,x0,end     # n == 1, 不循环 
      add t1,s1,s0      # c= a+ b 
      add s0,s1,x0      # a= b
      add s1,t1,x0      # b  =c 
      sub a0,a0,1       #n--
      bgt a0,x0,Loop; # if n >= 0 ,because n >= 0 so we could do  t= t *x at lease times.

end:
      add a0,t1,x0 # return 
      lw s0, 0(sp)  # restore register s0 for caller 
      lw s1, 4(sp)  # restore register s1 for caller
      addi sp,sp,8  # adjust stack to delete 2 items
      jr ra 	  # jump back to calling routine



class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1 = headA; 
        ListNode* l2 = headB;
        while(l1 != nullptr && l2 != nullptr){
            l1 = l1->next;
            l2= l2->next;
        }
        if(l1 != nullptr ){
            l2 = headA;
            l1 = l1->next;
            l2= l2->next;
        }


        
    }
};




