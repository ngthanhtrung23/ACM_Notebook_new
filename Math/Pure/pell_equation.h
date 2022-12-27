#include "../../Misc/int128.h"

// From https://github.com/zimpha/algorithmic-library/blob/master/cpp/mathematics/pell.py
// Find minimum solution for x^2 - d*y^2 = 1 (d <= 1000)
// Pell equation {{{
void up(i128& ai, i128& aim, i128 alpha) {
    i128 old_ai = ai;
    ai = alpha * ai + aim;
    aim = old_ai;
}
pair<vector<i128>,i128> pqa(i128 p0, i128 q0, int d) {
    double sqrt_d = sqrt(d);
    i128 p_i = p0, q_i = q0;
    i128 p_ir = LLONG_MIN, q_ir = LLONG_MIN;
    i128 i = -1, ir = LLONG_MIN;
    vector<i128> alphas;

    while (1) {
        ++i;
        double xi_i = (p_i + sqrt_d) / q_i;
        double xibar_i = (p_i - sqrt_d) / q_i;
        i128 alpha_i = xi_i + 1e-9;

        if (ir == LLONG_MIN && 1 < xi_i && -1 < xibar_i && xibar_i < 0) {
            ir = i;
            p_ir = p_i;
            q_ir = q_i;
        }
        if (ir != LLONG_MIN && ir != i && p_i == p_ir && q_i == q_ir) {
            break;
        }
        alphas.push_back(alpha_i);
        p_i = alpha_i * q_i - p_i;
        q_i = (d - p_i * p_i) / q_i;
    }
    return {alphas, i - ir};
}

// return minimum solution for x^2 - d*y^2 = 1
pair<i128,i128> pell(int d) {
    auto [alphas, l] = pqa(0, 1, d);

    int index = (l % 2 == 1) ? 2*l-1 : l-1;

    i128 b_i = 0, b_im = 1;
    i128 g_i = 1, g_im = 0;
    int pl = alphas.size() - l;

    for (int i = 0; i <= index; ++i) {
        i128 alpha_i;
        if (i < pl) alpha_i = alphas[i];
        else alpha_i = alphas[pl + (i - pl) % l];

        up(b_i, b_im, alpha_i);
        up(g_i, g_im, alpha_i);
    }
    return {g_i, b_i};
}
// }}}
