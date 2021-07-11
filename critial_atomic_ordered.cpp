#include<stdio.h>
#include<omp.h>

int main()
{
    int i, id;
    int x[5] = { 1,2,3,4,5 };
    int sum, sumlocal;
    sum = 0;
    #pragma omp parallel private(id) num_threads(7)
    {
        id = omp_get_thread_num();
        if ((id % 2) == 0)
        {
            printf("even number : %d \n", id);
        }
        #pragma omp barrier
        if ((id % 2) != 0)
            printf("odd number : %d \n", id);
    }

         #pragma omp parallel num_threads(4) shared(x, sum) private(id, sumlocal)
    {
        id = omp_get_thread_num();
        sumlocal = 0;
         #pragma omp for
        for (i = 0; i < 5; i++)
            sumlocal += x[i]*2;
         #pragma omp critical (calulate_sum)
        {
            sum += sumlocal;
            printf("id = %d: sumlocal= %d sum = %d\n", id, sumlocal, sum);
        }
    }
    printf("After parallel: sum = %d \n", sum);
    #pragma omp parallel  for private(i) ordered
    for (i = 0; i < 20; i++) {
    #pragma omp ordered
        printf("\nthread[%d]: hello world", omp_get_thread_num());
    }
    sum = 0;
    #pragma omp parallel for private(i)
    for (i = 0; i < 5; i++) {
    #pragma omp atomic
        sum += i * 3;
    }
    printf("\n summmm = %d", sum);
        
    return 0;
}
