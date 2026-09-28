/**
[1단계] 유연근무제
(2025 프로그래머스 코드챌린지 1차 예선)
 */

 #include <string>
#include <vector>
#include <cmath>

using namespace std;

int getPassedTimeNumber(int currentTime, int passedTime);

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for (int i = 0; i < schedules.size(); i++){
        int eventLimit = getPassedTimeNumber(schedules[i], 10);
        bool isNotLate = true;
        int currentDay = startday - 1; // % 연산 편의를 위해 0~6으로 요일 표시
        
        for (int logIndex = 0; logIndex < timelogs[i].size() && isNotLate; logIndex++){
            // 주말 필터링
            if (currentDay < 5) {
                if (timelogs[i][logIndex] > eventLimit) {
                    isNotLate = false;
                }
            }
            
            currentDay = (currentDay + 1) % 7;
        }
        
        if (isNotLate) {
            answer++;
        }
    }
    
    return answer;
}

int getPassedTimeNumber(int currentTime, int passedTime){
    int hour = floor(currentTime / 100), minute = currentTime % 100;
    
    minute += passedTime;
    if (minute >= 60) {
        hour++;
        minute -= 60;
    }
    
    return hour * 100 + minute;
}