/*
[골드5] 로봇 청소기
(삼성 SW 역량 테스트 기출)
*/

#include <iostream>
#include <vector>

using namespace std;

enum Directions {north, east, south, west};

vector<vector<int>> room;
vector<vector<bool>> cleaned;

// 특정 위치로 이동할 수 있는지 여부를 반환하는 함수
bool movable(int x, int y) {
	// 범위를 벗어나지 않는 경우 해당
	if (x >= 0 && x < room.size() && y >= 0 && y < room[0].size()) {
		// 벽인지 아닌지만 판단하면 됨
		return room[x][y] == 0;
	}
	// 범위를 벗어나면 절대 못감
	return false;
}

// 특정 위치가 청소할 필요가 있는지 여부를 반환하는 함수
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

	// 현재 위치에서 해당 방향으로 전진 시 도착하는 위치를 벡터로 담아 반환
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
	
	// 바라보고 있는 칸이 청소가 필요한지 여부 확인
	bool needsCleanOnFront() {
		vector<int> front = spotToGo(dir);
		int frontX = front[0], frontY = front[1];

		return (movable(frontX, frontY) && needsClean(frontX, frontY));
	}

	// 주변에 청소할 칸이 있는지 여부 확인
	bool needsToCleanAround() {
		// 아래쪽
		if (movable(x + 1, y) && needsClean(x + 1, y)) return true;
		// 오른쪽
		if (movable(x, y + 1) && needsClean(x, y + 1)) return true;
		// 위쪽
		if (movable(x - 1, y) && needsClean(x - 1, y)) return true;
		// 왼쪽
		if (movable(x, y - 1) && needsClean(x, y - 1)) return true;
		// 모두 안되면 없음
		return false;
	}

	// 반시계 회전하기
	void rotate() {
		dir = (dir + 3) % 4;
	}

	// 현재 방향으로 이동하기
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

	// 후진하기
	bool moveBack() {
		vector<int> togo = spotToGo((dir + 2) % 4); // 후진 시 가게 될 좌표
		// 이동 가능하면 이동
		if (movable(togo[0], togo[1])) {
			x = togo[0]; y = togo[1];
			return true;
		}
		// 이동 불가능한 경우
		return false;
	}

	// 현위치 청소하기
	void cleanup() {
		if (needsClean(x, y)) {
			cleaned[x][y] = true;
			cleanedSpots++; // 청소한 칸 세기
		}
	}
};

int main() {
	int N, M;
	cin >> N;
	cin >> M;

	// 로봇 정보 입력
	int xInput, yInput, dirInput;
	cin >> xInput;
	cin >> yInput;
	cin >> dirInput;
	Robot myrobot = { xInput, yInput, dirInput };

	// 방 정보 및 청소 여부 입력
	for (int i = 0; i < N; i++) {
		vector<int> subRoom; vector<bool> subCleaned;
		room.push_back(subRoom); cleaned.push_back(subCleaned);

		for (int j = 0; j < M; j++) {
			int state;
			cin >> state; // 벽인지 빈칸인지
			room[i].push_back(state);
			cleaned[i].push_back(false);
		}
	}

	// 시뮬레이션 진행
	bool onWorking = true;
	while (onWorking) {
		// 1. 현재 칸 청소
		myrobot.cleanup();

		// 2. 주변에 청소할 빈칸이 없는 경우
		if (!myrobot.needsToCleanAround()) {
			// 후진하기
			onWorking = myrobot.moveBack();
			continue;
		}
		// 3. 주변에 청소할 빈칸이 있는 경우
		myrobot.rotate();
		if (myrobot.needsCleanOnFront()) myrobot.proceed(); // 앞에 청소 필요하면 전진
	}

	// 시뮬레이션 종료 후, 청소하는 칸의 개수 출력
	cout << myrobot.cleanedSpots << "\n";

	return 0;
}