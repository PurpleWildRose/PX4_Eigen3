/**
 * 本页面介绍如何使用“原始”C/C++数组。这在多种情况下都非常有用，尤其是在将其他库中的向量和矩阵“导入”到 Eigen 中时。
 * 有时，您可能需要在 Eigen 中将预定义的数字数组用作向量或矩阵。虽然一种方法是复制数据，但更常见的情况是，您可能希望将这部分内存作为 Eigen 类型重新使用。幸运的是，使用 Map 类可以轻松实现这一点。
 *
 * - 稠密矩阵和数组操作
 *      - STL 迭代器和算法
 *
 * @param 映射类型和声明映射变量
 * 核心是解决「如何让 Eigen 直接复用外部预定义数组的内存，而非拷贝数据」的问题 ——Map 是 Eigen 提供的 “内存视图工具”，能把 C 风格数组 / 连续内存块 “映射” 成 Eigen 的向量 / 矩阵类型，全程无数据拷贝，既节省内存又提升性能。
 */
#include <Eigen/Dense>
#include <iostream>

using namespace std;

int main() {
    Eigen::Map<Eigen::Matrix<typename Scalar, int RowAtCompileTime, int ColAtCompileTime>>


    return 0;
}
