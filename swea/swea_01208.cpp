/*
1208. [S/W 문제해결 기본] 1일차 - Flatten
*/

#include<iostream>
#include <algorithm>

#define BOXNUM 100

using namespace std;

// 내림차순 정렬을 위한 함수
bool desc(int a, int b){
	return a > b;
}

// 특정 인덱스에서 특정 인덱스로 박스를 옮기는 함수
void moveBox(int from, int to, int box[BOXNUM]){
	box[from]--;
    box[to]++;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	
	//cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int result;
        int dumpCount; // 덤프 횟수
        int moveFrom, moveTo; // 박스를 뺄 인덱스, 넣을 인덱스
		// 각 상자의 높이를 저장할 배열
        int box[BOXNUM];
        
        cin >> dumpCount; // 덤프 횟수 입력
        for (int i = 0; i < BOXNUM; i++){
        	cin >> box[i]; // 박스 높이 입력
        }
        
        // 박스를 내림차순 정렬
        sort(box, box + BOXNUM, desc);
        
        // 포인터를 옮겨가며 박스 옮김
        moveFrom = 0; moveTo = BOXNUM - 1;
        
        for (int dumped = 0; dumped < dumpCount; dumped++){
            // 차이가 1 이하이면 더 할 이유 없음
            if (box[moveFrom] - box[moveTo] <= 1) break;
            
        	moveBox(moveFrom, moveTo, box); // 박스 이동
            // 포인터 이동
            if (box[moveFrom] < box[moveFrom + 1]) moveFrom++;
            else if (box[moveFrom] == box[moveFrom + 1]) moveFrom = 0; // 같은 무게에서는 앞 인덱스 우선으로 빼준다
            
            if (box[moveTo] > box[moveTo - 1]) moveTo--;
            else if (box[moveTo] == box[moveTo - 1]) moveTo = BOXNUM - 1; // 같은 무게에서는 뒤 인덱스 우선으로 넣어준다
        }
        
        // 현재 moveFrom과 moveTo가 최고, 최저점을 가리키고 있으므로 둘의 차이를 구하면 된다
        result = box[moveFrom] - box[moveTo];
        
        // 출력
        cout << "#" << test_case << " " << result << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}