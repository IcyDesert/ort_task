#include <cmath>
#include <iostream>

const double coef = -1.0;  //
const double g = 9.80;
const double h = 0.1;
const double EPSILON = 1e-7;
//  是否可以用函数指针？
inline double ax_out_of_v(double z, double w) { return coef * sqrt(z * z + w * w) * z; }

inline double ay_out_of_v(double z, double w) { return coef * sqrt(z * z + w * w) * w - g; }

class Trajectory {
   private:
    double x = 0.0;
    double y = 0.0;
    double vx;
    double vy;
    double ax;
    double ay;
    long long int n = 0;
   public:
    Trajectory(double v, double theta);
    void update_and_broadcast(void);
    void ronge_kutta(double (*p_func)(double z, double w));
    void mainloop(void);
};
Trajectory::Trajectory(double v, double theta) : vx(v * cos(theta)), vy(v * sin(theta)) {};

void Trajectory::update_and_broadcast(void) {
   x += vx * h + 0.5 * ax * h * h;
   y += vy * h + 0.5 * ay * h * h;
   printf("%.5f %.5f %.5f", x, n * h, y);
   return; 
}
void ronge_kutta(double (*p_func)(double z, double w)){
   return;
}
void Trajectory::mainloop(void) {
   double k1x, k2x, k3x, k4x;
   double k1y, k2y, k3y, k4y;
   do {
      // TODO 函数指针
      k1x = ax_out_of_v(vx, vy);
      k2x = ax_out_of_v(vx + 0.5 * h * k1x, vy + 0.5 * h * k1x);
      k3x = ax_out_of_v(vx + 0.5 * h * k2x, vy + 0.5 * h * k2x);
      k4x = ax_out_of_v(vx + h * k3x, vy + h * k3x);
      this->vx += h * (k1x + 2 * k2x + 2 * k3x + k4x) / 6;
      this->ax = k1x;

      // y is the same! remember to add on!
      ++n;
      update_and_broadcast();
   } while (this->y > __DBL_EPSILON__);
}