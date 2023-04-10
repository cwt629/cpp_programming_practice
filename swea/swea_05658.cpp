/*
5658. [모의 SW 역량테스트] 보물상자 비밀번호
*/

#include<iostream>
#include <string>
#include <set>

using namespace std;

// 하나의 16진수 문자를 10진수로 변환하는 함수
int convertSingleHexToDecimal(char hex) {
	// 0-9
	if (hex >= '0' && hex <= '9') return hex - '0';
	// A-F
	return hex - 'A' + 10;
}

// 주어진 16진수 string을 십진수로 변환하는 함수
int convertToDecimal(string hex) {
	int result = 0;
	int length = hex.length();

	for (int i = 0; i < length; i++) {
		int currentDigit = convertSingleHexToDecimal(hex[i]);
		result = result * 16 + currentDigit;
	}

	return result;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, K, digits;
		int count = 0, result = 0;
		string input;
		string inputDoubled;
		// 중복 제거를 위해 내림차순 set 활용
		set<int, greater<int>> storage;

		cin >> N; // 숫자의 개수
		cin >> K; // 구할 크기 순서

		digits = N / 4; // 각 변의 길이(각 숫자의 길이)
		cin >> input;
		// 4번째 숫자를 쉽게 받기 위해, input을 2번 붙여줌
		inputDoubled = input + input;
		
		// 회전시키며 숫자 받기
		for (int rotate = 0; rotate < digits; rotate++) {
			// 각 숫자 받아서 집합에 저장
			for (int i = 0; i < 4; i++) {
				string generatedHex = inputDoubled.substr(rotate + digits * i, digits);
				storage.insert(convertToDecimal(generatedHex));
			}
		}

		// 집합에서 K번째로 큰수를 구해온다
		for (auto it = storage.begin(); it != storage.end(); it++) {
			count++;
			// K번째 수면 result로 저장
			if (count == K) {
				result = *it;
				break;
			}
		}

		// 출력
		cout << "#" << test_case << " " << result << "\n";
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}