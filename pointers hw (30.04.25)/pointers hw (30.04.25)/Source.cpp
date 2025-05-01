#include <iostream>
using namespace std;

void print(int x, int y)
{
	cout << "x: " << x << "\n";
	cout << "y: " << y << "\n";
}

void obmin(int* px, int* py)
{
	int z = 1;
	int* pz = &z;
	*pz = *px;
	*px = *py;
	*py = *pz;
}

int main()
{

	int x = 10;
	int y = 20;
	print(x, y);
	cout << "\n";

	obmin(&x, &y);
	print(x, y);


}