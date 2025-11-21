/**
 * Eigen提供矩阵/向量算术运算，可以通过重载常见的 C++ 算术运算符（例如 +、-、*）或特殊方法（例如dot()、cross()等）来实现。对于Matrix类（矩阵和向量），
 * 运算符仅重载以支持线性代数运算。例如，matrix1 * matrix2表示矩阵乘积，而vector + scalar不允许使用其他运算符。
 * 
 * - 稠密矩阵和数组操作
 *      - 矩阵和向量运算 
 * 
 * @param 基本算术归约运算
 * Eigen还提供了一些简化操作，可以将给定的矩阵或向量简化为单个值，例如所有系数的和（由 sum ()计算）、积（prod()）或最大值（maxCoeff()）和最小值（minCoeff()）
 */
#include <iostream>
#include <Eigen/Dense>

using namespace std;

int main() {
    Eigen::Matrix2d mat;
    mat << 1, 2, 3, 4;

    cout << "Sum: " << mat.sum() << endl;
    cout << "Prod: " << mat.prod() << endl;
    cout << "Mean: " << mat.mean() << endl;
    cout << "MinCoeff: " << mat.minCoeff() << endl;
    cout << "MaxCoeff: " << mat.maxCoeff() << endl;
    // 迹（Trace） 是线性代数中的基础概念，Eigen 库通过 trace() 方法和 diagonal().sum() 两种方式高效计算，核心是主对角线元素之和（即行标与列标相等的元素 aii​ 之和）。
    cout << "Trace: " << mat.trace() << endl;


    // 还有一些函数变体minCoeff，maxCoeff它们通过参数返回相应系数的坐标：
    Eigen::MatrixXf m = Eigen::MatrixXf::Random(3, 3);
    std::ptrdiff_t i, j;
    float min_t = m.minCoeff(&i, &j);
    cout << "Random : \n" << m << endl;
    cout << "MinCoeff: " << min_t << ", Position: (" << i << ", " << j << ")" << endl;

    float max_t = m.maxCoeff(&i, &j);
    cout << "MaxCoeff: " << max_t << ", Position: (" << i << ", " << j << ")" << endl;


    return 0;
}