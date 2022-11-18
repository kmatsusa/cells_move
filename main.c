#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIDTH (15)
#define HEIGHT (15)
#define NONE (70)
#define ZERO (15)
#define ONE (15)



int map[HEIGHT][WIDTH];
int grand = 0;
int test[50];

int serch(int real, int y, int x, int flag)
{
    int sum = 0;
    
    if (flag != 0 && map[y][x] != 0 )
        return -100;
    if (x < 0 || y < 0)
        return -100;
    switch(flag){
        case 0:
            break;
        case 1:
            map[y-1][x]=0;
            break;
        case 2:
            map[y][x-1]=0;
            break;
        case 3:
            map[y+1][x]=0;
            break;
        case 4:
            map[y][x+1]=0;
            break;
    }
    if (y+1 < HEIGHT && real == map[y+1][x]){
        sum++;
        // printf("a");
        // printf("[%d][%d]",real, map[y+1][x]);
    }
    else if ( y+1 < HEIGHT && map[y+1][x] != 0){
        sum--;
        // printf("b");
        // printf("[%d][%d]",real, map[y+1][x]);
    }
    if (x+1 < WIDTH &&real == map[y][x+1]){
        sum++;
        // printf("c");
        // printf("[%d][%d]",real, map[y][x+1]);
    }
    else if (x+1 < WIDTH &&map[y][x+1] != 0){
        sum--;
        // printf("d");
        // printf("[%d][%d]",real, map[y][x+1]);
    }
    if (y-1 >= 0 &&real == map[y-1][x]){
        sum++;
        // printf("e");
    }
    else if (y-1 >= 0 &&map[y-1][x] != 0){
        sum--;
        // printf("f");
    }
    if (x-1 >= 0 &&real == map[y][x-1]){
        sum++;
        // printf("g");
    // printf("[%d][%d]",real,map[y][x-1]);
    }
    else if (x-1 >= 0 && map[y][x-1] != 0){
        sum--;
        // printf("h");
    }
    switch(flag){
        case 0:
            break;
        case 1:
            map[y-1][x]=real;
            break;
        case 2:
            map[y][x-1]=real;
            break;
        case 3:
            map[y+1][x]=real;
            break;
        case 4:
            map[y][x+1]=real;
            break;
    }
    return sum;
}

void moov(int direction, int y, int x){
    if(direction == 0)
        return ;
    else if(direction == 1)
    {
        map[y+1][x] = map[y][x];
        map[y][x] = 0;
    }
    else if(direction == 2)
    {
        map[y][x+1] = map[y][x];
        map[y][x] = 0;
    }
    else if(direction == 3)
    {
        map[y-1][x] = map[y][x];
        map[y][x] = 0;
    }
    else if(direction == 4)
    {
        map[y][x-1] = map[y][x];
        map[y][x] = 0;
    }
}

void premoov(int* direction, int y, int x){
    int ans;

    printf("(x = %d, y = %d, cell = %d)",x, y, map[y][x]);
    for (size_t i = 0; i < 5; i++){
        printf("%d",direction[i]);
    }
    printf(",");
    while (1){
        for (int i = 0; i < 5; i++){
            printf("[%d.%d]",direction[i],test[grand]);
            if (direction[i] == test[grand]){
                printf("[%d.%d]",direction[i],test[grand]);
                moov(i, y, x);
                grand++;
                if (grand == 49){
                    grand = 0;
                }
                return ;
            }
            grand++;
            if (grand == 49){
                grand = 0;
            }
        }
    }
    return ;
}

void change(int y, int x){
    int sum[] = {0,0,0,0,0};
    int new_sum = 0;
    int max = 0;
    int direction[5] = {5,5,5,5,5};

    if (map[y][x] != 0){
        sum[0] = serch(map[y][x], y, x, 0);
        // printf("-nor-");
        sum[1] = serch(map[y][x], y + 1, x, 1);  //down
        // printf("-down-");
        sum[2] = serch(map[y][x], y , x + 1, 2); 
        // printf("-right-");//right
        sum[3] = serch(map[y][x], y - 1, x, 3);
        // printf("-up-");  //up
        sum[4] = serch(map[y][x], y , x - 1, 4);
        // printf("left"); //left
    }
    for (int i = 0; i < 5; i++){
        if (i == 0){
            max = sum[0];
        }else if(sum[i] > max){
            max = sum[i];
            new_sum = i;
        }
    }
    for (int i = 0; i < 5; i++){
        if (sum[i] == max){
            direction[i] = i;
        }
    }
    // printf("|%d|",map[y][x]);
    // printf("[%d],[%d]",direction, new_sum);
    // printf("~%d~",new_sum);
    if (direction[0] == 0 &&
        direction[1] == 5 &&
        direction[2] == 5 &&
        direction[3] == 5 &&
        direction[4] == 5 ){
        return ;
    }else if (map[y][x] != 0){
        premoov(&direction[0], y, x);
        // moov(new_sum, y, x);
    }
}

int main(){
    srand((unsigned int)time(NULL));
    int alt;

    for (size_t i = 0; i < 50; i++){
        test[i] = 1 + rand() % 4;
        printf("%d\n", test[i]);
    }
    for (int y = 0; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){
            alt = rand() % 100; 
            if (0 <= alt && alt < NONE){
                map[y][x] = 0;
            } else if(NONE <= alt && alt < NONE + ZERO){
                map[y][x] = 1;
            } else{
                map[y][x] = 2;
            }
            switch (map[y][x]){
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("0");
                    break;
                case 2:
                    printf("1");
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    }
    for (int k = 0; k < 50; k++){
        sleep(1);
        
        for (int y = 0; y < HEIGHT; y++){
            printf("\n%d------",y);
            for (int x = 0; x < WIDTH; x++){
                change(y, x);
            }
        }
        printf("\n");
        for (int y = 0; y < HEIGHT; y++){
            for (int x = 0; x < WIDTH; x++){
                switch (map[y][x]){
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("0");
                    break;
                case 2:
                    printf("1");
                    break;
                default:
                    break;
                }
            }
            printf("\n");
        }
    }
}