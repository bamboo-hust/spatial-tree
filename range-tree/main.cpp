#include "RangeTree.h"

using namespace std;

int main() {
    int n = 10000;
    int q = 1000000;
    int w = 1e9;
    int cnt = 0;

    clock_t chk0 = clock();

    vector< RangeTree::Point<int, int> > a;
    for (int i = 0; i < n; ++i) {
        int x = rand() % w;
        int y = rand() % w;
        int v = rand() % w;
        a.push_back(RangeTree::Point<int, int>({x, y}, v));
    }
    RangeTree::RangeTree<int, int> T(a);

    clock_t chk1 = clock();

    for (int i = 0; i < q; ++i) {
        vector<int> lower = {rand() % w, rand() % w};
        vector<int> upper = {rand() % w, rand() % w};

        //vector< RangeTree::Point<int, int> > res = T.countInRange(lower, upper, {0, 0}, {0, 0});
        int res = T.countInRange(lower, upper);
        cnt += res;
        // for (auto it : res) {
        //     cout << it[0] << ' ' << it[1] << endl;
        // }
    }

    clock_t chk2 = clock();

    cout << cnt << endl;

    cerr << "Build time: " << (double)(chk1 - chk0) / CLOCKS_PER_SEC << endl;
    cerr << "Query time: " << (double)(chk2 - chk1) / CLOCKS_PER_SEC << endl;

	return 0;
}
