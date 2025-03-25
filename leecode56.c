int max(int x,int y){
    return x>y?x:y;
}
void Swape(int** intervals,int i,int j){
    int temx,temy;
    temx=intervals[i][0];
    intervals[i][0]=intervals[j][0];
    intervals[j][0]=temx;
    temy=intervals[i][1];
    intervals[i][1]=intervals[j][1];
    intervals[j][1]=temy;
}
void Sort(int** intervals, int intervalsSize){
    //排序
    for(int i=0;i<intervalsSize-1;i++){
        for(int j=i+1;j<intervalsSize;j++){
            if(intervals[j][0]<intervals[i][0]){
                Swape(intervals,i,j);
            }
        }
    }
}
/*
int PartSort(int** intervals, int low, int high) {
    int* pivot = intervals[low]; // 保存基准值指针（不要只存索引！）
    int left = low, right = high;
    while (left < right) {
        // 从右向左找第一个小于基准的元素
        while (left < right && intervals[right][0] >= pivot[0]) {
            right--;
        }
        // 从左向右找第一个大于基准的元素
        while (left < right && intervals[left][0] <= pivot[0]) {
            left++;
        }
        // 交换这两个元素
        if (left < right) {
            Swape(intervals, left, right);
        }
    }
    // 将基准值放到正确位置
    Swape(intervals, low, left);
    return left;
}*/
int PartSort(int** intervals, int left, int right) {
    int key=left; // 保存基准值指针（不要只存索引！）
    while (left < right) {
        // 从右向左找第一个小于基准的元素
        while (left < right && intervals[right][0] >= intervals[key][0]) {
            right--;
        }
        // 从左向右找第一个大于基准的元素
        while (left < right && intervals[left][0] <= intervals[key][0]) {
            left++;
        }
        // 交换这两个元素
            Swape(intervals, left, right);
    }
    // 将基准值放到正确位置
    Swape(intervals, key, left);
    return left;
}
void QuickSort(int** intervals,int low,int high){
    if(low>=high)
    return;
    int key=PartSort(intervals,low,high);
    QuickSort(intervals,low,key-1);
    QuickSort(intervals,key+1,high);
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    //Sort(intervals,intervalsSize);//排序
    QuickSort(intervals,0,intervalsSize-1);
    // 1. 分配行指针数组（int**）
    int** result = (int**)malloc(intervalsSize * sizeof(int*)); 
    // 2. 为每一行分配区间内存（int[2]）
    for (int i = 0; i < intervalsSize; i++) {
        result[i] = (int*)malloc(2 * sizeof(int)); // 每个区间2个int
    }
    result[0][0]= intervals[0][0];
    result[0][1]= intervals[0][1];
    *returnSize=1;
    for(int i=1;i<intervalsSize;i++){
        if(intervals[i][0]<=result[*returnSize-1][1]){
            result[*returnSize-1][1]=max(result[*returnSize-1][1],intervals[i][1]);
        }
        else{
            result[*returnSize][0]=intervals[i][0];
            result[*returnSize][1]=intervals[i][1];
            (*returnSize)++;
        }
    }
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2; // 每行2列
    }
    return result;

}