#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIDTH (20)
#define HEIGHT (20)
#define NONE (80)
#define ZERO (10)
#define ONE (10)

int map[HEIGHT][WIDTH][3];
// int block_check[HEIGHT][WIDTH];
int grand = 0;
int test[200];

int serch(int real, int y, int x, int flag)
{
    int sum = 0;

    if (flag != 0 && map[y][x][0] != 0)
        return -100;
    if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
        return -1000;
    switch (flag)
    {
    case 0:
        break;
    case 1:
        map[y - 1][x][0] = 0;
        break;
    case 2:
        map[y][x - 1][0] = 0;
        break;
    case 3:
        map[y + 1][x][0] = 0;
        break;
    case 4:
        map[y][x + 1][0] = 0;
        break;
    case 5:
        map[y - 1][x - 1][0] = 0;
        break;
    case 6:
        map[y + 1][x - 1][0] = 0;
        break;
    case 7:
        map[y + 1][x + 1][0] = 0;
        break;
    case 8:
        map[y - 1][x + 1][0] = 0;
        break;
    }
    if (y + 1 < HEIGHT && real == map[y + 1][x][0])
    {
        sum++;
        // printf("a");
        // printf("[%d][%d]",real, map[y+1][x]);
    }
    else if (y + 1 < HEIGHT && map[y + 1][x][0] != 0)
    {
        sum--;
        // printf("b");
        // printf("[%d][%d]",real, map[y+1][x]);
    }
    if (x + 1 < WIDTH && real == map[y][x + 1][0])
    {
        sum++;
        // printf("c");
        // printf("[%d][%d]",real, map[y][x+1]);
    }
    else if (x + 1 < WIDTH && map[y][x + 1][0] != 0)
    {
        sum--;
        // printf("d");
        // printf("[%d][%d]",real, map[y][x+1]);
    }
    if (y - 1 >= 0 && real == map[y - 1][x][0])
    {
        sum++;
        // printf("e");
    }
    else if (y - 1 >= 0 && map[y - 1][x][0] != 0)
    {
        sum--;
        // printf("f");
    }
    if (x - 1 >= 0 && real == map[y][x - 1][0])
    {
        sum++;
        // printf("g");
        // printf("[%d][%d]",real,map[y][x-1]);
    }
    else if (x - 1 >= 0 && map[y][x - 1][0] != 0)
    {
        sum--;
        // printf("h");
    }
    if (x + 1 < WIDTH && y + 1 < HEIGHT && real == map[y + 1][x + 1][0])
    {
        sum++;
        // printf("g");
        // printf("[%d][%d]",real,map[y][x-1]);
    }
    else if (x + 1 < WIDTH && y + 1 < HEIGHT && map[y + 1][x + 1][0] != 0)
    {
        sum--;
        // printf("h");
    }
    if (x + 1 < WIDTH && y - 1 >= 0 && real == map[y - 1][x + 1][0])
    {
        sum++;
        // printf("g");
        // printf("[%d][%d]",real,map[y][x-1]);
    }
    else if (x + 1 < WIDTH && y - 1 >= 0 && map[y - 1][x + 1][0] != 0)
    {
        sum--;
        // printf("h");
    }
    if (x - 1 >= 0 && y - 1 >= 0 && real == map[y - 1][x - 1][0])
    {
        sum++;
        // printf("g");
        // printf("[%d][%d]",real,map[y][x-1]);
    }
    else if (x - 1 >= 0 && y - 1 >= 0 && map[y - 1][x - 1][0] != 0)
    {
        sum--;
        // printf("h");
    }
    if (x - 1 >= 0 && y + 1 < HEIGHT && real == map[y + 1][x - 1][0])
    {
        sum++;
        // printf("g");
        // printf("[%d][%d]",real,map[y][x-1]);
    }
    else if (x - 1 >= 0 && y + 1 < HEIGHT && map[y + 1][x - 1][0] != 0)
    {
        sum--;
        // printf("h");
    }
    switch (flag)
    {
    case 0:
        break;
    case 1:
        map[y - 1][x][0] = real;
        break;
    case 2:
        map[y][x - 1][0] = real;
        break;
    case 3:
        map[y + 1][x][0] = real;
        break;
    case 4:
        map[y][x + 1][0] = real;
        break;
    case 5:
        map[y - 1][x - 1][0] = real;
        break;
    case 6:
        map[y + 1][x - 1][0] = real;
        break;
    case 7:
        map[y + 1][x + 1][0] = real;
        break;
    case 8:
        map[y - 1][x + 1][0] = real;
        break;
    }
    return sum;
}

