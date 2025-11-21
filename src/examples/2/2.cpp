/**
 * Eigen提供矩阵/向量算术运算，可以通过重载常见的 C++ 算术运算符（例如 +、-、*）或特殊方法（例如dot()、cross()等）来实现。对于Matrix类（矩阵和向量），
 * 运算符仅重载以支持线性代数运算。例如，matrix1 * matrix2表示矩阵乘积，而vector + scalar不允许使用其他运算符。
 * 
 * - 稠密矩阵和数组操作
 *      - 矩阵和向量运算 
 * 
 * @param 标量乘法和除法
 * 当然，左侧和右侧的行数和列数必须相同。它们的数据Scalar类型也必须相同，因为Eigen不会自动进行数据类型提升。这里用到的运算符有：
 *      二元运算符 * 如matrix*scalar
 *      二元运算符 * 如scalar*matrix
 *      二元运算符 / 如matrix/scalar
 *      复合运算符 *= 如matrix*=scalar
 *      复合运算符 /= 如matrix/=scalar
 */
#include <iostream>
#include <Eigen/Dense>

int main() {
    Eigen::Matrix2d m;
    m << 1, 2, 3, 4;

    Eigen::Vector3d n(1, 2, 3);

    std::cout << "m * 2.5: \n" << m * 2.5 << std::endl;
    std::cout << "n * 2: \n" << n / 2.5 << std::endl;

    m *= 3;
    std::cout << "Doing m*3: \n" << m << std::endl;

    return 0;
}