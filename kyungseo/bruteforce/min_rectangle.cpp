#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_w = 0;
    int max_h = 0;
    
    for (auto size : sizes){
        int w = size[0];
        int h = size[1];
        if (w < h) swap(w,h);
        max_w = max(max_w,w);
        max_h = max(max_h,h);
    }
    answer = max_w * max_h;
    return answer;
}

int main(){
    vector<vector<int>> sizes = {{60, 50}, {30, 70}, {60, 30}, {80, 40}};
    int answer = solution(sizes);
    cout << answer << endl;
    return 0;
}