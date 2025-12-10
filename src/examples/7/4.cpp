/**
 * 解释了Eigen的简化、访问者和广播，以及它们如何与矩阵和数组一起使用。
 *
 * - 稠密矩阵和数组操作
 *      - 减少、访客和广播
 *
 * @param 用户自定义规约函数
 * 参考： DenseBase::redux() 。
 */
#include <Eigen/Dense>
#include <iostream>

using namespace std;
struct SquareSumReducer {
    template<typename Scalar>
    Scalar operator()(const Scalar &acc, const Scalar &val) const{
        return acc + val * val;
    }
};

int main() {
    // 调用 redux() 前建议先判断矩阵是否为空，避免异常：
    // 测试实例
    Eigen::MatrixXd mat(2, 3);
    mat << 1, 2, 3,
            4, 5, 6;

    double square_sum = mat.redux(SquareSumReducer());
    std::cout << "矩阵的平方和： " << square_sum << endl;

    // 简化版：使用lambda表达式
    double square_sum_lambda = mat.redux([](const double &acc, const double &val) {
        return acc + val * val;
    });
    std::cout << "矩阵的平方和(lambda)： " << square_sum_lambda << endl;
    return 0;
}
