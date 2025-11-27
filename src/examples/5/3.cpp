/**
 *  operator()本页面介绍了 Eigen 3.4 版本中引入的用于索引行和列子集的多种方法。它不仅支持块 API的所有功能，还包含更多功能。特别是，它支持切片操作，即从矩阵中选取一组均匀分布的行、列或元素，或者从索引数组中选取索引。
 * 
 * - 稠密矩阵和数组操作
 *      - 基本切片
 * 
 * @param 编译时大小和增量
 * 在性能方面，Eigen 和编译器可以利用编译时大小和增量。为此，您可以使用`Eigen::fix<val>`强制执行编译时参数。此类编译时值可以与 `Eigen::last` 符号结合使用：
 *      v(seq(last - fix<7>, last - fix<2>))
 * 在这个例子中，Eigen 在编译时就知道返回的表达式有 6 个元素。这等价于：
 *      v(seq(last-7, fix<6>))
 * 我们可以按如下方式重新审视示例A 中的偶数列：
 *      A(all, seq(fix<0>, last, fix<2>))
 */
#include <iostream>
#include <Eigen/Dense>

using namespace std;

int main() {

    return 0;
}