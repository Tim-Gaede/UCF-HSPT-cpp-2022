#include <bits/stdc++.h>

using namespace std;

struct artifact {
    long double x, y, r;
};

/* return true iff artifacts a and b intersect */
bool collision(artifact &a, artifact &b) {
    long double dx = a.x - b.x;
    long double dy = a.y - b.y;
    return dx * dx + dy * dy <= (a.r + b.r) * (a.r + b.r); // avoid sqrt() until necessary
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<artifact> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].x >> v[i].y >> v[i].r;
        }

        /*
         * Note that an artifact can only merge with another
         * artifact that both intersects it and has appeared
         * at a previous time. 
         * Since input gives the artifacts in the order that
         * they appear, they just correspond to pairs of
         * artifacts a, b, with indices i, j, such that
         * a and b intersect and j < i. We find these in n^2
         * time.
         * We have at most n merges to take care of.
         */
        for (int i = 0; i < v.size(); i++) {
            long double x, y, r;
            // number of intersecting artifacts (i intersects with itself)
            int count = 1;
            // we will keep the relevant information for merging here
            artifact entry;
            entry.x = v[i].x;
            entry.y = v[i].y;
            // merged artifact's radius
            entry.r = v[i].r * v[i].r;
            for (int j = 0; j < i; j++) {
                if (collision(v[i], v[j])) {
                    entry.x += v[j].x;
                    entry.y += v[j].y;
                    entry.r += v[j].r * v[j].r;
                    // remove as we go once we're done (brings us up to n^3)
                    v.erase(v.begin() + j);
                    // update our index accordingly. 
                    // Note this also affects i!
                    j--;
                    i--;
                    count++;
                }
            }

            // If we have a merge to take care of
            if (count > 1) {
                // Create the merged artifact and push it
                entry.x /= count;
                entry.y /= count;
                entry.r = sqrtl(entry.r);
                v.erase(v.begin() + i);
                // +1 -1 ommited
                v.insert(v.begin() + i, entry);
                i--; // we also need to update here
            }
        }
        cout << v.size() << endl;
    }
    return 0;
}
