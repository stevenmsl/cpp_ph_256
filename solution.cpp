#include "solution.h"
#include "util.h"
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>

using namespace sol256;
using namespace std;

/*takeaways
  - basic dynamic programming
*/
int Solution::minCost(vector<vector<int>> &costs)
{
  const auto n = (int)costs.size();
  /*
    - minimum accumulated costs by house and colors
    - add one more dimension to simplify
      coding. we don't really care for what's
      in h[0]
  */
  auto h = vector<vector<int>>(n + 1, vector<int>(3, 0));
  for (int i = 1; i <= n; i++)
  {
    /*
      - the total minimum cost to paint the nth house
        with color 0 is the cost of painting it with
        color 0 plus the minimum total cost of painting
        the previous house with different colors
      - notice that index of the nth house in the costs
        vector is actually n-1
    */
    h[i][0] = costs[i - 1][0] + min(h[i - 1][1], h[i - 1][2]);
    h[i][1] = costs[i - 1][1] + min(h[i - 1][0], h[i - 1][2]);
    h[i][2] = costs[i - 1][2] + min(h[i - 1][0], h[i - 1][1]);
  }

  /* pick the minimum one among different colors */
  return min(h[n][0], min(h[n][1], h[n][2]));
}
