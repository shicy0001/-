/*
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-bad-version/
作者：shicy
日期：2019-11-30

你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。
假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。
你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。
 */

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    unsigned int low = 1, high  = n, mid = 0;
    bool t;
    
    if (n <= 1)
        return n;
    else if (n == 2)
       return (isBadVersion(1) == true? n-1:n);
    else
    {
        while (low + 1 < high)
        {
            mid = (low + high)/2;
            t = isBadVersion(mid);
            if (t == false)
                low = mid;
            else
                high = mid;
        }
        return (isBadVersion(low) == true? low:high);
    }
}