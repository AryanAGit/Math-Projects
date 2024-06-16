// use n= 2000000100 for most accuracy (found by testing). more/less is more innacurate. takes long time. use 70 mil if less accuracy needed
// this is probably due to underflow error when dividing by n
// use delta x = 0.0000001 for accuracy (10^-7) more/less seems to have underflow error
// pi= 3.14159265359
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Complex {
  double r;
  double i;

  void print() {
    if(i>=0) cout << std::fixed << std::setprecision(10) <<r << " + " << i << " i" << endl;
    else cout << std::fixed << std::setprecision(10) << r << " - " << -1*i << " i" << endl;
  }
};

//*********** ATTENTION REMINDER ***************
// Make sure functions return -1 if error 
// Make complex arithmetic (add, subract, multiply, divide)
// Also make hyper trig functions
// Return inf/-inf/ nan as errors
// complete complex arctan
//**********************************************
double Rintegral(double lower, double upper);
double f(double x);
double derivative(double c);
double Trapintegral(double lower, double upper);
long double Nderivative(double c, int n);

double factorial(int x);
double sine(double x);
double cosine(double x);
long double arcsine(double x);
long double arccosine(double x);
long double tangent(double x);
long double arcTan(double x);
long double arcTangent(double x);
long double sineH(double x);
long double cosineH(double x);
long double tangentH(double x);
long double newton(double x);
long double arcIntegrand(double x);
long double arc(double a, double b);

long double ln(double x);
long double e(long double);
long double squareRt(double x);
long double sqrtv2(double x);
long double nthRt(double x, int n);
long double nrtv2(double x, int n);
long double natLog(double x);
long double power(double x, double n);

long double lambertW(double x);
long double lambertW1(double x);


Complex complexLog(Complex z);
Complex complexSine(Complex z);
Complex complexCosine(Complex z);
Complex complexTangent(Complex z);
Complex complexPower(Complex z, double n);
Complex complexPowerv2(Complex z, Complex n);
Complex complexSineH(Complex z);
Complex complexCosineH(Complex z);
Complex complexTanH(Complex z);
Complex divideComplex(Complex z1, Complex z2);
Complex add(Complex z1, Complex z2);
Complex multiply(Complex z1, Complex z2);

  //in progress
Complex complexArcTangent(Complex z);
int main() 
{
 /* double x = 0;
  int n= 0;
  while (true) {
    
    cin >> x;
    cin.ignore(100, 10);
    cin >> n;
    cin.ignore(100, 10);
    cout <<"Using newton: " << std::fixed << std::setprecision(20) << nrtv2(x, n) << endl;
    cout << "Using binary search: " << std::fixed << std::setprecision(20) << nthRt(x, n) << endl;

  }
  */
  //long double input;
 // cin >> input;
 // cin.ignore(100, 10);
  Complex z = { 0 ,0 };
  complexLog(z).print();

  //Complex n = { 2, 3 };
  //Complex c = complexPowerv2(z, n);
  //c.print();
  //cout << std::fixed << std::setprecision(20)<< arcTan(100000);

 //cout << std::fixed << std::setprecision(20)<< exp(1);
 // cout << std::fixed << std::setprecision(20) << Rintegral(0, 30000) << endl;
 //cout << std::fixed << std::setprecision(20) << sine(103*3.14159265359/2) << endl;
  //cout << factorial(12);
  //cout << std::fixed << std::setprecision(20) << Trapintegral(0, 100000) << endl;
  //cout<<std::fixed<<std::setprecision(20) << derivative(2);
  // cout<<std::fixed<<std::setprecision(20) << Nderivative(4, 2);
  //cout << std::fixed << std::setprecision(20) << arcsine(input);  
  //cout << std::fixed << std::setprecision(20) << lambertW(-0.1) << endl;
 // cout << std::fixed << std::setprecision(20) << lambertW1(-0.1) << endl;
  //Complex c = { 0, 1 };
  //c = complexLog(c);
  //c.print();


  //cout << std::fixed << std::setprecision(20) << newton(3);
  //cout << std::fixed << std::setprecision(20) << arc(0, newton(3));


}
double f(double x) {
  double y = sine(x);

  return y;
}

