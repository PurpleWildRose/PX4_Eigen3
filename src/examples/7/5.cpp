/**
 * 解释了Eigen的简化、访问者和广播，以及它们如何与矩阵和数组一起使用。
 *
 * - 稠密矩阵和数组操作
 *      - 减少、访客和广播
 *
 * @param 访客（visitors）
 * 当需要获取矩阵或数组中某个系数的位置时，访问器非常有用。
 * 最简单的例子是 maxCoeff(&x,&y) 和 minCoeff(&x,&y)，它们可以用来查找矩阵或数组中最大或最小系数的位置。
 *
 * 传递给访问者的参数是指向存储行和列位置的变量的指针。这些变量应为 Index 类型，如下所示：
 */
#include <Eigen/Dense>
#include <iostream>

using namespace std;
int main() {
    Eigen::MatrixXf m(2,2);
    m << 1, 2,
            3, 4;
    // 获取位置的最大值
    Eigen::Index maxRow, maxCol;
    float max = m.maxCoeff(&maxRow, &maxCol);

    Eigen::Index minRow, minCol;
    float min = m.minCoeff(&minRow, &minCol);

    std::cout << "最小值: " << min << ", px: " << minRow << ", py: " << minCol << endl;
    std::cout << "最大值: " << max << ", px: " << maxRow << ", py: " << maxCol << endl;

    return 0;
}
