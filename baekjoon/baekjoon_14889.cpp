/*
[실버2] 스타트와 링크
(삼성 SW 역량 테스트 기출)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_STAT_GAP 10000000
using namespace std;

// 특정 조합에 대해 두 팀의 능력치 차이를 구하는 함수
int getGapByCombination(int N, vector<vector<int>> stats, vector<int> visit) {
	int Start = 0, Link = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue; // 자기 자신과의 조합 제외

			// 둘이 같은 팀인 경우
			if (visit[i] == visit[j]) {
				// 0은 Start, 1은 Link로 능력치를 더해준다(모두 탐색하므로 Sij만 더해줌)
				if (visit[i] == 0) Start += stats[i][j];
				else Link += stats[i][j];
			}
		}
	}

	// 구해진 두 값의 차이 반환
	return abs(Start - Link);
}

// n명에서 m명을 뽑는 조합을 모두 탐색하며 최소 차이를 구하는 함수
int getMinGap(int N, vector<vector<int>> stats) {
	int result = MAX_STAT_GAP;
	vector<int> visit(N); // 조합을 구하기 위한 서브 벡터
	for (int i = 0; i < N; i++) {
		// 조합을 구하기 위해, 서브 벡터의 앞 절반은 0, 뒤 나머지는 1로 채운다
		if (i < N / 2) visit[i] = 0;
		else visit[i] = 1;
	}

	// 각 조합마다 차이를 구한다
	do {
		int currentGap = getGapByCombination(N, stats, visit);
		result = min(result, currentGap);
	} while (next_permutation(visit.begin(), visit.end()));

	return result;
}

int main() {
	int N;
	vector<vector<int>> stats;
	cin >> N;

	// 능력치 저장
	for (int i = 0; i < N; i++) {
		vector<int> subVec;
		stats.push_back(subVec);
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			stats[i].push_back(temp);
		}
	}

	// 구한 정답
	cout << getMinGap(N, stats) << "\n";

	return 0;
}