double Rintegral(double a, double b) {
  double area = 0;
 
  unsigned int n = 70000000;
  double width = (b - a) / n;
  for (int i = 1; i < n; i++) {
    double rectangle = width * f(a + i * width);
    area += rectangle;
  }
  return area;
}
double Trapintegral(double a, double b) {
  double area = 0;
  unsigned int n = 70000000;
  double width = (b - a) / n;
  for (int i = 0; i < n; i++) {
    int j = i + 1;
    double trapezoid = width * 0.5*(f(a+i*width)+f(a+j*width));
    area += trapezoid;
  }
  return area;
}

double derivative(double c) {
  long double deltaX = 0.00000001;
  long double dx = 0;
  dx = (f(c + deltaX) - f(c)) / deltaX;
  dx -= (f(c - deltaX) - f(c)) / deltaX;
  return dx / 2;
}

long double Nderivative(double c, int n) {
  long double deltaX = 0.0001;
  long double dx = 0;
  if (n == 1) {
     return derivative(c);
  }
  else if (n ==0) {
    return f(c);
  }
  else if (n < 0) {
    cout << "Nth derivative must be >= 0" << endl;
  }
  else {
    dx = (Nderivative(c + deltaX, n - 1) - Nderivative(c, n - 1)) / deltaX;
    dx -= (Nderivative(c - deltaX, n - 1) - Nderivative(c, n - 1)) / deltaX;

  }
  return dx/2;
}


double factorial(int x) {
  //12 is the limit for highst factorial stored in int
  if (x == 0) return 1;
  double y = x * factorial(x - 1);
  return y;
 }


double sine(double x) {
  while (true) {
    if (x > 6.3)x -= 2* 3.14159265359;
    else if (x < -6.3) x += 2* 3.14159265359;
    else break;
  }
  double taylor = 0;
  for (int i = 0; i < 20; i++) {
    taylor = taylor + ((pow(-1, i)) * (pow(x, 2 * i + 1))/factorial(2*i+1));
  }
  return taylor;
}

double cosine(double x) {
  while (true) {
    if (x > 6.3)x -= 2 * 3.14159265359;
    else if (x < -6.3) x += 2 * 3.14159265359;
    else break;
  }
  double taylor = 0;
  for (int i = 0; i < 20; i++) {
    taylor = taylor + ((pow(-1, i)) * (pow(x, 2 * i)) / factorial(2 * i));
  }
  return taylor;
}


long double e(long double x) {
  if (x == 0) return 1;
  int intV = static_cast<int>(x);
  long double floatV = x - intV;

  if (x > -4 && x < 4) {
    long double taylor = 0;

    for (int i = 0; i < 18; i++) {
      taylor += (pow(x, i)) / factorial(i);
    }
    return taylor;
  }
  else if (x>0) {
 
    long double exp = e(1);
    long double val = 1;
    for (int i = 0; i < intV; i++) {
      val *= exp;
    }
    val *= e(floatV);
    return val;
    
  }
  else if (x<0) {
    long double exp = e(1);
    long double val = 1;
    for (int i = 0; i < -1*intV; i++) {
      val = val / exp;

    }
    val *= e(floatV);
    return val;
  }
}
long double ln(double x) {
  if (x == 1) return 0;
  long double guess=1;
  long double arg = x;
  int power = 10;
  long double max=0, min = 0;
  long double tried;
  bool neg = false;
  if (0 < x&& x < 1) {
    neg = true;
    arg = 1 / x;
  }
  arg = nthRt(arg, power);
  while (max==0||min==0) {
     tried = e(guess);

    if (tried - 0.00000001 < arg && arg < tried + 0.00000001) {
      
      return guess;

    }
    else if (tried > arg) {
      guess *= 0.5;
      min = guess; 
      //cout << "min =" << min << endl;

    }
    else if (arg > tried) {
      guess *= 2;
      max = guess;
      //cout << "max =" << max << endl;
    }
  }

  while (true) {
    guess = 0.5 * (min + max);
    tried = e(guess);
    if (tried - 0.00000001 < arg && arg < tried + 0.00000001) {
      break;
    }
    else if (tried > arg) {
      max = guess;
    }
    else if (arg > tried) {
      min = guess;
    }

  }
  if (!neg) return power*guess;
  else return (-1*power* guess);
}

