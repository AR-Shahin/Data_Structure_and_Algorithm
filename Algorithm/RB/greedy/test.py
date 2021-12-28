class Solution:
    def isValid(self, s):
        stack = []
        hash = {
            "}": "{",
            ")": "(",
            "]": "["
        }

        for c in s:
            if c in hash:
                if stack and stack[-1] == hash[c]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(c)
        return True if len(stack) == 0 else False


s = Solution()

print(s.isValid("()"))
