#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_scores_inc(const void *score_a, const void *score_b)
{
    int a = *(int *)score_a;
    int b = *(int *)score_b;
    return (a - b);
}

int compare_scores_desc(const void* score_a, const void* score_b)
{
    int val = compare_scores_inc(score_b, score_a);
    return val;
}

int compare_names(const void* name_a, const void* name_b)
{
    char **str_a = (char **)name_a;
    char **str_b = (char **)name_b;
    return strcmp(*str_a, *str_b);
}

int main()
{
    int scores[] = {542, 222, 63, 23, 225, 4, 345};
    int i;
    qsort(scores, 7, sizeof(int), compare_scores_desc);
    puts("These are the scores in decreasing order:");
    for (i = 0; i < 7; i++) {
        printf("%i, ", scores[i]);
    }
    puts("");

    char *names[] = {"Karen", "Mark", "Brett", "Molly"};
    qsort(names, 4, sizeof(char*), compare_names);
    puts("These are the sorted names:");
    for (i = 0; i < 4; i++) {
        printf("%s ,", names[i]);
    }
    puts("");

    return 0;
}