long double arcsine(double x) {
  long double guess = 0;
  long double max = 0, min = 0;
  long double tried;
  if (x == 1) return 3.14159265359;
  else if (x == -1) return -3.14159265359;
  else if (x > 0) max = 0.5 * 3.14159265359;
  else if (x == 0) return 0;
  else min = -0.5 * 3.14159265359;

  while (true) {
    guess = 0.5 * (min + max);
    tried = sine(guess);
    if (tried - 0.000000000001 < x && x < tried + 0.000000000001) {
      return guess;
    }
    else if (tried > x) {
      max = guess;
    }
    else if (x > tried) {
      min = guess;
    }

  }

}
long double arccosine(double x) {
  return ((0.5 * 3.14159265359) - arcsine(x));
}

long double newton(double x) {
  long double guess = x;
  for (int i = 0; i < 15; i++) {
    guess = guess - (f(guess) / derivative(guess));
  }
  return guess;
}
long double arcIntegrand(double x){
  long double val = derivative(x);
  val *= val;
  val++;
  return sqrt(val);
}
long double sqrtv2(double x) {
  if (x < 0) return -1;
  long double guess = 1;
  for (int i = 0; i < 50; i++) {
    guess = guess - (guess * guess - x) / (2 * guess);
  }
  return guess;
}

long double nrtv2(double x, int n) {
  if (n % 2 == 0 && x < 0) return -1;
  if (n == 0) return -1;
  long double guess =1;
  for (int i = 0; i < 1000; i++) {
    double num = guess;
    double den = 1;
    for (int j = 0; j < (n-1); j++) {
      num *= guess;
      den *= guess;
    }
    num -= x;
    den *= n;
    guess = guess - num / den;
  }
  return guess;
}


long double arc(double a, double b){
  double area = 0;
  unsigned int n = 7000;
  double width = (b - a) / n;
  for (int i = 0; i < n; i++) {
    int j = i + 1;
    double trapezoid = width * 0.5 * (arcIntegrand(a + i * width) + arcIntegrand(a + j * width));
    area += trapezoid;
  }
  return area;
 }

long double tangent(double x) {
  return sine(x) / cosine(x);
}

long double arcTan(double x) {
  long double guess = 1;
  long double max = 0, min = 0;
  long double tried;
  bool neg = false;
  if (x == 0) return 0;
  else if (x < 0) {
    neg = true;
    x *= -1;
  }
  while (max == 0 || min == 0) {
    tried = tangent(guess);

    if (tried - 0.00000001 < x && x < tried + 0.00000001) {

      return guess;

    }
    else if (tried > x) {
      guess *= 0.5;
      min = guess;
      // cout << "min =" << min << endl;

    }
    else if (x > tried) {
      guess *= 2;
      max = guess;
      // cout << "max =" << max << endl;
    }
  }

  while (true) {
    guess = 0.5 * (min + max);
    tried = tangent(guess);
    if (tried - 0.00000001 < x && x < tried + 0.00000001) {
      break;
    }
    else if (tried > x) {
      max = guess;
    }
    else if (x > tried) {
      min = guess;
    }

  }
  if (!neg) return guess;
  else return (-1 * guess);
}
long double squareRt(double x) {
  if (x < 0) {
    cout << "Imaginary, just like your friends :skull:" << endl;
    return -1;
  }
  long double guess = 1;
  long double max = 0, min = 0;
  long double tried;
  while (max == 0 || min == 0) {
    tried = guess*guess;

    if (tried - 0.000000001 < x && x < tried + 0.000000001) {

      return guess;

    }
    else if (tried > x) {
      guess *= 0.5;
      min = guess;
      // cout << "min =" << min << endl;

    }
    else if (x > tried) {
      guess *= 2;
      max = guess;
      // cout << "max =" << max << endl;
    }
  }
  while (true) {
    guess = 0.5 * (min + max);
    tried = guess*guess;
    if (tried - 0.000000001 < x && x < tried + 0.000000001) {
      break;
    }
    else if (tried > x) {
      max = guess;
    }
    else if (x > tried) {
      min = guess;
    }
    
  }
  return guess;
}

