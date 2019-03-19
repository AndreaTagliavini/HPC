/*****************************************************************
*	HPC OpenMP examples
*
*	
*
*
*
*
*
*	@Note: to compile this sources use g++ -fopenmp <source> -o <output>
*
*
*/
#include <stdio.h>
#include <omp.h>
 

/**Helloworld*/
/*
int main() {
	#pragma omp parallel num_threads(3)
	{
		int id = omp_get_thread_num();
		int data = id;
	    int total = omp_get_num_threads();
	    printf("Greetings from process %d out of %d with Data %d\n", id, total, data);
	}
	printf("parallel for ends.\n");
	return 0;
}
*/

/**Spawn variabile outside ParReg*/
/*
int main()
{
	int a;
	a = 11;
	#pragma omp parallel num_threads(3)
	{
		printf("A is :%d \n", a);
	}
	return 0;
}
*/

/**Spawn variabile inside ParReg*/
int main()
{
	#pragma omp parallel num_threads(3)
	{
		int a;
		a = omp_get_thread_num();
		printf("A is :%d \n", a);
	}
	return 0;
}
