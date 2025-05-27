#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <iomanip>
#include <algorithm>
using namespace std;

class Team
{
public:
	int times = 0, count = 0;
	std::string name;
	// Time to solve each problem, -1 means not solved
	std::vector<int> problems;
};

void rank_teams(std::vector<Team> &teams)
{
	for (int i = 0; i < teams.size(); i++)
	{
		for (int j = 0; j < teams[i].problems.size(); j++)
		{
			if (teams[i].problems[j] != -1)
			{
				teams[i].times += teams[i].problems[j];
				teams[i].count++;
			}
		}
		// cout << teams[i].times << " " << teams[i].count << " ";
	}
	sort(teams.begin(), teams.end(), [](Team a, Team b) {
		if (a.count == b.count)
		{
			return a.times < b.times;
		}
		return a.count > b.count;
	});
	// cout << endl;
};