int b_serch(int real, int y, int x, int flag)
{

    if (y + 1 < HEIGHT && real == map[y + 1][x][flag])
    {
        return 1;
    }
    else if (x + 1 < WIDTH && real == map[y][x + 1][flag])
    {
        return 1;
    }
    else if (y - 1 >= 0 && real == map[y - 1][x][flag])
    {
        return 1;
    }
    else if (x - 1 >= 0 && real == map[y][x - 1][flag])
    {
        return 1;
    }
    else if (x + 1 < WIDTH && y + 1 < HEIGHT && real == map[y + 1][x + 1][flag])
    {
        return 1;
    }
    else if (x + 1 < WIDTH && y - 1 >= 0 && real == map[y - 1][x + 1][flag])
    {
        return 1;
    }
    else if (x - 1 >= 0 && y - 1 >= 0 && real == map[y - 1][x - 1][flag])
    {
        return 1;
    }
    else if (x - 1 >= 0 && y + 1 < HEIGHT && real == map[y + 1][x - 1][flag])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void moov(int direction, int y, int x)
{
    if (direction == 0)
        return;
    else if (direction == 1)
    {
        map[y + 1][x][0] = map[y][x][0];
        map[y][x][0] = 0;
    }
    else if (direction == 2)
    {
        map[y][x + 1][0] = map[y][x][0];
        map[y][x][0] = 0;
    }
    else if (direction == 3)
    {
        map[y - 1][x][0] = map[y][x][0];
        map[y][x][0] = 0;
    }
    else if (direction == 4)
    {
        map[y][x - 1][0] = map[y][x][0];
        map[y][x][0] = 0;
    }
    else if (direction == 5)
    {
        map[y + 1][x + 1][0] = map[y][x][0];
        map[y][x][0] = 0;
    }
    else if (direction == 6)
    {
        map[y - 1][x + 1][0] = map[y][x][0];
        map[y][x][0] = 0;
    }
    else if (direction == 7)
    {
        map[y - 1][x - 1][0] = map[y][x][0];
        map[y][x][0] = 0;
    }
    else if (direction == 8)
    {
        map[y + 1][x - 1][0] = map[y][x][0];
        map[y][x][0] = 0;
    }

    // sum[5] = serch(map[y][x], y + 1 , x + 1, 5); //migisita
    //     sum[6] = serch(map[y][x], y - 1 , x + 1, 5); //migiue
    //     sum[7] = serch(map[y][x], y - 1 , x - 1, 5); //hidariue
    //     sum[8] = serch(map[y][x], y + 1 , x - 1, 5); //hidarisita
}

void premoov(int *direction, int y, int x)
{
    int ans;

    printf("(x = %d, y = %d, cell = %d)", x, y, map[y][x][0]);
    for (size_t i = 0; i < 9; i++)
    {
        printf("%d", direction[i]);
    }
    printf(",");
    while (1)
    {
        for (int i = 0; i < 9; i++)
        {
            printf("[%d.%d]", direction[i], test[grand]);
            if (direction[i] == test[grand])
            {
                moov(i, y, x);
                grand++;
                if (grand == 199)
                {
                    grand = 0;
                }
                return;
            }

            // if (direction[i] == test[grand]){
            //     printf("[%d.%d]",direction[i],test[grand]);
            //     moov(i, y, x);
            //     grand++;
            //     if (grand == 99){
            //         grand = 0;
            //     }
            //     return ;
            // }
        }
        grand++;
        if (grand == 199)
        {
            grand = 0;
        }
    }
    return;
}

// int assign(int real, int y, int x)
// {
//     if (map[y][x][1] == 1)
//     {
//         return 0;
//     }
//     if (y + 1 < HEIGHT && real == map[y + 1][x][0] && map[y + 1][x][0] == 1)
//     {

//         return 1;
//     }
// }

void block_make(int real, int y, int x)
{
    int i = 0;

    map[y][x][1] = 1;
    for (int k = y; k < HEIGHT; k++)
    {
        for (int l = 0; l < WIDTH; l++)
        {
            if (real == map[k][l][0])
            {
                if (b_serch(1, k, l, 1))
                {
                    map[k][l][1] = 1;
                    i++;
                }
            }
        }
    }
}

void block_check(int y, int x)
{
    int i = 0;

    for (int k = 0; k < HEIGHT; k++)
    {
        for (int l = 0; l < WIDTH; l++)
        {
            map[k][l][1] = 0;
        }
    }
    i = b_serch(map[y][x][0], y, x, 0);
    if (i == 0)
    {
        return;
    }
    else if (i == 1)
    {
        block_make(map[y][x][0], y, x);
        
        printf("\n-----------------------\n");
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                switch (map[y][x][1])
                {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("□");
                    break;
                case 2:
                    printf("■");
                    break;
                default:
                    break;
                }
            }
            printf("\n");
        }
        printf("---------------\n");

        sleep(1);


        return;
    }
}

