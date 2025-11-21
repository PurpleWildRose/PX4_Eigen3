/**
 * Eigen提供矩阵/向量算术运算，可以通过重载常见的 C++ 算术运算符（例如 +、-、*）或特殊方法（例如dot()、cross()等）来实现。对于Matrix类（矩阵和向量），
 * 运算符仅重载以支持线性代数运算。例如，matrix1 * matrix2表示矩阵乘积，而vector + scalar不允许使用其他运算符。
 * 
 * - 稠密矩阵和数组操作
 *      - 矩阵和向量运算 
 * 
 * @param 操作的有效性
 * Eigen会检查您执行的操作的有效性。如果可能，它会在编译时进行检查，并生成编译错误。这些错误信息可能很长且难以理解，但Eigen会将重要信息全部大写，以便于识别。例如：
 */

 #include <Eigen/Dense>

 int main() {
    Eigen::Matrix3f m;
    Eigen::Vector4f v;
    // error
    // v = m * v      // Compile-time error: YOU_MIXED_MATRICES_OF_DIFFERENT_SIZES

    Eigen::MatrixXf m(3,3);
    Eigen::VectorXf v(4);
    // v = m * v;    // Run-time assertion failure here: "invalid matrix product"

    return 0;
 }