/**
 * 在Eigen中，所有矩阵和向量都是Matrix模板类的对象。向量只是矩阵的一种特殊情况，它只有 1 行或 1 列。
 * 
 * - 稠密矩阵和数组操作
 *      - 矩阵类
 * 
 * @param 逗号初始化
 * 可以使用所谓的逗号初始化语法方便地设置矩阵和向量系数。
 */
#include <iostream>
#include <Eigen/Dense>

int main() {
    Eigen::Matrix3f m;
    m <<1, 2, 3, 
        4, 5, 6, 
        7, 8, 9;

    std::cout << "m = " << m << std::endl;

    return 0;
}