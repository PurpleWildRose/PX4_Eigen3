/**
 *  什么是 Array 类？
 *  与专用于线性代数的矩阵类不同，数组类（Array类）提供通用数组。此外，数组类还提供了一种简便的方法来执行系数级运算，这些运算可能不具有线性代数意义，例如将一个常数加到数组中的每个系数上，或者将两个数组的系数相乘。
 * 
 * - 稠密矩阵和数组操作
 *      - 数组类和系数运算 
 * 
 * @param 数组表达式和矩阵表达式之间的转换
 * 何时应该使用矩阵类的对象，何时应该使用数组类的对象？
 *      矩阵运算不能直接应用于数组，数组运算也不能直接应用于矩阵。
 *      因此，如果需要进行线性代数运算（例如矩阵乘法），则应该使用矩阵；如果需要进行系数运算，则应该使用数组。然而，有时情况并非如此简单，您可能需要同时使用矩阵运算和数组运算。在这种情况下，您需要将矩阵转换为数组，反之亦然。这样，无论对象声明为数组还是矩阵，都可以访问所有运算。
 * 
 * 矩阵表达式有一个`.array()`方法，可以将其“转换”为数组表达式，从而方便地进行系数运算。反之，数组表达式也有一个`.matrix()`方法。与所有Eigen表达式抽象一样，这不会产生任何运行时开销（前提是您允许编译器进行优化）。`.array ()`和`.matrix()`都可以用作右值和左值。
 * 在Eigen中，表达式中混合使用矩阵和数组是不允许的。例如，你不能直接将矩阵和数组相加；运算符的操作数要么都是矩阵，要么都是数组。不过，使用`.array()`和`.matrix()`+可以轻松地在两者之间进行转换。这条规则的例外是赋值运算符：允许将矩阵表达式赋值给数组变量，也允许将数组表达式赋值给矩阵变量。
 * 
 */
#include <iostream>
#include <Eigen/Dense>

using namespace std;

int main() {
    Eigen::MatrixXd m(2, 2);
    Eigen::MatrixXd n(2, 2);
    Eigen::MatrixXd result(2, 2);

    m << 1, 2, 3, 4;
    n << 5, 6, 7, 8;

    result = m * n;

    cout << "result (m * n) : \n" << result << endl;

    result = m.array() * n.array();
    cout << "result (m.array * n.array) : \n" << result << endl;

    result = m.array() + 4;
    cout << "result (m.array + 4) : \n" << result << endl;

    // cwiseProduct() 是 Eigen 库中用于矩阵 / 向量逐元素相乘的方法（数学上称为 Hadamard 乘积），区别于矩阵乘法（operator*），
    // 它要求两个操作数维度完全相同，结果矩阵的每个元素是原矩阵对应位置元素的乘积。
    result = m.cwiseProduct(n);
    cout << "result (m.cwiseProduct(n)) : \n" << result << endl;


    result = (m.array() + 4).matrix() * m;
    cout << "Combination 1 --\n" << result << endl << endl;

    result = (m.array() * n.array()).matrix() * m;
    cout << "Combination 2 --\n" << result << endl << endl;

    return 0;
}