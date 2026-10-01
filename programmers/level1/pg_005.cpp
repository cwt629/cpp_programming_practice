/**
 * [1단계] [PCCP 기출문제] 1번 / 동영상 재생기
 * (PCCP 기출문제)
 */

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int timeToSec(string time);
string secToTime(int sec);
vector<string> splitString(string word, string delimeter);

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int totalLength = timeToSec(video_len), current = timeToSec(pos),
    openingStart = timeToSec(op_start), openingEnd = timeToSec(op_end);
    
    for (string command : commands){
        if (command == "prev"){
            // 오프닝 구간에 걸치는 경우, 오프닝 끝으로 이동
            if (current >= openingStart && current < openingEnd) {
                current = openingEnd;
            }
            current -= 10;
            // 오프닝 구간에 걸치는 경우, 오프닝 끝으로 이동
            if (current >= openingStart && current < openingEnd) {
                current = openingEnd;
            }
            // 시작 위치 이전으로 가는 경우, 시작 위치로 이동
            if (current < 0) current = 0;
        }
        else if (command == "next"){
            // 오프닝 구간에 걸치는 경우, 오프닝 끝으로 이동
            if (current >= openingStart && current < openingEnd) {
                current = openingEnd;
            }
            
            current += 10;
            // 오프닝 구간에 걸치는 경우, 오프닝 끝으로 이동
            if (current >= openingStart && current < openingEnd) {
                current = openingEnd;
            }
            
            // 전체 길이를 초과하는 경우, 마지막으로 이동
            if (current > totalLength) current = totalLength;
        }
    }
    
    return secToTime(current);
}

// 시간 문자열을 초로 환산하는 함수
int timeToSec(string time){
    vector<string> tokens = splitString(time, ":");
    int minute = stoi(tokens[0]), sec = stoi(tokens[1]);
    
    return minute * 60 + sec;
}

// 초 숫자를 시간 문자열로 변환하는 함수
string secToTime(int sec){
    int minute = floor(sec / 60), second = sec % 60;
    string minuteString = to_string(minute),
    secondString = to_string(second);
    if (minuteString.length() == 1) {
        minuteString = "0" + minuteString;
    }
    if (secondString.length() == 1) {
        secondString = "0" + secondString;
    }
    string result = minuteString + ":" + secondString;
    return result;
}

// split 함수 구현하기
vector<string> splitString(string word, string delimeter){
    vector<string> result;
    int start = 0, end = word.find(delimeter);
    
    while (end != string::npos){
        string token = word.substr(start, end - start); // substr(시작, 개수)
        result.push_back(token);
        start = end + delimeter.length();
        end = word.find(delimeter, start);
    }
    
    // 마지막 남은 토큰도 저장해주기
    result.push_back(word.substr(start));
    
    return result;
}