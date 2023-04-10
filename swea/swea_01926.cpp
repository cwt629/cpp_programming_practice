/*
1926. 간단한 369게임
*/

#include<iostream>
#include <string>

using namespace std;

// 특정 숫자에 대해 외칠 문자열을 구하는 함수
string getWord(int number){
    string answer = "";
	string numString = to_string(number);
    for (int i = 0; i < numString.length(); i++){
        int currentDigit = numString[i] - '0'; // 숫자로 변환
        // 3, 6, 9 중 하나인 경우(0은 제외해줘야 한다!)
        if (currentDigit > 0 && currentDigit % 3 == 0) answer += "-";
    }
    
    // 3, 6, 9가 없었다면 숫자 그대로 외친다
    return (answer.length() > 0)? answer : numString;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 1;
	
	//cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N;
        cin >> N;
        
        for (int i = 1; i <= N; i++){
        	cout << getWord(i);
            // 마지막을 제외하고 띄어쓰기 해준다
            if (i < N) cout << " ";
        }
	}
    
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}