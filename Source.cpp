#include<iostream>
#include<vector>
#include<string>

class cavityMap {
	int n;
	std::vector<std::string> grid;
public:
	cavityMap() {}
	void read() {
		std::cin >> n;
		std::string s;
		for (int i = 0; i < n; ++i) {
			std::cin >> s;
			grid.push_back(s);
		}
	}

	void find_cavities() {
		if (n < 3) return;
		int m = n - 1;
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < m; ++j) {
				if (grid[i][j] >  grid[i - 1][j] &&
					grid[i][j] >  grid[i + 1][j] &&
					grid[i][j] >  grid[i][j - 1] &&
					grid[i][j] >  grid[i][j + 1]) {
					grid[i][j] = 'X';
				}
			}
		}
	}

	void print() {
		for (unsigned int i = 0; i < grid.size(); ++i)
			std::cout << grid[i] << std::endl;
	}
};

int main() {
	cavityMap p;
	p.read();
	p.find_cavities();
	p.print();

	return 0;
}