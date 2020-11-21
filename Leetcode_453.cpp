/*
* 453. 最小移动次数使数组元素相等
* 给定一个长度为 n 的非空整数数组，找到让数组所有元素相等的最小move次数。每次 move 将会使 n - 1 个元素增加 1。
* 
* 每次n-1个元素加1，等同于1个元素减1。引用评论，少数民族(55个)加分等于汉族(1个)减分.
* 
*/
int minMoves(vector<int>& nums) {
        int min = INT_MAX;
        int res = 0;
		//找到最小值
        for(int i=0;i < nums.size();i++){
            if(nums[i] < min)
                min = nums[i];
        }
		//求出所有元素到最小值的和
        for(int j=0;j < nums.size();j++){
            res += nums[j] - min;
        }
        return res;
    }