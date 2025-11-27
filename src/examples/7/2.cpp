/**
 * 解释了Eigen的简化、访问者和广播，以及它们如何与矩阵和数组一起使用。
 * 
 * - 稠密矩阵和数组操作
 *      - 减少、访客和广播 
 * 
 * @param 范数计算
 * 向量的(欧几里得范数)平方范数可以通过squaredNorm()获得。它等于向量与其自身的点积，等价于其系数绝对值的平方和。ℓ2向量的平方范数可以得到.
 * Eigen还提供了norm()方法，该方法返回squaredNorm()的平方根。
 * 这些运算也可以作用于矩阵；在这种情况下，一个 n×p 矩阵被视为一个大小为 (n*p) 的向量，因此例如norm()方法返回的是“Frobenius”范数或“Hilbert-Schmidt”范数。我们不讨论矩阵的 \(\ell^2\) 范数，因为它含义可能有所不同。ℓ2矩阵的范数，因为它可以有不同的含义。
 * 如果您需要其他系数的 \(\ell^p\) 范数，请使用lpNorm<p>()方法。如果您需要 \(\ell^\infty\) 范数（即系数绝对值的最大值），模板参数p可以取特殊值Infinity。ℓp规范，使用ℓ∞范数，即系数绝对值的最大值。
 */
#include <iostream>
#include <Eigen/Dense>
using namespace std;

int main() {
    Eigen::VectorXf v(2);
    Eigen::MatrixXf m(2, 2), n(2, 2);

    v << -1, 2;

    m << 1, -2, -3, 4;

    cout << "v.squaredNorm(): " << v.squaredNorm() << endl;
    cout << "v."

    return 0;
}