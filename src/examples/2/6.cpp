/**
 * Eigen提供矩阵/向量算术运算，可以通过重载常见的 C++ 算术运算符（例如 +、-、*）或特殊方法（例如dot()、cross()等）来实现。对于Matrix类（矩阵和向量），
 * 运算符仅重载以支持线性代数运算。例如，matrix1 * matrix2表示矩阵乘积，而vector + scalar不允许使用其他运算符。
 * 
 * - 稠密矩阵和数组操作
 *      - 矩阵和向量运算 
 * 
 * @param 点积和叉积
 * 对于点积和叉积，需要使用dot()和cross()方法。当然，点积也可以用 u.adjoint()*v 表示为一个 1x1 矩阵。
 *      Eigen中的叉积不仅适用于长度为 3 的向量，也适用于长度为 2 的向量，详情请参阅文档。点积适用于任意长度的向量。当使用复数时，Eigen的点积对于第一个变量是共轭线性的，对于第二个变量是线性的。
 */
#include <iostream>
#include <Eigen/Dense>

using namespace std;

int main() {
    Eigen::Vector3d v(1, 2, 3);
    Eigen::Vector3d w(0, 1, 2);

    cout << "Dot: \n" << v.dot(w) << endl;
    double dp = v.adjoint() * w;
    double dp_t = v.transpose() * w;
    cout << "dp: " << dp << ", dp_t: " << dp_t << endl;

    // 设三维向量 a=(ax​,ay​,az​)（列向量形式为
    // ​ax​ay​az​​
    // ​）和 b=(bx​,by​,bz​)，则其叉积记为 a×b（读作 “a 叉 b”），定义如下：
    // 1. 数学表达式（行列式形式）
    // a×b=
    // ​iax​bx​​jay​by​​kaz​bz​​
    // ​
    // 其中 i,j,k 是三维空间中 x、y、z 轴的单位正交基向量（满足 i×j=k，j×k=i，k×i=j）。
    // 2. 展开计算式
    // 按行列式展开后，叉积结果为：
    // a×b=(ay​bz​−az​by​, az​bx​−ax​bz​, ax​by​−ay​bx​)

    // 结果向量的三个分量分别对应：y-z 平面、z-x 平面、x-y 平面的 “投影叉积”
    cout << "Cross: \n" << v.cross(w) << endl;

    Eigen::Vector2d m(1, 2);
    Eigen::Vector2d n(0, 1);
    cout << "Dot: " << m.dot(n) << endl;
    
    // 叉积是三维向量的运算，Eigen 对二维向量的 cross() 做了特殊处理（返回标量而非向量），以下是详细解析：
    // cout << "Cross" << m.cross(n) << endl;
    return 0;
}