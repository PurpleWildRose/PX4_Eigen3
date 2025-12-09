/**
 * 讨论几种高级矩阵初始化方法，并详细介绍了之前介绍过的逗号初始化方法。此外，还解释了如何获取特殊矩阵，例如单位矩阵和零矩阵。
 *
 * - 稠密矩阵和数组操作
 *      - 高级初始化
 *
 * @param 用作临时对象
 * 如上所示，静态方法（例如 Zero() 和 Constant()）可用于在声明变量时或在赋值运算符右侧初始化变量。您可以将这些方法视为返回一个矩阵或数组；实际上，它们返回的是所谓的表达式对象，这些对象会在需要时求值为矩阵或数组，因此这种语法不会产生任何额外的开销。
 * 这些表达式也可以用作临时对象。入门指南中的第二个示例（我们在此重现）已经说明了这一点。
 */
#include <iostream>
#include <Eigen/Dense>

using namespace std;

int main() {
    Eigen::MatrixXd m = Eigen::MatrixXd::Random(3, 3);
    m = Eigen::MatrixXd::Random(3, 3) * 50;
    cout << "m = " << endl << m << endl;

    Eigen::VectorXd v(3);
    v << 1, 2, 3;
    cout << "m*v: " << endl << m * v << endl;

    // 逗号初始化器也可以用于构造临时对象。以下示例构造一个 2×3 的随机矩阵，然后将该矩阵的左侧乘以 [0110] 。
    Eigen::MatrixXf mat = Eigen::MatrixXf::Random(2, 3);
    cout << mat << endl << endl;
    mat = (Eigen::MatrixXf(2, 2) << 0, 1, 1, 0).finished() * mat;
    cout << mat << endl;

    Eigen::Vector2f v2 = Eigen::Vector2f::Constant(0.2);
    Eigen::Matrix2f n = (Eigen::MatrixXf(2, 2) << 1.0f, 3.0f, 6.0f, 9.0f).finished();
    std::cout << "v2 * n: " << std::endl << v2.transpose() * n << std::endl;

    return 0;
}
