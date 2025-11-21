/**
 * Eigen提供矩阵/向量算术运算，可以通过重载常见的 C++ 算术运算符（例如 +、-、*）或特殊方法（例如dot()、cross()等）来实现。对于Matrix类（矩阵和向量），
 * 运算符仅重载以支持线性代数运算。例如，matrix1 * matrix2表示矩阵乘积，而vector + scalar不允许使用其他运算符。
 * 
 * - 稠密矩阵和数组操作
 *      - 矩阵和向量运算 
 * 
 * @param 矩阵乘法和矩阵向量乘法
 * 矩阵乘法同样使用矩阵运算operator*。由于向量是矩阵的一种特殊情况，它们也隐式地包含在矩阵运算中，因此矩阵向量乘法实际上只是矩阵乘法的一种特殊情况，向量向量外积也是如此。因此，所有这些情况都只需要两个运算符即可处理：
 *      二元运算符 * 如a*b
 *      复合运算符 *= 例如a*=b（右乘：a*=b等价于a = a*b）
 */
#include <iostream>
#include <Eigen/Dense>

using namespace std;

int main() {
    Eigen::Matrix2d mat;
    mat << 1, 2, 3, 4;
    Eigen::Vector2d u(-1, 1), v(2, 0);
    cout << "mat * mat: \n" << mat * mat << endl;

    cout << "mat * u: \n" << mat * u << endl;

    cout << "u^t * mat: \n" << u.transpose() * mat << endl;

    cout << "u^t * v: \n" << u.transpose() * v << endl;

    cout << "u * v^t: \n" << u * v.transpose() << endl;

    // 担心这样做m=m*m可能会导致别名问题，请暂时放心：Eigen将矩阵乘法视为特殊情况，并会处理此处引入临时变量的问题，因此它会编译成m=m*m：
    mat = mat * mat;
    cout << "Now mat is \n" << mat << endl;

    // noalias() 是用于禁用别名检查的成员函数，核心作用是优化矩阵 / 向量赋值运算的性能，避免不必要的临时内存分配。
    // Eigen 默认会检查赋值操作中左值与右值是否存在内存重叠（即 “别名”，如 A = A * B 中 A 同时出现在左右两侧）。若检测到别名，Eigen 会创建临时矩阵存储中间结果，再赋值给左值，防止计算过程中数据被覆盖导致错误。
    // noalias() 只能用于 C = 表达式 的形式，不支持复合赋值（如 C += A*B）——Eigen 对复合赋值默认优化，无需手动加 noalias()。
    // c.noalias = a * b

    return 0;
}
    