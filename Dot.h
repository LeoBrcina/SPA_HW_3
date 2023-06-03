#pragma once
#include <vector>

using namespace std;

class Dot
{
private:
	int a, b;
public:
	int get_a() const;
	int get_b() const;
	void set_a(int a);
	void set_b(int b);
	void draw(const Dot& a, const Dot& b, const vector<Dot>& walls) const;
	bool wall(int a, int b, const vector<Dot>& walls) const;
};

