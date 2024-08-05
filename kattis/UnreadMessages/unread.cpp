#include <iostream>

int main()
{
    int n, m;
    std::cin >> n >> m;
    long int* friends_to_last_seen = new long int[n+1];
    long int num_unread = 0;
    long int friend_sent;
    for (long int i = 1; i <= m; i++)
    {
        std::cin >> friend_sent;
        num_unread -= i - friends_to_last_seen[friend_sent];
        friends_to_last_seen[friend_sent] = i;
        num_unread += n;
        std::cout << num_unread << std::endl;
    }
    delete[] friends_to_last_seen;
}
