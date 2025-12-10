1.cpp
    介绍了一些基本的规约函数，就是前面讲的一些操作
    sum()/prod()/mean()/maxCoeff()/mincCoeff()/trace()
2.cpp
    范式：
    欧几里得平方范式： squaredNorm()
    平方根范式(): norm()
    1-范式： lpNorm<1>()    列和范数	所有列的 “元素绝对值之和” 的最大值
    ∞-范式: lpNorm<Eigen::Infinity>()   行和范数	所有行的 “元素绝对值之和” 的最大值
3.cpp
    介绍了布尔范式
    all() / any() / count()
4.cpp
    自定义范式
    通过EigenBase::redux调用，常用结构体或lambda去实现
5.cpp
    访客无非就是通过函数获取其位置等信息
6.cpp
    部分范式
    主要是逐行或者逐列去实现：
        ?.colwise().?
        ?.rowwise().?
7.cpp
    部分范式与其他操作结合使用，如
    ?.colwise().规约?.?
8.cpp
    广播无非就是将某一行或一列算数运算到其他行或列。
9.cpp
    广播与其他操作的组合使用
    计算列的平方欧氏距离
    (mat.colwise() - v).colwise().squaredNorm().minCoeff()
