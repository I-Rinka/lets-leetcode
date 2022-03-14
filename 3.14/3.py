class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        hs={}
        begin=0
        maxL=0
        for i in range(len(s)):
            if s[i] in hs:
                if hs[s[i]]+1<begin:
                    begin=begin
                else:
                    begin=hs[s[i]]+1
                del hs[s[i]]
            hs[s[i]]=i
            l=i-begin+1
            if l>maxL:
                maxL=l
        return maxL