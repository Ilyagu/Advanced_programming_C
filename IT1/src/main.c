// Copyright 2021 Nagdimaev Ilyagu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func/func.h"

int main() {
    Road *all_roads = calloc(50, sizeof(Road));
    // print(all_roads, added_roads);
    size_t added_roads;
    added_roads = load_data(all_roads);
    size_t n;
    printf("Введите число дорог:\n");
    input_lanes(&n);
    char test_type[50];
    input_type(test_type);
    char* result = qual(all_roads, added_roads, test_type, n);
    if (strcmp(result, "Таких дорог нет") == 0 || strcmp(result, "ERROR") == 0)
        printf("%s", result);
    else
        printf("\nСреднее качество дорог с покрытием %s  "
           "c количеством полос %zu: \n%s",
           test_type, n, result);
    free(all_roads);
    return 0;
}
