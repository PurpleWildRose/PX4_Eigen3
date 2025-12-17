/**
 * 自 3.4 版本起，Eigen 提供了便捷的方法，可以将矩阵重塑为不同大小的矩阵或向量。所有情况均通过 ` DenseBase::reshaped(NRowsType,NColsType) ` 和 DenseBase::reshaped() 函数处理。
 * 这些函数不会执行原地重塑，而是返回输入表达式的视图 。
 *
 * - 稠密矩阵和数组操作
 *      - 重塑
 *
 * @param 原地重塑(ReshapeInPlace)
 * 以上示例创建了重塑后的视图，但如何就地重塑给定的矩阵呢？当然，这项任务仅适用于具有运行时维度的矩阵和数组。
 * 在许多情况下，这可以通过 `PlainObjectBase::resize(Index,Index)` 来实现
 */
#include <Eigen/Dense>
#include <iostream>

using namespace std;
int main() {
    std::cout << "Eigen 版本：" << EIGEN_WORLD_VERSION << "."
              << EIGEN_MAJOR_VERSION << "." << EIGEN_MINOR_VERSION << std::endl;
    Eigen::MatrixXi m = Eigen::Matrix4i::Random();
    cout << "Here is the matrix m:" << endl << m << endl;
    // Here is the matrix m:
    //     1804289383 -1550966999  1365180540   336465782
    //     -465790871 -1122281286   304089172 -1868760786
    //     -189735855 -1364114958    35005211    -2309581
    //     719885386  2044897763 -1852781081  1101513929
    // cout << "Here is m.reshaped(2, 8):" << endl << m.reshaped(2, 8) << endl;
    // Here is m.reshaped(2, 8):
    //     1804289383  -189735855 -1550966999 -1364114958  1365180540    35005211   336465782    -2309581
    //     -465790871   719885386 -1122281286  2044897763   304089172 -1852781081 -1868760786  1101513929
    m.resize(2, 8);
    cout << "Here is the matrix m after m.resize(2,8):" << endl << m << endl;
    // Here is the matrix m after m.resize(2,8):
    //     1804289383  -189735855 -1550966999 -1364114958  1365180540    35005211   336465782    -2309581
    //     -465790871   719885386 -1122281286  2044897763   304089172 -1852781081 -1868760786  1101513929


    // 但是请注意，与 reshaped 不同， resize 的结果取决于输入存储顺序。因此，它的行为类似于 reshaped<AutoOrder> ：
    // Eigen 的内存存储顺序
    //     ColMajor（列优先，默认）：矩阵数据按列存储（如 2×2 矩阵 [[1,2],[3,4]] 的内存顺序是 1,3,2,4）；
    //     RowMajor（行优先）：矩阵数据按行存储（同上矩阵的内存顺序是 1,2,3,4）；
    //     AutoOrder：自动继承原矩阵的存储顺序（原矩阵是 ColMajor 就用 ColMajor，是 RowMajor 就用 RowMajor）。

    // 最后，目前不支持将重塑后的矩阵赋值给自身，这样做会因别名效应而导致未定义行为。以下操作是被禁止的：

    // A = A.reshaped(2,8);
    // This is OK:   这样可以：

    // A = A.reshaped(2,8).eval();
    return 0;
}