long double nthRt(double x, int n) {
  if (x < 0&&n%2 ==0) {
    cout << "Not real, just like your friends :skull:" << endl;
    return -1;
  }
  if (n== 0) {
    cout << ":skull:" << endl;
    return -1;
  }
  if (x == 0 && n > 0) return 0;
  else if (x == 0 && n < 1) {
    cout << "Bruh division by 0 goes hard ngl :skull: " << endl;
    return -1;
  }
  bool neg = false;
  if (x < 0) {
    neg = true;
    x *= -1;
  }
  long double guess = 1;
  long double max = 0, min = 0;
  long double tried;
  while (max == 0 || min == 0) {
    tried = 1;
    for (int i = 0; i < n; i++) {
      tried *= guess;
    }
    

    if (tried - 0.0000001 < x && x < tried + 0.0000001) {

      return guess;

    }
    else if (tried > x) {
      guess *= 0.5;
      min = guess;
      // cout << "min =" << min << endl;

    }
    else if (x > tried) {
      guess *= 2;
      max = guess;
      // cout << "max =" << max << endl;
    }
  }

  double error;
  if (x < 1000) error = 0.00000001;
  else if (x < 100000) error = 0.000001;
  else if (x < 1000000000000)error = 0.001;
  else error = 0.01;
  while (true) {
    guess = 0.5 * (min + max);
    tried = 1;
    
    
    for (int i = 0; i < n; i++) {
      tried *= guess;
    }

    if (tried - error < x && x < tried +error) {
      break;
    }
    else if (tried > x) {
      max = guess;
    }
    else if (x > tried) {
      min = guess;
    }
  }

  if (!neg) return guess;
  else return -1 * guess;
}
long double natLog(double x) {
  long double area = 0;
  unsigned int n = 70000000;
  int power = 4;
  double arg = nthRt(x, power);
  double width = (arg - 1) / n;
  
  for (int i = 0; i < n; i++) {
    int j = i + 1;
    double trapezoid = width * 0.5 * (1/(1 + i * width) + 1/(1 + j * width));
    area += trapezoid;
  }
  return power*area;
}
long double lambertW(double x) {
  double min = -1;
  double max = 1;
  double tried = 0;
  double guess = 1;
  while (true) {
    tried = guess * e(guess);
    if (tried - 0.00000001 < x && x < tried + 0.00000001) {
      return guess;
    }
    else if (tried < x) {
      guess *= 2;
      max = guess;
    }
    else break;
  }
  while (true) {
    guess = 0.5 * (min + max);
    tried = guess*e(guess);
    if (tried - 0.00001 < x && x < tried + 0.00001) {
      return guess;
    }
    else if (tried > x) {
      max = guess;
    }
    else if (x > tried) {
      min = guess;
    }

  }
}
long double lambertW1(double x) {
  double min = -1 ;
  double max = 0;
  if (x > max || x < min) return 1;

  double tried = 0;
  double guess =-1;
  while (true) {
    tried = guess * e(guess);
    if (tried - 0.00000001 < x && x < tried + 0.00000001) {
      return guess;
    }
    else if (tried < x) {
      guess *= 2;
      max = guess;
    }
    else break;
  }
  while (true) {
    guess = 0.5 * (min + max);
    tried = guess * e(guess);
    if (tried - 0.00000001 < x && x < tried + 0.00000001) {
      return guess;
    }
    else if (tried < x) {
      min = guess;
    }
    else if (x < tried) {
      max = guess;
    }
  }
}
long double power(double x, double n) {
  if (x >= 0 && n > 0) return e(n * ln(x));
  else if ( n == 0) return 1;
  else if (x == 0 && n < 0) {
    cout << "Division by 0 error" << endl;
    return -1;
  }
  else if (x < 0) {
    cout << "Please input positive numbers. If power is odd, just input the same number but positive. If not, then the result is complex, and can't be done" << endl;
    return -1;
  }
}
Complex complexLog(Complex z) {
  double mod = squareRt((z.r * z.r) + (z.i * z.i));
  mod = natLog(mod);
  double theta;
  Complex c;
  if (z.r == 0 && z.i > 0) {
    theta = 0.5 * 3.14159265359;
  }
  else  if (z.r == 0 && z.i > 0) {
    theta = -0.5 * 3.14159265359;
  }
  else if (z.r == 0 && z.i == 0) {
    c.i = 0;
    c.r = 0;
    cout << "Can't do ln(0)" << endl;
    return c;
  }

  else {
    theta = arcTan(z.i / z.r);
    if (z.r < 0) {
      theta += 3.14159265359;
    }
    else if (z.i < 0) {
      theta += (2 * 3.14159265359);
    }
  }
   c = { mod, theta };
  return c;
}

