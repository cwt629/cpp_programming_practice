/*
[���5] �κ� û�ұ�
(�Ｚ SW ���� �׽�Ʈ ����)
*/

#include <iostream>
#include <vector>

using namespace std;

enum Directions {north, east, south, west};

vector<vector<int>> room;
vector<vector<bool>> cleaned;

// Ư�� ��ġ�� �̵��� �� �ִ��� ���θ� ��ȯ�ϴ� �Լ�
bool movable(int x, int y) {
	// ������ ����� �ʴ� ��� �ش�
	if (x >= 0 && x < room.size() && y >= 0 && y < room[0].size()) {
		// ������ �ƴ����� �Ǵ��ϸ� ��
		return room[x][y] == 0;
	}
	// ������ ����� ���� ����
	return false;
}

// Ư�� ��ġ�� û���� �ʿ䰡 �ִ��� ���θ� ��ȯ�ϴ� �Լ�
bool needsClean(int x, int y) {
	return !cleaned[x][y];
}

class Robot {
public:
	int x;
	int y;
	int dir;
	int cleanedSpots = 0;
	Robot(int xInput, int yInput, int dirInput) {
		x = xInput;
		y = yInput;
		dir = dirInput;
	}

	// ���� ��ġ���� �ش� �������� ���� �� �����ϴ� ��ġ�� ���ͷ� ��� ��ȯ
	vector<int> spotToGo(int direction) {
		vector<int> spot(2);
		switch (direction) {
		case north:
			spot = { x - 1, y};
			break;

		case east:
			spot = { x, y + 1};
			break;

		case south:
			spot = { x + 1, y };
			break;

		case west:
			spot = { x, y - 1 };
			break;
		}

		return spot;
	}
	
	// �ٶ󺸰� �ִ� ĭ�� û�Ұ� �ʿ����� ���� Ȯ��
	bool needsCleanOnFront() {
		vector<int> front = spotToGo(dir);
		int frontX = front[0], frontY = front[1];

		return (movable(frontX, frontY) && needsClean(frontX, frontY));
	}

	// �ֺ��� û���� ĭ�� �ִ��� ���� Ȯ��
	bool needsToCleanAround() {
		// �Ʒ���
		if (movable(x + 1, y) && needsClean(x + 1, y)) return true;
		// ������
		if (movable(x, y + 1) && needsClean(x, y + 1)) return true;
		// ����
		if (movable(x - 1, y) && needsClean(x - 1, y)) return true;
		// ����
		if (movable(x, y - 1) && needsClean(x, y - 1)) return true;
		// ��� �ȵǸ� ����
		return false;
	}

	// �ݽð� ȸ���ϱ�
	void rotate() {
		dir = (dir + 3) % 4;
	}

	// ���� �������� �̵��ϱ�
	void proceed() {
		switch (dir) {
		case north:
			x--;
			break;

		case east:
			y++;
			break;

		case south:
			x++;
			break;

		case west:
			y--;
			break;
		}
	}

	// �����ϱ�
	bool moveBack() {
		vector<int> togo = spotToGo((dir + 2) % 4); // ���� �� ���� �� ��ǥ
		// �̵� �����ϸ� �̵�
		if (movable(togo[0], togo[1])) {
			x = togo[0]; y = togo[1];
			return true;
		}
		// �̵� �Ұ����� ���
		return false;
	}

	// ����ġ û���ϱ�
	void cleanup() {
		if (needsClean(x, y)) {
			cleaned[x][y] = true;
			cleanedSpots++; // û���� ĭ ����
		}
	}
};

int main() {
	int N, M;
	cin >> N;
	cin >> M;

	// �κ� ���� �Է�
	int xInput, yInput, dirInput;
	cin >> xInput;
	cin >> yInput;
	cin >> dirInput;
	Robot myrobot = { xInput, yInput, dirInput };

	// �� ���� �� û�� ���� �Է�
	for (int i = 0; i < N; i++) {
		vector<int> subRoom; vector<bool> subCleaned;
		room.push_back(subRoom); cleaned.push_back(subCleaned);

		for (int j = 0; j < M; j++) {
			int state;
			cin >> state; // ������ ��ĭ����
			room[i].push_back(state);
			cleaned[i].push_back(false);
		}
	}

	// �ùķ��̼� ����
	bool onWorking = true;
	while (onWorking) {
		// 1. ���� ĭ û��
		myrobot.cleanup();

		// 2. �ֺ��� û���� ��ĭ�� ���� ���
		if (!myrobot.needsToCleanAround()) {
			// �����ϱ�
			onWorking = myrobot.moveBack();
			continue;
		}
		// 3. �ֺ��� û���� ��ĭ�� �ִ� ���
		myrobot.rotate();
		if (myrobot.needsCleanOnFront()) myrobot.proceed(); // �տ� û�� �ʿ��ϸ� ����
	}

	// �ùķ��̼� ���� ��, û���ϴ� ĭ�� ���� ���
	cout << myrobot.cleanedSpots << "\n";

	return 0;
}