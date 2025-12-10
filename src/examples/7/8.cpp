/**
 * 解释了Eigen的简化、访问者和广播，以及它们如何与矩阵和数组一起使用。
 *
 * - 稠密矩阵和数组操作
 *      - 减少、访客和广播
 *
 * @param 广播(Broadcasting)
 * 广播背后的概念与部分归约类似，区别在于广播构造的表达式是通过在一个方向上复制向量（列或行）来将其解释为矩阵。
 * 一个简单的例子是将某个列向量添加到矩阵的每一列。这可以通过以下方式实现：
 */
#include <Eigen/Dense>
#include <iostream>

using namespace std;
int main() {
    Eigen::MatrixXf mat(2, 4);
    Eigen::VectorXf v(2);
    mat << 1, 2, 6, 9,
            3, 1, 7, 2;
    v << 0, 1;

    mat.colwise() += v;
    cout << "广播结果: \n" << mat << endl;

    return 0;
}
