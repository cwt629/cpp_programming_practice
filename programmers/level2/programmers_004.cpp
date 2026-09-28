/**
[2단계] 서버 증설 횟수
(2025 프로그래머스 코드챌린지 2차 예선)
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int servers[24] = {0};
    
    for (int time = 0; time < 24; time++){
        int currentCapacity = (servers[time] + 1) * m;
        if (players[time] >= currentCapacity) {
            int additionalServer = floor((players[time] - currentCapacity) / m) + 1;
            answer += additionalServer;
            // 현재부터 k시간 후까지 서버 증설
            for (int current = time; current < time + k && current < 24; current++){
                servers[current] += additionalServer;
            }
        }
    }
    
    return answer;
}