#ifndef CITYMAP_H
#define CITYMAP_H

#include <string>

using namespace std;

struct Rebro
    {
        int a;
        int b;
    };

class CityMap
{
public:
    CityMap(int **map_in, int lines_in);
    void f_rez();
    string path;
    int sum;
private:
    void min_line();
    void min_column();
    int fmin_str(int l, int c);
    int fmin_col(int l, int c);
    Rebro cleaner_map();
    int columns;
    int lines;
    int **map_orig;
    int **map;
    Rebro *rez;

};

#endif // CITYMAP_H
