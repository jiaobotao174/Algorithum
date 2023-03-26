/*（小数，基准元素，大数）。在区间中随机挑选一个元素作基准，将小于基准的元素放在基准之前，大于基准的元素放在基准之后，再分别对小数区与大数区进行排序。
快速排序思路：
1. 选取第一个数为基准
2. 将比基准小的数交换到前面，比基准大的数交换到后面
3. 对左右区间重复第二步，直到各区间只有一个数
*/
#include <vector>

using namespace std;

// 快速排序（递归）
void QuickSort(vector<int>& v, int low, int high){
    if (low >=high){
        return;
    }
    int first = low;      // 低位下标
    int last = high;      // 高位下标
    int key = v[first];   // 设第一个为基准

    while (first < last){
        // 将比第一个小的移到前面
        while (first < last && v[last] >= key)
            last--;
        if (first < last)
            v[first++] = v[last];

        // 将比第一个大的移到后面
        while (first < last && v[first] <= key)
            first++;
        if (first < last)
            v[last--] = v[first];
    }
    // 基准置位
    v[first] = key;
    // 前半递归
    QuickSort(v, low, first - 1);
    // 后半递归
    QuickSort(v, first + 1, high);

}
int main(){
    return 0;
}
