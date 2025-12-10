/**
 * 解释了Eigen的简化、访问者和广播，以及它们如何与矩阵和数组一起使用。
 *
 * - 稠密矩阵和数组操作
 *      - 减少、访客和广播
 *
 * @param 部分规约(partial reductions)
 * 部分归约是指可以按列或行对矩阵或数组进行归约操作，对每一列或每一行应用归约操作，并返回包含相应值的列向量或行向量。部分归约可以通过 `colwise()` 或 `rowwise()` 函数实现。
 * 一个简单的例子是，求给定矩阵中每一列元素的最大值，并将结果存储在一个行向量中:
 */
#include <Eigen/Dense>
#include <iostream>

using namespace std;
int main() {
    Eigen::MatrixXf mat(2, 4);
    mat << 1, 2, 3, 4,
            5, 6, 7, 8;
    cout << "mat.colwise().maxCoeff(): " << mat.colwise().maxCoeff() << endl;
    cout << "mat.colwise().minCoeff(): " << mat.colwise().minCoeff() << endl;
    cout << "mat.rowwise().maxCoeff(): " << mat.rowwise().maxCoeff() << endl;
    cout << "mat.rowwise().minCoeff(): " << mat.rowwise().minCoeff() << endl;

    cout << "mat.col(?).maxCoeff() :" << mat.col(0).maxCoeff() << endl;
    return 0;
}
