// 这个cpp实际上不是严格意义上的cpp
// 只是个参数文件，为了避免文件读写而已
// 因此也没有include Eigen，报错是正常的

namespace R_NS{
    Eigen::Matrix4d R_ = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
}