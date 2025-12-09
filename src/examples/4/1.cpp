/**
 *  块是矩阵或数组中的一个矩形区域。块表达式既可以用作右值，也可以用作左值。与Eigen表达式一样，只要允许编译器进行优化，这种抽象就不会增加任何运行时开销。
 *
 * - 稠密矩阵和数组操作
 *      - 块操作
 *
 * @param 使用块操作
 * Eigen中最通用的代码块操作是 ` .block()`。它有两个版本，语法如下：
 *      大小为(p,q) 的块, 起始于(i,j)
 *          1. 构建动态大小块表达式的版本: Eigen::Matrix::Block(i, j, p, q)
 *          2. 构建固定大小块表达式的版本: Eigen::Matrix::Block<p, q>(i, j)
 *
 * 这两个版本都可用于固定大小和动态大小的矩阵和数组。这两个表达式在语义上是等价的。唯一的区别在于，如果块大小较小，固定大小版本通常会提供更快的代码，但需要编译时知道块大小。
 */
#include <iostream>
#include <Eigen/Dense>

using namespace std;

int main() {
    Eigen::MatrixXf m(4, 4);
    m << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16;
    cout << "Block in the middle" << endl;
    cout << m.block<2, 2>(1, 1) << endl << endl;

    for (int i = 1; i <= 3; ++i) {
        cout << "Block of size: " << i << ", x: " << i << endl;
        cout << m.block(0, 0, i, i) << endl << endl;
    }
    int j1 = 2;
    int j2 = 3;
    cout << "Non-square block of size " << j1 << "x" << j2 << endl;
    cout << m.block(0, 0, j1, j2) << endl << endl;
    // 在上面的例子中，`.block()`函数被用作右值，也就是说，它只是被读取了。然而，代码块也可以用作左值，这意味着你可以给代码块赋值。

    // 以下示例对此进行了说明。该示例还演示了数组中的块，其工作方式与上面演示的矩阵中的块完全相同。
    Eigen::Array22f n;
    n << 1, 2, 3, 4;
    Eigen::Array44f a = Eigen::Array44f::Constant(0.6);
    std::cout << "Here is the array a:\n" << a << "\n\n";
    a.block<2, 2>(1, 1) = n;
    std::cout << "Here is now a with m copied into its central 2*2 block:\n" << a << "\n\n";
    a.block(0, 0, 2, 3) = a.block(2, 1, 2, 3);
    std::cout << "Here is now a with bottom-right 2x3 block copied into top-left 2x3 block:\n" << a << "\n\n";

    // 虽然`.block()`方法可以用于任何块操作，但还有其他方法可以处理特殊情况，提供更专业的 API 和/或更好的性能。说到性能，关键在于编译时尽可能多地向Eigen提供信息。
    // 例如，如果你的块是矩阵中的一整列，使用下面介绍的专用`.col()`函数可以让Eigen知道这一点，从而为其提供优化机会。
    return 0;
}
