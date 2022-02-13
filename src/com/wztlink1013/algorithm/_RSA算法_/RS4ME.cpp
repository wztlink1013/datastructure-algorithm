// 模幂运算反复平方算法
#include <stdio.h>
#include <vector>
namespace NS_RS4ME {
using namespace std;
vector<int> GetBits(int b);
int RS4ME(int a, int b, int n)
{
  auto bits = GetBits(b);
  int c = 0;
  int d = 1;
  for (int k = bits.size() - 1; k >= 0; k--)
  {
    c *= 2;
    d = d * d % n;
    if (bits[bits.size() - 1 - k])
    {
      c++;
      d = d * a % n;
    }
  }
  return d;
}
vector<int> GetBits(int b)
{
  vector<int> bits;
  while (b)
  {
    bits.insert(bits.begin(), b & 1);
    b >>= 1;
  }
  return bits;
}
} //namespace NS_RS4ME
using namespace NS_RS4ME;
int main()
{
  vector<vector<int>> abn = {
    {2, 40, 13}, //3
    {2, 50, 13}, //4
  };
  int N = abn.size();
  for (int i = 0; i < N; i++) {
    printf("%2d: \n", i + 1);
    int a = abn[i][0];
    int b = abn[i][1];
    int n = abn[i][2];
    printf(" a=%d, b=%d, n=%d.\n", a, b, n);
    int d = RS4ME(a, b, n);
    printf(" %d^%d mod %d = %d\n\n", a, b, n, d);
  }
}