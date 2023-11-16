#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

const char PLACEHOLDER = '8';
const char HIDDEN = '#';
const char MINE = '*';
const char FLAG = 'F';
const char EMPTY = ' ';
typedef struct {
    char** arr;
    char** revealed;
    int size;
} Array;

bool pop(Array *a, int x, int y){
    a->arr[x][y] = EMPTY;
    if(a->revealed[x][y] == MINE)
        return true;
    else return false;

}

void flag(Array *a, int x, int y){
    a->arr[x][y] = FLAG;
}

void initialize(Array *a,int n) {

    //Creates a NxN array of chars
    a->arr = (char**)malloc(n * sizeof(char*));
    a->revealed = (char**)malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++)
    {
        a->arr[i] = (char*)malloc(n * sizeof(char));
        a->revealed[i] = (char*)malloc(n * sizeof(char*));
    }
    a->size = n;

    for(int i = 0; i < a->size; i++)
        for(int j = 0; j < a->size; j++)
        {
            a->arr[i][j] = HIDDEN;
            a->revealed[i][j] = PLACEHOLDER;
        }
            
}
void print(const Array *a) {
    int i,j;
    for( i = 0; i < a->size; i++) {
        printf("%c ", (char)i+65);
    }
    printf("\n");
    for( i = 0; i < a->size; i++) {
        for( j = 0; j < a->size; j++){
            if(a->arr[i][j] == EMPTY)
                printf("%c ", a->revealed[i][j]);
            else
            printf("%c ", a->arr[i][j]);
        }
        printf("%d",i);

        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    printf("Select Difficulty\n 1. Easy(6x6, 8 bombs)\n 2. Medium(8x8 (24 bombs))\n 3. Hard(12x12) (48 bombs)\n");
    int difficulty_in,size_in;
    scanf("%d", &difficulty_in);

    switch (difficulty_in)
    {
    case 1:
        size_in = 6;
        break;
    case 2:
        size_in = 8;
        break;
    case 3:
        size_in = 12;
        break;
    default:
        break;
    }
    Array *Board = (Array*)malloc(sizeof(Array));
    initialize(Board, size_in);
    bool gaming = true;
    while(gaming)
    {
        int x,y;
        char action;
        print(Board);
        printf("Select Option\n p. Pop\n f. Flag\n");
        scanf(" %19s", &action);
        switch (action)
        {
        case 'p':
            printf("Select X,Y\n");
            scanf("%d", &x);
            scanf("%d", &y);
            if(pop(Board, x, y))
            {
                printf("You lost!");
                gaming = false;
            }
            print(Board);
            break;
        case 'f':
            printf("Select X,Y\n");
            scanf("%d", &x);
            scanf("%d", &y);
            flag(Board, x, y);
            print(Board);
            break;
        default:
            break;
        }
    }
    return 0;
}