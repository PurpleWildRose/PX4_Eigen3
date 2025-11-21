/**
 * 在Eigen中，所有矩阵和向量都是Matrix模板类的对象。向量只是矩阵的一种特殊情况，它只有 1 行或 1 列。
 * 
 * - 稠密矩阵和数组操作
 *      - 矩阵类
 * 
 * @param 分配和调整大小
 * 赋值操作是指将一个矩阵复制到另一个矩阵中operator=。Eigen会自动调整左侧矩阵的大小，使其与右侧矩阵的大小匹配
 */
#include <iostream>
#include <Eigen/Dense>

int main() {
    Eigen::MatrixXd m(2, 2);
    std::cout << "seze: " << m.size() << ", rows: " << m.rows() << ", cols: " << m.cols() << std::endl;

    Eigen::MatrixXd n(3, 3);
    m = n;
    std::cout << "seze: " << m.size() << ", rows: " << m.rows() << ", cols: " << m.cols() << std::endl;

    return 0;
}