int nonDivisibleSubset(int k, vector<int> S) {
    if (k == 1)
        return 1;
    else {
        vector<int> R; //amortized set
        map<int, int> occ;
        occ[-1] = 0;
        for (int i = 0; i < S.size(); i++) {
            int r = S[i] % k;
            auto it = occ.find(r);
            if (it == occ.end()) {
                occ[r] = 1;
                R.push_back(r);
            } else
                occ[r] = it->second + 1;
        }
        for (int i = 0; i < R.size() - 1; i++) {
            int curr = R[i];
            if (curr == -1)
                continue;
            for (int j = i + 1; j < R.size(); j++) {
                int target = R[j];
                if (target == -1)
                    continue;
                if (curr + target == k) {
                    if (occ[curr] >= occ[target]) {
                        occ[-1] = occ[-1] + occ[target];
                        R[j] = -1;
                    } else {
                        occ[-1] = occ[-1] + occ[curr];
                        R[i] = -1;
                    }
                }
            }
        }

        for (int i = 0; i < R.size(); i++) { //super important clean up
            if (R[i] != -1) {
                if (occ[R[i]] >= 2) {
                    if (2 * R[i] == k || 2 * R[i] == 0)
                        occ[-1] = occ[-1] + (occ[R[i]] - 1); //I'll take them all out but one
                }
            }
        }

        int len = S.size() - occ[-1];
        return len;
    }
}
