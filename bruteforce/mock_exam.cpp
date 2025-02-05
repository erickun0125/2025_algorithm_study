#include <iostream>
#include <vector>
#include <algorithm>  // max 사용

using namespace std;

vector<int> solution(vector<int> answers) {
    // 수포자들의 정답 패턴
    vector<int> pattern1 = {1, 2, 3, 4, 5};
    vector<int> pattern2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> pattern3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    // 맞춘 개수 저장
    vector<int> score(3, 0);  

    // 정답 배열과 비교하여 맞춘 개수 세기
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == pattern1[i % pattern1.size()]) score[0]++;
        if (answers[i] == pattern2[i % pattern2.size()]) score[1]++;
        if (answers[i] == pattern3[i % pattern3.size()]) score[2]++;
    }

    // 가장 높은 점수 찾기
    int maxScore = max({score[0], score[1], score[2]});

    // 최고 점수를 가진 사람 찾기
    vector<int> result;
    for (int i = 0; i < 3; i++) {
        if (score[i] == maxScore) {
            result.push_back(i + 1); // 1번부터 시작이므로 i+1
        }
    }

    return result;
}

int main() {
    vector<int> answers = {1, 2, 3, 4, 5};
    vector<int> result = solution(answers);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    cout << endl;

    return 0;
}