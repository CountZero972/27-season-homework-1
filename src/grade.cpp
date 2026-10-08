#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

void initScores(int* scores, int n){
    fill(scores, scores+n,-1);
}
void inputScores(int* scores, int n){
    for(int i=0; i<n; i++){
        int score;
        cin >> score;
        while(score<0 || score>100){  // 成绩不合法就要求重新输入
            cin >> score;
        }
        scores[i] = score;
    }
}
double calcAverage(int *scores, int n){
    if(n==0){
        return 0.0;
    }
    int sum = accumulate(scores, scores+n, 0);
    double avg = double(sum)/n;
    return avg;
}

void findMinMax(const int*scores, int n, int* max, int* min){
    if(n<=0){
        *max = -1;
        *min = -1;
        return;
    }
    *max = *max_element(scores, scores+n);
    *min = *min_element(scores, scores+n);
}

void countGrades(const int* scores, int n, int* counts){
    for_each(scores, scores+n,[&counts](int score){
        int index = min(score/10, 9)-5;  
   // 写min与9比较, 防止score=100时index=5
        if(index<0){
            index = 0;
        }
        counts[index]++;
    } );
}

int safeGet(const int* scores, int n, int index){
    if(  index < 0 || index>=n || scores[index] == -1){
        return -1;
    }
    return scores[index];
}

void printResults(const int* scores, int n, double avg, const int* counts, int max, int min){
    cout << "成绩: " << endl;
    for(int i=0; i<(n/10); i++){
        for(int j=0; j<10 && j+10*i<n; j++){
            cout << scores[j+10*i] << " ";    // 每行10个进行输出
        }
        cout << endl;
    }
    cout << "人数: " << n << endl;
    cout << "平均分: " << avg << endl;
    cout << "各分数段人数: " << endl;
    for(int k=0; k<5; k++){
        cout << counts[k] << " ";
    }
    cout << endl;
    cout << "最大值: " << max << endl;
    cout << "最小值: " << min << endl;
}
int main(){
    int scores[100];
    int n;
    int counts[5] = {0};
    int max=-1, min=-1;
    double avg = 0.0;
    int testIndex;
// 初始化数组
    initScores(scores, 100);
// 录入成绩
    cout << "请输入学生人数: ";
    cin >> n;
    inputScores(scores, n);
// 算平均值
    avg = calcAverage(scores, n);
// 算最值
    findMinMax(scores, n, &max, &min);
// 统计分数段
    countGrades(scores, n, counts);
// 安全查询测试
    cout << "请输入要查询的下标: ";
    cin >> testIndex;
    int queried = safeGet(scores, n, testIndex);
    if(queried == -1){
        cout << "查询失败" << endl;
    }
    else{
        cout << "下标" << testIndex << "的成绩是: " << queried << endl;
    }
// 打印所有结果
    printResults(scores, n, avg, counts, max, min);
    return 0;
}
