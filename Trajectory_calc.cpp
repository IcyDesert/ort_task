#include <cmath>

double coef = -1.0;  //
double g = 9.80;
double h = 0.1;
//  是否可以用函数指针？
inline double f_dot_z(double z, double w) { return coef * sqrt(z * z + w * w) * z; }

inline double f_dot_w(double z, double w) { return coef * sqrt(z * z + w * w) * w - g; }

class Trajectory {
   private:
   double x;
   double y;
   double vx;
   double vy;

   Trajectory();
};