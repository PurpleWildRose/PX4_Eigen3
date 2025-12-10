/**
 * 解释了Eigen的简化、访问者和广播，以及它们如何与矩阵和数组一起使用。
 *
 * - 稠密矩阵和数组操作
 *      - 减少、访客和广播
 *
 * @param 将广播与其他业务相结合(Combining broadcasting with other operations)
 * 广播还可以与其他操作结合使用，例如矩阵或数组操作、归约和部分归约。
 * 现在我们已经引入了广播、归约和部分归约，接下来可以深入探讨一个更高级的例子：在矩阵 m 的列中找到向量 v 的最近邻。本例将使用欧氏距离，并通过名为 squaredNorm() 的部分归约函数计算平方欧氏距离：
 */
#include <Eigen/Dense>
#include <iostream>

using namespace std;
int main( ){
    // asDiagonal()将向量转化为对角矩阵
    Eigen::MatrixXf m(2, 4);
    Eigen::VectorXf v(2);

    m << 1, 23, 6, 9, 3, 11, 7, 2;
    v << 2, 3;

    Eigen::Index index;
    // 查看最近邻居
    (m.colwise() - v).colwise().squaredNorm().minCoeff(&index);

    cout << "最近的邻居是列: " << index << endl;
    cout << m.col(index) << endl;

    return 0;
}
