/*
[2단계] [PCCP 기출문제] 3번 / 충돌위험 찾기
(PCCP 기출문제)
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> getInitialMap(int totalRow, int totalCol);
void printMap(vector<vector<int>> map);

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    // points를 기반으로 row와 col의 최대 최소 값을 구한다
    int minRow = 100, minCol = 100, maxRow = 0, maxCol = 0;
    for (vector<int> coord : points){
        if (minRow > coord[0] - 1) minRow = coord[0] - 1;
        if (minCol > coord[1] - 1) minCol = coord[1] - 1;
        if (maxRow < coord[0] - 1) maxRow = coord[0] - 1;
        if (maxCol < coord[1] - 1) maxCol = coord[1] - 1;
    }
    
    // 각 time마다 로봇의 위치에 따라 카운트를 더한다
    vector<vector<vector<int>>> timeMap;
    
    for (vector<int> robotPoints: routes){
        int time = 0;
        
        for (int pointIndex = 0; pointIndex < robotPoints.size() - 1; pointIndex++){
            vector<int> start = points[robotPoints[pointIndex] - 1];
            vector<int> target = points[robotPoints[pointIndex + 1] - 1];
            int currentIndex[2] = {start[0] - minRow - 1, start[1] - minCol - 1};
            int targetIndex[2] = {target[0] - minRow - 1, target[1] - minCol - 1}; // 우리의 map 상에서의 인덱스로 저장
            // 현재 상태를 먼저 timeMap에 저장(맨 처음에만)
            if (pointIndex == 0){
                if (timeMap.size() < time + 1){
                    timeMap.push_back(getInitialMap(maxRow - minRow + 1, maxCol - minCol + 1));
                }
                timeMap[time++][currentIndex[0]][currentIndex[1]]++;
            }
            
            while (!(currentIndex[0] == targetIndex[0] && currentIndex[1] == targetIndex[1])){
                // 이동: 위아래 우선, 좌우는 그 후
                if (currentIndex[0] < targetIndex[0]){
                    currentIndex[0]++;
                }
                else if (currentIndex[0] > targetIndex[0]){
                    currentIndex[0]--;
                }
                else if (currentIndex[1] < targetIndex[1]){
                    currentIndex[1]++;
                }
                else {
                    currentIndex[1]--;
                }
                
                // 이동 후 해당 위치에 time 기록
                if (timeMap.size() < time + 1){
                    timeMap.push_back(getInitialMap(maxRow - minRow + 1, maxCol - minCol + 1));
                }
                timeMap[time++][currentIndex[0]][currentIndex[1]]++;
            }
        }
    }
    
    // 모든 time 맵을 순회하며, 카운트가 2 이상인 경우를 모두 센다
    for (vector<vector<int>> currentMap : timeMap){
        for (int row = 0; row < currentMap.size(); row++){
            for (int col = 0; col < currentMap[row].size(); col++){
                if (currentMap[row][col] > 1){
                    answer++;
                }
            }
        }
    }
    
    return answer;
}

vector<vector<int>> getInitialMap(int totalRow, int totalCol){
    vector<vector<int>> map;
    for (int i = 0; i < totalRow; i++){
        vector<int> currentRow;
        for (int j = 0; j < totalCol; j++){
            currentRow.push_back(0);
        }
        
        map.push_back(currentRow);
    }
    
    return map;
}

void printMap(vector<vector<int>> map){
    for (int row = 0; row < map.size(); row++){
        for (int col = 0; col < map[row].size(); col++){
            cout << map[row][col] << " ";
        }
        cout << endl;
    }
}