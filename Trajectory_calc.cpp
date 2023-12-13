#include <cmath>

double coef = -1.0;  //
double g = 9.80;
double h = 0.1;
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

   public:
    Trajectory(double v, double theta);
    void update_and_broadcast(void);
    void mainloop(void);
};

Trajectory::Trajectory(double v, double theta) : vx(v * cos(theta)), vy(v * sin(theta)) {};

void Trajectory::update_and_broadcast(void) {
   x += vx * h + 0.5 * ax * h * h;
   y += vy * h + 0.5 * ay * h * h;
   return; // should broadcast
}
void Trajectory::mainloop(void) {
   double k1x, k2x, k3x, k4x;
   double k1y, k2y, k3y, k4y;
   do {
      k1x = ax_out_of_v(vx, vy);
      k2x = ax_out_of_v(vx + 0.5 * h * k1x, vy + 0.5 * h * k1x);
      k3x = ax_out_of_v(vx + 0.5 * h * k2x, vy + 0.5 * h * k2x);
      k4x = ax_out_of_v(vx + h * k3x, vy + h * k3x);
      this->vx += h * (k1x + 2 * k2x + 2 * k3x + k4x) / 6;
      this->ax = k1x;

      // y is the same! remember to add on!
      update_and_broadcast();
   } while (this->y > __DBL_EPSILON__);
}