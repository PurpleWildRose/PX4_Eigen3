/**
 *  operator()本页面介绍了 Eigen 3.4 版本中引入的用于索引行和列子集的多种方法。它不仅支持块 API的所有功能，还包含更多功能。特别是，它支持切片操作，即从矩阵中选取一组均匀分布的行、列或元素，或者从索引数组中选取索引。
 * 
 * - 稠密矩阵和数组操作
 *      - 基本切片
 * 
 * @param 索引数组
 * 通用函数operator()还可以接受任意行或列索引列表作为输入，这些索引可以存储为 `<div>` ArrayXi、`<div>` std::vector<int>、std::array<int,N>`<div>` 等。
 */
#include <iostream>
#include <Eigen/Eigen>
#include <vector>

using namespace std;

int main() {
    std::vector<int> ind{4, 2, 5, 5, 3};
    Eigen::MatrixXi A = Eigen::MatrixXi::Random(4, 6);

    cout << "Initial matrix A:\n" << A << "\n\n";
    cout << "A(all, ind):\n" << A(Eigen::Sequential(0, ) << "\n\n";

    return 0;
}