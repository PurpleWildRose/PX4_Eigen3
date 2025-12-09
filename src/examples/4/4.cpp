/*
 *  块是矩阵或数组中的一个矩形区域。块表达式既可以用作右值，也可以用作左值。与Eigen表达式一样，只要允许编译器进行优化，这种抽象就不会增加任何运行时开销。
 *
 * - 稠密矩阵和数组操作
 *      - 块操作
 *
 * @param 向量的块操作
 * Eigen还提供了一组专门针对向量和一维数组这种特殊情况设计的块操作：
 *                              构建动态大小块表达式的版本                                      构建固定大小块表达式的版本
 * 包含第一个n元素的块*:        vector.head(n)                                              vector<n>()
 * 包含最后n元素的块*:          vector.tail(n)                                              vector.tail<n>()
 * 包含元素的块n，从位置i *开始。 vector.segment(i, n)                                       vector.segment<n>(i)
 */
#include <iostream>
#include <Eigen/Dense>

using namespace std;

int main() {
    Eigen::ArrayXf m(6);
    m << 1, 2, 3, 4, 5, 6;
    cout << "head: \n" << m.head(2) << endl;
    cout << "tail: \n" << m.tail<2>() << endl;
    m.segment(2, 2) *= 2;
    cout << "segment: \n" << m.segment<5>(1) << endl;

    return 0;
}