Complex complexSine(Complex z) {
  double a = z.r;
  double b = z.i;
  double real = (0.5 * sine(a)) * (e(b) + e(-1 * b));
  double imag = (0.5 * cosine(a)) * (e(b) - e(-1 * b));
  Complex result = { real, imag };
  return result;
}

Complex complexCosine(Complex z) {
  double a = z.r;
  double b = z.i;
  double real = (0.5 * cosine(a)) * (e(b) + e(-1 * b));
  double imag = (0.5 * sine(a)) * (e(-1 * b) - e(b));
  Complex result = { real, imag };
  return result;
}

Complex complexTangent(Complex z) {
  Complex z1 = complexSine(z);
  Complex z2 = complexCosine(z);
  double a = z1.r;
  double b = z1.i;
  double c = z2.r;
  double d = z2.i;
  if (c == 0 && d == 0) {
    cout << "Tangent is undefined, returning 0" << endl;
    Complex fail = { 0, 0 };
    return fail;
  }
  double real = ((a * c + b * d)) / (c * c + d * d);
  double imag = ((b * c - a * d)) / (c * c + d * d);
  Complex result = { real, imag };
  return result;
}

Complex complexPower(Complex z, double n) {
  Complex result = { 0, 0 };
  if (z.r == 0 && z.i == 0) return result;
  double r = squareRt(z.i * z.i + z.r * z.r);
  double theta = 0;
  if(z.r == 0&& z.i >0) theta = 0.5 * 3.14159265359;
  else if(z.r == 0 && z.i< 0) theta = -0.5* 3.14159265359;
  else {
    theta = arcTan(z.i / z.r);
   if (z.r < 0) {
    theta += 3.14159265359;
   }
  }
  double real = (e(n * ln(r))) * cosine(theta * n);
  double imag = (e(n * ln(r))) * sine(theta * n);
  result.r = real;
  result.i = imag;
  return result;
  
}
//work in progress
Complex complexArcTangent(Complex z) {
  Complex arg1 = { z.r, z.i + 1 };
  Complex arg2 = { z.r, z.i - 1 };

  Complex z1 = complexLog(arg1);
  Complex z2 = complexLog(arg2);

  Complex result = { 0.5 * (z2.i - z1.i), 0.5 * (z1.r - z2.r) };
  return result;
}

