// mandelbrotC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <chrono>
#include <opencv.hpp>
using namespace std;
const int iterations = 6000;
const int check = 500;
struct Complex{
  double real;
  double imaginary;

 
};
double mod(Complex c);
int mandelbrot(Complex c);
void square(Complex& c);
int main()
{
  cv::Mat image
  ofstream fout;
  ofstream fout2;
  ofstream fout3;
  ofstream fout4;

  fout.open("output1.txt", ios::trunc);
  fout2.open("output2.txt", ios::trunc);
  fout3.open("output3.txt", ios::trunc);
  fout4.open("output4.txt", ios::trunc);

  string output = "";

  Complex c = { 0, 0 };
  int attempt = 0;
  int count = 0;
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < iterations; i++) {
    for (int j = 0; j < iterations; j++) {
      c.real = -2 + i * 2.75 / iterations;
      c.imaginary = -1.25 + (j * 2.5 / iterations);
       attempt = mandelbrot(c);
       count++;
       if (attempt != 0) {
         output += to_string(c.real) + " " + to_string(c.imaginary) + " " + to_string(attempt) + "\n";
       }
       if (count % 100000 == 0) {
         if (count % 400000 == 0) fout << output;
         else if (count % 300000 == 0) fout2 << output;
         else if (count % 200000 == 0) fout3 << output;
         else fout4 << output;
         output = "";
       }
    }
  }
  fout.close();
  auto end = std::chrono::high_resolution_clock::now();
  chrono::duration<double> duration = end - start;
  cout << "Time taken: " << duration.count() << " seconds" << std::endl;

}
double mod(Complex c) {
  double mod = 0;
  mod += pow(c.real, 2);
  mod += pow(c.imaginary, 2);
  mod = pow(mod, 0.5);
  return mod;
}

void square(Complex &c) {
  double tempReal = c.real;
  double tempI = c.imaginary;

  c.real = pow(tempReal, 2) - pow(tempI, 2);
  c.imaginary = 2 * tempI * tempReal;
}

int mandelbrot(Complex c) {
  Complex z = { 0, 0 };
  for (int i = 0; i < check; i++) {
    square(z);
    z.real += c.real;
    z.imaginary += c.imaginary;
    if (mod(z) >= 2) {
      return (i+1);
    }
  }
  return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
