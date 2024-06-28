#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read ( int *arr, int *n ) {
    int u = 0;
    for ( int *a = arr, i = 1; i <= *n; ++i ){
        printf(" n[%d] =  ", i);
        scanf("%d", a);
        if ( *a ) {
            u++;
            a++;
        }
    }
    *n = u;
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

int main() {
    int *arr, n;
    
    printf(" nums to be in: ");
    scanf("%d", &n);
    
    arr = ( int* ) malloc ( n * sizeof( int ) );
    read( arr, &n );
    
    arr = ( int* ) realloc ( arr, n * sizeof( int ) );
    
    printf("\n array with no null:\n");
    display( arr, n );
    
    return 0;
}
