#include <bits/stdc++.h>

using rooms_t = std::vector<std::vector<int>>;

// check if all the roooms can be accessed
// a room cannot be accessed if:
// the key ifor that room is in the room itself
// the key does not exist
// note that the room 0 is not locked, then there are
// n -1 keys where n is the size of the hotel

// visit rooms in any order and keep track of
// rooms already visited. Return result
// visited == total_rooms
bool solution(rooms_t &rooms)
{
    const auto total_rooms{rooms.size()};
    std::set<int> visited_rooms{};

    std::function<int(int)> visit = [&](const int k)
    {
        int acc{0};
        std::cerr << "passed key: " << k << std::endl;
        auto res{visited_rooms.insert(k)};
        if (res.second)
        {

            std::cerr << "Visiting: " << k << std::endl;
            for (const auto &key : rooms[k])
            {
                acc += visit(key);
            }
        }
        return acc;
    };

    visit(0);
    return visited_rooms.size() == total_rooms;
}

bool solutionb(rooms_t &rooms)
{
    const auto total_rooms{rooms.size()};
    std::vector<char> visited_rooms(total_rooms, 0);
    std::function<int(int)> visit = [&](const int k)
    {
        int acc{0};
        visited_rooms[k] = 1;
        for (const auto &key : rooms[k])
        {
            if (!visited_rooms[key])
            {
                acc += visit(key);
            }
        }
        return acc;
    };
    visit(0);

    for (const auto &r : visited_rooms)
    {
        if (!r)
        {
            return false;
        }
    }
    return true;
    // this seems to be slower than the loop above
    // return std::all_of(visited_rooms.begin(), visited_rooms.end(), [](char i){return !!i;});
}

// loop version
/**
 * @brief
 *
 * @return int
 *
 * class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        boolean[] seen = new boolean[rooms.size()];
        seen[0] = true;
        Stack<Integer> stack = new Stack();
        stack.push(0);

        //At the beginning, we have a todo list "stack" of keys to use.
        //'seen' represents at some point we have entered this room.
        while (!stack.isEmpty()) { // While we have keys...
            int node = stack.pop(); // Get the next key 'node'
            for (int nei: rooms.get(node)) // For every key in room # 'node'...
                if (!seen[nei]) { // ...that hasn't been used yet
                    seen[nei] = true; // mark that we've entered the room
                    stack.push(nei); // add the key to the todo list
                }
        }

        for (boolean v: seen)  // if any room hasn't been visited, return false
            if (!v) return false;
        return true;
    }
}

bool solution_it(rooms_t &rooms)
{
    const auto total_rooms{rooms.size()};

    std::function<int(int)> visit = [&](const int k)
    {
        int acc{0};
        std::cerr << "passed key: " << k << std::endl;
        auto res{visited_rooms.insert(k)};
        if (res.second)
        {

            std::cerr << "Visiting: " << k << std::endl;
            for (const auto &key : rooms[k])
            {
                acc += visit(key);
            }
        }
        return acc;
    };

    visit(0);
    return visited_rooms.size() == total_rooms;
}

 */
int main()
{
    rooms_t rooms_notall{
        {1, 3},
        {3, 0, 1},
        {2},
        {0},
    };
    rooms_t rooms_seq{
        {1},
        {2},
        {3},
        {},
    };
    rooms_t rooms_allfirst{
        {2, 3, 1},
        {},
        {},
        {},
    };
    rooms_t rooms{
        {3},
        {2},
        {},
        {1},
    };

    if (solution(rooms))
    {
        std::cerr << "ALL visited\n";
    }
    else
    {
        std::cerr << "Not all visited\n";
    }
    std::cerr << "sdfsf" << std::endl;
}
