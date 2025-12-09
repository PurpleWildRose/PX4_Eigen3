/**
 * 解释了Eigen的简化、访问者和广播，以及它们如何与矩阵和数组一起使用。
 *
 * - 稠密矩阵和数组操作
 *      - 减少、访客和广播
 *
 * @param 布尔规约函数
 * 以下归约操作适用于布尔值：
 *      all() 如果给定矩阵或数组中的所有系数都为 true，则返回 true。
 *      any() 如果给定矩阵或数组中至少有一个系数的值为 true，则返回 true。
 *      count() 返回给定矩阵或数组中值为真的系数的数量。
 */
#include <Eigen/Dense>
#include <iostream>

using namespace std;
int main() {
    Eigen::Matrix2d mat;
    mat << 1, 2, 3, -4;


    return 0;
}
