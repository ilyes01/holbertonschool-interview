#!/usr/bin/python3
""" sorted count of given keywords """
import requests


def count_words(subreddit, word_list, count={}, after=""):
  """ funtion that count keywords in subredit hot list's titles"""
    if len(count) <= 0:
        for item in word_list:
            count[item] = 0

    if after is None:
        word_list = [[key, value] for key, value in count.items()]
        word_list = sorted(word_list, key=lambda x: (-x[1], x[0]))
        for k in word_list:
            if k[1]:
                print("{}: {}".format(k[0].lower(), k[1]))
        return None
    url = "https://www.reddit.com/r/{}/hot/.json".format(subreddit)
    params = { 'after': after}
    headers = {'user-agent': 'ilyes'}
    res = requests.get(
        url,
        headers=headers,
        params=params,
        allow_redirects=False,
    )

    if res.status_code == 200:
        after = res.json().get("data").get("after")
        children = res.json().get("data").get("children")
        for posts in children:
            title = posts.get("data").get("title")
            t = [str.lower() for str in title.split(' ')]
            for word in word_list:
                count[word] += t.count(word.lower())
    else:
        return None
    count_words(subreddit, word_list, count, after)
