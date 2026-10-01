/**
 * [2단계] [PCCP 기출문제] 2번 / 퍼즐 게임 챌린지
 * (PCCP 기출문제)
 */

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {   
    // 최고 난이도를 구한다
    int maxDiff = diffs[0];
    for (int i = 1; i < diffs.size(); i++){
        if (maxDiff < diffs[i]) maxDiff = diffs[i];
    }
    
    // level에 대하여 이진 탐색
    int start = 1, end = maxDiff;
    while (start <= end) {
        int level = (start + end) / 2;
        long long spentTime = 0;
        
        for (int i = 0; i < diffs.size() && spentTime <= limit; i++){
            int currentDiff = diffs[i], currentTime = times[i], prevTime = (i > 0)? times[i - 1] : 0;
            if (currentDiff <= level){
                spentTime += (long long)currentTime;
            }
            else {
                spentTime += (long long)(currentTime + prevTime) * (long long)(currentDiff - level) + (long long)currentTime;
            }
        }
        
        // 성공 시, 좀 더 레벨을 낮춰보기
        if (spentTime <= limit){
            end = level - 1;
        }
        // 실패 시, 좀 더 레벨을 높여보기
        else {
            start = level + 1;
        }
    }
    
    return start;
}