#include <string>
#include <vector>
#include <utility>
#include <map>
class Employee
{
public:
    std::string name;
    int age;
    int salary;
    std::string department;
};

std::vector<std::pair<std::string, int>>
calculate_average(const std::vector<Employee> &employees)
{
    std::vector<std::pair<std::string, int>> average;
    for (int i = 0; i < employees.size(); i++)
    {

        if (average.size() != 0)
        {
            bool flag = false;
            for (int j = 0; j < average.size(); j++)
            {
                if (average[j].first == employees[i].department)
                {
                    flag = true;
                    average[j].second += employees[i].salary;
                    break;
                }
            }
            if (flag == false)
            {
                average.push_back(std::make_pair(employees[i].department, employees[i].salary));
            }
        }
        else
        {
            average.push_back(std::make_pair(employees[i].department, employees[i].salary));
        }
    }
    std::map<std::string, int> m;
    for (int i = 0; i < employees.size(); i++)
    {
        m[employees[i].department]++;
    }
    for (int i = 0; i < average.size(); i++)
    {
        average[i].second /= m[average[i].first];
    }
    return average;
};
