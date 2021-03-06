#include <bits/stdc++.h>

using namespace std;

int edit_distance(const string &str1, const string &str2)
{
  vector<vector<int>> table(str1.size() + 1, vector<int>(str2.size() + 1));

  for (int i = 0; i <= str1.size(); i++)
  {
    for (int j = 0; j <= str2.size(); j++)
    {
      if (i == 0)
      {
        table[i][j] = j;
      }
      else if (j == 0)
      {
        table[i][j] = i;
      }
      else if (str1[i - 1] == str2[j - 1])
      {
        table[i][j] = table[i - 1][j - 1];
      }
      else
      {
        table[i][j] = 1 + min(min(table[i][j - 1], table[i - 1][j]), table[i - 1][j - 1]);
      }
    }
  }

  return table[str1.size()][str2.size()];
}

int main()
{
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
