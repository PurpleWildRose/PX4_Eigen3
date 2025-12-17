/**
 * 自 3.4 版本起，Eigen 的稠密矩阵和数组提供了与 STL 兼容的迭代器。
 * 如下所示，这使得它们自然而然地与范围循环和 STL 的算法兼容。
 *
 * - 稠密矩阵和数组操作
 *      - STL 迭代器和算法
 *
 * @param 遍历一维数组和向量
 * 任何密集的一维表达式都会暴露出 begin()/end() 方法对，以便对其进行迭代。
 */
#include <Eigen/Dense>
#include <iostream>
#include <math.h>

using namespace std;
int main() {
    // 低版本不被支持
    Eigen::Vector4i v = Eigen::Vector4i::Random();
    cout << "Vector : " << v << endl;
    for (auto a : v) {
        cout << a << " ";
    }

    // 一维表达式也很容易传递给 STL 算法：
    Eigen::Array4i v = Eigen::Array4i::Random().abs();
    cout << "Here is the initial vector v:\n" << v.transpose() << "\n";
    // Here is the initial vector v:
    //     1804289383  465790871  189735855  719885386
    std::sort(v.begin(), v.end());
    cout << "Here is the sorted vector v:\n" << v.transpose() << "\n";
    // Here is the sorted vector v:
    //     189735855  465790871  719885386 1804289383


    // 与 std::vector 类似，1D 表达式也公开了 cbegin()/cend() 方法对，以便方便地获取非常量对象的 const 迭代器。
    return 0;
}
