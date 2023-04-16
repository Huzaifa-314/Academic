#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base YouTubeChannel class
class YouTubeChannel
{
protected:
    string name;
    string id;
    string owner;
    vector<string> videos;

public:
    int subscriberCount;
    YouTubeChannel(string n, string i, string o)
    {
        name = n;
        id = i;
        owner = o;
        subscriberCount = 0;
    }
    string getName()
    {
        return name;
    }
    int getSubscriberCount()
    {
        return subscriberCount;
    }
    void addVideo(string title)
    {
        videos.push_back(title);
    }
    virtual void watchVideo()
    {
        cout << "Watching video on " << name << endl;
    }
};

// CookingChannel class derived from YouTubeChannel
class CookingChannel : public YouTubeChannel
{
public:
    CookingChannel(string n, string i, string o) : YouTubeChannel(n, i, o) {}
};

// SportsChannel class derived from YouTubeChannel
class SportsChannel : public YouTubeChannel
{
public:
    SportsChannel(string n, string i, string o) : YouTubeChannel(n, i, o) {}
};

// NewsChannel class derived from YouTubeChannel
class NewsChannel : public YouTubeChannel
{
public:
    NewsChannel(string n, string i, string o) : YouTubeChannel(n, i, o) {}
};

// User class
class User
{
public:
    vector<YouTubeChannel*> subscriptions;
    void subscribe(YouTubeChannel* channel)
    {
        subscriptions.push_back(channel);
        channel->subscriberCount++;
    }
    void unsubscribe(YouTubeChannel* channel)
    {
        for (int i = 0; i < subscriptions.size(); i++)
        {
            if (subscriptions[i] == channel)
            {
                subscriptions.erase(subscriptions.begin() + i);
                channel->subscriberCount--;
                break;
            }
        }
    }
    void watchVideo(YouTubeChannel* channel)
    {
        channel->watchVideo();
    }
    void showSubscriptions()
    {
        for (int i = 0; i < subscriptions.size(); i++)
        {
            cout << subscriptions[i]->getName() << " - " << subscriptions[i]->getSubscriberCount() << " subscribers" << endl;
        }
    }
};

int main()
{
    User user;
    CookingChannel cooking("Cooking with Jane", "c1", "Jane");
    SportsChannel sports("SportsCenter", "s1", "ESPN");
    NewsChannel news("CNN News", "n1", "CNN");

    int choice;
    do
    {
        cout << "Select an option:\n";
        cout << "1. Subscribe to a channel\n";
        cout << "2. Unsubscribe from a channel\n";
        cout << "3. Watch a video\n";
        cout << "4. Show subscription list\n";
        cout << "5. Quit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int channelChoice;
            cout << "Select a channel to subscribe to:\n";
            cout << "1. Cooking with Jane\n";
            cout << "2. SportsCenter\n";
            cout << "3. CNN News\n";
            cin >> channelChoice;

            switch (channelChoice)
            {
            case 1:
                user.subscribe(&cooking);
                cout << "Subscribed to Cooking with Jane\n";
                break;
            case 2:
                user.subscribe(&sports);
                cout << "Subscribed to SportsCenter\n";
                break;
            case 3:
                user.subscribe(&news);
                cout << "Subscribed to CNN News\n";
                break;
            }
            break;
        }
        case 2:
        {
            int channelChoice;
            cout << "Select a channel to unsubscribe from:\n";
            for (int i = 0; i < user.subscriptions.size(); i++)
            {
                cout << i + 1 << ". " << user.subscriptions[i]->getName() << endl;
            }
            cin >> channelChoice;
            user.unsubscribe(user.subscriptions[channelChoice - 1]);
            cout << "Unsubscribed from " << user.subscriptions[channelChoice - 1]->getName() << endl;
            break;
        }
        case 3:
        {
            int channelChoice;
            cout << "Select a channel to watch a video on:\n";
            for (int i = 0; i < user.subscriptions.size(); i++)
            {
                cout << i + 1 << ". " << user.subscriptions[i]->getName() << endl;
            }
            cin >> channelChoice;
            user.watchVideo(user.subscriptions[channelChoice - 1]);
            break;
        }
        case 4:
            user.showSubscriptions();
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }

    }
    while (choice != 5);

    return 0;
}
