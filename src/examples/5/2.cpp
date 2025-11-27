/**
 *  operator()本页面介绍了 Eigen 3.4 版本中引入的用于索引行和列子集的多种方法。它不仅支持块 API的所有功能，还包含更多功能。特别是，它支持切片操作，即从矩阵中选取一组均匀分布的行、列或元素，或者从索引数组中选取索引。
 * 
 * - 稠密矩阵和数组操作
 *      - 基本切片
 * 
 * @param 概述
 * 使用Eigen::seq或Eigen::seqN函数可以获取矩阵或向量中均匀分布的行、列或元素集合，其中“seq”代表等差数列。     ==      matrix.row(?)
 */
#include <iostream>
#include <Eigen/Dense>
using namespace std;

int main() {
    /********************************************************************************************************** */
    // 表示从 firstIdx 到 lastIdx 的整数序列
    // seq(firstIdx, lastIdx)      -->    seq(2, 5) <==> {2, 3, 4, 5}

    // 同样的方法，但使用增量incr从firstIdx到lastIdx。
    // seq(firstIdx, lastIdx, incr)     -->     seq(2, 8, 2) <==> {2, 4, 6, 8}

    // 表示从firstIdx开始的size整数序列
    // seqN(firstIdx, size)       -->       seqN(2, 5) <==> {2, 3, 4, 5, 6}
    
    // 同样的方法，但使用增量incr从一个索引推进到下一个索引。 	
    // seqN(firstIdx, size, incr)       -->         seqN(2, 3, 3) <==> {2, 5, 8}


    /********************************************************************************************************** */
    // 也可以借助 Eigen::last 符号来定义'firstIdx'  'lastIdx'参数，该符号表示通过 `operator()` 将算术序列传递给底层矩阵/向量后，其最后一行、最后一列或最后一元素的索引。

    // 从左下角开始，从i行,n列开始
    // A(seq(i, last), seqN(0, n))                      <==>        A.bottomLeftCorner(A.rows()-i, n)

    // i从第 j 个点开始的块，有m行n列
    // A(seqN(i, i+m), seqN(j, j+n))                    <==>        A.block(i, j, m, n)

    // i0从j0 开始到i1j1结束的区块
    // A(seq(i0, i1), seq(j0, j1))                      <==>        A.block(i0,j0, i1-i0+1, j1-j0+1)

    // A 的n偶数列
    // A(0, seq(0, Eigen::last, 2))

    // A 从first行到n的奇数行
    // A(seqN(1, n, 2), all)

    // 倒数第二列
    // A(all, last-1)                                   <==>        A.col(A.cols() - 2)

    // 中间一行
    // A(last/2. all)                                   <==>        A.row((A.rows()-1)/2)

    // v 的最后一个元素从 i 开始(vectorXd)
    // v(seq(i, last))                                  <==>        v.tail(v.size()-i)

    // v 的最后n元素
    // v(seq(last+1-n, last))                           <==>        v.tail(n)


    /********************************************************************************************************** */
    // 如上例所示，引用最后 n 个元素（或行/列）的写法比较繁琐。如果使用非默认的增量，则会变得更加棘手且容易出错。这时就需要用到`Eigen::placeholders::lastN(size)`和`Eigen::placeholders::lastN(size,incr) ` 了：

    // v 的最后n元素
    // v.lastN(n)                                       <==>        v.tail(n)

    // A 的右下角大小为mxn
    // A(lastN(m), lastN(n))                            <==>        v.bottomRightCorner(m, n)

    // 最后n几列占 1 列，共 3 列。
    // A(all, lastN(n, 3))

    return 0;
}