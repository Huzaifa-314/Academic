#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif




using namespace std;

struct Channel
{
    string name,id,owner;
    vector<string> videos;
    int s_c;
};

struct User
{
    string name,username;
    vector<string> subscription;
};

void create_channel(Channel& channel)
{
    cout << "Input Channel Data:\n";
    cout << "Channel name: ";
    getline(cin, channel.name);
    cout << "Channel id: ";
    getline(cin, channel.id);
    cout << "Owner name: ";
    getline(cin, channel.owner);
    cout << "Initial subscribers: ";
    cin >> channel.s_c;
    cin.ignore();
    cout << "Total videos: ";
    int n_v;
    cin >> n_v;
    cin.ignore();
    cout << "Enter video titles:\n";
    for (int i = 0; i < n_v; i++)
        {
         string title;
         getline(cin, title);
         channel.videos.push_back(title);
        }
}

void display_channel(const Channel& channel)
{
    cout << "Channel name: " << channel.name << endl;
    cout << "ID: " << channel.id << endl;
    cout << "Channel Owner: " << channel.owner << endl;
    cout << "Total Subscribers: " << channel.s_c << endl;
    cout << "Total Videos: " << channel.videos.size() << endl;
    for (const string& title : channel.videos)
        {
         cout << title << endl;
        }
}

void subscribe(vector<Channel>& channels, User& user)
{
    cout << "Which channel do you want to subscribe to?" << endl;
    for (int i = 0; i < channels.size(); i++)
    {
        cout << i + 1 << ". " << channels[i].name << endl;
    }
    int choice;
    cin >> choice;
    if (choice < 1 || choice > channels.size())
    {
        cout << "Invalid choice" << endl;
        return;
    }
    Channel& channel = channels[choice - 1];
    if (find(user.subscription.begin(), user.subscription.end(), channel.name) != user.subscription.end())
    {
        // Channel is already subscribed
        cout << "You are already subscribed to " << channel.name << endl;
        return;
    }
    user.subscription.push_back(channel.name);
    channel.s_c++;
    cout << "Updated total subscribers for " << channel.name << ": " << channel.s_c << endl;
    cout << "Updated subscription list " << user.name << ": " << endl;
    for (const string& name : user.subscription)
    {
        cout << name << endl;
    }
}


void unsubscribe(vector<Channel>& channels, User& user)
{
    cout << "Which channel do you want to unsubscribe from?" << endl;
    for (int i = 0; i < user.subscription.size(); i++)
    {
        cout << i + 1 << ". " << user.subscription[i] << endl;
    }
    int choice;
    cin >> choice;
    if (choice < 1 || choice > user.subscription.size())
    {
        cout << "Invalid choice" << endl;
        return;
    }
    string& name = user.subscription[choice - 1];
    for (Channel& channel : channels)
    {
        if (channel.name == name)
        {
            channel.s_c--;
            break;
        }
    }
    user.subscription.erase(user.subscription.begin() + choice - 1);
    cout << "Updated subscription list " << user.name << ": " << endl;
    for (const string& name : user.subscription)
    {
        cout << name << endl;
    }
}

int main()
{
    system(CLEAR);
    vector<Channel> channels;
    User user;
    while (true)
    {
        cout << "\nSelect an option:\n";
        cout << "1. Create a new channel\n";
        cout << "2. Display all channels\n";
        cout << "3. Subscribe\n";
        cout << "4. Unsubscribe\n";
        cout << "5. Display user subscription\n";
        cout << "6. Quit\n";
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
            case 1:
{
    system(CLEAR);
    Channel channel;
    create_channel(channel);
    channels.push_back(channel);
    cout << "New channel created:\n";
    display_channel(channel);
    break;
}
case 2:
{
    system(CLEAR);
    cout << "\nAll channels:\n";
    for (const Channel& channel : channels)
    {
        display_channel(channel);
        cout << endl;
    }
    break;
}
case 3:
{
    system(CLEAR);
    subscribe(channels, user);
    break;
}
case 4:
{
    system(CLEAR);
    unsubscribe(channels, user);
    break;
}
case 5:
{
    system(CLEAR);
    cout << "\nUser subscription:\n";
    for (const string& name : user.subscription)
    {
        cout << name << endl;
    }
    break;
}
case 6:
{
    system(CLEAR);
    cout << "Quiting program\n";
    return 0;
}

        }
    }
    return 0;
}
