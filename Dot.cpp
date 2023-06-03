#include "Dot.h"
#include<iostream>
#include <Windows.h>

using namespace std;

int Dot::get_a() const
{
    return a;
}

int Dot::get_b() const
{
    return b;
}

void Dot::set_a(int a)
{
    this->a = a;
}

void Dot::set_b(int b)
{
    this->b = b;
}

void Dot::draw(const Dot& a, const Dot& b, const vector<Dot>& walls) const
{
    if (a.get_a() == b.get_a() && a.get_b() == b.get_b()) {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 40; j++) {
                if (i == a.get_b() && j == a.get_a()) {
                    cout << "x";
                }
                else {
                    cout << "-";
                }
            }
            cout << endl;
        }
        return;
    }

    int movex = 0;
    int movey = 0;

    if (b.get_a() != a.get_a())
        movex = (b.get_a() - a.get_a()) / abs(b.get_a() - a.get_a());
    if (b.get_b() != a.get_b())
        movey = (b.get_b() - a.get_b()) / abs(b.get_b() - a.get_b());

    int xx = a.get_a();
    int yy = a.get_b();

    while (xx != b.get_a() || yy != b.get_b()) {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 40; j++) {
                if (i == a.get_b() && j == a.get_a()) {
                    cout << "A";
                }
                else if (i == b.get_b() && j == b.get_a()) {
                    cout << "B";
                }
                else if (i == yy && j == xx) {
                    cout << "x";
                }
                else if (wall(j, i, walls)) {
                    cout << "*";
                }
                else {
                    cout << "-";
                }
            }
            cout << endl;
        }
        Sleep(100);


        if (xx != b.get_a() && !wall(xx + movex, yy, walls))
            xx += movex;
        if (yy != b.get_b() && !wall(xx, yy + movey, walls))
            yy += movey;


        system("CLS");
    }


    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 40; j++) {
            if (i == a.get_b() && j == a.get_a() && !(a.get_a() == b.get_a() && a.get_b() == b.get_b())) {
                cout << "A";
            }
            else if (i == b.get_b() && j == b.get_a() && !(a.get_a() == b.get_a() && a.get_b() == b.get_b())) {
                cout << "x";
            }
            else if (wall(j, i, walls)) {
                cout << "*";
            }
            else {
                cout << "-";
            }
        }
        cout << endl;
    }
}

bool Dot::wall(int a, int b, const vector<Dot>& walls) const
{
    for (int i = 0; i < walls.size(); i++)
    {
        if (walls[i].get_a() == a && walls[i].get_b() == b)
        {
            return true;
        }
    }
    return false;
}
