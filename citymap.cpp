#include "citymap.h"


CityMap::CityMap(int **map_in, int lines_in)
{
    map_orig = map_in;
    lines = lines_in;
    columns = lines;

    rez = new Rebro [lines];

    map = new int* [lines];

    for(int i=0;i<lines;i++)
    {
        map[i] = new int [columns];

        for(int j=0;j<columns;j++)
        {
            map[i][j] = map_orig[i][j];
        }
    }
}

void CityMap::min_line()
{
    int min;

    for(int i=0;i<lines;i++)
    {
        min = 1000;

        for(int j=0;j<columns;j++)
        {
            if((min > map[i][j]) && (map[i][j] >= 0))
                min = map[i][j];
        }

        for(int j=0;j<columns;j++)
        {
            if(map[i][j] != -1)
                map[i][j] -= min;
        }
    }
}

void CityMap::min_column()
{
    int min;

    for(int i=0;i<columns;i++)
    {
        min = 1000;

        for(int j=0;j<lines;j++)
        {
            if((min > map[j][i]) && (map[j][i] >= 0))
                min = map[j][i];
        }

        for(int j=0;j<lines;j++)
        {
            if(map[j][i] != -1)
                map[j][i] -= min;
        }
    }
}



int CityMap::fmin_str(int l, int c)
{
    int min = 1000;

    for(int i=0;i<columns;i++)
    {
        if(i!=c)
            if((min > map[l][i]) && (map[l][i] >= 0))
                min = map[l][i];
    }
    return min;
}

int CityMap::fmin_col(int l, int c)
{
    int min = 1000;

    for(int i=0;i<lines;i++)
    {
        if(i!=c)
            if((min > map[i][l]) && (map[i][l] >= 0))
                min = map[i][l];
    }
    return min;
}

Rebro CityMap::cleaner_map()
{
    Rebro a;
    int max =- 1, k, m;

    for(int i=0;i<lines;i++)
    {
        for(int j=0;j<columns;j++)
        {
            if(map[i][j] == 0)
            {
                if(max <= fmin_str(i, j) + fmin_col(j, i))
                {
                    max = fmin_str(i, j) + fmin_col(j, i);
                    k = i;
                    m = j;
                }
            }
        }
    }

    for(int i=0;i<lines;i++)
    {
        for(int j=0;j<columns;j++)
        {
            if(i==k) map[i][j] = -1;
            if(j==m) map[i][j] = -1;
        }
    }

    a.a = k;
    a.b = m;

    return a;

}

void CityMap::f_rez()
{
    int i = 0;

    while(i != lines - 2)
    {
        min_line();
        min_column();
        rez[i] = cleaner_map();
        i++;

    }

    int a,b, z = lines - 2;

    for(int i=1;i<z;i++)
    {
        for(int j=i;j<z;j++)
        {
            if(rez[i].a == rez[j].b)
            {
                a = rez[i].a;
                b = rez[i].b;
                rez[i] = rez[j];
                rez[j].a = a;
                rez[j].b = b;
            }
        }
    }

    this->path = to_string(rez[0].a + 1) + "->" + to_string(rez[0].b + 1) + "->";

    int prev = rez[0].b;

    for(int i=1;i<z;i++)
    {
        if(rez[i].a != prev)
        {
            this->path += to_string(rez[i].a + 1) + "->";
        }
        this->path += to_string(rez[i].b + 1) + "->";
        prev = rez[i].b;
    }

    this->path += to_string(rez[0].a + 1);

    int sum = map_orig[rez[i-1].b][rez[0].a];
    sum += map_orig[rez[0].a][rez[0].b];

    for(int i=1;i<z;i++)
        sum += map_orig[rez[i].a][rez[i].b];
    for(int i=0;i<z-1;i++)
        if(rez[i].b!=rez[i+1].a)
            sum += map_orig[rez[i].b][rez[i+1].a];

    this->sum = sum;

}
