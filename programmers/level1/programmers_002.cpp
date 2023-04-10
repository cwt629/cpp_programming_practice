/*
[1�ܰ�] ������ �ݾ� ����ϱ�
(��Ŭ�� ç����)
*/

using namespace std;

// �ʿ��� �ݾ��� ��ȯ�ϴ� �Լ�
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