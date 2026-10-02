/*
[2단계] 비밀 코드 해독
(2025 프로그래머스 코드챌린지 1차 예선)
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> getSequenceUntil(int end);
vector<vector<int>> getCombination(vector<int> array, int selectionRemaining);
void printCombinations(vector<vector<int>> combination);
vector<int> getSubstring(vector<int> origin, int start);
int getMatchCount(vector<int> target, vector<int> trial);

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    // 1~n 중 5개를 선택하는 모든 조합에 대해 완전탐색 진행
    vector<vector<int>> combinations = getCombination(getSequenceUntil(n), 5);
    
    for (vector<int> target: combinations){
        bool isAllMatched = true;
        for (int qIndex = 0; qIndex < q.size(); qIndex++){
            int matchCount = getMatchCount(target, q[qIndex]);
            if (matchCount != ans[qIndex]){
                isAllMatched = false;
                break;
            }
        }
        
        if (isAllMatched){
            answer++;
        }
        
    }
    
    return answer;
}

vector<int> getSequenceUntil(int end){
    vector<int> result;
    for (int i = 1; i <= end; i++){
        result.push_back(i);
    }
    
    return result;
}

vector<vector<int>> getCombination(vector<int> array, int selectionRemaining){
    vector<vector<int>> result;
    
    if (selectionRemaining == 1){
        for (int element: array){
            vector<int> current = {element};
            result.push_back(current);
        }
        
        return result;
    }
    
    for (int i = 0; i < array.size(); i++){
        int fixedElement = array[i];
        vector<int> rest = getSubstring(array, i + 1);
        vector<vector<int>> miniCombinations = getCombination(rest, selectionRemaining - 1);
        // 각 miniCombinations마다 맨앞에 현재 엘리먼트를 붙여서 결과에 붙인다
        for (vector<int> combination: miniCombinations){
            vector<int> finalCombination = {fixedElement};
            for (int element: combination){
                finalCombination.push_back(element);
            }
            result.push_back(finalCombination);
        }
    }
    
    return result;
}

void printCombinations(vector<vector<int>> combination){
    for (int i = 0; i < combination.size(); i++){
        cout << "[";
        for (int j = 0; j < combination[i].size(); j++){
            if (j > 0) cout << ", ";
            cout << combination[i][j];
        }
        cout << "]" << endl;
    }
}

vector<int> getSubstring(vector<int> origin, int start){
    vector<int> result;
    for (int i = start; i < origin.size(); i++){
        result.push_back(origin[i]);
    }
    
    return result;
}

int getMatchCount(vector<int> target, vector<int> trial){
    int result = 0;
    for (int targetNum: target){
        for (int trialNum: trial){
            if (targetNum == trialNum) result++;
        }
    }
    
    return result;
}