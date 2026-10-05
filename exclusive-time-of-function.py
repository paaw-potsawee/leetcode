# https://leetcode.com/problems/exclusive-time-of-functions/description/
class Solution:
    def exclusiveTime(self, n: int, logs: list[str]) -> list[int]:
        time = [0] * n
        st = []
        timer = 0
        for i in range(0, len(logs)):
            id, act, tmp = logs[i].split(":")
            id = int(id)
            tmp = int(tmp)

            if (act == "start"):
                if (len(st) > 0):
                    st[-1][1] = st[-1][1] + (tmp - timer)
                # id, total time used
                st.append([id, 0])
            else:
                tmp += 1
                prev = st.pop()[1]
                time[id] = time[id] + prev + (tmp - timer)

            timer = tmp
        return time
