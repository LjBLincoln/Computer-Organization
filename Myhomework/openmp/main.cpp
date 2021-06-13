
#include <iostream>
#include <omp.h>   // NEW ADD
using namespace std;
#define M 400
#define N 400
#define K 400
int main()
{

	int A[M][K] = { 0 };
	int B[K][N] = { 0 };
	int C[M][N] = { 0 };
	int i = 0;
	int j = 0;
	int m = 0;
	FILE *fp;
	fp=fopen("log.txt","r");
	if(fp==NULL)
		printf("�ļ���ʧ�ܣ�\n");
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < K; j++)
		{
			fscanf(fp,"%d", &A[i][j]);
		}
	}
	fp=fopen("log.txt","r");
	for (i = 0; i < K; i++)
	{
		for (j = 0; j < N; j++)
		{
			fscanf(fp,"%d", &B[i][j]);
		}
	}
	#pragma omp parallel for num_threads(4)
	for (i = 0; i < M; i++){
		for (j = 0; j < N; j++)
		{
			int sum = 0;
			for (m = 0; m < K; m++)
			{
				sum = sum + A[i][m] * B[m][j];
			}
			C[i][j] = sum;
		}
	}
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%6d",C[i][j]);
		}
		printf("\n");
	}
	#if _OPENMP
        cout << " support openmp " << endl;
#else
        cout << " not support openmp" << endl;
#endif
	return 0;
}
