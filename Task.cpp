#include<iostream>
#include<vector>
#include "Dot.h"

using namespace std;

int main() {

	int a, b;
	bool wish = true;
	vector<Dot> v;
	vector<Dot> wall;
	Dot d;
	for (int i = 0; i < 2; i++)
	{
		cout << "A" << i + 1 << ": ";
		cin >> a;
		a = a - 1;
		d.set_a(a);
		cout << "B" << i + 1 << ": ";
		cin >> b;
		b = b - 1;
		d.set_b(b);
		v.push_back(d);
	}

	do
	{
		cout << "Type in X coordinate of the wall: ";
		cin >> a;
		a = a - 1;
		d.set_a(a);
		cout << "Type in Y coordinate of the wall: ";
		cin >> b;
		b = b - 1;
		d.set_b(b);
		wall.push_back(d);
		cout << "Do you wish to continue, type 1 if yes, type 0 if not !!!";
		cin >> wish;
	} while (wish);

	d.draw(v[0], v[1], wall);

	return 0;
}