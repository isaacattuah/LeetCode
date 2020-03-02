class Solution:
    def isValid(self, S: str) -> bool:
        stack = []

        for c in S:
            if c == 'c':
                n = len(stack)
                if n < 2 or stack[n - 2] != 'a' or stack[n - 1] != 'b':
                    return False
                stack.pop()
                stack.pop()
            else:
                stack.append(c)

        return len(stack) == 0
