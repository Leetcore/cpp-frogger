#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class Tile
{
public:
    int x;
    int y;
    char pic;
};

int x;
int y;
const int row_count = 5;
const int col_count = 30;
string input;

Tile row[row_count][col_count];
Tile player;
Tile car;
Tile car2;

void render()
{
    for (short y = 0; y < row_count; y++)
    {
        for (short x = 0; x < col_count; x++)
        {
            if (player.x == x && player.y == y)
            {
                cout << player.pic;
            }
            else if (car.x == x && car.y == y)
            {
                cout << car.pic;
            }
            else if (car2.x == x && car2.y == y)
            {
                cout << car2.pic;
            }
            else
            {
                cout << row[y][x].pic;
            }
        }
        cout << endl;
    }
}

void move_car()
{
    if (car.x < col_count)
    {
        car.x++;
    }
    else
    {
        car.x = 0;
    }
    if (car2.x < col_count)
    {
        car2.x += 2;
    }
    else
    {
        car2.x = 0;
    }
}

int main()
{
    for (int i = 0; i < col_count; i++)
    {
        Tile tile_entity;
        tile_entity.pic = '#';
        row[0][i] = tile_entity;
    }
    for (int i = 0; i < col_count; i++)
    {
        Tile tile_entity;
        tile_entity.pic = '-';
        row[1][i] = tile_entity;
    }
    for (int i = 0; i < col_count; i++)
    {
        Tile tile_entity;
        tile_entity.pic = '#';
        row[2][i] = tile_entity;
    }
    for (int i = 0; i < col_count; i++)
    {
        Tile tile_entity;
        tile_entity.pic = '-';
        row[3][i] = tile_entity;
    }
    for (int i = 0; i < col_count; i++)
    {
        Tile tile_entity;
        tile_entity.pic = '#';
        row[4][i] = tile_entity;
    }

    player.x = 14;
    player.y = 4;
    player.pic = 'F';

    car.y = 1;
    car.pic = 'A';
    car2.y = 3;
    car2.pic = 'A';

    cout << "\033[2J\033[1;1H";
    while (true)
    {
        move_car();
        render();
        cin >> input;
        if (input == "up")
        {
            player.y = player.y - 1;
        }
        if (input == "down")
        {
            player.y = player.y + 1;
        }
        if (input == "left")
        {
            player.x = player.x - 1;
        }
        if (input == "right")
        {
            player.x = player.x + 1;
        }
        cout << "\033[2J\033[1;1H";
    }
    return 0;
}