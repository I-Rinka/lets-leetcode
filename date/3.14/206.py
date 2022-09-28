class Solution:
    def reverseList(self, head):
        cur=head
        nodeStack=[]
        while cur!=None:
            nodeStack.append(cur)
            cur=cur.next
        
        ans=nodeStack.pop()
        cur=ans
        while nodeStack.count>0:
            n=nodeStack.pop()
            n.next=None
            cur.next=n
            cur=n

        return ans