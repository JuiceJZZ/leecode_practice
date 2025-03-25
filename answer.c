int maxSubArray(int* nums, int numsSize) {
    //以current_max存储当前最大的连续和结果,增加了记录子数组起始点和终点下标的功能
    //nums = [-2,1,-3,4,-1,2,1,-5,4]
    int current_max=nums[0];
    int max=current_max;
    int start,end,tem_start;
    start=end=tem_start=0;
    for(int i=1;i<numsSize;i++){
        if(current_max>=0){
            current_max+=nums[i];
        }
        else{
            current_max=nums[i];
            tem_start=i;
        }
        if(current_max>max){
            max=current_max;
            start=tem_start;
            end=i;
        }
    }
    return  max;
}