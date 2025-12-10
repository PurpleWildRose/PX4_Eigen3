/**
 * 解释了Eigen的简化、访问者和广播，以及它们如何与矩阵和数组一起使用。
 *
 * - 稠密矩阵和数组操作
 *      - 减少、访客和广播
 *
 * @param 将部分规约与其他操作相结合(Combining partial reductions with other operations)
 * 也可以利用部分约简的结果进行进一步处理。以下示例展示了如何找到矩阵中元素之和最大的列。
 * 使用按列部分约简，可以将其编码为：
 */
#include <Eigen/Dense>
#include <iostream>

using namespace std;
int main() {
    Eigen::MatrixXf mat(2, 4);
    mat << 1, 2, 3, 4,
            5, 6 ,7, 8;
    Eigen::Index maxIndex;

    float maxNorm = mat.colwise().sum().maxCoeff(&maxIndex);
    cout << "值: " << maxNorm << ", 位置: " << maxIndex << endl;
    cout << "对应的向量: " << mat.col(maxIndex) << endl;

    return 0;
}