void change(int y, int x)
{
    int sum[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int new_sum = 0;
    int max = 0;
    int direction[] = {15, 15, 15, 15, 15, 15, 15, 15, 15};

    block_check(y, x);
    sum[0] = serch(map[y][x][0], y, x, 0);
    // printf("-nor-");
    sum[1] = serch(map[y][x][0], y + 1, x, 1); // down
    // printf("-down-");
    sum[2] = serch(map[y][x][0], y, x + 1, 2);
    // printf("-right-");//right
    sum[3] = serch(map[y][x][0], y - 1, x, 3);
    // printf("-up-");  //up
    sum[4] = serch(map[y][x][0], y, x - 1, 4);
    // printf("left"); //left
    sum[5] = serch(map[y][x][0], y + 1, x + 1, 5); // migisita
    sum[6] = serch(map[y][x][0], y - 1, x + 1, 6); // migiue
    sum[7] = serch(map[y][x][0], y - 1, x - 1, 7); // hidariue
    sum[8] = serch(map[y][x][0], y + 1, x - 1, 8); // hidarisita

    for (int i = 0; i < 9; i++)
    {
        if (i == 0)
        {
            max = sum[0];
        }
        else if (sum[i] > max)
        {
            max = sum[i];
            new_sum = i;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (sum[i] == max)
        {
            direction[i] = i;
        }
    }
    // printf("|%d|",map[y][x]);
    // printf("[%d],[%d]",direction, new_sum);
    // printf("~%d~",new_sum);
    if (direction[0] == 0 && // dont move
        direction[1] == 15 &&
        direction[2] == 15 &&
        direction[3] == 15 &&
        direction[4] == 15 &&
        direction[5] == 15 &&
        direction[6] == 15 &&
        direction[7] == 15 &&
        direction[8] == 15)
    {
        return;
    }
    else
    {
        premoov(&direction[0], y, x);
        // moov(new_sum, y, x);
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    int alt;

    for (size_t i = 0; i < 200; i++)
    {
        test[i] = 1 + rand() % 8;
        printf("%d\n", test[i]);
    }
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            map[y][x][1] = 0;
            alt = rand() % 100;
            if (0 <= alt && alt < NONE)
            {
                map[y][x][0] = 0;
            }
            else if (NONE <= alt && alt < NONE + ZERO)
            {
                map[y][x][0] = 1;
            }
            else
            {
                map[y][x][0] = 2;
            }
            switch (map[y][x][0])
            {
            case 0:
                printf(" ");
                break;
            case 1:
                printf("□");
                break;
            case 2:
                printf("■");
                break;
            default:
                break;
            }
        }
        printf("\n");
    }
    for (int k = 0; k < 50; k++)
    {
        sleep(1);

        for (int y = 0; y < HEIGHT; y++)
        {
            printf("\n%d------", y);
            for (int x = 0; x < WIDTH; x++)
            {
                if (map[y][x][0] != 0)
                {
                    change(y, x);
                }
            }
        }
        printf("\n");
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                switch (map[y][x][0])
                {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("□");
                    break;
                case 2:
                    printf("■");
                    break;
                default:
                    break;
                }
            }
            printf("\n");
        }
    }
}