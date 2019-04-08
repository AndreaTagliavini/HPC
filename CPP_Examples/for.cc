#include <iostream>
#include <omp.h>

#define NUM 20



int main(){
	int a[NUM];

	for(int i=0; i<NUM; i++)
		a[i] = i;

	#pragma omp parallel shared (a) num_threads(10)
	{
		if(omp_get_thread_num() == 0)
			std::cout<<omp_get_num_threads()<<"\n";
		#pragma omp for
		for(int i=0; i<NUM; i++){
			a[i] = a[i]*2;
			#pragma omp critical
			{
				std::cout<<"T:"<<omp_get_thread_num()<<"INDEX"<<i<<"\n";
			}
		}
	
	}
	

	for(int i=0; i<NUM; i++)
		std::cout<<"a["<<i<<"] = "<<a[i]<<"\n";

	return 0;
}
