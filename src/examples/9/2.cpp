/**
 * 自 3.4 版本起，Eigen 的稠密矩阵和数组提供了与 STL 兼容的迭代器。
 * 如下所示，这使得它们自然而然地与范围循环和 STL 的算法兼容。
 *
 * - 稠密矩阵和数组操作
 *      - STL 迭代器和算法
 *
 * @param 遍历二维数组和矩阵的系数
 * STL 迭代器本质上是为遍历一维结构而设计的。这就是为什么 begin()/end() 方法对二维表达式禁用的原因。不过，通过 reshaped() 创建一个一维线性视图，仍然可以轻松遍历二维表达式的所有系数：
 */
#include <Eigen/Dense>
#include <iostream>

using namespace std;

int main() {

    Eigen::Matrix2d m = Eigen::Matrix2d::Random();

    for (auto it : m.reshaped()) {
        cout << m << " ";
    }
    return 0;
}
