/**
 *  什么是 Array 类？
 *  与专用于线性代数的矩阵类不同，数组类（Array类）提供通用数组。此外，数组类还提供了一种简便的方法来执行系数级运算，这些运算可能不具有线性代数意义，例如将一个常数加到数组中的每个系数上，或者将两个数组的系数相乘。
 * 
 * - 稠密矩阵和数组操作
 *      - 数组类和系数运算 
 * 
 * @param 数组类型
 * Array是一个类模板，它接受与Matrix相同的模板参数。与Matrix一样，前三个模板参数是必需的
 * Array<typename Scalar, int RowsAtCompileTime, int ColsAtCompileTime>
 */
#include <Eigen/Dense>
#include <iostream>

int main() {
// Eigen也为一些常见情况提供了类型定义，其方式与矩阵类型定义类似，但略有不同，因为“array”一词既用于指一维数组也用于二维数组。
// 我们采用以下约定：形如 ArrayNt 的类型定义表示一维数组，其中 N 和 t 分别表示数组的大小和标量类型，这与本页解释的矩阵类型定义相同。
// 对于二维数组，我们使用形如 ArrayNNt 的类型定义。
    typedef Eigen::Array<float, Eigen::Dynamic, 1> ArrayXf;
    typedef Eigen::Array<float, 3, 1> Array3f;
    typedef Eigen::Array<double, Eigen::Dynamic, Eigen::Dynamic> ArrayXXd;
    typedef Eigen::Array<double, 3, 3> Array33d;

    return 0;
}