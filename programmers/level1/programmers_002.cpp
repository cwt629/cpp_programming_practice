/*
[1단계] 부족한 금액 계산하기
(위클리 챌린지)
*/

using namespace std;

// 필요한 금액을 반환하는 함수
long long getRequirement(int price, int count) {
    long long result = 0;
    for (int i = 1; i <= count; i++) {
        result += price * i;
    }

    return result;
}

long long solution(int price, int money, int count)
{
    long long requirement = getRequirement(price, count);
    long long answer = (requirement > money) ? requirement - money : 0;

    return answer;
}