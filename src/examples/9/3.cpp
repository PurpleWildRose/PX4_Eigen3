/**
 * 自 3.4 版本起，Eigen 的稠密矩阵和数组提供了与 STL 兼容的迭代器。
 * 如下所示，这使得它们自然而然地与范围循环和 STL 的算法兼容。
 *
 * - 稠密矩阵和数组操作
 *      - STL 迭代器和算法
 *
 * @param 遍历二维数组和矩阵的行或列
 * 也可以获取二维表达式的行或列的迭代器。这些迭代器可以通过 rowwise() 和 colwise() 代理函数实现。以下示例演示了如何对矩阵的每一行进行排序：
 */
#include <Eigen/Dense>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    Eigen::Matrix4i m = Eigen::Matrix4i::Random();
    cout << "Here is the initial matrix A:\n" << m << "\n";
    // Here is the initial matrix A:
    //     1804289383 1550966999 1365180540  336465782
    //     465790871 1122281286  304089172 1868760786
    //     189735855 1364114958   35005211    2309581
    //     719885386 2044897763 1852781081 1101513929

    for (auto it : m.colwise()){
        std::sort(it.start(), it.end());

    }
    cout << "Here is the sorted matrix A:\n" << m << "\n";
    // Here is the sorted matrix A:
    //     336465782 1365180540 1550966999 1804289383
    //     304089172  465790871 1122281286 1868760786
    //     2309581   35005211  189735855 1364114958
    //     719885386 1101513929 1852781081 2044897763

    return 0;
}
