/**
 * Eigen提供矩阵/向量算术运算，可以通过重载常见的 C++ 算术运算符（例如 +、-、*）或特殊方法（例如dot()、cross()等）来实现。对于Matrix类（矩阵和向量），
 * 运算符仅重载以支持线性代数运算。例如，matrix1 * matrix2表示矩阵乘积，而vector + scalar不允许使用其他运算符。
 * 
 * - 稠密矩阵和数组操作
 *      - 矩阵和向量运算 
 * 
 * @param 转置（Transposition）与共轭（Conjugation）
 * transpose aT, conjugate a¯, and adjoint (i.e., conjugate transpose) a∗  分别通过成员函数transpose()、conjugate()和adjoint()获得。
 */
#include <iostream>
#include <Eigen/Dense>

int main() {
    Eigen::MatrixXcf a = Eigen::MatrixXcf::Random(2, 2);
    std::cout << "a origin: \n" << a << std::endl;

    std::cout << "a transpose: \n" << a.transpose() << std::endl;

    std::cout << "a conjugate: \n" << a.conjugate() << std::endl;

    std::cout << "a adjoint: \n" << a.adjoint() << std::endl;

    // 对于实矩阵，conjugate()是一个空运算，因此adjoint()等价于transpose()。

    // 对于基本的算术运算符。 transpose() and adjoint()只需返回一个代理对象无需进行实际的转置运算。
    // 如果执行 b = a.transpose() 则转置运算会在结果写入b的同时进行evaluated。
    // 如果执行 a = a.transpose() 则Eigena会在转置运算完成之前就开始将结果写入, 因此，该指令a = a.transpose()并不会a像预期那样
    // try{
    //     a = a.transpose();
    //     std::cout << "Error way: \n" << a << std::endl;
    // }
    // catch(const std::exception& e){
    //     std::cout << "Error way: \n" << std::endl;
    // }
        
    // 这就是所谓的别名问题。在“调试模式”（即断言未被禁用时），这类常见陷阱会被自动检测到。
    // 对于原地转置，例如在 中a = a.transpose()，只需使用transposeInPlace()函数即可：
    a.transposeInPlace();
    std::cout << "Inplace: \n" << a << std::endl;

    // 仅支持方阵（如 3×3 矩阵）或动态尺寸矩阵（MatrixXd/VectorXd，编译时维度未固定）；
    // 固定尺寸的非方阵（如 Vector3d 是 Matrix<double, 3, 1>，固定 3 行 1 列）无法通过 transposeInPlace() 原地转置（维度无法从 3×1 改为 1×3）
    Eigen::Vector3d b(3);
    b << 1, 2, 3;
    std::cout << "rows: " << b.rows() << ", cols: " << b.cols() << std::endl;
    std::cout << "bt.rows: " << b.transpose().rows() << ", cols: " << b.transpose().cols() << std::endl;
    // b.transposeInPlace();    // Error
    // std::cout << "rows: " << b.rows() << ", cols: " << b.cols() << std::endl;

    return 0;
}