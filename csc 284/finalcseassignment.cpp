#include <iostream>
#include <string>
#include <vector>

using namespace std;

class YouTubeChannel {
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
};

int main() {
    // Create a new YouTube channel object
    YouTubeChannel myChannel("MyChannel", "123", "Me");

    // Add some videos to the channel
    myChannel.addVideo("Video 1");
    myChannel.addVideo("Video 2");

    // Subscribe to the channel
    myChannel.subscribe();

    // Print some information about the channel
    cout << "Channel Name: " << myChannel.getChannelName() << endl;
    cout << "Channel ID: " << myChannel.getChannelId() << endl;
    cout << "Channel Owner: " << myChannel.getChannelOwner() << endl;
    cout << "Video Count: " << myChannel.getVideoCount() << endl;
    cout << "Subscriber Count: " << myChannel.getSubscriberCount() << endl;

    // Unsubscribe from the channel
    myChannel.unsubscribe();

    // Print the updated subscriber count
    cout << "Subscriber Count: " << myChannel.getSubscriberCount() << endl;

    return 0;
}
