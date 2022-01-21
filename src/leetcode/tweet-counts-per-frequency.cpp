#include <bits/stdc++.h>
using namespace std;

class TweetCounts
{
    unordered_map<string, vector<int>> tC;

    function<int(char)> getInterval = [](char s)
    {
        return s == 'm' ? 60 : (s == 'h' ? 3600 : 3600 * 24);
    };

public:
    TweetCounts()
    {
        tC.clear();
    }

    void recordTweet(string tweetName, int time)
    {
        tC[tweetName].insert(upper_bound(begin(tC[tweetName]), end(tC[tweetName]), time), time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)
    {
        int interval = getInterval(freq[0]);
        int time = startTime - 1;
        auto intervalStart = upper_bound(begin(tC[tweetName]), end(tC[tweetName]), time);

        vector<int> res;
        while (time < endTime)
        {
            time = min(endTime, time + interval);
            auto intervalEnd = upper_bound(intervalStart, end(tC[tweetName]), time);

            res.push_back(intervalEnd - intervalStart);
            intervalStart = intervalEnd;
        }
        return res;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */