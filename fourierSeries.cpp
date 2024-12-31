
#include <iostream>
#include <cmath>
#include <string>
#include <chrono>
#include <vector>
#include <fstream>
using namespace std;
int nRiemman = 10000000;
int sumBound = 50;
double pi = 3.141592653;
double c = 5;
double f(double x);
double a0();
double an(int n);
double bn(int n);
double filter(double x);


/***************************************************/
double f(double x) {
//if (x > 0) return 1;
  //else return -1;
  // return (x * (x - 1) * x + 1);
  return  floor(x);
}
/***************************************************/


int main()
{
  string f = "";
  auto start = std::chrono::high_resolution_clock::now();
  ofstream fout;
  fout.open("fourier.txt");
  double A0 = filter(a0());
  std::cout<<"a0 = " << A0 << "\t"<<c << endl;
  f += to_string(A0);
  fout << A0 << "\t" << c << endl;
  for (int i = 1; i <= sumBound; i++) {
    double a = filter(an(i));
    double b = filter(bn(i));
    std::cout << a << "*cos((" << i << "xpi)/" << c << ")     + " << b << "*sin((" << i << "x*pi)/" << c << ")" << endl;
    fout << a << "\t" << b << endl;
    if (a < 0) {
      f += " -" + to_string(-a) + "  cos( " + to_string(i * pi / c) + " x) ";
    }
    else if (a == 0);
 
    else {
      f += " +" + to_string(a) + "  cos( " + to_string(i * pi / c) + " x) ";
    }
    if (b < 0) {
      f += " -" + to_string(-b) + "  sin( " + to_string(i * pi / c) + " x) ";
    }
    else if (b == 0);
    else {
      f += " +" + to_string(b) + "  sin( " + to_string(i * pi / c) + " x) ";
    }
  }
  fout.close();
  std::cout<<"Fourier Series: " << f << endl;
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> duration = end - start;
  std::cout << "Function execution time: " << duration.count() << " ms" << std::endl;

}

double filter(double x) {
  if (x<0.0001 && x>-0.0001)
    return 0;
  else return x;
}

double a0() {

  double integral = 0;
  for (int i = 0; i < nRiemman; i++) {
    integral += f((-c + (2 * c)*i / nRiemman)) * (2*c)/nRiemman;
  }
  return integral / (2*c);
}

double an(int n) {
  double integral = 0;
  for (int i = 0; i < nRiemman; i++) {
    double x = (-c + (2 * c) * i / nRiemman);
    integral += cos(n*x*pi/c)*f(x) * (2 * c) / nRiemman;
  }
  return integral / c;
}

double bn(int n) {
  double integral = 0;
  for (int i = 0; i < nRiemman; i++) {
    double x = (-c + (2 * c) * i / nRiemman);
    integral += sin(n * x*pi/c) * f(x) * (2 * c) / nRiemman;
  }
  return integral / c;
}

