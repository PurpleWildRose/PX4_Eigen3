1.cpp
    使用块操作   .block(?, ?, ?, ?)  / .block<?, ?>(?, ?)
2.cpp
    列和行
        m.col(?)    m.row(?)
3.cpp
    角相关操作
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
4.cpp
    向量的块操作
         * 包含第一个n元素的块*:        vector.head(n)                                              vector<n>()
        * 包含最后n元素的块*:          vector.tail(n)                                              vector.tail<n>()
        * 包含元素的块n，从位置i *开始。 vector.segment(i, n)                                       vector.segment<n>(i)