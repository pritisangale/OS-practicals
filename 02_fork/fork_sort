#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
    pid_t pid;
    int a[20], n, i, j, temp;

    printf("enter number of elements\n");
    scanf("%d", &n);

    printf("enter %d numbers\n", n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    pid = fork();

    if(pid == 0)
    {
        printf("\nChild Process\n");
        printf("Child PID = %d\n", getpid());

        // Bubble sort in ascending order
        for(i = 0; i < n-1; i++)
        {
            for(j = 0; j < n-i-1; j++)
            {
                if(a[j] > a[j+1])
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }

        printf("CHILD PERFORMED ASCENDING SORT=");

        for(i = 0; i < n; i++)
            printf("%d ", a[i]);

        printf("\n");
    }
    else
    {
        wait(NULL);

        printf("\n\n\nhi from Parent\n");
        printf("Parent Process\n");
        printf("Parent PID = %d\n", getpid());

        // Bubble sort in descending order
        for(i = 0; i < n-1; i++)
        {
            for(j = 0; j < n-i-1; j++)
            {
                if(a[j] < a[j+1])
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }

        printf("PARENT PERFORMED DESCENDING SORT=");

        for(i = 0; i < n; i++)
            printf("%d ", a[i]);

        printf("\n");
    }
}
