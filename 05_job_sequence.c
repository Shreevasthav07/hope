
#include <stdio.h>

struct Job {
    char id;
    int deadline, profit;
};

int main() {
    struct Job job[50], temp;
    char slot[51];
    int n, i, j, maxD = 0;
    int total = 0, d;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    /* Read job details */
    for(i = 0; i < n; i++) {
        printf("Enter job ID, deadline and profit: ");
        scanf(" %c%d%d", &job[i].id,
              &job[i].deadline, &job[i].profit);

        if(job[i].deadline > maxD)
            maxD = job[i].deadline;
    }

    /* Sort jobs by decreasing profit */
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(job[j].profit < job[j+1].profit) {
                temp = job[j];
                job[j] = job[j+1];
                job[j+1] = temp;
            }
        }
    }

    if(maxD > 50)
        maxD = 50;

    /* Initialize slots */
    for(i = 0; i <= maxD; i++)
        slot[i] = '-';

    /* Schedule jobs */
    for(i = 0; i < n; i++) {
        d = job[i].deadline;

        if(d > maxD)
            d = maxD;

        for(j = d; j >= 1; j--) {
            if(slot[j] == '-') {
                slot[j] = job[i].id;
                total += job[i].profit;
                break;
            }
        }
    }

    /* Display scheduled jobs */
    printf("\nScheduled jobs: ");

    for(i = 1; i <= maxD; i++) {
        if(slot[i] != '-')
            printf("%c ", slot[i]);
    }

    printf("\nMaximum profit = %d\n", total);

    return 0;
}
