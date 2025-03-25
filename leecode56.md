#题目：
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
示例 1：
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 
提示：
1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
#二维数组是怎么分配内存空间的
#指针和内存分配问题：
 // 1. 分配行指针数组（int**）
    int** result = (int**)malloc(intervalsSize * sizeof(int*)); 
    // 2. 为每一行分配区间内存（int[2]）
    for (int i = 0; i < intervalsSize; i++) {
        result[i] = (int*)malloc(2 * sizeof(int)); // 每个区间2个int
    }
*returnColumnSizes = (int*)malloc(sizeof(int) *(*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2; // 每行2列
    }
#*returnColumnSizes=[2, 2, 2]
/*result 是真正的二维数组，需要 int** 类型来操作
int** returnColumnSizes 只是为了能修改外部的 int* 变量（即那个一维数组*returnColumnSizes）*/