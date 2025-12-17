/**
 * 自 3.4 版本起，Eigen 提供了便捷的方法，可以将矩阵重塑为不同大小的矩阵或向量。所有情况均通过 ` DenseBase::reshaped(NRowsType,NColsType) ` 和 DenseBase::reshaped() 函数处理。
 * 这些函数不会执行原地重塑，而是返回输入表达式的视图 。
 *
 * - 稠密矩阵和数组操作
 *      - 重塑
 *
 * @param 重新设计的二维视图(Reshaped 2D views)
 * 更通用的重塑变换通过 ` reshaped(nrows,ncols) 函数实现。
 * 以下示例展示了如何将一个 4x4 矩阵重塑为一个 2x8 矩阵
 */
#include <Eigen/Dense>
#include <iostream>

using namespace std;
int main() {
    // reshape() 是 “视图重塑”（不改变内存、不拷贝数据），resize() 是 “容器扩容 / 缩容”（改变内存、可能拷贝 / 初始化数据）
    // 更通用的重塑变换通过 ` reshaped(nrows,ncols) 函数实现。
    // 以下示例展示了如何将一个 4x4 矩阵重塑为一个 2x8 矩阵：

    // reshaped是3.4版本有的，目前版本为3.2
    Eigen::Matrix2f m = Eigen::Matrix2f::Random();
    cout << "原矩阵: \n" << m << endl;
    cout << "reshaped矩阵: \n" << m.reshaped() << endl;

    return 0;
}
