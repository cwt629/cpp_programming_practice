/*
1206. [S/W 문제해결 기본] 1일차 - View
*/

#include<iostream>
#include <string>
#include <vector>

using namespace std;

// 입력을 받아 배열로 저장해 반환하는 함수
vector<int> generateBuildingsArray(){
	int length;
    cin >> length; // 건물의 개수
    vector<int> buildings; // 동적 배열
    for (int i = 0; i < length; i++){
        int input;
    	cin >> input;
        buildings.push_back(input);
    }
    
    return buildings;
}

// 네 수의 최대값을 반환하는 함수
int getMax(int a, int b, int c, int d){
	int max = a;
    if (max < b) max = b;
    if (max < c) max = c;
    if (max < d) max = d;
    
    return max;
}

// 특정 건물에서 조망권이 확보된 세대의 개수를 반환하는 함수
int countViews(vector<int> buildings, int index){
	// 좌우 2채씩의 건물 중 최대 높이를 받아온다
    int highestAround = getMax(buildings[index - 2], buildings[index - 1], buildings[index + 1], buildings[index + 2]);
    
    // 좌우 최대높이보다 더 낮거나 같으면 0세대, 그렇지 않으면 차이만큼은 조망권 확보
    int gap = buildings[index] - highestAround;
    return (gap > 0)? gap : 0;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
    int result = 0;
    string message;
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
	//cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		vector<int> buildings = generateBuildingsArray(); // 빌딩 정보

        for (int i = 2; i < buildings.size() - 2; i++){
        	result += countViews(buildings, i);
        }
        
        // 출력
        message = "#" + to_string(test_case) + " " + to_string(result);
        cout << message << "\n";
        
        // 초기화
        result = 0;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}