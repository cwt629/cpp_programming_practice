/*
[�ǹ�1] ������ �����ֱ�
(�Ｚ SW ���� �׽�Ʈ ����)
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_POSSIBLE 1000000000
#define MIN_POSSIBLE -1000000000

using namespace std;

// �����ڵ鿡 ���� permutation�� �����ϱ� ���� ���꺤�͸� ���ϴ� �Լ�
vector<int> generateSubvector(int operators[4]) {
	vector<int> subvector;
	for (int i = 0; i < 4; i++) {
		// �տ������� ������������ �־��ش�
		for (int quantity = 0; quantity < operators[i]; quantity++) {
			subvector.push_back(i);
		}
	}

	return subvector;
}

// �� ���ڸ� Ư�� �����ڿ� ���� ����ϴ� �Լ�
int operate(int num1, int num2, int operatorNumber) {
	switch (operatorNumber) {
	case 0:
		return num1 + num2;

	case 1:
		return num1 - num2;

	case 2:
		return num1 * num2;

	case 3:
		// �� ���� 0 �̻��̸� �״�� ������
		if (num1 >= 0) return num1 / num2;
		// �� ���� �����̸�, ����� �ٲ� ������ �� -�� �ٿ���
		return -((-num1) / num2);
	}
}

// �־��� ������� ������ ����� ��ȯ�ϴ� �Լ�
int getOperationResult(vector<int> numbers, vector<int> operators) {
	int result = numbers[0];
	for (int i = 0; i < operators.size(); i++) {
		result = operate(result, numbers[i + 1], operators[i]);
	}

	return result;
}

int main() {
	int N;
	int operators[4] = { 0, 0, 0, 0 }; // ������ ����
	int minValue = MAX_POSSIBLE, maxValue = MIN_POSSIBLE;

	cin >> N; // N �Է�
	vector<int> numbers(N); // ũ�Ⱑ N��, �� ���ڵ鿡 ���� ����

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp; // �� ���� �Է�
		numbers[i] = temp;
	}
	
	for (int i = 0; i < 4; i++) {
		cin >> operators[i]; // �� �������� ����
	}

	// �����ڵ��� ��� permutation�Ѵ�
	vector<int> subvector = generateSubvector(operators);
	do {
		int result = getOperationResult(numbers, subvector);
		// �ִ� �� �ּ� ����
		minValue = min(minValue, result);
		maxValue = max(maxValue, result);
	} while (next_permutation(subvector.begin(), subvector.end()));

	// ���� ����� ���
	cout << maxValue << "\n";
	cout << minValue << "\n";

	return 0;
}