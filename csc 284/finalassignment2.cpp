#include <iostream>
#include <string>
#include <vector>

using namespace std;
class YouTubeChannel
{
protected:
    string channelName;
    string channelId;
    string channelOwner;
    int subscriberCount;
    vector<string> videoTitles;

public:
    YouTubeChannel(string name, string id, string owner)
    {
        channelName = name;
        channelId = id;
        channelOwner = owner;
        subscriberCount = 0;
    }

    void addVideo(string title)
    {
        videoTitles.push_back(title);
    }
    int getVideoCount()
    {
        return videoTitles.size();
    }
    void subscribe()
    {
        subscriberCount++;
    }
    void unsubscribe()
    {
        subscriberCount--;
    }
    int getSubscriberCount()
    {
        return subscriberCount;
    }

    // Get the name of the channel
    string getChannelName()
    {
        return channelName;
    }
    string getChannelId()
    {
        return channelId;
    }
    string getChannelOwner()
    {
        return channelOwner;
    }
    virtual void watchVideo() = 0;
};
class CookingChannel : public YouTubeChannel
{
public:
    CookingChannel(string name, string id, string owner) : YouTubeChannel(name, id, owner) {}
    void watchVideo() override
    {
        cout << "Watching a cooking video on " << channelName << endl;
    }
};
class SportsChannel : public YouTubeChannel
{
public:
    SportsChannel(string name, string id, string owner) : YouTubeChannel(name, id, owner) {}
    void watchVideo() override
    {
        cout << "Watching a sports video on " << channelName << endl;
    }
};
class NewsChannel : public YouTubeChannel
{
public:
    NewsChannel(string name, string id, string owner) : YouTubeChannel(name, id, owner) {}
    void watchVideo() override
    {
        cout << "Watching a news video on " << channelName << endl;
    }
};
class User
{

public:
    vector<YouTubeChannel*> subscriptionList;
    void subscribe(YouTubeChannel* channel)
    {
        channel->subscribe();
        subscriptionList.push_back(channel);
        cout << "Subscribed to " << channel->getChannelName() << endl;
    }
    void unsubscribe(YouTubeChannel* channel)
    {
        channel->unsubscribe();
        for (int i = 0; i < subscriptionList.size(); i++)
        {
            if (subscriptionList[i] == channel)
            {
                subscriptionList.erase(subscriptionList.begin() + i);
                break;
            }
        }
        cout << "Unsubscribed from " << channel->getChannelName() << endl;
    }
    void watchVideo(YouTubeChannel* channel)
    {
        channel->watchVideo();
    }
    void showSubscriptionList()
    {
        cout << "Subscription List:" << endl;
        for (int i = 0; i < subscriptionList.size(); i++)
        {
            cout << i+1 << ". " << subscriptionList[i]->getChannelName() << " (" << subscriptionList[i]->getSubscriberCount() << " subscribers)" << endl;
        }
    }
};

int main()
{
    CookingChannel* cookingChannel = new CookingChannel("Cooking with Jane", "1234", "Jane");
    cookingChannel->addVideo("How to Make Pancakes");
    cookingChannel->addVideo("The Perfect Scrambled Eggs");
    SportsChannel* sportsChannel = new SportsChannel("Sports Highlights", "5678", "John");
    sportsChannel->addVideo("Best Goals of the Season");
    sportsChannel->addVideo("NBA Playoffs Recap");

    NewsChannel* newsChannel = new NewsChannel("World News Today", "9012", "Kate");
    newsChannel->addVideo("Breaking News: Earthquake in Japan");
    newsChannel->addVideo("Politics Roundup: Elections Results");

    User user;

    bool quit = false;
    while (!quit)
    {
        cout << endl << "Menu:" << endl;
        cout << "1. Subscribe to a channel" << endl;
        cout << "2. Unsubscribe from a channel" << endl;
        cout << "3. Watch a video" << endl;
        cout << "4. Show subscription list" << endl;
        cout << "5. Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Choose a channel to subscribe to:" << endl;
            cout << "1. " << cookingChannel->getChannelName() << endl;
            cout << "2. " << sportsChannel->getChannelName() << endl;
            cout << "3. " << newsChannel->getChannelName() << endl;
            int channelChoice;
            cout << "Enter your choice: ";
            cin >> channelChoice;
            switch (channelChoice)
            {
            case 1:
                user.subscribe(cookingChannel);
                break;
            case 2:
                user.subscribe(sportsChannel);
                break;
            case 3:
                user.subscribe(newsChannel);
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
            }
            break;
        case 2:
            cout << "Choose a channel to unsubscribe from:" << endl;
            user.showSubscriptionList();
            int unsubscribeChoice;
            cout << "Enter your choice: ";
            cin >> unsubscribeChoice;
            if (unsubscribeChoice >= 1 && unsubscribeChoice <= user.subscriptionList.size())
            {
                user.unsubscribe(user.subscriptionList[unsubscribeChoice-1]);
            }
            else
            {
                cout << "Invalid choice." << endl;
            }
            break;
        case 3:
            cout << "Choose a channel to watch a video on:" << endl;
            user.showSubscriptionList();
            int watchChoice;
            cout << "Enter your choice: ";
            cin >> watchChoice;
            if (watchChoice >= 1 && watchChoice <= user.subscriptionList.size())
            {
                user.watchVideo(user.subscriptionList[watchChoice-1]);
            }
            else
            {
                cout << "Invalid choice." << endl;
            }
            break;
        case 4:
            user.showSubscriptionList();
            break;
        case 5:

            quit = true;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
    delete cookingChannel;
    delete sportsChannel;
    delete newsChannel;

    return 0;
}
