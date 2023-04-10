/*
2117. [모의 SW 역량테스트] 홈 방범 서비스
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 집 클래스
class House {
public:
	int row;
	int col;
	House(int r, int c) {
		row = r;
		col = c;
	}
	bool reachable(int pointRow, int pointCol, int distance) {
		return abs(pointRow - row) + abs(pointCol - col) <= distance;
	}
};

// K에 따른 운영 비용
int getCost(int K) {
	return K * K + (K - 1) * (K - 1);
}

// 특정 K와 범위를 받는 집의 세대수를 비교해, 손해를 보지 않는지 판단하는 함수
bool notLoss(int K, int M, int houseNum) {
	return M * houseNum - getCost(K) >= 0;
}

// 가능한 최대 K값을 구하는 함수
int getMaximumK(int M, int houseNumber) {
	int K = 0;
	int maxIncome = M * houseNumber;
	int nextCost = 1;

	while (nextCost <= maxIncome) {
		K++;
		nextCost = getCost(K + 1);
	}

	return K;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M, maxK;
		int result = 0; // 서비스받는 집 개수
		vector<House> houses;

		cin >> N;
		cin >> M;

		// 입력받기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int input;
				cin >> input;
				// 집 정보 저장
				if (input == 1) {
					House h = { i, j };
					houses.push_back(h);
				}
			}
		}

		maxK = getMaximumK(M, houses.size());

		// 완전 탐색
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = maxK; k >= 1; k--) {
					// 서비스 받을 수 있는 세대 수를 구한다
					int count = 0;
					for (int num = 0; num < houses.size(); num++) {
						if (houses[num].reachable(i, j, k - 1)) count++;
					}
					// 손실이 안나면 그 경우만 보면 된다(넓을수록 집을 많이 포함하므로)
					if (notLoss(k, M, count)) {
						if (result < count) result = count; // 큰걸로 갱신
						break;
					}
				}
			}
		}

		// 결과 출력
		cout << "#" << test_case << " " << result << "\n";
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}