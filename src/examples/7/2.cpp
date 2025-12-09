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
#include <math.h>
using namespace std;

int main() {
    Eigen::VectorXf v(2);
    Eigen::MatrixXf m(2, 2), n(2, 2);

    v << -1, 2;

    m << 1, -2, -3, 4;

    // 注意欧几里得平方范数 == 该向量对自身的点积
    cout << "v.squaredNorm(): \n" << v.squaredNorm() << endl;
    cout << "v.dot(v): \n" << v.dot(v) <<endl;

    cout << "v.norm(): \n" << v.norm() << std::endl;
    cout << "sqrt(v.squaredNorm()): \n" << sqrt(v.squaredNorm()) << std::endl;

    // 系数绝对值最大范数
    cout << "v.lpNorm<Identity>(): \n" << v.lpNorm<Eigen::Infinity>() << std::endl;
    cout << "v.lpNorm<1>(): \n" << v.lpNorm<1>() << std::endl;
    cout << endl << endl;
    cout << "m.squaredNorm(): \n" << m.squaredNorm() << std::endl;
    cout << "m.norm(): \n" << m.norm() << std::endl;
    cout << "m.lpNorm<1>(): \n" << m.lpNorm<1>() << std::endl;
    cout << "m.lpNorm<Eigen::Infinity>(): \n" << m.lpNorm<Eigen::Infinity>() << std::endl;

    // 算子范数：1-范数和 ∞ -范数矩阵算子范数可以很容易地按如下方式计算：
    //  1 - 范数：matrix.lpNorm<1>()
    //  1 - 范数（L1）	列和范数	所有列的 “元素绝对值之和” 的最大值
    //  ∞ - 范数：matrix.lpNorm<Eigen::Infinity>()
    //  ∞ - 范数（L∞）	行和范数	所有行的 “元素绝对值之和” 的最大值

    Eigen::MatrixXf A(2, 3);
    A << 1, -2, 3,
         -4, 5, -6;

    // Eigen 版本问题导致最后结果不一致。
    // Eigen 3.2 及以下：lpNorm<1>() 对矩阵会展平为向量计算（错误，和你遇到的一致）。
    // ========== 1. 手动计算（验证定义） ==========
    // 1-范数：列和的最大值
    float col1_sum = std::abs(1) + std::abs(-4) ;
    float col2_sum = std::abs(-2) + std::abs(5) ;
    float col3_sum = std::abs(3) + std::abs(-6);
    float l1_manual = std::max({col1_sum, col2_sum, col3_sum}); // 9

    // ∞-范数：行和的最大值
    float row1_sum = std::abs(1) + std::abs(-2) + std::abs(3);
    float row2_sum = std::abs(-4) + std::abs(5) + std::abs(-6) ;
    float linf_manual = std::max(row1_sum, row2_sum); // 15

    // ========== 2. Eigen 调用 API 计算 ==========
    float l1_eigen = A.lpNorm<1>();          // 1-范数
    float linf_eigen = A.lpNorm<Eigen::Infinity>(); // ∞-范数

    // ========== 3. 输出对比 ==========
    std::cout << "矩阵 A：\n" << A << "\n\n";
    std::cout << "手动计算 1-范数：" << l1_manual << " | Eigen 计算：" << l1_eigen << "\n";
    std::cout << "手动计算 ∞-范数：" << linf_manual << " | Eigen 计算：" << linf_eigen << "\n";
    return 0;
}
