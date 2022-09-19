#include <iostream>
#include <cstdlib>

using namespace std;

class floodFill
{
public:
    void printModel(int cell[][10], int hidden_cell[][10]);
    void WBconvert(int x, int y);

    int temp = 0;
    int area = 0;

    int count[100] = { 0, }; // area  , count
    int cell[10][10];
    int hidden_cell[10][10];
};



int main()
{
    floodFill ff;

    ff.printModel(ff.cell, ff.hidden_cell);

    for (int y = 1; y < 9; y++)
    {
        for (int x = 1; x < 9; x++)
        {
            ff.WBconvert(x, y);
            if (ff.temp == 1)
            {
                ff.area++;
                ff.temp = 0;
            }
        }
    }

    cout << endl;

    for (ff.area; ff.area > -1; ff.area--)
    {
        cout << ff.area << "번째 영역의 1의 갯수: " << ff.count[ff.area] << "개" << endl;
    }
}

void floodFill::printModel(int cell[][10], int hidden_cell[][10])
{
    for (int y = 0; y < 10; y++)
        for (int x = 0; x < 10; x++)
        {
            cell[x][y] = 0;
            hidden_cell[x][y] = 0;
        }
    for (int y = 1; y < 9; y++)
    {
        for (int x = 1; x < 9; x++)
        {
            if (rand() % 2 == 0)
            {
                cell[x][y] = 0;
                hidden_cell[x][y] = 0;
            }
            else
            {
                cell[x][y] = 1;
                hidden_cell[x][y] = 1;
            }
        }
    }

    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            cout << cell[x][y] << "  ";

        }
        cout << endl;
    }
}

void floodFill::WBconvert(int x, int y)
{
    if (hidden_cell[x][y] == 1)
    {
        hidden_cell[x][y] = 0;
        WBconvert(x, y - 1);
        WBconvert(x + 1, y);
        WBconvert(x, y + 1);
        WBconvert(x - 1, y);

        count[area]++;
        temp = 1;
    }
}