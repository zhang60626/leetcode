/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {
    Queue<NestedInteger> q;
    NestedIterator ni;
    
    public NestedIterator(List<NestedInteger> nestedList) {
        q = new LinkedList();
        for (NestedInteger n : nestedList) {
            if (n.isInteger()) q.add(n);
            else if (!n.getList().isEmpty()) q.add(n);
        }
        ni = null;
    }

    @Override
    public Integer next() {
        if (ni != null) return ni.next();
        return q.remove().getInteger(); 
    }

    @Override
    public boolean hasNext() {
        if (ni != null) {
            if (ni.hasNext()) return true;
            else {
                ni = null;
                return hasNext();
            }
        }
        if (!q.isEmpty()) {
            if (q.peek().isInteger()) return true;
            else {
                ni = new NestedIterator(q.remove().getList());
                return hasNext();
            }
        } else return false;
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */