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

class Vecotr3fd {
  public:
    float &operator[](int idx) {
      if (idx < 0 || idx >3)
        throw std::out_of_range("Vector3fd index out of range");

      return data[idx];
    }
    void print() {
      std::cout << "Vector3fd: " << data[0] << " " << data[1] << " " << data[2] << std::endl;
    }
  private:
    float data[3] = {1.0f, 2.0f, 3.0f};
};

class Matrix3fd {
  public:
    // 错误示范：给矩阵重载 operator[]（仅能接收一个参数）
    float &operator[](int idx) {
      if (idx < 0 || idx > 9)
        throw std::out_of_range("Matrix3fd index out of range");

      return data[idx];
    }

    // 正确方式：重载 operator() 接收两个参数（行、列）
    float &operator()(int row, int col){
      if (row < 0 || row > 3 || col < 0 || col > 3)
        throw std::out_of_range("Matrix3fd index out of range");

      return data[row * 3 + col];
    }

    void print() {
      printf("matrix3fd: %f %f %f,\n%f %f %f,\n%f %f %f,\n", data[0], data[1], data[2],
                                                              data[3], data[4], data[5],
                                                              data[6], data[7], data[8]);
    }
  private:
    float data[9] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f};
};

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

  // 请注意，此语法m(index)不仅限于向量，也适用于一般矩阵，即通过索引访问系数数组。但这取决于矩阵的存储顺序。所有特征矩阵默认采用列优先存储顺序，但可以更改为行优先
  // 该operator[]函数也支持基于索引的向量访问，但请注意，C++ 不允许operator[]接受多个参数。我们将其限制operator[]为向量，因为 C++ 语言的一个缺陷会导致编译结果与`!`matrix[i,j]相同。matrix[j]
  Vecotr3fd v3d;
  v3d[2] = 10.0f;
  v3d.print();

  // 验证错误法
  Matrix3fd m3d;
  m3d[2, 1] = 11.0;
  m3d.print();
  // 验证正确法
  m3d(2, 2) = 15.0;
  m3d.print();
}

