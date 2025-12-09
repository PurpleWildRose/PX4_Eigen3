/**
 * 讨论几种高级矩阵初始化方法，并详细介绍了之前介绍过的逗号初始化方法。此外，还解释了如何获取特殊矩阵，例如单位矩阵和零矩阵。
 *
 * - 稠密矩阵和数组操作
 *      - 高级初始化
 *
 * @param 特殊矩阵和数组
 * Matrix和Array类都有静态方法，例如` Zero()`，可用于将所有系数初始化为零。该方法有三种变体。第一种变体不接受任何参数，只能用于固定大小的对象。
 * 如果要将动态大小的对象初始化为零，则需要指定其大小。
 * 因此，第二种变体需要一个参数，可用于一维动态大小的对象；
 * 而第三种变体需要两个参数，可用于二维对象。
 */
#include <iostream>
#include <Eigen/Eigen>

using namespace std;
using namespace Eigen;

int main() {
    cout << "A fixed-size array: \n";
    Array33f a1 = Array33f::Zero();
    cout << "fixed: 2*2 zero: " << endl << a1 << endl;

    cout << "A one-dimensional dynamic-size array: \n";
    ArrayXf a2 = ArrayXf::Zero(3);
    cout << "Dynamic array 3 zero: " << endl << a2 << endl;

    cout << "A two-dimensional dynamic-size array: \n";
    VectorXd a3 = VectorXd::Zero(3);
    cout << "Dynamic vector 3 zero: " << endl << a2 << endl;

    cout << "a two-dimensional dynamic-size array: ";
    ArrayXXd a4 = ArrayXXd::Zero(3, 3);
    cout <<"Dynamic array 2*2 zero: " << endl << a4 << endl;

    // 类似地，静态方法`Constant (value)` 将所有系数设置为value0。如果需要指定对象的大小，则附加参数应放在 `value`value参数之前，例如 `[value] `。
    // `Random ()`MatrixXd::Constant(rows, cols, value)方法使用随机系数填充矩阵或数组。
    // 可以通过调用`Identity() `获取单位矩阵；此方法仅适用于`Matrix` 对象，不适用于`Array` 对象，因为“单位矩阵”是线性代数概念。`LinSpaced(size, low, high)` 方法仅适用于向量和一维数组；它生成一个指定大小的向量，其系数在 `size` 和 `high` 之间等距分布。
    ArrayXXf table(10, 4);
    table.col(0) = ArrayXf::LinSpaced(10, 0, 90);
    table.col(1) = M_PI / 180 * table.col(0);           // EIGEN_PI
    table.col(2) = table.col(1).sin();
    table.col(3) = table.col(1).cos();
    cout << "  Degrees    Randians        sine        Cosine\n";
    cout << table << endl;

    // 像 LinSpaced() 返回的对象这样的对象可以赋值给变量（和表达式）。Eigen定义了诸如 setZero()、MatrixBase::setIdentity() 和 DenseBase::setLinSpaced() 之类的实用函数来方便地执行此操作。
    // 以下示例对比了构造矩阵 \( J = \bigl[ \begin{smallmatrix} O & I \\ I & O \end{smallmatrix} \bigr] \) 的三种方法：
    //      使用静态方法和赋值、使用静态方法和逗号初始化器，或使用 setXxx() 方法。J= J=[O \ I     I \ O]
    //      使用静态方法和赋值，使用静态方法和逗号初始化器，或者使用 setXxx() 方法。
    const int size = 6;
    MatrixXd mat1(size, size);
    mat1.topLeftCorner(size / 2, size / 2) = MatrixXd::Zero(size / 2, size / 2);
    mat1.topRightCorner(size / 2, size / 2) = MatrixXd::Identity(size / 2, size / 2);
    mat1.bottomLeftCorner(size / 2, size / 2) = MatrixXd::Identity(size / 2, size / 2);
    mat1.bottomRightCorner(size / 2, size / 2) = MatrixXd::Zero(size / 2, size / 2);
    cout << "mat1: " << endl << mat1 << endl;

    MatrixXd mat2(size, size);
    mat2.topLeftCorner(size / 2, size / 2).setZero();
    mat2.topRightCorner(size / 2, size / 2).setIdentity();
    mat2.bottomLeftCorner(size / 2, size / 2).setIdentity();
    mat2.bottomRightCorner(size / 2, size / 2).setZero();
    cout << "mat2: " << endl << mat2 << endl;

    // 使用近似逗号初始化
    MatrixXd mat3(size, size);
    mat3 << MatrixXd::Zero(size / 2, size / 2), MatrixXd::Identity(size / 2, size / 2),
                MatrixXd::Identity(size / 2, size / 2), MatrixXd::Zero(size / 2, size / 2);
    cout << "mat3: " << endl << mat3 << endl;

    return 0;
}
