#include <iostream> // cin/cout/endl
using namespace std;
//int round(double x){if(x+0.5 > (int)x){return (int)(x+1.0);}return (int)x;}
int main()
{
  double R, G, B;
  cout<<"R: "; cin>>R;
  cout<<"G: "; cin>>G;
  cout<<"B: "; cin>>B;
  R = R / 255 * 100.0 / 100.0;
  G = G / 255 * 100.0 / 100.0;
  B = B / 255 * 100.0 / 100.0;

  cout << R << ", " << G << ", " << B << ", 1.0" << endl;
  system("pause");
}