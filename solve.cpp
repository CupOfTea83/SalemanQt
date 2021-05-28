#include "citymap.h"


int solve()
{
    int n = 6;
    int map [6][6]= {
        {-1, 14, -1, -1, -1, -1},
        {-1, -1, -1, -1, 42, 23},
        {19, -1, -1, 9, -1, -1},
        {-1, -1, -1, -1, -1, 31},
        {-1, -1, 18, -1, -1, -1},
        {28, 23, -1, -1, -1, -1}
    };

    int **mapptr = new int* [n];
    for(int i=0;i<n;i++)
    {
        mapptr[i] = new int [n];

        for(int j=0;j<n;j++)
        {
            mapptr[i][j] = map[i][j];
        }

    }


    CityMap counter(mapptr, n);

    counter.f_rez();

    return 0;
}
