/**
 * 在Eigen中，所有矩阵和向量都是Matrix模板类的对象。向量只是矩阵的一种特殊情况，它只有 1 行或 1 列。
 * 
 * - 稠密矩阵和数组操作
 *      - 矩阵类
 * 
 * @param 可选模板参数
 * Matrix类接受六个模板参数，但目前为止我们只讨论了前三个。其余三个参数是可选的。以下是完整的模板参数列表：
 * Matrix<typename Scalar, int RowAtCompileTime, int ColAtCompileTime, int Options, int MaxRowsAtCompileTime = RowsAtCompileTime, int MaxColsAtCompileTime = ColsAtCompileTime>
 * 
 * Options是一个位域.
 *      RowMajor。它指定此类型的矩阵使用行优先存储顺序；
 *      默认情况下，存储顺序为列优先。
 * 
 * Scalar可以是以下任何一种类型i：(含义为int)、f(含义为float)、d(含义为double)、cf(含义为complex<float>) 或cd(含义为complex<double>)。虽然typedefs 仅针对这五种类型定义，但这并不意味着它们是唯一受支持的标量类型。
 */
int main() {

    return 0;
}