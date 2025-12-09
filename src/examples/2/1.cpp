/**
 * Eigen提供矩阵/向量算术运算，可以通过重载常见的 C++ 算术运算符（例如 +、-、*）或特殊方法（例如dot()、cross()等）来实现。对于Matrix类（矩阵和向量），
 * 运算符仅重载以支持线性代数运算。例如，matrix1 * matrix2表示矩阵乘积，而vector + scalar不允许使用其他运算符。
 *
 * - 稠密矩阵和数组操作
 *      - 矩阵和向量运算
 *
 * @param 加法和减法
 * 当然，左侧和右侧的行数和列数必须相同。它们的数据Scalar类型也必须相同，因为Eigen不会自动进行数据类型提升。这里用到的运算符有：
 *      二元运算符 + 如同a+b
 *      二元运算符 - 例如a-b
 *      一元运算符 - 例如-a
 *      复合运算符 += 如a+=b
 *      复合运算符 -= 如a-=b
 */
#include <iostream>
#include <Eigen/Dense>

int main() {
    Eigen::Matrix2d a;
    a << 1, 2, 3, 4;
    Eigen::MatrixXd b(2, 2);
    b << 1, 4, 6, 8;
    std::cout << "a + b = \n" << a + b << std::endl;
    std::cout << "a - b = \n" << a - b << std::endl;

    a += b;
    std::cout << "Doing a += b, result: \n" << a << std::endl;

    b -= a;
    std::cout << "Doing a -= b, result: \n" << b << std::endl;

    std::cout << "Doing -a, result: \n" << -a << std::endl;


    typedef Eigen::Matrix<int, 3, 3, Eigen::RowMajor> Matrix3id;
    Matrix3id c;
    c << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    std::cout << "c: \n" << c << std::endl;
    std::cout << "c index: " << c(1, 2) << std::endl;

    return 0;
}
