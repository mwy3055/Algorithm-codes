// 초밥 벨트: vector 불가능. map<int, multiset<string>>?
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <stack>

int l, q;

struct customer
{
    int enter_time, x, n, eat_count;
    std::string name;

    customer(int t, int x, std::string &name, int n) : enter_time(t), x(x), name(name), n(n), eat_count(0) {}
    customer() = default;

    bool all_eat()
    {
        return this->eat_count == this->n;
    }
};

struct sushi
{
    int enter_time, x;
    std::string name;

    sushi(int t, int x, std::string &name) : enter_time(t), x(x), name(name) {}
    sushi() = default;

    int index_when(int t)
    {
        auto time_past = t - enter_time;
        return (x + time_past) % l;
    }
};

// std::unordered_map<std::string, std::vector<sushi>> sushi_belt; // 초밥 벨트에서, 초밥이 처음 놓인 위치
std::unordered_map<std::string, std::unordered_map<int, sushi>> sushi_belt; // enter_time
std::unordered_map<std::string, customer> customers;                        // 손님

void getinput()
{
    std::cin >> l >> q;
}

// b가 [a, c] 구간 안에 있는가?
bool is_between(int a, int b, int c)
{
    return a <= b && b <= c;
}

void eat_sushi(int t, customer &c)
{
    std::unordered_set<int> eat_sushies;
    for (auto &[enter_time, sushi1] : sushi_belt[c.name])
    {
        auto sushi_customer_enter_time = std::max(sushi1.enter_time, c.enter_time);

        int start_index = sushi1.index_when(sushi_customer_enter_time);
        int end_index = start_index + (t - sushi_customer_enter_time);
        int customer_index = c.x;

        // 무조건 되는 상황
        if ((t - sushi_customer_enter_time >= l) ||
            (end_index >= l && (end_index % l) < start_index && (is_between(start_index, customer_index, l - 1) || is_between(0, customer_index, end_index % l))) ||
            (end_index < l && is_between(start_index, customer_index, end_index)))
        {
            eat_sushies.insert(enter_time);
            c.eat_count++;
        }
    }

    for (auto &es : eat_sushies)
    {
        sushi_belt[c.name].erase(es);
    }
}

void eat_sushi(int t)
{
    std::vector<std::string> leave;
    // 고객이 온 시점부터 t까지 전부 먹기
    for (auto &[name, customer1] : customers)
    {
        // 먹기
        // 스시가 [enter_time, t] 안에 이 고객을 지나갈까?
        eat_sushi(t, customer1);

        // 다 먹었으면,
        if (customer1.all_eat())
        {
            leave.push_back(name);
        }
    }

    for (auto &leave_name : leave)
    {
        customers.erase(leave_name);
    }
}

void make_sushi(int t, int x, std::string &name)
{
    auto new_sushi = sushi(t, x, name);
    if (sushi_belt.find(name) == sushi_belt.end())
    {
        std::unordered_map<int, sushi> sushi_with_name;
        sushi_with_name[t] = new_sushi;
        sushi_belt[name] = sushi_with_name;
    }
    else
    {
        sushi_belt[name][t] = new_sushi;
    }
}

void customer_comes(int t, int x, std::string &name, int n)
{
    customers[name] = customer(t, x, name, n);
}

void take_photo(int t)
{
    // 남아있는 사람, 초밥 수 출력
    int customers_count = 0, sushi_count = 0;
    for (auto &[name, sushies] : sushi_belt)
    {
        sushi_count += sushies.size();
    }
    for (auto &value : customers)
    {
        customers_count++;
    }
    std::cout << customers_count << ' ' << sushi_count << '\n';
}

void solve()
{
    for (int i = 0; i < q; i++)
    {
        int type, t;
        std::cin >> type >> t;
        if (type == 100)
        {
            int x;
            std::string name;
            std::cin >> x >> name;
            make_sushi(t, x, name);
        }
        else if (type == 200)
        {
            // x에 사람 놓기
            int x, n;
            std::string name;
            std::cin >> x >> name >> n;
            customer_comes(t, x, name, n);
        }
        else if (type == 300)
        {
            // 시점 t까지 초밥 먹기
            eat_sushi(t);
            // 사진 찍기
            take_photo(t);
        }
        else
            exit(-1);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}