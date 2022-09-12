#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill4x4( int a[][4] ) {
    for( int r = 0; r < 4; r++ )
        for( int c = 0; c < 4; c++ )
            a[r][c] = rand() % 100 + 1;
}

void show4x4( int a[][4] ) {
    for( int r = 0; r < 4; r++ )
        for( int c = 0; c < 4; c++ )
            printf( "%5d%c", a[r][c], "   \n"[c] );
     puts( "" );
}

int showPair( int a, int b, int pos ) {
    printf( "%2dx%-2d%c", a, b, "   \n"[pos] );
    return a * b;
}

void mult4x4( int a[][4], int b[][4], int d[][4], bool x ) {
    for( int r = 0; r < 4; r++ )
        for( int c = 0; c < 4; c++ )
            // assign (=), not accumulate (+=)
            // notice the 'exchange' of row/col access of 'b[][]'
            if( x )
                d[r][c] = showPair( a[r][c], b[r][c], c );
            else
                d[r][c] = showPair( a[r][c], b[c][r], c );
    puts( "" ); show4x4( d );
}

int main()
{
    srand(time(0));
    double time_spent = 0.0;

    clock_t begin = clock();

    int a[4][4]; fill4x4( a ); show4x4( a );
    int b[4][4]; fill4x4( b ); show4x4( b );
    int d[4][4];
    mult4x4( a, b, d, true );
    mult4x4( a, b, d, false );

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The time is %f seconds. ", time_spent);
    return 0;
}