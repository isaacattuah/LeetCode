class Solution:
    def watchedVideosByFriends(self, watchedVideos: List[List[str]], friends: List[List[int]], id: int, level: int) -> List[str]:
        visited = [False] * 100
        visited[id] = True
        queue = collections.deque([id])
        count = collections.Counter()

        for _ in range(level):
            for _ in range(len(queue)):
                for friend in friends[queue[0]]:
                    if visited[friend] == False:
                        visited[friend] = True
                        queue.append(friend)
                queue.popleft()

        for friend in queue:
            for video in watchedVideos[friend]:
                count[video] += 1

        return sorted(count.keys(), key=lambda video: (count[video], video))
