#include <cmath>
#include <iostream>

const double coef = -1.0;     // 系数，即-k/m，可以预先计算得知
const double g = 9.80;        // 重力加速度
const double h = 0.1;         // 迭代步长
const double EPSILON = 1e-6;  // 小量，用于判断是否非负

class Trajectory {
   private:
    // x、y坐标
    double x = 0.0;
    double y = 0.0;
    // x、y方向速度分量
    double vx;
    double vy;
    // x、y方向加速度分量
    double ax;
    double ay;
    long long int n = 0;  // 微分方程迭代步数
    void ronge_kutta(double vx, double vy, int mode);
    double ax_out_of_v(double z, double w);
    double ay_out_of_v(double z, double w);

   public:
    Trajectory(double v, double theta);
    void update_and_broadcast(void);
    void mainloop(void);
    ~Trajectory();
};
/**
 * @brief 弹道对象的构造函数；在构造时一并给xy分量的初速度赋初值
 * @param v 子弹的合初速度
 * @param theta 子弹初速度仰角
 */
Trajectory::Trajectory(double v, double theta) : vx(v * cos(theta)), vy(v * sin(theta)){};

/**
 * @brief 利用速度分量，通过微分方程计算x方向加速度（为了与推导过程保持一致，这里没有改符号）
 * @param z x轴速度
 * @param w y轴速度
 * @return
 */
inline double Trajectory::ax_out_of_v(double z, double w) { return coef * sqrt(z * z + w * w) * z; }
/**
 * @brief 利用速度分量，通过微分方程计算y方向加速度（为了与推导过程保持一致，这里没有改符号）
 * @param z x方向速度
 * @param w y方向速度
 */
inline double Trajectory::ay_out_of_v(double z, double w) { return coef * sqrt(z * z + w * w) * w - g; }
/**
 * @brief 利用四阶龙格库塔法、微分方程更新速度
 * （其实可以用函数指针数组或传函数参数，但是才两个，没必要）
 * @param vx x方向速度
 * @param vy y方向速度
 * @param mode 控制参数，0为x轴计算，1为y轴计算
 */
void Trajectory::ronge_kutta(double vx, double vy, int mode) {
    double k1, k2, k3, k4;
    switch (mode) {
    case 0:
        k1 = ax_out_of_v(vx, vy);
        k2 = ax_out_of_v(vx + 0.5 * h * k1, vy + 0.5 * h * k1);
        k3 = ax_out_of_v(vx + 0.5 * h * k2, vy + 0.5 * h * k2);
        k4 = ax_out_of_v(vx + h * k3, vy + h * k3);
        this->vx += h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        this->ax = k1;
        break;
    case 1:
        k1 = ay_out_of_v(vx, vy);
        k2 = ay_out_of_v(vx + 0.5 * h * k1, vy + 0.5 * h * k1);
        k3 = ay_out_of_v(vx + 0.5 * h * k2, vy + 0.5 * h * k2);
        k4 = ay_out_of_v(vx + h * k3, vy + h * k3);
        this->vy += h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        this->ay = k1;
        break;
    default:
        return;
    }
    return;
}
/**
 * @brief 与坐标相关的操作，包括更新及广播x、y的坐标
 */
void Trajectory::update_and_broadcast(void) {
    x += vx * h + 0.5 * ax * h * h;
    y += vy * h + 0.5 * ay * h * h;
    printf("%.5f %.5f %.5f\n", x, n * h, y);
    return;
}
/**
 * @brief 循环迭代，直到y <= 0即落地
 */
void Trajectory::mainloop(void) {
    printf("x     t     y\n");
    do {
        ronge_kutta(this->vx, this->vy, 0);
        ronge_kutta(this->vx, this->vy, 1);
        ++n;
        update_and_broadcast();
    } while (this->y > EPSILON);
}
Trajectory::~Trajectory(){};

int main(void) {
    Trajectory trj(10, M_PI / 4);
    trj.mainloop();
}