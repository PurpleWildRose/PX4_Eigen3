/**
 * 在Eigen中，所有矩阵和向量都是Matrix模板类的对象。向量只是矩阵的一种特殊情况，它只有 1 行或 1 列。
 *
 * - 稠密矩阵和数组操作
 *      - 矩阵类
 *
 * @param 调整大小
 * 可以使用`rows()`、`cols()`和`size()`方法获取矩阵的当前大小。这些方法分别返回行数、列数和系数个数。动态矩阵的大小调整可以通过`resize()`方法完成。
 *      · resize仅限动态矩阵
 */
#include <Eigen/Dense>
#include <iostream>

int main() {
    // Eigen::MatrixXd m 定义的是动态大小矩阵，但未初始化其行列数，直接使用 << 赋值会导致尺寸不匹配。
    Eigen::MatrixXd m(4, 3);
    m << 1, 2, 3,
        4, 5, 6,
        7, 8, 9,
        10, 11, 12;

    std::cout << "rows: " << m.rows() << std::endl;
    std::cout << "cols: " << m.cols() << std::endl;
    std::cout << "size: " << m.size() << std::endl;
    std::cout << m << std::endl;
// 如果矩阵的实际大小不变，则此resize()方法不会产生任何操作；否则，它会破坏现有矩阵：系数的值可能会发生变化。
// 如果您需要一种resize()不会改变系数的保守版本，请使用`conservativeResize()`函数，更多详情请参阅此页面。
    m.resize(2, 6);
    std::cout << "rows: " << m.rows() << std::endl;
    std::cout << "cols: " << m.cols() << std::endl;
    std::cout << "size: " << m.size() << std::endl;
    std::cout << m << std::endl;

    m.resize(3, 6);
    std::cout << "rows: " << m.rows() << std::endl;
    std::cout << "cols: " << m.cols() << std::endl;
    std::cout << "size: " << m.size() << std::endl;
    std::cout << m << std::endl;

    Eigen::Matrix2d n;
    n << 1, 2, 3, 4;

// 为了保持 API 的一致性，所有这些方法仍然适用于固定大小的矩阵。当然，你实际上无法调整固定大小矩阵的大小。
// 尝试将固定大小更改为实际不同的值会触发断言失败；但以下代码是合法的：
    n.resize(1, 4);
    std::cout << "rows: " << n.rows() << std::endl;
    std::cout << "cols: " << n.cols() << std::endl;
    std::cout << "size: " << n.size() << std::endl;
    std::cout << n << std::endl;

    return 0;
}

