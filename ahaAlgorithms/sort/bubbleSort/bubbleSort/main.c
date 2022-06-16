//
//  main.c
//  bubbleSort
//
//  Created by apple on 2022/6/16.
//
/**
 5
 huhu 5
 haha 3
 xixi 5
 hengheng 2
 gaoshou 8

 gaoshou 8
 huhu 5
 xixi 5
 haha 3
 hengheng 2
 */

#include <stdio.h>
#include <stdbool.h>

struct student {
    char name[21];
    int score;
};

int main(int argc, const char * argv[]) {
    
    struct student a[100], t;
    int i, j, n;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%s %d", a[i].name, &a[i].score);
    }
    for (i = 1; i <= n-1; i++) {
        bool flag = true;
        for (j = 1; j <= n-i; j++) {
            if (a[j].score < a[j + 1].score) {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                flag = false;
            }
        }
        if (flag) {
            break;
        }
    }
    printf("\n");
    for (i = 1; i <= n; i++) {
        printf("%s %d\n", a[i].name, a[i].score);
    }
    getchar();getchar();
    
    return 0;
}
