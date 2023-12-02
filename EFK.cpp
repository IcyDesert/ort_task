#include <iostream>
#include <valarray>


class EFK
{
private:
    // 状态矩阵
    double status_prior[9] = {0};
    double status_amend[9] = {0};
    // 观测矩阵
    double obs_prior[4] = {0};
    double obs_amend[4] = {0};
public:
    EFK(double status_init[9]) {};

    void calc_obs(void); // 观测值计算
    void toggle(void); // 装甲板旋转引起切换
    ~EFK();
};