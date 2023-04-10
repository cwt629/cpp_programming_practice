/* 
[1�ܰ�] ����� ������ ����
(���� �ڵ� ç���� ����2)
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Ư�� ������ ��� ������ Ȧ������ �Ǵ��ϴ� �Լ�
bool hasOddDivisors(int n) {
    // ������ �������� ��츸 ��� ������ Ȧ��!
    double rootValue = sqrt(n);
    double floorValue = floor(rootValue);

    // ��Ʈ���� �������� ���η� ��ȯ
    return (rootValue == floorValue);
}

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; i++) {
        // ������ ���� �����ϴ� ��
        int sign = (hasOddDivisors(i)) ? -1 : 1;
        answer += sign * i;
    }

    return answer;
}