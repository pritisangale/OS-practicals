#include <stdio.h>

int main()
{
    int n, m;

    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], work[10], finish[10];
    int safeSeq[10];

    int i, j, k, count = 0;
    int found;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Maximum Requirement Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");

    for (j = 0; j < m; j++)
    {
        scanf("%d", &avail[j]);
    }

    // Calculate Need Matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("\nNeed Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", need[i][j]);
        }

        printf("\n");
    }

    // Initialize Work and Finish
    for (j = 0; j < m; j++)
        work[j] = avail[j];

    for (i = 0; i < n; i++)
        finish[i] = 0;

    // Find Safe Sequence
    while (count < n)
    {
        found = 0;

        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int possible = 1;

                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if (possible)
                {
                    // Process can execute
                    for (j = 0; j < m; j++)
                        work[j] += alloc[i][j];

                    safeSeq[count] = i;
                    count++;

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0)
        {
            break;
        }
    }

    if (count == n)
    {
        printf("\nSystem is in a SAFE state.\n");

        printf("Safe Sequence: ");

        for (i = 0; i < n; i++)
        {
            printf("P%d", safeSeq[i]);

            if (i != n - 1)
                printf(" -> ");
        }

        printf("\n");
    }
    else
    {
        printf("\nSystem is NOT in a safe state.\n");
    }

    return 0;
}
