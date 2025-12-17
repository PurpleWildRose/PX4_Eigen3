/**
 * 自 3.4 版本起，Eigen 提供了便捷的方法，可以将矩阵重塑为不同大小的矩阵或向量。所有情况均通过 ` DenseBase::reshaped(NRowsType,NColsType) ` 和 DenseBase::reshaped() 函数处理。
 * 这些函数不会执行原地重塑，而是返回输入表达式的视图 。
 *
 * - 稠密矩阵和数组操作
 *      - 重塑
 *
 * @param 一维线性视图(1D linear views)
 * 重塑操作的一个非常常见的用途是，根据给定的二维矩阵或表达式创建一维线性视图。在这种情况下，可以推导出尺寸，
 * 因此可以省略，如下例所示：
 */
#include <Eigen/Dense>
#include <iostream>

using namespace std;
int main() {
    // 此快捷方式始终返回列向量，默认情况下，输入系数始终按列优先顺序解释。有关对排序的更多控制，请参阅 DenseBase::reshaped() 的文档。
    Eigen::Matrix4i m = Eigen::Matrix4i::Random();
    cout << "Here is the matrix m: \n" << m << endl;
    // Here is the matrix m:
    //  1804289383 -1550966999  1365180540   336465782
    //  -465790871 -1122281286   304089172 -1868760786
    //  -189735855 -1364114958    35005211    -2309581
    //   719885386  2044897763 -1852781081  1101513929
    cout << "Here is m.reshaped().transpose(): \n" << m.reshaped().transpose() << endl;
    // Here is m.reshaped().transpose():
    //  1804289383  -465790871  -189735855   719885386 -1550966999 -1122281286 -1364114958  2044897763  1365180540   304089172    35005211 -1852781081   336465782 -1868760786    -2309581  1101513929

    cout << "Here is m.reshaped<RowMajor>().transpose(): \n" << m.reshaped<Eigen::RowMajor>().transpose() << endl;
    // Here is m.reshaped<RowMajor>().transpose():
    //  1804289383 -1550966999  1365180540   336465782  -465790871 -1122281286   304089172 -1868760786  -189735855 -1364114958    35005211    -2309581   719885386  2044897763 -1852781081  1101513929

    return 0;
}
