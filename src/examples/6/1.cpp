/**
 * 讨论几种高级矩阵初始化方法，并详细介绍了之前介绍过的逗号初始化方法。此外，还解释了如何获取特殊矩阵，例如单位矩阵和零矩阵。
 *
 * - 稠密矩阵和数组操作
 *      - 高级初始化
 *
 * @param 逗号初始化器
 * Eigen提供了一种逗号初始化语法，使用户能够轻松设置矩阵、向量或数组的所有系数。只需从左上​​角开始，从左到右、从上到下列出系数即可。对象的大小需要预先指定。如果列出的系数过少或过多，Eigen将会报错。
 */
#include <iostream>
#include <Eigen/Dense>
using namespace std;

int main() {
    Eigen::Matrix3f n;
    n << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    cout << n << endl;

    // 此外，初始化列表的元素本身可以是向量或矩阵。一个常见的用途是将向量或矩阵连接起来。例如，以下是如何连接两个行向量。请记住，在使用逗号初始化器之前，必须先设置列表的大小。
    Eigen::RowVectorXd vec1(3);
    vec1 << 1, 2, 3;
    cout << "vec1: " << endl <<  vec1 << endl;

    Eigen::RowVectorXd vec2(4);
    vec2 << 1, 4, 9, 16;
    cout << "vec2: " << endl << vec2 << endl;

    Eigen::RowVectorXd joined(7);
    joined << vec1, vec2;
    cout << "joined: " << endl << joined << endl;

    // 我们可以使用相同的技术来初始化具有块结构的矩阵。
    Eigen::Matrix3f m;
    m.row(0) << 1, 2, 3;
    m.block(1, 0, 2, 2) << 4, 5, 7, 8;
    m.col(2).tail(2) << 6, 9;
    cout << "matrix: " << endl << m << endl;

    return 0;
}
