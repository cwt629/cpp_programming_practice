/*
1204. [S/W 문제해결 기본] 1일차 - 최빈수 구하기
*/

#include<iostream>

#define STUDENT_NUM 1000
#define MAX_SCORE 100

using namespace std;

// 점수별로 몇명 받았는지 저장하는 함수
void countScores(int* scores, int* students){
	// 해당하는 인덱스 카운트
    for (int i = 0; i < STUDENT_NUM; i++){
    	int currentScore = students[i];
        scores[currentScore]++;
    }
}

// 최빈수를 구하는 함수
int getFrequentNumber(int* scores){
	int result = 0;
    for (int i = 1; i <= MAX_SCORE; i++){
    	// 구해진 최빈수보다 크거나 같으면 갱신(같아도 점수가 더 높으므로)
        if (scores[i] >= scores[result]) result = i;
    }
    
    return result;
}

int main(int argc, char** argv)
{
	int test_case, input_test_case;
	int T;

	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int scores[MAX_SCORE + 1] = {0}; // 각 점수대별 인원수
        int students[STUDENT_NUM];
        int result;
        
        cin >> input_test_case; // 테스트케이스 번호
        // 학생들 정보 입력
        for (int i = 0; i < STUDENT_NUM; i++){
        	cin >> students[i];
        }
        
        // 점수 정보 저장
        countScores(scores, students);
        
        // 구해진 최빈수
        result = getFrequentNumber(scores);
        
        // 메시지 출력
        cout << "#" << input_test_case << " " << result << "\n";
	}
    
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}