type Tweet = { userId: number; tweetId: number };

class Twitter {
  tweets: Tweet[]; // all the tweets

  following: Map<number, Set<number>>; // user a -> users followed by a

  constructor() {
    this.tweets = [];
    this.following = new Map<number, Set<number>>();
  }

  postTweet(userId: number, tweetId: number): void {
    this.tweets.push({ userId, tweetId });
  }

  getNewsFeed(userId: number): number[] {
    const n = this.tweets.length;
    const res: number[] = [];
    let cnt = 0;

    for (let i = n - 1; i >= 0 && cnt < 10; i--) {
      const tweet = this.tweets[i];

      const isFollowing =
        this.following.has(userId) && this.following.get(userId)?.has(tweet.userId);

      if (tweet.userId === userId || isFollowing) {
        res.push(tweet.tweetId);
        cnt++;
      }
    }

    return res;
  }

  follow(followerId: number, followeeId: number): void {
    if (!this.following.has(followerId)) {
      this.following.set(followerId, new Set<number>());
    }

    this.following.get(followerId)?.add(followeeId);
  }

  unfollow(followerId: number, followeeId: number): void {
    if (this.following.has(followerId)) {
      this.following.get(followerId)?.delete(followeeId);
    }
  }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * var obj = new Twitter()
 * obj.postTweet(userId,tweetId)
 * var param_2 = obj.getNewsFeed(userId)
 * obj.follow(followerId,followeeId)
 * obj.unfollow(followerId,followeeId)
 */
