/*
[실버1] 연산자 끼워넣기
(삼성 SW 역량 테스트 기출)
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_POSSIBLE 1000000000
#define MIN_POSSIBLE -1000000000

using namespace std;

// 연산자들에 대한 permutation을 진행하기 위해 서브벡터를 구하는 함수
vector<int> generateSubvector(int operators[4]) {
	vector<int> subvector;
	for (int i = 0; i < 4; i++) {
		// 앞에서부터 오름차순으로 넣어준다
		for (int quantity = 0; quantity < operators[i]; quantity++) {
			subvector.push_back(i);
		}
	}

	return subvector;
}

// 두 숫자를 특정 연산자에 대해 계산하는 함수
int operate(int num1, int num2, int operatorNumber) {
	switch (operatorNumber) {
	case 0:
		return num1 + num2;

	case 1:
		return num1 - num2;

	case 2:
		return num1 * num2;

	case 3:
		// 앞 수가 0 이상이면 그대로 나눠줌
		if (num1 >= 0) return num1 / num2;
		// 앞 수가 음수이면, 양수로 바꿔 나눠준 뒤 -를 붙여줌
		return -((-num1) / num2);
	}
}

// 주어진 순서대로 연산한 결과를 반환하는 함수
int getOperationResult(vector<int> numbers, vector<int> operators) {
	int result = numbers[0];
	for (int i = 0; i < operators.size(); i++) {
		result = operate(result, numbers[i + 1], operators[i]);
	}

	return result;
}

int main() {
	int N;
	int operators[4] = { 0, 0, 0, 0 }; // 연산자 개수
	int minValue = MAX_POSSIBLE, maxValue = MIN_POSSIBLE;

	cin >> N; // N 입력
	vector<int> numbers(N); // 크기가 N인, 각 숫자들에 대한 벡터

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp; // 각 숫자 입력
		numbers[i] = temp;
	}
	
	for (int i = 0; i < 4; i++) {
		cin >> operators[i]; // 각 연산자의 개수
	}

	// 연산자들을 모두 permutation한다
	vector<int> subvector = generateSubvector(operators);
	do {
		int result = getOperationResult(numbers, subvector);
		// 최대 및 최소 갱신
		minValue = min(minValue, result);
		maxValue = max(maxValue, result);
	} while (next_permutation(subvector.begin(), subvector.end()));

	// 구한 결과값 출력
	cout << maxValue << "\n";
	cout << minValue << "\n";

	return 0;
}