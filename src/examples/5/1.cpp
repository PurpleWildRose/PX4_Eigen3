/**
 *  operator()本页面介绍了 Eigen 3.4 版本中引入的用于索引行和列子集的多种方法。它不仅支持块 API的所有功能，还包含更多功能。特别是，它支持切片操作，即从矩阵中选取一组均匀分布的行、列或元素，或者从索引数组中选取索引。
 *
 * - 稠密矩阵和数组操作
 *      - 切片和索引
 *
 * @param 概述
 * 上述所有操作均通过通用的DenseBase::operator()(const RowIndices&, const ColIndices&)方法处理。每个参数可以是：
 *      1. 索引单行或单列的整数，包括符号索引。
 *      2. 符号Eigen::placeholders::all表示按升序排列的所有相应行或列。
 *      3. 由Eigen::seq、Eigen::seqN或 Eigen::placeholders::lastN 函数构造的ArithmeticSequence。
 *      4. 任何一维整数向量/数组，包括 Eigen 的向量/数组、表达式、std::vector、std::array 以及普通的 C 数组：int[N]。
 */

 #include <iostream>
 #include <Eigen/Dense>

 using namespace std;

 int main() {
    // 更一般地说，它可以接受任何公开以下两个成员函数的对象：
    // <integral type> operator[](<integral type>) const;
    // <integral type> size() const;

    // 其中<integral type>代表与Eigen::Index兼容的任何整数类型（即std::ptrdiff_t）。
    return 0;
 }
