#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read ( int **arr, int n ) {
    *arr = ( int* ) malloc ( n * sizeof( int ) );
    for ( int *a = *arr; a < *arr + n; ++a ){
        printf(" n[%ld] =  ", a - *arr + 1);
        scanf("%d", a);
    }
}

void display ( int *arr, int n ) {
    printf("[");
    for ( int *a = arr; a < arr + n; ++a ){
        printf("%d", *a);
        if ( a < arr + n - 1 )
            printf(", ");
    }
    printf("]");
}

void delete ( int **arr, int *n ) {
    int u = 0;
    for ( int *a = *arr; a < *arr + *n; ++a ) {
        if ( !*a ) continue;
        (*arr)[u++] = *a;
    }
    *arr = ( int* ) realloc ( *arr, u * sizeof( int ) );
    *n = u;
}

int main() {
    int *arr, n;
    
    printf(" nums to be in: ");
    scanf("%d", &n);
    read( &arr, n );
    printf(" array before:\n");
    display( arr, n );
    delete( &arr, &n );
    printf("\n array after:\n");
    display( arr, n );
    
    return 0;
}
