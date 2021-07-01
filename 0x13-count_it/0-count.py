#!/usr/bin/python3
"""
Queries the Reddit API
"""

import requests


def count_words(subreddit, word_list, after='', words_counting={}):
    """Queries the Reddit API"""
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    h = {'User-Agent': 'python3:holberton.task:v1.0'}
    payload = {'limit': '100', 'after': after}
    r = requests.get(url, headers=h, params=payload, allow_redirects=False)

    if r.status_code == 200:
        data = r.json().get('data')
        children = data.get('children')
        after = data.get('after')

        for cnt in children:
            title = cnt.get('data').get('title')

            for mv in word_list:
                match = title.lower().split().count(mv.lower())

                if match > 0:
                    if mv in words_counting:
                        words_counting[mv] += match

                    else:
                        words_counting[mv] = match

        if after is not None:
            return count_words(subreddit, word_list, after, words_counting)

        else:
            if not len(words_counting) > 0:
                return

            datas = sorted(words_counting.items(),
                           key=lambda key_value: (-key_value[1], key_value[0]))
            for key, value in datas:
                print('{}: {}'.format(key.lower(), value))
    else:
        return
