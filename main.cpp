#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol256;

/*
Input: [[17,2,17],[16,16,5],[14,3,19]]
Output: 10
Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue.
             Minimum cost: 2 + 5 + 3 = 10.
*/
tuple<vector<vector<int>>, int>
testFixture1()
{
  auto costs = vector<vector<int>>{
      {17, 2, 17}, {16, 16, 5}, {14, 3, 19}};

  return make_tuple(costs, 10);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::minCost(get<0>(f));
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  return 0;
}