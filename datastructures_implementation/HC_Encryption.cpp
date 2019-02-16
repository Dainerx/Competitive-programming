string encryption(string S) {

    string Sp;
    for (int i = 0; i < S.size(); i++)
        if (S[i] >= 97 && S[i] <= 97 + 26)
            Sp += S[i];

    float SRL = sqrt(Sp.size());
    int R, C;
    if (floor(SRL) == SRL) {
        R = C = floor(SRL);
    } else {
        R = floor(SRL);
        C = ceil(SRL);
        if (R * C < Sp.size())
            R = C;
    }

    vector< vector<char> > M(R);
    for (int i = 0; i < R; i++) {
        M[i].resize(C);
        for (int j = 0; j < C; j++) {
            if ((C * i + j) <= Sp.size())
                M[i][j] = Sp[C * i + j];
        }
    }

    string result;
    for (int c = 0; c < M[c].size(); c++) {
        for (int r = 0; r < M.size(); r++) {
            if (M[r][c]!='\0')
                result+= M[r][c];
        }
        if (c < C - 1 )
            result+=  " ";
    }

    return result;

}
