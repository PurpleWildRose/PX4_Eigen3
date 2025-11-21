/**
 * 在Eigen中，所有矩阵和向量都是Matrix模板类的对象。向量只是矩阵的一种特殊情况，它只有 1 行或 1 列。
 * 
 * - 稠密矩阵和数组操作
 *      - 矩阵类
 * 
 * @param 矩阵的前三个模板参数
 * Matrix类接受六个模板参数，但目前我们只需了解前三个参数即可。其余三个参数具有默认值，我们暂时保持默认设置，稍后会进行讨论。
 * template<typename _Scalar, int _Rows, int _Cols, int _Options, int _MaxRows, int _MaxCols>
 * Matrix模板的三个必填参数是：
 *      Matrix<typename Scale, int RowAtCompileTime, int ColAtCompileTime>
 *  ^ Scale: 标量类型，即系数的类型。也就是说，如果您想要一个浮点数矩阵，请float在此处选择。有关所有支持的标量类型列表以及如何扩展对新类型的支持，请参阅“标量类型”部分。
 *  ^ RowAtCompileTime/ColAtCompileTime: 编​​译时已知的矩阵的行数和列数
 * 
 * 
 * 
 * @param 向量
 * 如上所述，在特征向量（Eigen）中，向量是矩阵的一种特殊情况，它只有一行或一列。只有一列的情况最为常见；这种向量被称为列向量，通常简称为向量。另一种情况，即只有一行，则被称为行向量。
 */
#include <iostream>
#include <Eigen/Eigen>

using Eigen::Matrix;
typedef Matrix<float, 4, 4> Matrix4f;
typedef Matrix<int, 1, 2> RowVector2i;
typedef Matrix<float, 3, 1> Vector3f;

int main() {

    Matrix4f m = Matrix4f::Random();
    std::cout << "m = " << std::endl << m << std::endl;

    Vector3f n = Vector3f::Random();
    std::cout << "n = " << std::endl << n << std::endl;

    RowVector2i t = RowVector2i::Random();
    std::cout << "t = " << std::endl << t << std::endl;
    return 0;
}