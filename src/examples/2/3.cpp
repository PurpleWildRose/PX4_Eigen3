/**
 * Eigen提供矩阵/向量算术运算，可以通过重载常见的 C++ 算术运算符（例如 +、-、*）或特殊方法（例如dot()、cross()等）来实现。对于Matrix类（矩阵和向量），
 * 运算符仅重载以支持线性代数运算。例如，matrix1 * matrix2表示矩阵乘积，而vector + scalar不允许使用其他运算符。
 * 
 * - 稠密矩阵和数组操作
 *      - 矩阵和向量运算 
 * 
 * @param关于表达式模板的说明
 * 现在简单提一下：
 *      在Eigen中，算术运算符（例如 `=` operator+）本身并不执行任何计算，它们只是返回一个描述待执行计算的“表达式对象”。实际的计算是在之后，当整个表达式被求值时发生的，通常是在 `$(expression)` 函数中operator=。
 */
#include <iostream>
#include <Eigen/Dense>

int main() {
    Eigen::Vector4d m(1, 2, 3, 4);
    Eigen::Vector4d n(4, 5, 6, 7);

    for(int i = 0; i < m.size(); i++) {
        std::cout << "dot: " << m[i] * n[i] << std::endl;
    }

    return 0;
}