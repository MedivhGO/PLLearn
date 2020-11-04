#include <iostream>
#include <random>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]) {
	default_random_engine e; //随机数引擎 范围内的每个数生成的概率都是相同的
	normal_distribution<> n(4,1.5); //随机数分布
	uniform_real_distribution<double> u(0,1);
	vector<unsigned> vals(9);
	for (size_t i = 0; i != 200; ++i) {
		unsigned v = lround(n(e));
		if (v < vals.size())
			++vals[v];
	}
	for (size_t j = 0; j != vals.size(); ++j) {
		cout << j << ": " << string(vals[j],'*') << endl;
	}
	
	for (size_t j = 0; j < 10; ++j) {
		cout << u(e) << " ";
	}
}