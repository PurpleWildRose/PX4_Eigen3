/*
 *  块是矩阵或数组中的一个矩形区域。块表达式既可以用作右值，也可以用作左值。与Eigen表达式一样，只要允许编译器进行优化，这种抽象就不会增加任何运行时开销。
 * 
 * - 稠密矩阵和数组操作
 *      - 块操作 
 * 
 * @param 角相关操作
 * Eigen还提供了针对紧贴矩阵或数组角或边的块的特殊方法。例如，可以使用`.topLeftCorner() ` 来引用矩阵左上角的块。
 *                              构建动态大小块表达式的版本                                      构建固定大小块表达式的版本
 *      左上角 p×q 块* :        matrix.topLeftCorner(p,q)                                   matrix.topLeftCorner<p, q>()   
 *      左下角 p×q 块* :        matrix.bottomLeftCorner(p, q)                               matrix.bottomLeftCorner<p, q>()
 *      右上角 p×q 块* :        matrix.topRightCorner(p, q)                                 matrix.topRightCorner<p, q>()
 *      右下角 p×q 块* :        matrix.bottomRoghtCorner(p, q)                              matrix.bottomRightCorner<p, q>()
 *      包含前 q 行的块*:        matrix.topRows(q)                                           matrix.topRows<q>()
 *      包含最后 q 行的块*:      matrix.bottomRows(q)                                        matrix.bottomRows<q>()
 *      包含前 p 列的块*:        matrix.rightCols(q)                                         matrix.rightCols<q>()
 *      包含最后 p 列的块*:      matrix.bottomCols(q)                                        matrix.bottomCols<q>()
 *      包含从 i *开始的 q 列的块 matrix.middleCols(i, q)                                     matrix.middleCols<q>(i)
 *      包含从 i *开始的 q 行的块 matrix.middleRows(i, q)                                     matrix.middleRows<q>(i)
 */
#include <Eigen/Dense>
#include <iostream>

using namespace std;

int main() {
    Eigen::MatrixXd m(4, 4);
    m << 1, 2, 3, 4, 5, 6, 7, 8 ,9 ,10, 11, 12, 13, 14, 15, 16;
    cout << "m" << m << endl << endl;

    cout << "m.topLeftCorner: " << endl << m.topLeftCorner(2, 2) << endl;
    cout << "m.bottomRightCorner: " << endl << m.bottomRightCorner(2, 2) << endl;
    cout << "m.leftCols: " << endl << m.leftCols<2>() << endl << endl;
    cout << "m.bottomRows: " << endl << m.bottomRows(2) << endl;

    cout << "m.middleCols: " << endl << m.middleRows<2>(2) << endl;
    cout << "m.middleRows: " << endl << m.middleCols(2, 2) << endl;
    return 0;
}