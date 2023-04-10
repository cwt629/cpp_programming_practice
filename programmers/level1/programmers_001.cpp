/* 
[1단계] 약수의 개수와 덧셈
(월간 코드 챌린지 시즌2)
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 특정 숫자의 약수 개수가 홀수인지 판단하는 함수
bool hasOddDivisors(int n) {
    // 정수의 제곱수인 경우만 약수 개수가 홀수!
    double rootValue = sqrt(n);
    double floorValue = floor(rootValue);

    // 루트값이 정수인지 여부로 반환
    return (rootValue == floorValue);
}

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; i++) {
        // 더할지 뺄지 구분하는 수
        int sign = (hasOddDivisors(i)) ? -1 : 1;
        answer += sign * i;
    }

    return answer;
}