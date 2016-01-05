int S = 500;
bool cmp(Query A, Query B)
{
  if (A.l / S ！= B.l / S) return A.l / S < B.l / S;
  return A.r > B.r
}

