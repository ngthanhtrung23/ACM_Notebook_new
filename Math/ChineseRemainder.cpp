bool linearCongruences(const vector<Int> &a, const vector<Int> &b, 
         const vector<Int> &m, Int &x, Int &M) {  
   int n =     a.size();
   x = 0; M = 1;
   REP(i, n) {
      Int a_ = a[i] % M, b_ = b[i] - a[i] * x, m_ = m[i];
      Int y, t, g = extgcd(a_, m_, y, t);
      if (b_ % g) return false;
      b_ /= g; m_ /= g;
      x += M * (y * b_ % m_);
      M *= m_;
   }
   x = (x + M) % M;
   return true;
}