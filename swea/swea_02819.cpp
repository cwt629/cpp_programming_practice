/*
2819. 격자판의 숫자 이어 붙이기
*/

#include<iostream>
#include <set>
using namespace std;

set<int> storage; // 결과값 저장할 집합
int grid[4][4]; // 격자판

// DFS 방식으로 격자판을 탐색하는 함수
void dfs(int row, int col, int acc, int selectionRemaining) {
	int newAcc = acc * 10 + grid[row][col]; // 현위치 값까지 더해줌

	// 선택을 모두 마친 경우 집합에 저장
	if (selectionRemaining == 0) {
		storage.insert(newAcc);
		return;
	}

	// 왼쪽
	if (col > 0) dfs(row, col - 1, newAcc, selectionRemaining - 1);
	// 위쪽
	if (row > 0) dfs(row - 1, col, newAcc, selectionRemaining - 1);
	// 오른쪽
	if (col < 3) dfs(row, col + 1, newAcc, selectionRemaining - 1);
	// 아래쪽
	if (row < 3) dfs(row + 1, col, newAcc, selectionRemaining - 1);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		// 격자판 저장
		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				cin >> grid[row][col];
			}
		}

		// DFS로 탐색 시작
		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				dfs(row, col, 0, 6); // 해당 수를 선택했으므로 남은 횟수는 7 - 1 = 6
			}
		}

		// 탐색 완료 후 개수 출력
		cout << "#" << test_case << " " << storage.size() << "\n";

		// 집합 초기화(grid는 어차피 입력받을 것이므로 초기화 필요 없음)
		storage.clear();
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}