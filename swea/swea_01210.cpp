/*
1210. [S/W 문제해결 기본] 2일차 - Ladder1
*/

#include<iostream>

#define BOUNDARY 100

using namespace std;

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
        int input_test_case;
        int currentX; int currentY = BOUNDARY - 1; // 현위치
        bool cameFromLeft = false, cameFromRight = false; // 왼쪽/오른쪽으로부터 왔는지 여부
		int grid[BOUNDARY][BOUNDARY];
        cin >> input_test_case;
        
        // 격자의 각 숫자를 받아온다
        for (int row = 0; row < BOUNDARY; row++){
        	for (int col = 0; col < BOUNDARY; col++){
            	cin >> grid[row][col];
                // 도착점의 x좌표를 저장한다
                if (grid[row][col] == 2) currentX = col;
            }
        }
        
        // x 점에서부터 위로 거슬러올라간다.
        while (currentY > 0){
        	// 왼쪽 이동 가능한 경우
            if (currentX > 0 && !cameFromLeft && grid[currentY][currentX - 1] == 1) {
                currentX--;
                cameFromRight = true;
            }
            // 오른쪽 이동 가능한 경우
            else if (currentX < BOUNDARY - 1 && !cameFromRight && grid[currentY][currentX + 1] == 1) {
                currentX++;
                cameFromLeft = true;
            }
            // 둘 다 이동 불가능하면 위로 올라간다
            else {
                currentY--;
                cameFromLeft = cameFromRight = false;
            }
        }
        
        // 루프를 벗어났을 때의 x좌표 출력
        cout << "#" << input_test_case << " " << currentX << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}