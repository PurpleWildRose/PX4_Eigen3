/**
 *  operator()本页面介绍了 Eigen 3.4 版本中引入的用于索引行和列子集的多种方法。它不仅支持块 API的所有功能，还包含更多功能。特别是，它支持切片操作，即从矩阵中选取一组均匀分布的行、列或元素，或者从索引数组中选取索引。
 * 
 * - 稠密矩阵和数组操作
 *      - 基本切片
 * 
 * @param 逆序
 * 也可以使用负增量按降序枚举行/列索引。例如，枚举 A 表从第 20 列到第 10 列的索引：
 *      A(all, seq(20, 10, fix<-2>))
 * 从最后一行开始的最后n行：
 *      A(lastN(last, n, fix<-1>), all)
 * 您还可以使用 `ArithmeticSequence::reverse()` 方法来反转其顺序。因此，前面的示例也可以写成：
 *      A(lastN(n.reverse(), all))
 */
#include <iostream>
#include <Eigen/Dense>

 int main() {

    return 0
 }
