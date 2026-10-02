/*
[2단계] 지게차와 크레인
(2025 프로그래머스 코드챌린지 1차 예선)
*/

#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct Container {
    char type;
    bool isRemoved;
};

struct Coordinate {
    int row;
    int col;
};

void printContainers(vector<vector<Container>> containers);

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    // 컨테이너들을 빈 칸으로 두르고 있는 형태로 이차원 벡터 형성
    vector<vector<Container>> containers;
    for (int row = 0; row < storage.size() + 2; row++){
        vector<Container> currentRow;
        for (int col = 0; col < storage[0].length() + 2; col++){
            Container currentContainer;
            if (row == 0 || row == storage.size() + 1 || col == 0 || col == storage[0].length() + 1){
                currentContainer = {' ', true};
            }
            else {
                currentContainer = {storage[row - 1][col - 1], false};
            }
            currentRow.push_back(currentContainer);
        }
        containers.push_back(currentRow);
    }
    
    // request 실행 시작
    for (string request : requests){
        char target = request[0];
        switch(request.length()){
            // 한자리: 접근 가능한 컨테이너만 꺼냄
            case 1:
                {
                    // (0,0) 자리에서 DFS 방식으로 탐색
                    vector<Coordinate> targetContainers; // 탐색하며 위치들을 저장해둘 벡터
                    
                    // 방문 여부 저장
                    vector<vector<bool>> visited;
                    for (int row = 0; row < containers.size(); row++){
                        vector<bool> visitedRow;
                        for (int col = 0; col < containers[row].size(); col++){
                            visitedRow.push_back(false);
                        }
                        visited.push_back(visitedRow);
                    }
                    
                    stack<Coordinate> dfsStack;
                    dfsStack.push({0, 0});
                    visited[0][0] = true;
                    
                    while (!dfsStack.empty()){
                        Coordinate currentPosition = dfsStack.top();
                        dfsStack.pop();
                        int row = currentPosition.row, col = currentPosition.col;
                        // 각각마다 이동 가능하면 먼저 이동하고, 이동 불가하나 타겟과 일치하면 후보로 넣
                        // 1. 우측
                        if (col < containers[row].size() - 1){
                            // 이동 가능한 경우
                            if (containers[row][col + 1].isRemoved && !visited[row][col + 1]){
                                dfsStack.push({row, col + 1});
                                visited[row][col + 1] = true;
                            }
                            // 이동 불가하지만 타겟과 일치한 경우
                            else if (containers[row][col + 1].type == target){
                                targetContainers.push_back({row, col + 1});
                            }
                        }
                        
                        // 2. 아래
                        if (row < containers.size() - 1){
                            // 이동 가능한 경우
                            if (containers[row + 1][col].isRemoved && !visited[row + 1][col]){
                                dfsStack.push({row + 1, col});
                                visited[row + 1][col] = true;
                            }
                            // 이동 불가하지만 타겟과 일치한 경우
                            else if (containers[row + 1][col].type == target){
                                targetContainers.push_back({row + 1, col});
                            }
                        }
                        
                        // 3. 좌측
                        if (col > 0){
                            // 이동 가능한 경우
                            if (containers[row][col - 1].isRemoved && !visited[row][col - 1]){
                                dfsStack.push({row, col - 1});
                                visited[row][col - 1] = true;
                            }
                            // 이동 불가하지만 타겟과 일치한 경우
                            else if (containers[row][col - 1].type == target){
                                targetContainers.push_back({row, col - 1});
                            }
                        }
                        
                        // 4. 위
                        if (row > 0){
                            // 이동 가능한 경우
                            if (containers[row - 1][col].isRemoved && !visited[row - 1][col]){
                                dfsStack.push({row - 1, col});
                                visited[row - 1][col] = true;
                            }
                            // 이동 불가하지만 타겟과 일치한 경우
                            else if (containers[row - 1][col].type == target){
                                targetContainers.push_back({row - 1, col});
                            }
                        }
                    }
                    
                    // 선별된 컨테이너들을 모두 제거해준다
                    for (Coordinate coord: targetContainers){
                        containers[coord.row][coord.col].isRemoved = true;
                    }
                }
                break;
                
            // 두자리: 모든 컨테이너 꺼냄
            case 2:
                {
                    for (int row = 1; row < containers.size() - 1; row++){
                        for (int col = 1; col < containers[row].size() - 1; col++){
                            if (containers[row][col].type == target){
                                containers[row][col].isRemoved = true;
                            }
                        }
                    }
                }
                break;
        }
    }
    
    // 모두 마친 이후, 컨테이너들 중 isRemoved = false인 컨테이너들이 남은 컨테이너들!
    for (int row = 1; row < containers.size() - 1; row++){
        for (int col = 1; col < containers[row].size() - 1; col++){
            if (!containers[row][col].isRemoved) answer++;
        }
    }
    
    return answer;
}

void printContainers(vector<vector<Container>> containers){
    for (int row = 1; row < containers.size() - 1; row++){
        for (int col = 1; col < containers[row].size() - 1; col++){
            cout << containers[row][col].type << "(" << (containers[row][col].isRemoved? "X" : "O") << ") ";
        }
        cout << endl;
    }
}