/**
 * 解释了Eigen的简化、访问者和广播，以及它们如何与矩阵和数组一起使用。
 * 
 * - 稠密矩阵和数组操作
 *      - 减少、访客和广播 
 * 
 * @param 减少(Reductions)
 * 在Eigen中，归约函数是指接受矩阵或数组作为输入，并返回一个标量值的函数。最常用的归约函数之一是`.sum()`，它返回给定矩阵或数组中所有系数之和
 */
#include <Eigen/Dense>
#include <iostream>

using namespace std;
int main() {
    Eigen::Matrix2d mat;
    mat << 1, 2, 3, 4;

    cout << "Here is mat.sum: " << mat.sum() << endl;
    cout << "Here is mat.prod: " << mat.prod() << endl;
    cout << "Here is mat.mean: " << mat.mean() << endl;
    cout << "Here is mat.maxCoeff: " << mat.maxCoeff() << endl;
    cout << "Here is mat.minCoeff: " << mat.minCoeff() << endl;
    cout << "Here is mat.trace: " << mat.trace() << endl;
    // trace() equailty to diagonal().sum()
    cout << "Here is mat.diagonal.sum: " << mat.diagonal().sum() << endl;
    return 0;
}