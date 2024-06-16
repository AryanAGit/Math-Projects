
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;
const int pointNum = 50000;
//sides of the polygon to do the chaos game in 
const int sides = 3;
struct point {
	double x;
	double y;
};

point randP(point c);

int main()
{

	
	srand(time(0));
	point center;
	if (sides == 2) center = { 0.5, 0 };
	else center = { 0.5, 0.5 / (tan(3.14159265359 / sides)) };
	point* pointArray = new point[sides];
	for (int i = 0; i < sides; i++) {
		double angle = i * 2 * 3.14159265359 / sides;
		point temp = { (-1 * center.x) * cos(angle) + center.y * sin(angle) + center.x,(-1 * center.x) * sin(angle) - center.y * cos(angle) + center.y };
		pointArray[i] = temp;
	}
	ofstream fout;
	fout.open("ChaosGame.txt", ios::trunc);
	
	point test = randP(center);
	point randP = { 0, 0 };

	for (int i = 0; i < pointNum; i++) {
	
		fout << test.x << " " << test.y << endl;
		randP = pointArray[rand() % sides];
		test.x = 0.5*(test.x + randP.x);
		test.y = 0.5 * (test.y + randP.y);
	}
	fout.close();
	point p = { 1, 0 };
	int turns1 = sides * 0.25;
	int turns2 = sides * 0.75;

	point xmax = { (p.x - center.x) * cos(turns1*2 * 3.14159265359 / sides) - (p.y - center.y) * sin(turns1 * 2 * 3.14159265359 / sides) + center.x , (p.x - center.x) * sin(turns1 * 2 * 3.14159265359 / sides) + (p.y - center.y) * cos(turns1 * 2 * 3.14159265359 / sides) + center.y };
	point xmin = {(p.x - center.x) * cos(turns2*2 * 3.14159265359 / sides) - (p.y - center.y) * sin(turns2 * 2 * 3.14159265359 / sides) + center.x , (p.x - center.x) * sin(turns2 * 2 * 3.14159265359 / sides) + (p.y - center.y) * cos(turns2 * 2 * 3.14159265359 / sides) + center.y };
	double ymax;
	if (sides % 2 == 0) {
		ymax = 2 * center.y;
	}
	else {
		ymax = center.y + 0.5 / sin(3.14159265359 / sides);
	}
	cout << "Xmax = " << xmax.x << endl;
	cout << "Xmin = " << xmin.x << endl;
	cout << "Ymax = " << ymax << endl;
	cout << "Ymin = 0" << endl;

	cout << "\n\nSuggested graph range: \nx: [" << xmin.x - 0.1 << ", " << xmax.x + 0.1 << "]" << endl;
	cout << "y: [-0.2, " << xmax.x - xmin.x << "]" << endl;

}

point randP(point c) {
	point temp;
	double angle = rand() % sides;
	angle *= 2 * 3.14159265359 / sides;
	double a = c.x;
	double b = c.y;
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<double> dist(0, 1);
	temp.x = dist(gen);
	
	if (0 < temp.x && temp.x >= 0.5) {
		uniform_real_distribution<double> dist(0, temp.x * b / a);
		temp.y = dist(gen);
	}
	else {
		uniform_real_distribution<double> dist(0, (temp.x - 1) *-1* b / a);
		temp.y = dist(gen);
	}
	temp.x = (temp.x - a) * cos(angle) - (temp.y - b) * sin(angle) + a;
	temp.y = (temp.x - a) * sin(angle) + (temp.y - b) * cos(angle) + b;
	return temp;
}