long double arcTangent(double x) {
  double area = 0;
  unsigned int n = 46320;
  double width = (x) / n;
  for (int i = 0; i < n; i++) {
    int j = i + 1;
    double f1 = 1 / (1 + i * i * width * width);
    double f2 = 1 / (1 + j * j * width * width);
    double trapezoid = width * 0.5 * (f1 + f2);
    area += trapezoid;
  }
  return area;
}

Complex complexPowerv2(Complex z, Complex n) {
  Complex result = { 0, 0 };
  if (z.r == 0 && z.i == 0) return result;
  double r = squareRt(z.i * z.i + z.r * z.r);
  double theta = 0;
  if (z.r == 0 && z.i > 0) theta = 0.5 * 3.14159265359;
  else if (z.r == 0 && z.i < 0) theta = -0.5 * 3.14159265359;
  else {
    theta = arcTan(z.i / z.r);
    if (z.r < 0) {
      theta += 3.14159265359;
    }
  }
  Complex arg = { theta * n.r , theta * n.i };
  Complex z1 = complexCosine(arg);
  Complex z2 = complexSine(arg);
  double j = cosine(n.i * ln(r));
  double k = sine(n.i * ln(r));
  double c = z1.r;
  double d = z1.i;
  double g = z2.r;
  double h = z2.i;
  double mod = e(n.r * ln(r));
  double real = mod * (j * (c - h) - k * (d + g));
  double imag = mod * (j * (d + g) + k * (c - h));
  result = { real, imag };
  return result;
}
long double cosineH(double x) {
  return 0.5 * (e(x) + e(-1 * x));
}
long double sineH(double x) {
  return 0.5 * (e(x) - e(-1 * x));
}
long double tangentH(double x) {
  if(cosineH(x) != 0) return sineH(x)/cosineH(x);
  else {
    cout << "Division by 0 error" << endl;
    return -1;
  }
}
Complex complexSineH(Complex z) {
  double a = z.r;
  double b = z.i;
  double real = 0.5 * (cosine(b)) * (e(a) - e(-1 * a));
  double imag = 0.5 * (sine(b)) * (e(a) + e(-1 * a));
  Complex result = { real, imag };
  return result;
}
Complex complexCosineH(Complex z) {
  double a = z.r;
  double b = z.i;
  double real = 0.5 * (cosine(b)) * (e(a) + e(-1 * a));
  double imag = 0.5 * (sine(b)) * (e(a) - e(-1 * a));
  Complex result = { real, imag };
  return result;
}
Complex divideComplex(Complex z1, Complex z2) {
  double a = z1.r;
  double b = z1.i;
  double c = z2.r;
  double d = z2.i;
  Complex result = { -1, -1 };
  if (d == 0 && c == 0) {
    cout << "Division by 0" << endl;
    return result;
  }
  double real = (a * c + b * d) / (c * c + d * d);
  double imag = (b * c - a * d) / (c * c + d * d);
  result.r = real;
  result.i = imag;
  return result;

}

Complex complexTanH(Complex z){
  Complex z1 = complexSineH(z);
  Complex z2 = complexCosineH(z);
  if (z2.r == 0 && z2.i == 0) {
    cout << "Division by 0 error" << endl;
    Complex fail = { -1, -1 };
    return fail;
  }
  return divideComplex(z1, z2);

}
Complex add(Complex z1, Complex z2) {
  Complex result = { z1.r + z2.r, z1.i + z2.i };
  return result;
}
Complex multiply(Complex z1, Complex z2) {
  double real = z1.r * z2.r - (z1.i * z2.i);
  double imag = z1.r * z2.i + z1.i * z2.r;
  Complex result = { real, imag };
  return result;
}


