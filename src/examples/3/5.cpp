 /**
 *  什么是 Array 类？
 *  与专用于线性代数的矩阵类不同，数组类（Array类）提供通用数组。此外，数组类还提供了一种简便的方法来执行系数级运算，这些运算可能不具有线性代数意义，例如将一个常数加到数组中的每个系数上，或者将两个数组的系数相乘。
 *
 * - 稠密矩阵和数组操作
 *      - 数组类和系数运算
 *
 * @param 其他系数运算
 * 除了上述的加法、减法和乘法运算符之外， Array类还定义了其他基于系数的运算。例如，`.abs()`方法计算每个系数的绝对值，而`.sqrt()`方法计算系数的平方根。如果有两个大小相同的数组，可以使用`.min(.)`方法构造一个新数组，该数组的系数取两个给定数组对应系数的最小值。
 */
#include <iostream>
#include <Eigen/Dense>

using namespace std;

int main() {
    Eigen::ArrayXf a = Eigen::ArrayXf::Random(5);
    a *= 2;

    cout << "a = \n" << a << endl << endl;
    cout << "a.abs: \n" << a.abs() << endl << endl;
    cout << "a.abs.sqrt(): \n" << a.abs().sqrt() << endl << endl;
    // a.min(...)：将原矩阵 a 与上述平方根结果逐元素比较，取较小值。
    cout << "a.min(a.abs().sqrt()): \n" << a.min(a.abs().sqrt()) << endl << endl;

    return 0;
}
