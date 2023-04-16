#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Abstract base class for YouTube channels
class YouTubeChannel {
protected:
string channelName;
string channelId;
string channelOwner;
int subscriberCount;
vector<string> videoTitles;

public:
// Constructor
YouTubeChannel(string name, string id, string owner) {
channelName = name;
channelId = id;
channelOwner = owner;
subscriberCount = 0;
}
// Add a new video to the channel
void addVideo(string title) {
    videoTitles.push_back(title);
}

// Get the number of videos on the channel
int getVideoCount() {
    return videoTitles.size();
}

// Subscribe to the channel
void subscribe() {
    subscriberCount++;
}

// Unsubscribe from the channel
void unsubscribe() {
    subscriberCount--;
}

// Get the current number of subscribers
int getSubscriberCount() {
    return subscriberCount;
}

// Get the name of the channel
string getChannelName() {
    return channelName;
}

// Get the ID of the channel
string getChannelId() {
    return channelId;
}

// Get the owner of the channel
string getChannelOwner() {
    return channelOwner;
}

// Pure virtual function to watch a video on the channel
virtual void watchVideo() = 0;
};

// Subclass for cooking channels
class CookingChannel : public YouTubeChannel {
public:
CookingChannel(string name, string id, string owner) : YouTubeChannel(name, id, owner) {}
void watchVideo() override {
cout << "Watching a cooking video on " << channelName << endl;
}
};

// Subclass for sports channels
class SportsChannel : public YouTubeChannel {
public:
SportsChannel(string name, string id, string owner) : YouTubeChannel(name, id, owner) {}
void watchVideo() override {
cout << "Watching a sports video on " << channelName << endl;
}
};

// Subclass for news channels
class NewsChannel : public YouTubeChannel {
public:
NewsChannel(string name, string id, string owner) : YouTubeChannel(name, id, owner) {}
void watchVideo() override {
cout << "Watching a news video on " << channelName << endl;
}
};

// User class
class User {
private:
vector<YouTubeChannel*> subscriptionList;

public:
// Subscribe to a channel
void subscribe(YouTubeChannel* channel) {
channel->subscribe();
subscriptionList.push_back(channel);
cout << "Subscribed to " << channel->getChannelName() << endl;
}
// Unsubscribe from a channel
void unsubscribe(YouTubeChannel* channel) {
    channel->unsubscribe();
    for (int i = 0; i < subscriptionList.size(); i++) {
        if (subscriptionList[i] == channel) {
            subscriptionList.erase(subscriptionList.begin() + i);
            break;
        }
    }
    cout << "Unsubscribed from " << channel->getChannelName() << endl;
}

// Watch a video on a channel
void watchVideo(YouTubeChannel* channel) {
    channel->watchVideo();
}

// Print a list of subscribed channels
void showSubscriptionList() {
    cout << "Subscription List:" << endl;
    for (int i = 0; i < subscriptionList.size(); i++) {
        cout << i+1 << ". " << subscriptionList[i]->getChannelName() << " (" << subscriptionList[i]->getSubscriberCount() << " subscribers
            break;

        case 4:
            // Show subscription list
            user.showSubscriptionList();
            break;

        case 5:
            // Quit
            quit = true;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}

// Clean up memory
delete cookingChannel;
delete sportsChannel;
delete newsChannel;

return 0;
}
