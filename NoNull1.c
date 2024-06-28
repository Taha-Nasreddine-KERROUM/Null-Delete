#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read ( int *arr, int n ) {
    
    for ( int *a = arr; a < arr + n; ++a ){
        printf(" n[%ld] =  ", a - arr + 1);
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

void delete(int *arr, int *n) {
    for ( int *a = arr; a < arr + *n; ++a ) {
        if ( !*a ) {
            memmove(a, a + 1, ((*n - 1) - (a - arr)) * sizeof(int));
            a--;
            --*n;
        }
    }
}

int main() {
    int *arr, n;
    
    printf(" nums to be in: ");
    scanf("%d", &n);
    
    arr = ( int* ) malloc ( n * sizeof( int ) );
    read( arr, n );
    
    printf(" array before:\n");
    display( arr, n );
    
    delete( arr, &n );
    arr = ( int* ) realloc ( arr, n * sizeof( int ) );
    
    printf("\n array after:\n");
    display( arr, n );
    
    
    return 0;
}
