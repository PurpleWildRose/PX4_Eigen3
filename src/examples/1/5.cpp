/**
 * 在Eigen中，所有矩阵和向量都是Matrix模板类的对象。向量只是矩阵的一种特殊情况，它只有 1 行或 1 列。
 * 
 * - 稠密矩阵和数组操作
 *      - 矩阵类
 * 
 * @param 特殊值动态
 * 当然，Eigen并不局限于编译时维度已知的矩阵。`and`RowsAtCompileTime模板ColsAtCompileTime参数可以取特殊值Dynamic，表示矩阵大小在编译时未知，因此必须作为运行时变量处理。
 * 在Eigen术语中，这种大小称为动态 大小；而编译时已知的大小称为固定 大小。例如，便捷的 typedef `<matrix> MatrixXd` 表示一个动态大小的双精度浮点数矩阵
 * Matrix.h
 *      typedef Matrix<double, Dynamic, Dynamic> MatrixXd;
 * 
 *      typedef Matrix<double, Dynamic, 2> VectorXi;
 * 
 */
#include <iostream>
#include <Eigen/Eigen>

using Eigen::Matrix;
using Eigen::Dynamic;

typedef Matrix<int, Dynamic, 1> Vector1i;
typedef Matrix<double, Dynamic, Dynamic> VectorXd;

int main() {
    Vector1i vi = Vector1i::Random(3);
    std::cout << "vi = " << std::endl << vi << std::endl;

    VectorXd vx = VectorXd::Random(2, 6);
    std::cout << "vx = " << std::endl << vx << std::endl;

    return 0;
}