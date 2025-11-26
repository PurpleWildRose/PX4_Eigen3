/**
 *  块是矩阵或数组中的一个矩形区域。块表达式既可以用作右值，也可以用作左值。与Eigen表达式一样，只要允许编译器进行优化，这种抽象就不会增加任何运行时开销。
 * 
 * - 稠密矩阵和数组操作
 *      - 块操作 
 * 
 * @param 列和行
 * 单独的列和行是块的特殊情况。Eigen提供了轻松处理它们的方法：.col()和.row()。
 *      第i行: matrix.row(i)
 *      第j列: matrix.col(j)
 */
#include <iostream>
#include <Eigen/Dense>

using namespace std;

int main() {
    // 该示例还表明，块表达式（这里是列）可以像任何其他表达式一样用于算术运算。
    Eigen::MatrixXf m(3, 3);
    m << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    cout << "Here is the matrix m: " << endl << m << endl;
    cout << "2nd Row: " << m.row(1) << endl;
    m.col(2) += 3 * m.col(0);
    cout << "After adding 3 time the first column into the third column, the matrix is: \n" ;
    cout << m << endl;

    return 0;
}