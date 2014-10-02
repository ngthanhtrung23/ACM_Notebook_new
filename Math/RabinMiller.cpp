bool suspect(Int a, int s, Int d, Int n) {
   Int x = powMod(a, d, n);
   if (x == 1) return true;
   for (int r = 0; r < s; ++r) {
      if (x == n - 1) return true;
      x = x * x % n;
   }
   return false;
}
// {2,7,61,-1}                 is for n < 4759123141 (= 2^32)
// {2,3,5,7,11,13,17,19,23,-1} is for n < 10^16 (at least)
bool isPrime(Int n) {
   if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
   int test[] = {2,3,5,7,11,13,17,19,23,-1};
   Int d = n - 1, s = 0;
   while (d % 2 == 0) ++s, d /= 2;
   for (int i = 0; test[i] < n && test[i] != -1; ++i)
      if (!suspect(test[i], s, d, n)) return false;
   return true;
}