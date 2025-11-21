/**
 * 在Eigen中，所有矩阵和向量都是Matrix模板类的对象。向量只是矩阵的一种特殊情况，它只有 1 行或 1 列。
 * 
 * - 稠密矩阵和数组操作
 *      - 矩阵类
 * 
 * @param 系数访问器
 * Eigen中的主要系数访问器和修改器是重载的括号运算符。对于矩阵，行索引始终先传递。对于向量，只需传递一个索引。编号从 0 开始。以下示例不言自明：
 */
#include <iostream>
#include <Eigen/Dense>

int main() {
  Eigen::MatrixXd m(2, 2);
  m(0, 0) = 3;
  m(1, 0) = 2.5;
  m(0, 1) = -1;
  m(1, 1) = m(1, 0) + m(0, 1);
  std::cout << "Here is the matrix m:\n" << m << std::endl;
  Eigen::VectorXd v(2);
  v(0) = 4;
  v(1) = v(0) - 1;
  std::cout << "Here is the vector v:\n" << v << std::endl;
}

// 请注意，此语法m(index)不仅限于向量，也适用于一般矩阵，即通过索引访问系数数组。但这取决于矩阵的存储顺序。所有特征矩阵默认采用列优先存储顺序，但可以更改为行优先
// 该operator[]函数也支持基于索引的向量访问，但请注意，C++ 不允许operator[]接受多个参数。我们将其限制operator[]为向量，因为 C++ 语言的一个缺陷会导致编译结果与`!`matrix[i,j]相同。matrix[j]