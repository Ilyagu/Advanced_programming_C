// Copyright 2021 Nagdimaev Ilyagu

#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    Road *all_roads = calloc(50, sizeof(Road));
    // print(all_roads, added_roads);
    size_t added_roads;
    added_roads = load_data(all_roads);
    size_t n;
    printf("%s\n", "Введите количество дорог");
    input_lanes(&n);
    printf("%s\n", "Введите вид покрытия (Асфальт или Грунт):");
    char test_type[50];
    while (1) {
        scanf("%s", test_type);
        if (strcmp(test_type, "Асфальт") == 0)
            break;
        else if (strcmp(test_type, "Грунт") == 0)
            break;
        else
            printf("%s", "Некорректный ввод, повторите еще раз:");
    }
    printf("\nСреднее качество дорог с покрытием %s  "
           "c количеством полос %ld: \n%s",
           test_type, n,
           qual(all_roads, added_roads, test_type, n));
    free(all_roads);
    return 0;
}
