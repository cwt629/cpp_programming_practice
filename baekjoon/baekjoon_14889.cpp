/*
[�ǹ�2] ��ŸƮ�� ��ũ
(�Ｚ SW ���� �׽�Ʈ ����)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_STAT_GAP 10000000
using namespace std;

// Ư�� ���տ� ���� �� ���� �ɷ�ġ ���̸� ���ϴ� �Լ�
int getGapByCombination(int N, vector<vector<int>> stats, vector<int> visit) {
	int Start = 0, Link = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue; // �ڱ� �ڽŰ��� ���� ����

			// ���� ���� ���� ���
			if (visit[i] == visit[j]) {
				// 0�� Start, 1�� Link�� �ɷ�ġ�� �����ش�(��� Ž���ϹǷ� Sij�� ������)
				if (visit[i] == 0) Start += stats[i][j];
				else Link += stats[i][j];
			}
		}
	}

	// ������ �� ���� ���� ��ȯ
	return abs(Start - Link);
}

// n���� m���� �̴� ������ ��� Ž���ϸ� �ּ� ���̸� ���ϴ� �Լ�
int getMinGap(int N, vector<vector<int>> stats) {
	int result = MAX_STAT_GAP;
	vector<int> visit(N); // ������ ���ϱ� ���� ���� ����
	for (int i = 0; i < N; i++) {
		// ������ ���ϱ� ����, ���� ������ �� ������ 0, �� �������� 1�� ä���
		if (i < N / 2) visit[i] = 0;
		else visit[i] = 1;
	}

	// �� ���ո��� ���̸� ���Ѵ�
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

	// �ɷ�ġ ����
	for (int i = 0; i < N; i++) {
		vector<int> subVec;
		stats.push_back(subVec);
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			stats[i].push_back(temp);
		}
	}

	// ���� ����
	cout << getMinGap(N, stats) << "\n";

	return 0;
}